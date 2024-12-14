#ifndef UTILS_H
#define UTILS_H

#include <string>
#include <random>
#include <iostream>

struct BorderChars {
    const std::string topLeft = "┌";
    const std::string topRight = "┐";
    const std::string bottomLeft = "└";
    const std::string bottomRight = "┘";
    const std::string vertical = "│";
    const std::string horizontal = "────";
    const std::string cross = "┼";
    const std::string topCross = "┬";
    const std::string bottomCross = "┴";
    const std::string leftCross = "├";
    const std::string rightCross = "┤";
    const std::string space = "    ";
};

inline BorderChars border;

int randint(int min, int max);

void cout_at(int x, int y, const std::string& str);

#endif //UTILS_H
