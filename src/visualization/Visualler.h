#ifndef VISUALLER_H
#define VISUALLER_H

#include "../machine.h"


class Visualler {
private:
    std::shared_ptr<VendingMachine> machine;
    void visualize_case(int storage_width, int storage_height) const;

    void visualize_storage(int width, int height) const;

    void visualize_stats() const;

public:
    Visualler(std::shared_ptr<VendingMachine> machine);

    std::string getCornerChar(int bar, int slot, int width, int height) const;

    std::string getBorderChar(int bar, int slot, int width) const;

    std::string getCrossChar(int bar, int slot, int height) const;

    void visualize() const;
};



#endif //VISUALLER_H
