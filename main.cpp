#include <iostream>

#include "src/machine.h"
#include "src/filler/StorageFiller.h"
#include "src/visualization/Visualler.h"

int main() {
    auto vending_machine = std::make_shared<VendingMachine>(3, 5, 9);

    StorageFiller filler;

    filler.fillMachine(vending_machine);

    Visualler visualler(vending_machine);

    while (true){

    visualler.visualize();

    }

    return 0;
}
