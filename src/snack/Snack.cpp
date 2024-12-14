#include "Snack.h"

Snack::Snack(const std::string& i, const std::string& n, double p, int cal, const std::string& snackId)
    : icon(i), name(n), price(p), calories(cal), id(snackId) {
}