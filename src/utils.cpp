#include "utils.h"

int randint(const int min, const int max) {
    static std::mt19937 generator(std::chrono::system_clock::now().time_since_epoch().count());
    std::uniform_int_distribution distribution(min, max);
    return distribution(generator);
}

void cout_at(int x, int y, const std::string& str) {
    std::cout << "\033[" << y << ";" << x << "H";

    std::cout << str;
}

