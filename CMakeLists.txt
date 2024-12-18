cmake_minimum_required(VERSION 3.29)
project(vending_machine)

set(CMAKE_CXX_STANDARD 20)

add_executable(vending_machine main.cpp
        src/processors/cash/CashBox.cpp
        src/helpers/filler/StorageFiller.cpp
        src/objects/item/Snack.cpp
        src/processors/storage/BarStorage.cpp
        src/machine.cpp
        src/helpers/utils.cpp
        src/interfaces/bar/BarLine.cpp
        src/interfaces/bar/BarSlot.cpp
        src/processors/cash/CashBox.h
        src/helpers/filler/StorageFiller.h
        src/objects/item/Snack.h
        src/processors/storage/BarStorage.h
        src/machine.h
        src/helpers/utils.h
        src/interfaces/bar/BarLine.h
        src/interfaces/bar/BarSlot.h
        src/helpers/visualization/visualler.cpp
        src/helpers/visualization/visualler.h
        src/interfaces/keypad/Keypad.cpp
        src/interfaces/keypad/Keypad.h
        src/handlers/MouseHandler.cpp
        src/handlers/MouseHandler.h
        src/objects/client/Client.cpp
        src/objects/client/Client.h
        src/objects/item/Item.cpp
        src/objects/item/Item.h
        src/interfaces/tray/SnackTray.cpp
        src/interfaces/tray/SnackTray.h
)
