#ifndef ITEM_H
#define ITEM_H

#include <string>


class Item {
protected:
    std::string icon;
    std::string name;

public:
    Item();
    Item(std::string i, std::string n);

    virtual ~Item() = default;

    std::string getIcon() const { return icon; }
    std::string getName() const { return name; }
};



#endif //ITEM_H
