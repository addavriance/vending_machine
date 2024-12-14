#include "BarSlot.h"

#include <iostream>

BarSlot::BarSlot(int d) : depth(d), isEmpty(true), isFull(false) {}

bool BarSlot::addSnack(std::shared_ptr<Snack>& snack) {
    if (isFull) return false;

    snacks.push_back(std::move(snack));

    isFull = snacks.size() == depth;

    isEmpty = false;

    return true;
}

std::shared_ptr<Snack> BarSlot::getSnack(int index) {
    if (isEmpty) return nullptr;

    if (index >= snacks.size()) return nullptr;

    return snacks[index];
}

std::shared_ptr<Snack> BarSlot::dropSnack() {
    if (isEmpty) return nullptr;

    auto snack = snacks[0];

    snacks.erase(snacks.begin());

    isEmpty = snacks.empty();

    return snack;
}