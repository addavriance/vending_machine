#ifndef CASHBOX_H
#define CASHBOX_H

#include <utility>


class CashBox {
private:
    double balance;
    double balanceLimit;
    int transactionCount;

public:
    CashBox();
    CashBox(double balanceLimit);

    double getBalance() const;

    void addCash(double amount);
    double takeCash(double amount);

    std::pair<bool, double> process(double price, double amount);
    bool canProcess(double change, double amount) const;

};



#endif //CASHBOX_H
