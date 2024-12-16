#include "CashBox.h"

#include <utility>

CashBox::CashBox() : balance(0), balanceLimit(3500), transactionCount(0) {};
CashBox::CashBox(double balLim) : balance(0), balanceLimit(balLim), transactionCount(0) {};

void CashBox::addCash(double amount) {
    if (balance + amount <= balanceLimit) {
        balance += amount;
    }
}

double CashBox::takeCash(double amount) {
    if (balance - amount >= 0) {
        balance -= amount;
    } else {
        amount = balance;

        balance = 0;
    }

    return amount;
}

double CashBox::getBalance() const {
    return balance;
}

std::pair<bool, double> CashBox::process(double price, double amount) {
    transactionCount++;

    double change = amount - price;

    if (!canProcess(change, amount)) return std::make_pair(false, amount);

    addCash(price);

    return std::make_pair(true, change);
}

bool CashBox::canProcess(double change, double amount) const {
    if (change < 0) {
        return false;
    }

    if (balance + amount > balanceLimit) {
        return false;
    }

    return true;
}
