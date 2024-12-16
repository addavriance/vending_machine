#include "Keypad.h"

Keypad::Keypad(): x(0), y(0), temp_cash(0) { }
Keypad::Keypad(int x, int y): x(x), y(y), temp_cash(0) { }

void Keypad::click(int click_x, int click_y) {
    int char_x = click_x - x - 1;
    int char_y = click_y - y - 1;

    if (char_x < 0 || char_y < 0 || char_x > 2 || char_y > 2) return;

    int char_pos = char_x + (char_y * 3);

    if (char_pos < char_map.size() - 3 && display_text.size() < 3) // type
        display_text+=char_map[char_pos];

    if (char_pos == 6) display_text = ""; // del
    if (char_pos == 7) display_text = display_text.substr(0, display_text.size() - 1); // erase
    if (char_pos == 8) { // buy
        if (onBuyRequest && !display_text.empty()) {
            try {
                auto slot = display_text.at(1) - '0' - 1;
                auto line = findCharIndex(char_map, display_text.at(0));

                auto success = onBuyRequest(line, slot, returnMoney(temp_cash));

                if (success) {
                    display_text = " OK";
                } else {
                    display_text = "ERR";
                }
            } catch (const std::exception&) {
                display_text = "ERR";
            }
        }
    }

}

void Keypad::visualize() {

    cout_at(x+1, y-1, display_text);

    for (int i = -1; i <= 4; i++) {
        cout_at(x, y+i, border.vertical);
        cout_at(x+4, y+i, border.vertical);
    }

    cout_at(x+1, y-2, border.horizontal);
    cout_at(x+1, y, border.horizontal);
    cout_at(x+1, y+4, border.horizontal);

    cout_at(x, y-2, border.topLeft);
    cout_at(x+4, y-2, border.topRight);

    cout_at(x, y, border.leftCross);
    cout_at(x+4, y, border.rightCross);
    cout_at(x, y+4, border.bottomLeft);
    cout_at(x+4, y+4, border.bottomRight);

    int y_shift = 0;

    for (int i = 0; i < char_map.size(); i++) {
        if (i % 3 == 0) y_shift++;
        cout_at(x + 1 + i % 3, y+y_shift, char_map[i]);
    }
}


