//
// Created by Admin on 2025-03-05.
//

#include "Player.h"
#include "Character.h"
#include <iostream>

//Constructor that Calls Base Character Creator
Player::Player(string name, int hp, int strength)
    : Character(name, hp, strength) {}

//Adds an Item to Player Inventory
void Player::addItem(string item) {
    Inventory.push_back(item); //Adding item to Inventory through a Vecotr
    cout << item << " Added to Inventory!\n";
}

//Using an Item (Just Deletes itself for now)
void Player::useItem(int index) {
    if (index >= 0 && index < Inventory.size()) {
        cout << "Used " << Inventory[index] << ".\n"; //Using Item
        Inventory.erase(Inventory.begin() + index);
    } else
        cout << "Invalid Item Selection.\n"; //Item Fail Check
}
// Function for Displaying Stats and Inventory
void Player::displayStats() const {
    cout << "Inventory: \n"; //Displaying Current Inventory
    if (Inventory.empty()) { //Checks if Inventory is Empty
        cout << "Inventory Empty.\n";
    } else {
        for (const auto& item : Inventory) { //Const so it can only Read and not Modify the Player Class,
            cout << item << "  \n"; //Auto& so that it auto determines the correct Item and & to prevent it from copying, as well as streamlining the loop
        }
        cout << "\n";
    }
}
