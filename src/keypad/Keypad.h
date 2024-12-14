#ifndef KEYPAD_H
#define KEYPAD_H
#include <string>


class Keypad {

private:
    int x;
    int y;

    std::string display_text;
    double temp_cash;

    std::vector<std::string> char_map =
        {
            "A", "B", "C",
            // "D", "E", "F",
            // "G", "H", "K",
            "1", "2", "3",
            "×", "⌫", "✓"
        };


public:
    Keypad();
    Keypad(int x, int y);

    void type_char(int click_x, int click_y);

    void visualize();

};



#endif //KEYPAD_H
