#ifndef ROOM_H
#define ROOM_H

#include <iostream>
#include <memory>
#include "Enemy.h"
#include "Item.h"

using namespace std;

class Room {
private:
    int roomID;   //RoomID for Debugging
    bool hasItem;
    shared_ptr<Enemy> enemy;  // Pointer to an enemy in the room
    shared_ptr<Item> item;    // Pointer to an item in the room
    int difficultyMultiplier;
    shared_ptr<Room> leftRoom;  // Pointer to the left room (if any)
    shared_ptr<Room> rightRoom; // Pointer to the right room (if any)


public:
    // Constructor: Initializes a room with an ID
    Room(int id, int difficultyMultiplier);

    // Generates the room's contents (enemy and item) randomly
    void generateRoom();

    // Enemy handling
    bool hasEnemy() const;
    shared_ptr<Enemy> getEnemy();
    void removeEnemy();

    // Item handling
    bool hasItemFunc() const;
    shared_ptr<Item> getItem();
    void removeItem();

    // Room linking functions
    shared_ptr<Room> getLeftRoom() const;
    shared_ptr<Room> getRightRoom() const;
    void setLeftRoom(shared_ptr<Room> room);
    void setRightRoom(shared_ptr<Room> room);

    // Displays room information (for debugging)
    void displayRoomInfo() const;
};

#endif // ROOM_H
