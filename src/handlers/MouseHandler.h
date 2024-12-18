#ifndef MOUSEHANDLER_H
#define MOUSEHANDLER_H

#include <functional>
#include <map>
#include <thread>
#include <atomic>
#include <termios.h>
#include <chrono>
#include <iostream>
#include <unistd.h>

class MouseHandler {
private:
    termios oldSettings;
    termios newSettings;

    // Структура для хранения координат
    struct Point {
        int x;
        int y;
    };

    // Структура для отслеживания двойного клика
    struct ClickInfo {
        Point lastClick;
        std::chrono::steady_clock::time_point lastClickTime;
        bool isFirstClick = true;
    } clickTracker;

    std::map<std::string, std::function<void(int, int)>> callbacks;
    const int DOUBLE_CLICK_TIMEOUT_MS = 500;

    std::thread eventThread;
    std::atomic<bool> isRunning;

    void enableMouseTracking();
    void disableMouseTracking();
    void handleClick(int x, int y);
    void eventLoop();

public:
    MouseHandler();
    ~MouseHandler();

    // Регистрация callback'ов
    void onSingleClick(std::function<void(int, int)> callback);
    void onDoubleClick(std::function<void(int, int)> callback);
    void onMouseMove(std::function<void(int, int)> callback);

    // Методы управления событиями
    bool tickEvent();  // Обработать одно событие
    void startEventLoop();  // Запустить цикл в отдельном потоке
    void stopEventLoop();   // Остановить цикл
};

#endif // MOUSEHANDLER_H