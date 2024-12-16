#include <iostream>

#include "src/machine.h"
#include "src/client/Client.h"
#include "src/filler/StorageFiller.h"
#include "src/handlers/MouseHandler.h"
#include "src/visualization/Visualler.h"

int main() {
    auto client = std::make_shared<Client>();

    client->setBalance(100);

    StorageFiller filler;

    MouseHandler handler;

    auto vending_machine = std::make_shared<VendingMachine>(3, 5, 5);
    Visualler visualler(vending_machine);

    vending_machine->setClient(client);

    vending_machine->keypad->insertMoney(20);

    handler.onSingleClick([vending_machine](int x, int y) {
        vending_machine->keypad->click(x, y);
    });

    handler.startEventLoop();

    filler.fillMachine(vending_machine);

    while (true){
        visualler.visualize();
    }

    return 0;
}
