//
// Created by Иван Нетяженко on 16.12.2024.
//

#include "Item.h"

Item::Item() = default;

Item::Item(std::string i, std::string n): icon(std::move(i)), name(std::move(n)) {}
