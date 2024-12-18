#include "Client.h"

Client::Client() : inventory_size(10), balance(0.0), inventory(std::vector<std::shared_ptr<Item>>()) {
}

Client::~Client() = default;

void Client::addItem(std::shared_ptr<Item>& item) {
    if (inventory.size() <= inventory_size) {
        inventory.push_back(std::move(item));
    }
}

std::shared_ptr<Item> Client::dropItem(int index) {

    std::shared_ptr<Item> empty = inventory.at(index);
    if (index >= 0 && index < inventory.size()) {
        inventory.erase(inventory.begin() + index);
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

std::vector<std::shared_ptr<Item>> Client::getInventory() {
    return inventory;
}