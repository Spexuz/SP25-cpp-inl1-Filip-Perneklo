#include "Game.h"
#include "Room.h"
#include <iostream>
#include <memory>
#include <cstdlib>
#include <ctime>

using namespace std;

//Constructor for initializing the game
Game::Game() {
    isRunning = true; //Game Starts and Sets Run State to True
    srand(time(0)); //Seeding the Random Generation through MLT (Machine Local Time)

    //Creating the Starting Room and Generating Room Layout
    shared_ptr<Room> firstRoom = make_shared<Room>(1); //Assigns the First Room the ID of 1
    firstRoom->generateRoom(); //Generates the Layout
    rooms.push_back(firstRoom); //Pushes the Room to the First Spot of the Vector

    currentRoom = firstRoom;

    //Generating the Rest of the Map (19 Rooms)
    shared_ptr<Room> previousRoom = firstRoom; //Simple for Loop for Room Generation until 20 is hit
    for (int i = 2; i <= 20; i++) {
        shared_ptr<Room> newRoom = make_shared<Room>(i);
        newRoom->generateRoom(); //Runs each Generated room through the Function for assigning Items/Monsters
        rooms.push_back(newRoom); //Assigning Rooms to the Vector

        //Assigns Room thier respective direction, aka Left or Right
        if (rand() % 2 == 0) {
            previousRoom->setLeftRoom(newRoom);
        } else {
            previousRoom->setRightRoom(newRoom);
        }

        previousRoom = newRoom; // Moves Forward in the Room Gen Chain
    }
}

//Main Game Loop
void Game::run() {
    cout << "Welcome to the Darkest Dungeon\n";
    cout << "Enter 'LEFT' or 'RIGHT' to Move, use 'QUIT' to Exit the Game\n";

    while (isRunning) {
        currentRoom->displayRoomInfo(); //Shows Room Information

        //Player input
        string choice;
        cout << "> ";
        cin >> choice;

        if (choice == "QUIT") { //Huge If Statement to Handle Player Input and Handling Invalid Inputs.
            isRunning = false;
            cout << "Exiting game..." << endl;
        } else if (choice == "LEFT") {
            if (currentRoom->getLeftRoom()) {
                currentRoom = currentRoom->getLeftRoom();
            } else {
                cout << "Hmm.. There does not seem to be a Door Here.\n";
            }
        } else if (choice == "RIGHT") {
            if (currentRoom->getRightRoom()) {
                currentRoom = currentRoom->getRightRoom();
            } else {
                cout << "Hmm.. There does not seem to be a Door Here\n";
            }
        } else {
            cout << "Please Use: 'LEFT', 'RIGHT', or 'QUIT'.\n";
        }
    }
}

//Memory Cleanup
Game::~Game() {
    rooms.clear();
}