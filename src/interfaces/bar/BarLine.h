#pragma once

#include "BarSlot.h"
#include <vector>

class BarLine {
private:
    std::vector<BarSlot> slots;
    int lineWidth;
    int slotDepth;

public:
    BarLine(int width, int depth);
    BarSlot& getSlot(int index);
    const std::vector<BarSlot>& getSlots() const { return slots; }
    int getWidth() const { return lineWidth; }
};