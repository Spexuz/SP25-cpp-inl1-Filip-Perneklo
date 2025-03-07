#ifndef GAME_H
#define GAME_H

#include <vector> // Vector for Storing all rooms
#include <memory>
#include "Room.h"
#include "Player.h"
#include "Enemy.h"

using namespace std;

class Game {
private:
    bool isRunning;
    vector<shared_ptr<Room>> rooms; // Room Placeholder
    shared_ptr<Room> startingRoom; // Pointer to Define First Room
    shared_ptr<Room> currentRoom; // Pointer to the Player's Current Location
    Player player; // Player Object

public:
    Game(); // Constructor
    ~Game(); // Destructor

    void run(); // Running the Game Loop
    void initializeGame(); // Starts the Game and Generates all Rooms
    void generateRooms(int numRooms); // Generates Procedural Rooms
    void gameLoop(); // Game Loop for Handling Player Movement and Interactions
    void moveToRoom(char direction); // Moves the Player Based on Choice (Left or Right)
    void displayIntro() const; // Runs Game Introduction
    void combat(shared_ptr<Enemy> enemy); // Declare combat system
    void pickupItem();
};

#endif // GAME_H