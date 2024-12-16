#include "Client.h"

Client::Client() : inventory_size(10), balance(0.0) {
    inventory = std::make_shared<std::vector<Item>>();
}

Client::~Client() = default;

void Client::addItem(std::shared_ptr<Item>& item) {
    if (inventory->size() < inventory_size) {
        inventory->push_back(*item);
    }
}

Item Client::dropItem(int index) {

    Item empty = inventory->at(index);
    if (index >= 0 && index < inventory->size()) {
        inventory->erase(inventory->begin() + index);
    }

    return empty;
}

void Client::setBalance(double amount) {
    balance = amount;
}

void Client::addBalance(double amount) {
    balance += amount;
}

double Client::takeCash(double amount) {
    if (amount <= balance) {
        balance -= amount;
        return amount;
    }
    double available = balance;
    balance = 0;
    return available;
}

std::shared_ptr<std::vector<Item>> Client::getInventory() {
    return inventory;
}