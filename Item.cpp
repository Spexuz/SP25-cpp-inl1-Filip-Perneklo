#include "Item.h"

// Constructor for Item
Item::Item(string name, int value) : name(name), value(value) {}

// Getter for item name
string Item::getName() const {
    return name;
}

// Getter for item effect value
int Item::getValue() const {
    return value;
}
