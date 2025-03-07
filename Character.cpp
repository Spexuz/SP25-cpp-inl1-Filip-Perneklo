//
// BASE CLASS FOR PLAYER AND ENEMY - PROVIDING FUNCTIONALITY
// MAIN GETTERS AND STATISTIC DISPLAY FUNCTIONS
//

#include "Character.h"
#include <iostream> //All my Homies hate C++
using namespace std; // But we love Namespaces

// Constructor - Initializes Character Attributes
Character::Character(string name, int health, int strength)
    : name(name), health(health), strength(strength) {}

// Virtual Destructor - Ensures Derived classes are Cleaned up if necessary
Character::~Character() {}

// Getters - Fixes Access to Private Attributes of the Character Class
string Character::getName() const {
    return name; // Gets the Current Name of the Target
}

int Character::getHealth() const {
    return health; // Gets the Current Health of the Target
}

bool Character::isAlive() const { //Checking is PC/NPC is Still ALive
    return health > 0; //Returns True if HP is above 0
}

int Character::getStrength() const {
    return strength; // Gets the Current Strength of the Target
}
//Applies Damage to the Targeted Character
void Character::takeDamage(int damage) {
    health -= damage;
    if (health < 0) {
        health = 0; // Prevents the Target from going into Negative HP Numbers
    }               // And sets the taget hp to 0 if they were to do it somehow
}

//Attacking another Character
void Character::attack(Character &target) {
    //cout << "[DEBUG] " << name << " is attacking " << target.getName() << "\n"; // Debug before attack
    cout << name << " attacks " << target.getName() << " for " << strength << " damage\n";

    target.takeDamage(strength);

    //cout << "[DEBUG] Attack finished\n"; // Debug after attack
}




// Getter for Displaying Character Stats
void Character::displayStats() const {
    cout << "Name: " << name << "\n";
    cout << "Health: " << health << "\n";
    cout << "Strength: " << strength << "\n";
}

