#pragma once
#include "../item/Snack.h"
#include <memory>

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
    int getDepth() const { return depth; }
};