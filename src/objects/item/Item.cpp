#include "Item.h"

Item::Item() = default;

Item::Item(std::string i, std::string n): icon(std::move(i)), name(std::move(n)) {}
