#include "Visualler.h"

#include <iostream>
#include <ostream>

#include "../utils.h"
#include "../keypad/Keypad.h"

Visualler::Visualler(std::shared_ptr<VendingMachine> m): machine(std::move(m)) {}

std::string Visualler::getCornerChar(int bar, int slot, int width, int height) const {
    return (bar == 0 && slot == 0) ? border.topLeft :
    (bar == 0 && slot == width - 1) ? border.topRight :
    (bar == height - 1 && slot == 0) ? border.bottomLeft :
    (bar == height -1 && slot == width - 1) ? border.bottomRight : "";
}

std::string Visualler::getBorderChar(int bar, int slot, int width) const {
    const bool slot_even = slot % 2 == 0;
    const bool bar_even = bar % 2 == 0;

    return (!slot_even && bar_even) ? border.horizontal :
    (slot_even && !bar_even) ? border.vertical :
    (slot == 0) ? border.leftCross :
    (slot == width-1) ? border.rightCross : "";
}

std::string Visualler::getCrossChar(int bar, int slot, int height) const {
    if (slot % 2 == 0 && bar % 2 == 0) {
        if (bar == 0) return border.topCross;
        if (bar != height - 1) return border.cross;
        return border.bottomCross;
    }

    return "";
}


void Visualler::visualize_case(int storage_width, int storage_height) const {
    int panel_width = 10;
    int panel_height = 5;

    int startX = 1 + storage_width + 4 * storage_width;
    int startY = 1 + storage_height + 1 * storage_height;

    int endX = panel_width + storage_width + 4 * storage_width;
    int endY = panel_height + storage_height + 1 * storage_height;

    // Стык верха
    cout_at(startX, 0, border.topCross);

    // Боковые стенки
    for (int y = 2; y < endY; y++) {
        if (y > startY) { // Отсек выдачи
            cout_at(0, y, border.vertical);
            cout_at(startX, y, border.vertical);
        }

        cout_at(endX, y, border.vertical);
    }

    // Верхние и нижние стенки
    for (int x = 1; x < endX-3; x++) {
        cout_at(x, endY, border.horizontal);

        if (x > startX) cout_at(x, 0, border.horizontal);
    }

    // Стыки отсека выдачи
    cout_at(startX, startY, border.rightCross);
    cout_at(0, startY, border.leftCross);

    cout_at(0, endY, border.bottomLeft);
    cout_at(startX, endY, border.bottomCross);

    cout_at(endX, 0, border.topRight);

    cout_at(endX, endY, border.bottomRight);
}


void Visualler::visualize_storage(int width, int height) const {
    int draw_width = width*2+1;
    int draw_height = height*2+1;

    for (int bar_index = 0; bar_index < draw_height; bar_index++) {
        for (int slot_index = 0; slot_index < draw_width; slot_index++) {

            std::string snack_icon = "  ";

            std::string corner_char = getCornerChar(bar_index, slot_index, draw_width, draw_height);
            std::string border_char = getBorderChar(bar_index, slot_index, draw_width);
            std::string cross_char = getCrossChar(bar_index, slot_index, draw_height);

            const std::shared_ptr<Snack> snack = machine->getSnack((bar_index-1)/2, (slot_index-1)/2);
            if (snack) snack_icon = snack->getIcon();

            if (!corner_char.empty()) std::cout << corner_char;
            else if (!border_char.empty()) std::cout << border_char;
            else if (!cross_char.empty()) std::cout << cross_char;
            else std::cout << " " << snack_icon << " ";
        }

        std::cout << "\n";
    }
}

void Visualler::visualize_stats() const {
    const int stats_x = 27;
    const int stats_y = 2;

    cout_at(stats_x, stats_y, "Machine balance: " + std::to_string(machine->getBalance()));
    cout_at(stats_x, stats_y+1, "Your balance: " + std::to_string(machine->getClientBalance()));
    cout_at(stats_x, stats_y+2, "Keypad temp: " + std::to_string(machine->keypad->getBalance()));
}


void Visualler::visualize() const {
    system("clear");

    auto [width, height, _] = machine->getDimensions();

    visualize_storage(width, height); // ⤵
    visualize_case(width, height); // refactor?

    machine->keypad->visualize();

    visualize_stats();

    std::cout.flush();
}
