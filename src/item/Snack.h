#pragma once
#include <string>

#include "Item.h"

class Snack : public Item{
protected:
    double price;
    int calories;
    std::string id;

public:
    Snack(const std::string& icon, const std::string& name, double price, int cal, const std::string& snackId);

    ~Snack() override = default;

    double getPrice() const { return price; }
    int getCalories() const { return calories; }
    std::string getId() const { return id; }

    bool operator==(const Snack& other) const {
        return id == other.id;
    }
};
