#include "MouseHandler.h"
#include <iostream>
#include <sys/ioctl.h>
#include <unistd.h>

MouseHandler::MouseHandler() : isRunning(false) {
    tcgetattr(STDIN_FILENO, &oldSettings);
    newSettings = oldSettings;

    newSettings.c_lflag &= ~(ICANON | ECHO);
    tcsetattr(STDIN_FILENO, TCSANOW, &newSettings);

    enableMouseTracking();
}

MouseHandler::~MouseHandler() {
    stopEventLoop();
    disableMouseTracking();
    tcsetattr(STDIN_FILENO, TCSANOW, &oldSettings);
}

void MouseHandler::enableMouseTracking() {
    std::cout << "\033[?1000h"; // Включить отслеживание кликов
    std::cout << "\033[?1003h"; // Включить отслеживание всех событий мыши
    std::cout << "\033[?1015h"; // Расширенный режим отслеживания мыши
    std::cout << "\033[?1006h"; // SGR режим кодирования
    std::cout.flush();
}

void MouseHandler::disableMouseTracking() {
    std::cout << "\033[?1000l";
    std::cout << "\033[?1003l";
    std::cout << "\033[?1015l";
    std::cout << "\033[?1006l";
    std::cout.flush();
}

void MouseHandler::onSingleClick(std::function<void(int, int)> callback) {
    callbacks["click"] = callback;
}

void MouseHandler::onDoubleClick(std::function<void(int, int)> callback) {
    callbacks["doubleclick"] = callback;
}

void MouseHandler::onMouseMove(std::function<void(int, int)> callback) {
    callbacks["move"] = callback;
}

void MouseHandler::handleClick(int x, int y) {
    auto now = std::chrono::steady_clock::now();

    if (!clickTracker.isFirstClick) {
        auto duration = std::chrono::duration_cast<std::chrono::milliseconds>
            (now - clickTracker.lastClickTime).count();

        if (duration <= DOUBLE_CLICK_TIMEOUT_MS &&
            x == clickTracker.lastClick.x &&
            y == clickTracker.lastClick.y) {
            if (callbacks.count("doubleclick")) {
                callbacks["doubleclick"](x, y);
            }
            clickTracker.isFirstClick = true;
            return;
        }
    }

    if (callbacks.count("click")) {
        callbacks["click"](x, y);
    }

    clickTracker.lastClick = {x, y};
    clickTracker.lastClickTime = now;
    clickTracker.isFirstClick = false;
}

bool MouseHandler::tickEvent() {
    char buf[32];
    fd_set fds;
    timeval tv = {0, 0};

    FD_ZERO(&fds);
    FD_SET(STDIN_FILENO, &fds);

    // Проверяем, есть ли данные для чтения
    if (select(STDIN_FILENO + 1, &fds, NULL, NULL, &tv) > 0) {
        if (read(STDIN_FILENO, buf, sizeof(buf)) > 0) {
            // Парсим SGR последовательность
            if (buf[0] == '\033' && buf[1] == '[' && buf[2] == '<') {
                int eventType, x, y;
                sscanf(buf + 3, "%d;%d;%d", &eventType, &x, &y);

                switch (eventType) {
                    case 0: // Клик мыши
                        handleClick(x, y);
                        break;
                    case 35: // Движение мыши
                        if (callbacks.count("move")) {
                            callbacks["move"](x, y);
                        }
                        break;
                }
                return true;
            }
        }
    }
    return false;
}

void MouseHandler::eventLoop() {
    while (isRunning) {
        tickEvent();
        std::this_thread::sleep_for(std::chrono::milliseconds(10));
    }
}

void MouseHandler::startEventLoop() {
    if (!isRunning) {
        isRunning = true;
        eventThread = std::thread(&MouseHandler::eventLoop, this);
    }
}

void MouseHandler::stopEventLoop() {
    if (isRunning) {
        isRunning = false;
        if (eventThread.joinable()) {
            eventThread.join();
        }
    }
}