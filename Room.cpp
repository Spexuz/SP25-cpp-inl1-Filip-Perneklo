//
// Created by Admin on 2025-03-06.
//

#include "Room.h"

// Consturctor that Initializes Rooms with an ID and Random Contents
Room::Room(int id) : roomID(id), hasEnemy(false), hasItem(false) {
    generateRoom(); // Assigns Enemys/Items Randomly
}

//Function for Randomly Determining Room Conents
void Room::generateRoom() {
    srand(time(0)); //Random Seed
    hasEnemy = rand() % 2 == 0; // 50% Chance to Contain an Enemy
    hasItem = rand() % 5 == 0; // 20% Chance to Contain an Item
}

//Getter Functions
bool Room::containsEnemy() const { return hasEnemy; } //Checks and Returns if the Room contains an Enemy
bool Room::containsItem() const { return hasItem; } //Checks and Returns if the Room Contains an Item
shared_ptr<Room> Room::getLeftRoom() { return leftRoom; } //Checks and Returns the LeftRoom
shared_ptr<Room> Room::getRightRoom() { return rightRoom; } //Checks and Returns the Right Room

//Function for Linking the Rooms Together
void Room::setLeftRoom(shared_ptr<Room> room) { leftRoom = room; }
void Room::setRightRoom(shared_ptr<Room> room) { rightRoom = room; }

//Room Information for Debugging and Testing
void Room::displayRoomInfo() const {
    cout <<"Room ID: " << roomID << "\n"; //Verify Room Number
    cout <<"Enemy: " << (hasEnemy ? "TRUE" : "FALSE") << "\n"; //EnemyChecker
    cout <<"Item: " << (hasItem ? "TRUE" : "FALSE") << "\n"; //Item Checker
}




