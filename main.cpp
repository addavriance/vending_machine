#include <iostream>

#include "src/machine.h"
#include "src/filler/StorageFiller.h"
#include "src/handlers/MouseHandler.h"
#include "src/visualization/Visualler.h"

int main() {

    StorageFiller filler;

    MouseHandler handler;

    auto vending_machine = std::make_shared<VendingMachine>(3, 5, 5);
    Visualler visualler(vending_machine);


    handler.onSingleClick([vending_machine](int x, int y) {
        vending_machine->keypad->click(x, y);

    handler.startEventLoop();

    filler.fillMachine(vending_machine);

    while (true){
        visualler.visualize();
    }

    return 0;
}
