#include "BarSlot.h"
#include <iostream>

BarSlot::BarSlot(int d) : depth(d), isEmpty(true), isFull(false) {}

bool BarSlot::addSnack(std::shared_ptr<Snack>& snack) {
    if (snacks.size() >= depth) return false;

    snacks.push_back(std::move(snack));

    isFull = snacks.size() == depth;

    isEmpty = false;

    return true;
}

std::shared_ptr<Snack> BarSlot::getSnack(int index) {
    if (isEmpty || index >= snacks.size()) {
        return nullptr;
    }

    return snacks[index];
}

std::shared_ptr<Snack> BarSlot::dropSnack() {
    if (snacks.empty()) {
        return nullptr;
    }

    auto snack = snacks.front();
    snacks.erase(snacks.begin());

    isEmpty = snacks.empty();
    isFull = false;

    return snack;
}