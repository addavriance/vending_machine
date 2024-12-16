#pragma once

#include "../../objects/item/Snack.h"

class BarSlot {
private:
    int depth;
    std::vector<std::shared_ptr<Snack>> snacks;
    bool isEmpty;
    bool isFull;

public:
    explicit BarSlot(int d);
    bool addSnack(std::shared_ptr<Snack>& snack);

    std::shared_ptr<Snack> getSnack(int index);

    std::shared_ptr<Snack> dropSnack();
    bool isSlotEmpty() const { return isEmpty; }
    bool isSlotFull() const { return isFull; }
    int getDepth() const { return depth; }

    std::vector<std::shared_ptr<Snack>>& getSnacks() { return snacks; };
};