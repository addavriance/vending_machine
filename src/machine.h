#pragma once
#include "storage/BarStorage.h"

#include <memory>
#include <string>
#include <map>

#include "cash/CashBox.h"

class VendingMachine {

private:
    int width;
    int height;
    int depth;

    std::unique_ptr<BarStorage> storage;
    std::unique_ptr<CashBox> cash_box;

public:
    VendingMachine(int width, int height, int depth);

    std::tuple<int, int, int> getDimensions();

    bool addSnack(std::shared_ptr<Snack> snack, int line, int slot);

    std::shared_ptr<Snack> getSnack(int line, int slot, int index = 0);

    std::pair<std::shared_ptr<Snack>, double> buySnack(int line, int slot, double amount);
};

