#ifndef SNACKTRAY_H
#define SNACKTRAY_H

#include "../../objects/item/Snack.h"
#include "../../helpers/utils.h"

#include <vector>


class SnackTray {

private:
    int x;
    int y;

    int size;

    std::vector<std::shared_ptr<Snack>> snacks;

    std::function<void(std::shared_ptr<Snack> snack)> onTakeSnack;
public:
    SnackTray();
    SnackTray(int x, int y, int size);

    void addSnack(std::shared_ptr<Snack>& snack);

    std::shared_ptr<Snack> takeSnack(int index);

    std::shared_ptr<std::vector<Snack>> getSnacks();

    int getSize() { return size; }

    bool isFull() { return snacks.size() == size; }

    bool isEmpty() { return snacks.empty(); }

    void click(int click_x, int click_y);

    void visualize();

    void setOnTakeSnack(std::function<void(std::shared_ptr<Snack> snack)> callback) {
        onTakeSnack = std::move(callback);
    }

};



#endif //SNACKTRAY_H
