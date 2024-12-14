#include "Keypad.h"

#include "../utils.h"

Keypad::Keypad(): x(0), y(0), temp_cash(0) { }
Keypad::Keypad(int x, int y): x(x), y(y), temp_cash(0) { }

void Keypad::type_char(int click_x, int click_y) {
    int char_x = click_x - x;
    int char_y = click_y - y;

}

void Keypad::visualize() {
    cout_at(x+1, y, border.horizontal);
    cout_at(x+1, y+4, border.horizontal);

    cout_at(x, y, border.topLeft);
    cout_at(x+4, y, border.topRight);
    cout_at(x, y+4, border.bottomLeft);
    cout_at(x+4, y+4, border.bottomRight);

    for (int i = 1; i <= 3; i++) {
        cout_at(x, y+i, border.vertical);
        cout_at(x+4, y+i, border.vertical);
    }

    int y_shift = 0;

    for (int i = 0; i < char_map.size(); i++) {
        if (i % 3 == 0) y_shift++;
        cout_at(x+i%3+1, y+y_shift, char_map[i]);
    }
}


