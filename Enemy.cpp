#include "Enemy.h"
#include <iostream>

using namespace std;

// Constructor for the Enemy
Enemy::Enemy(string name, int hp, int strength)
    : Character(name, hp, strength) {}

//Destructor
Enemy::~Enemy() {}
