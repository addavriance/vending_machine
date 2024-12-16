#pragma once

#include "../../interfaces/bar/BarLine.h"

#include <vector>

class BarStorage {
private:
    int width;
    int height;
    int depth;
    std::vector<BarLine> lines;

public:
    BarStorage(int w, int h, int d);
    int getWidth() const { return width; }
    int getHeight() const { return height; }
    int getDepth() const { return depth; }
    const std::vector<BarLine>& getLines() const { return lines; }
    BarLine& getLine(int index);
};