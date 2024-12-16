#pragma once

#include <map>

#include "./processors/storage/BarStorage.h"
#include "./processors/cash/CashBox.h"
#include "./objects/client/Client.h"
#include "./interfaces/keypad/Keypad.h"
#include "./helpers/utils.h"

class VendingMachine {

private:
    int width;
    int height;
    int depth;

    std::shared_ptr<Client> current_client;

    std::unique_ptr<BarStorage> storage;
    std::unique_ptr<CashBox> cash_box;

public:
    VendingMachine(int width, int height, int depth);

    std::unique_ptr<Keypad> keypad;

    std::tuple<int, int, int> getDimensions();

    bool addSnack(std::shared_ptr<Snack> snack, int line, int slot);

    std::shared_ptr<Snack> getSnack(int line, int slot, int index = 0);

    std::pair<std::shared_ptr<Snack>, double> buySnack(int line, int slot, double amount);

    double getBalance() { return cash_box->getBalance(); }

    double getClientBalance() { return current_client->getBalance(); }

    void setClient(std::shared_ptr<Client> client) {
        current_client = std::move(client);
    }

    void setupKeypadCallbacks() {
        keypad->setOnBuyRequest([this](int line, int slot, double amount) {
            if (!current_client) {
                return false;
            }

            auto [snack, change] = this->buySnack(line, slot, amount);

            if (snack) {
                // Если покупка успешна
                current_client->addBalance(change); // Возвращаем сдачу
                auto item = std::static_pointer_cast<Item>(snack);
                current_client->addItem(item); // Добавляем в инвентарь
                return true;
            }

            current_client->addBalance(keypad->returnMoney(amount));

            return false;
        });

        keypad->setOnInsertMoney([this](double amount) {
            if (!current_client) return 0.0;

            // Снимаем деньги с клиента и добавляем в кейпад
            double inserted = current_client->takeCash(amount);
            return inserted;
        });
    }
};

