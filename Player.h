//
// Created by Admin on 2025-03-05.
//

#ifndef PLAYER_H
#define PLAYER_H

#include "Character.h"
#include <vector>
#include <string>

using namespace std;


class Player : public Character {
    private:
        vector<string> Inventory; // Player Inventory Vector
    public:
        Player(string name, int hp, int strength); //Constructor
        Player();
        void addItem(string item); // Function for Adding Items
        void useItem(int index); //Function for Using Items

        void displayStats() const;
};



#endif //PLAYER_H
