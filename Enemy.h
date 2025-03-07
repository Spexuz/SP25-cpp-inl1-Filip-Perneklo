#ifndef ENEMY_H
#define ENEMY_H

#include "Character.h"

class Enemy : public Character {
public:
    Enemy(string name, int hp, int strength); // Constructor
    virtual ~Enemy(); // ✅ Declare Virtual Destructor
};

#endif // ENEMY_H
