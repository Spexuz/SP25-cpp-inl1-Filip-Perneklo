#include "Game.h"
#include "Room.h"
#include "Item.h"
#include <iostream>
#include <memory>
#include <cstdlib>
#include <ctime>

using namespace std;

// Constructor for initializing the game
Game::Game() {
    isRunning = true; // Game Starts and Sets Run State to True
    srand(time(0)); // Seeding the Random Generation through Machine Local Time

    // Creating the Starting Room and Generating Room Layout
    shared_ptr<Room> firstRoom = make_shared<Room>(1); // Assigns the First Room the ID of 1
    firstRoom->generateRoom(); // Generates the Layout
    rooms.push_back(firstRoom); // Pushes the Room to the First Spot of the Vector

    currentRoom = firstRoom;

    // Generating the Rest of the Map (19 Rooms)
    shared_ptr<Room> previousRoom = firstRoom; // Simple for Loop for Room Generation until 20 is hit
    for (int i = 2; i <= 20; i++) {
        shared_ptr<Room> newRoom = make_shared<Room>(i);
        newRoom->generateRoom(); // Runs each Generated room through the Function for assigning Items/Monsters
        rooms.push_back(newRoom); // Assigning Rooms to the Vector

        // Assigns Room their respective direction, aka Left or Right
        if (rand() % 2 == 0) {
            previousRoom->setLeftRoom(newRoom);
        } else {
            previousRoom->setRightRoom(newRoom);
        }

        previousRoom = newRoom; // Moves Forward in the Room Generation Chain
    }
}

// Main Game Loop
void Game::run() {
    cout << "Welcome to the Darkest Dungeon\n";
    cout << "Enter 'LEFT' or 'RIGHT' to Move, use 'PICKUP' to pick up items, use 'QUIT' to Exit the Game\n";

    while (isRunning) {
        currentRoom->displayRoomInfo(); // Shows Room Information

        // Checks the Room for Enemies and Triggers Combat when Present
        if (currentRoom->hasEnemy()) {
            cout << "An enemy appears!\n";
            combat(currentRoom->getEnemy());

            // If the player dies, stop the game
            if (!player.isAlive()) {
                cout << "You Died. Game over.\n";
                isRunning = false;
                return;
            }
        }

        // Player Movement and Input
        string choice;
        cout << "> ";
        cin >> choice;

        // Convert input to uppercase for consistency
        for (char &c : choice) {
            c = toupper(c);
        }

        if (choice == "QUIT") {
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
        } else if (choice == "PICKUP") {
            pickUpItem();
        } else {
            cout << "Please Use: 'LEFT', 'RIGHT', 'PICKUP', or 'QUIT'.\n";
            currentRoom->displayRoomInfo(); // Redisplay room info after invalid input
        }
    }
}

// Function to allow players to pick up items
void Game::pickUpItem() {
    if (currentRoom->hasItem()) {
        shared_ptr<Item> item = currentRoom->getItem();
        cout << "You picked up: " << item->getName() << "!" << endl;
        player.addItem(item->getName()); // assuming player has addItem() defined
        cout << "Item added to inventory!" << endl;
        currentRoom->removeItem();
    } else {
        cout << "There is nothing to pick up here." << endl;
    }
}

void Game::combat(std::shared_ptr<Enemy> enemy) {
    cout << enemy->getName() << " is Present in the Dungeon!\n";

    while (player.isAlive() && enemy->isAlive()) {
        cout << "Choose Action: ATTACK or RUN\n> ";
        string action;
        cin >> action;

        // Convert input to uppercase
        for (char &c : action) {
            c = toupper(c);
        }

        if (action == "ATTACK") {
            player.attack(*enemy);

            // Check if enemy is defeated before it attacks
            if (!enemy->isAlive()) {
                cout << "You defeated " << enemy->getName() << "!\n";
                currentRoom->removeEnemy();
                return;
            }

            // Enemy's turn
            enemy->attack(player);
            if (!player.isAlive()) {
                cout << "You have been defeated!\n";
                isRunning = false;
                return;
            }

        } else if (action == "RUN") {
            cout << "You got away safely!\n";
            return;
        } else {
            cout << "Invalid Input. Choose ATTACK or RUN.\n";
        }
    }
}

// Memory Cleanup
Game::~Game() {
    rooms.clear();
}
