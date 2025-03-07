#ifndef ITEM_H
#define ITEM_H

#include <string>

using namespace std;

// Item Class – Represents a collectible item (for example, a Health Potion)
class Item {
private:
    string name; // Item name
    int value;   // Effect value

public:
    // Constructor for items
    Item(string name, int value);

    // Getters
    string getName() const;
    int getValue() const;
};

#endif // ITEM_H
