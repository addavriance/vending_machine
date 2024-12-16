#include "Snack.h"

Snack::Snack(const std::string& i, const std::string& n, double p, int cal, const std::string& snackId)
    : Item(i, n), price(p), calories(cal), id(snackId) {
}