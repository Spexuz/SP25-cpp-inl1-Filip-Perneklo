#include "Room.h"
#include "Item.h"
#include <cstdlib>
#include <ctime>

// Constructor: Initializes the room
Room::Room(int id, int difficultyMultiplier)
    : roomID(id), hasItem(false), difficultyMultiplier(difficultyMultiplier) {
    generateRoom();
}
    // Do not call generateRoom() here; Gave me a huge fucking headache
    // We call it explicitly in Game.cpp after creating the room.

// Generates room contents (enemy and item) randomly
void Room::generateRoom() {
    int enemyChance = rand() % 2;
    int itemChance = rand() % 5;

    if (enemyChance == 0) {
        enemy = make_shared<Enemy>("Skeleton", 20 * difficultyMultiplier, 5 * difficultyMultiplier);
    } else {
        enemy = nullptr;
    }

    hasItem = (itemChance == 0);

    if (hasItem) {
        item = make_shared<Item>("Health Potion", 10);
    } else {
        item = nullptr;
    }
}

// Enemy handling
bool Room::hasEnemy() const {
    return enemy != nullptr;
}

shared_ptr<Enemy> Room::getEnemy() {
    return enemy;
}

void Room::removeEnemy() {
    enemy = nullptr;
}

// Item handling
bool Room::hasItemFunc() const {
    return hasItem;
}

shared_ptr<Item> Room::getItem() {
    return item;
}

void Room::removeItem() {
    item = nullptr;
}

// Room linking functions
shared_ptr<Room> Room::getLeftRoom() const {
    return leftRoom;
}

shared_ptr<Room> Room::getRightRoom() const {
    return rightRoom;
}

void Room::setLeftRoom(shared_ptr<Room> room) {
    leftRoom = room;
}

void Room::setRightRoom(shared_ptr<Room> room) {
    rightRoom = room;
}

// Displays room information (for debugging/testing)
void Room::displayRoomInfo() const {
    cout << "Room ID: " << roomID << "\n";
    cout << "Enemy: " << (hasEnemy() ? "TRUE" : "FALSE") << "\n";
    cout << "Item: " << (hasItemFunc() ? "TRUE" : "FALSE") << "\n";
}
