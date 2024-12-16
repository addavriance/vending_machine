cmake_minimum_required(VERSION 3.29)
project(vending_machine)

set(CMAKE_CXX_STANDARD 20)

add_executable(vending_machine main.cpp
        src/cash/CashBox.cpp
        src/filler/StorageFiller.cpp
        src/item/Snack.cpp
        src/storage/BarStorage.cpp
        src/machine.cpp
        src/utils.cpp
        src/bar/BarLine.cpp
        src/bar/BarSlot.cpp
        src/cash/CashBox.h
        src/filler/StorageFiller.h
        src/item/Snack.h
        src/storage/BarStorage.h
        src/machine.h
        src/utils.h
        src/bar/BarLine.h
        src/bar/BarSlot.h
        src/visualization/visualler.cpp
        src/visualization/visualler.h
        src/keypad/Keypad.cpp
        src/keypad/Keypad.h
        src/handlers/MouseHandler.cpp
        src/handlers/MouseHandler.h
        src/client/Client.cpp
        src/client/Client.h
        src/item/Item.cpp
        src/item/Item.h
)
