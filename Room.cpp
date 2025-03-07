#include "Room.h"

// Constructor: Initializes Rooms with an ID and Random Contents
Room::Room(int id) : roomID(id), hasItem(false) {
}

// Function for Randomly Determining Room Contents
void Room::generateRoom() {
    // Ensure randomness works correctly (srand is now ONLY in Game.cpp)
    int enemyChance = rand() % 2; // 50% chance to have an enemy
    int itemChance = rand() % 5;  // 20% chance to have an item

    // Assign an enemy if the condition is met
    if (enemyChance == 0) {
        enemy = make_shared<Enemy>("Skeleton", 20, 5);
    } else {
        enemy = nullptr;
    }

    // Assign item if condition is met
    hasItem = (itemChance == 0);
}

// Enemy Handling
bool Room::hasEnemy() const {
    return enemy != nullptr;
}

shared_ptr<Enemy> Room::getEnemy() {
    return enemy;
}

void Room::removeEnemy() {
    enemy = nullptr;
}

// Getter Functions
bool Room::containsItem() const { return hasItem; } // Checks if the Room Contains an Item
shared_ptr<Room> Room::getLeftRoom() const { return leftRoom; } // Returns the Left Room
shared_ptr<Room> Room::getRightRoom() const { return rightRoom; } // Returns the Right Room

// Function for Linking the Rooms Together
void Room::setLeftRoom(shared_ptr<Room> room) { leftRoom = room; }
void Room::setRightRoom(shared_ptr<Room> room) { rightRoom = room; }

// Room Information for Debugging and Testing
void Room::displayRoomInfo() const {
    cout << "Room ID: " << roomID << "\n"; // Verify Room Number
    cout << "Enemy: " << (hasEnemy() ? "TRUE" : "FALSE") << "\n"; // Enemy Checker
    cout << "Item: " << (hasItem ? "TRUE" : "FALSE") << "\n"; // Item Checker
}
