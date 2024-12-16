#include "StorageFiller.h"

std::shared_ptr<Snack> StorageFiller::createRandomSnack() {
    int index = randint(0, snackTemplates.size() - 1);
    auto [icon, name, price, id] = snackTemplates[index];

    int calories = randint(100, 500);

    return std::make_shared<Snack>(icon, name, price, calories, id);
}

void StorageFiller::fillMachine(const std::shared_ptr<VendingMachine>& machine) {
    if (!machine) return;

    auto [width, height, depth] = machine->getDimensions();

    for (int line = 0; line < height; ++line) {
        for (int slot = 0; slot < width; ++slot) {
            const auto snack = createRandomSnack();
            for (int d = 0; d < depth; ++d) {
                if (!machine->addSnack(snack, line, slot)) {
                    std::cerr << "Failed to add snack at position: " << line << "," << slot << "," << d << std::endl;
                }
            }
        }
    }
}
