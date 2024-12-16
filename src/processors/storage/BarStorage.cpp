#include "BarStorage.h"

BarStorage::BarStorage(int w, int h, int d) : width(w), height(h), depth(d) {
    if (w <= 0 || h <= 0 || d <= 0) {
        throw std::invalid_argument("Dimensions must be positive");
    }

    for (int i = 0; i < height; ++i) {
        lines.emplace_back(width, depth);
    }
}

BarLine& BarStorage::getLine(int index) {
    if (index < 0 || index > height) {
        throw std::out_of_range("Line index out of range");
    }
    return lines[index];
}