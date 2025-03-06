//
// Created by Admin on 2025-03-06.
//

#ifndef ROOM_H
#define ROOM_H

#include <iostream>
#include <memory> //För Pointers och Smart Pointers
#include <cstdlib> // För RNG
#include <ctime> //För Random Seed

using namespace std;
//Room Class for Procedurally Generation Rooms
class Room {
private:
    bool hasEnemy; //Determines if Room Contains a Monster
    bool hasItem; //Determines if Room Contains a Item
    shared_ptr<Room> leftRoom; //Pointer to Left Room Connection
    shared_ptr<Room> rightRoom; //Pointer to Right ROom Connection
    int roomID; //RoomID for later Debugging

public:
    //Constructor
    Room(int id);

    //Randomly Assigning Rooms Items or Monsters
    void generateRoom();

    //Getters
    bool containsEnemy() const;
    bool containsItem() const;
    shared_ptr<Room> getLeftRoom() const;
    shared_ptr<Room> getRightRoom() const;

    //Setters
    void setLeftRoom(shared_ptr<Room> room);
    void setRightRoom(shared_ptr<Room> room);

    //Displaying Room Information
    void displayRoomInfo() const;
};



#endif //ROOM_H
