#pragma once
#include <string>

class Snack {
protected:
    std::string icon;
    std::string name;
    double price;
    int calories;
    std::string id;

public:
    Snack(const std::string& icon, const std::string& name, double price, int cal, const std::string& snackId);

    virtual ~Snack() = default;

    std::string getIcon() const { return icon; }
    std::string getName() const { return name; }
    double getPrice() const { return price; }
    int getCalories() const { return calories; }
    std::string getId() const { return id; }

    bool operator==(const Snack& other) const {
        return id == other.id;
    }
};