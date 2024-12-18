#ifndef KEYPAD_H
#define KEYPAD_H

#include "../../helpers/utils.h"

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
            "×", " ", "✓"
        };

    std::string money_slot = "▭";

    std::function<bool(int, int, double)> onBuyRequest;
    std::function<double(double)> onInsertMoney;

public:
    Keypad();
    Keypad(int x, int y);

    void click(int click_x, int click_y);

    void visualize();

    double getBalance() const {
        return temp_cash;
    }

    bool insertMoney(double amount) {
        if (onInsertMoney) {
            temp_cash += onInsertMoney(amount);
            return true;
        }
        return false;
    }

    double returnMoney(double amount) {
        if (amount <= temp_cash) {
            temp_cash-=amount;
            return amount;
        }
        return 0;
    }

    void setOnBuyRequest(std::function<bool(int, int, double)> callback) {
        onBuyRequest = std::move(callback);
    }

    void setOnInsertMoney(std::function<double(double)> callback) {
        onInsertMoney = std::move(callback);
    }

};



#endif //KEYPAD_H
