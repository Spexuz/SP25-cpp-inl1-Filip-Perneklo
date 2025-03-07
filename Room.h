#ifndef ROOM_H
#define ROOM_H

#include <iostream>
#include <memory>  // For smart pointers
#include <cstdlib> // For random number generation
#include <ctime>   // To seed randomness

#include "Enemy.h"  // Ensure Enemy class is included

using namespace std;

// Room Class for Procedural Generation
class Room {
private:
    bool hasItem;  // Determines if the room contains an item
    shared_ptr<Room> leftRoom;  // Pointer to Left Room
    shared_ptr<Room> rightRoom; // Pointer to Right Room
    shared_ptr<Enemy> enemy;    // Pointer to Enemy Object
    int roomID; // Room ID for debugging

public:
    // Constructor
    Room(int id);

    // Room Content Generation
    void generateRoom();

    // Enemy Handling
    bool hasEnemy() const;            // Checks if there is an enemy
    shared_ptr<Enemy> getEnemy();      // Returns enemy in the room
    void removeEnemy();                // Removes the enemy after defeat

    // Item Handling
    bool containsItem() const;         // Checks if the room has an item

    // Room Navigation
    shared_ptr<Room> getLeftRoom() const;
    shared_ptr<Room> getRightRoom() const;
    void setLeftRoom(shared_ptr<Room> room);
    void setRightRoom(shared_ptr<Room> room);

    // Display Information
    void displayRoomInfo() const;
};

#endif // ROOM_H
