#pragma once

#include "../../objects/item/Snack.h"

class BarSlot {
private:
    int depth;
    std::vector<std::shared_ptr<Snack>> snacks;

public:
    explicit BarSlot(int d);
    bool addSnack(std::shared_ptr<Snack>& snack);

    std::shared_ptr<Snack> getSnack(int index);

    std::shared_ptr<Snack> dropSnack();

    int getDepth() const { return depth; }

    bool isEmpty() const { return snacks.empty(); }
    bool isFull() const { return snacks.size() == depth; }


    std::vector<std::shared_ptr<Snack>>& getSnacks() { return snacks; };
};