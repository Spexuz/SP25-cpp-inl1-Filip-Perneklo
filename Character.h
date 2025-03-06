//
// BASE CLASS FOR PLAYER AND ENEMY
//

#ifndef CHARACTER_H
#define CHARACTER_H

#include <string>

using namespace std;

class Character {
    protected:
        string name; //NAME OF PC/NPC
        int health; //Health (HealthPoints HP)
        int strength; //Strength (AttackPower AP)

public:
    Character(string name, int health, int strength); //Constructor for CharacterObject
    virtual ~Character(); //Virtual destructor (LOOK THIS UP)

    // Getters
    string getName() const;
    int getHealth() const;
    int getStrength() const;

    // Methods
    virtual void takeDamage(int damage); // Reduces HP based on Damage
    virtual void displayStats() const;
};



#endif //CHARACTER_H
