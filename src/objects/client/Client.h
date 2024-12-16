#ifndef CLIENT_H
#define CLIENT_H

#include "../item/Item.h"

class Client {
private:
    std::shared_ptr<std::vector<Item>> inventory;

    int inventory_size;

    double balance;

public:
    Client();

    ~Client();

    void addItem(std::shared_ptr<Item>& item);

    Item dropItem(int index);

    std::shared_ptr<std::vector<Item>> getInventory();

    void setBalance(double amount);

    double getBalance() { return balance; }

    void addBalance(double amount);

    double takeCash(double amount);




};



#endif //CLIENT_H
