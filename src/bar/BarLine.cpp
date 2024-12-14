#include "BarLine.h"
#include <stdexcept>

BarLine::BarLine(int width, int depth) : lineWidth(width), slotDepth(depth) {
    for (int i = 0; i < width; ++i) {
        slots.emplace_back(depth);
    }
}

BarSlot& BarLine::getSlot(int index) {
    if (index < 0 || index >= lineWidth) {
        throw std::out_of_range("Slot index out of range");
    }
    return slots[index];
}