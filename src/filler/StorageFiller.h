// StorageFiller.h
#ifndef STORAGEFILLER_H
#define STORAGEFILLER_H

#include "../machine.h"
#include "../utils.h"
#include <vector>

class StorageFiller {
private:
    std::vector<std::tuple<std::string, std::string, double, std::string>> snackTemplates = {
        {"🍫", "Chocolate Bar", 2.50, "SNK" + std::to_string(randint(1000, 9999))},
        {"🥨", "Pretzels", 1.75, "SNK" + std::to_string(randint(1000, 9999))},
        {"🍪", "Cookies", 1.50, "SNK" + std::to_string(randint(1000, 9999))},
        {"🍬", "Candy", 1.00, "SNK" + std::to_string(randint(1000, 9999))},
        {"🍫", "Energy Bar", 2.00, "SNK" + std::to_string(randint(1000, 9999))},
        {"🥜", "Nuts", 2.25, "SNK" + std::to_string(randint(1000, 9999))},
        {"🍿", "Popcorn", 1.25, "SNK" + std::to_string(randint(1000, 9999))},
        {"🧂", "Potato Chips", 1.50, "SNK" + std::to_string(randint(1000, 9999))},
        {"🍭", "Lollipop", 1.75, "SNK" + std::to_string(randint(1000, 9999))},
        {"🥠", "Rice Crackers", 1.25, "SNK" + std::to_string(randint(1000, 9999))}
    };

    std::shared_ptr<Snack> createRandomSnack();

public:
    void fillMachine(const std::shared_ptr<VendingMachine>&);
};

#endif //STORAGEFILLER_H