#include "SnackTray.h"


SnackTray::SnackTray(): x(0), y(0), size(0) {}
SnackTray::SnackTray(int x, int y, int size): x(x), y(y), size(size) {}

void SnackTray::click(int click_x, int click_y) {
    int char_x = click_x - x - 2;
    int char_y = click_y - y - 1;

    if (char_x < 0 || char_x > size || char_y != 0) return;
    if (snacks.empty()) return;

    auto snack = takeSnack(char_x);
    if (snack == nullptr) return;
    onTakeSnack(std::move(snack));
}

void SnackTray::addSnack(std::shared_ptr<Snack>& snack) {
    if (snack == nullptr) return;
    if (snacks.size() < size) snacks.push_back(std::move(snack));
}

std::shared_ptr<Snack> SnackTray::takeSnack(int index) {
    if (index < 0 || index >= snacks.size()) {
        return nullptr;
    }

    std::shared_ptr<Snack> snack = snacks[index];
    snacks.erase(snacks.begin() + index);
    return snack;
}


void SnackTray::visualize() {
    int draw_width = size * 2 - 1;

    for (int i = 0; i <= draw_width; i++) {
        cout_at(x+i, y, border.horizontal);
        cout_at(x+i, y+2, border.horizontal);
    }

    cout_at(x, y+1, border.vertical);
    cout_at(x+draw_width+4, y+1, border.vertical);

    cout_at(x, y, border.topLeft);
    cout_at(x, y+2, border.bottomLeft);

    cout_at(x+draw_width+4, y, border.topRight);
    cout_at(x+draw_width+4, y+2, border.bottomRight);

    for (int i = 0; i < snacks.size(); i++) {
        cout_at(x+2+(i*2), y+1, snacks[i]->getIcon());
    }
}


