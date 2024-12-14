#include "machine.h"

#include <iostream>

#include "storage/BarStorage.h"

VendingMachine::VendingMachine(int w, int h, int d) : width(w), height(h), depth(d),
    storage(std::make_unique<BarStorage>(width, height, depth)),
    cash_box(std::make_unique<CashBox>()){ }

std::tuple<int, int, int> VendingMachine::getDimensions() {
    return { width, height, depth };
}

bool VendingMachine::addSnack(std::shared_ptr<Snack> snack, int line, int slot) {
    try {
        auto& barslot = storage->getLine(line).getSlot(slot);

        if (!barslot.isSlotEmpty()) { return false; }

        return barslot.addSnack(snack);
    } catch (std::out_of_range& e) {
        return false;
    }
}

std::shared_ptr<Snack> VendingMachine::getSnack(int line, int slot, int index) {
    try {
        return storage->getLine(line).getSlot(slot).getSnack(index);
    } catch (const std::out_of_range&) {
        return nullptr;
    }
}

std::pair<std::shared_ptr<Snack>, double> VendingMachine::buySnack(int line, int slot, double amount) {
    try {
        BarSlot barslot = storage->getLine(line).getSlot(slot);
        std::shared_ptr<Snack> snack = barslot.getSnack(0);

        auto [success, change] = cash_box->process(snack->getPrice(), amount);

        if (!success) {
            return std::make_pair(nullptr, amount);
        }

        barslot.dropSnack();

        return std::make_pair(snack, change);
    } catch (const std::out_of_range&) {
        return std::make_pair(nullptr, amount);
    }
}