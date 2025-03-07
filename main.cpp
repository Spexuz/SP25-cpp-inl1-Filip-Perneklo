#include <iostream>
#include "Game.h"
#include "Character.h"

using namespace std;

// MAIN FILE FOR HANDLING GAME LOOP
int main() {

    Game game;  // Create the Game Object
    game.selectDifficulty();
    game.run(); // Start the Game Loop

    Character hero("Hero", 100, 20);
    Character enemy("Enemy", 50, 10);

    hero.displayStats();
    enemy.displayStats();

    cout << "\nBattle Start!\n";

    hero.attack(enemy);
    enemy.displayStats();

    if (!enemy.isAlive()) {
        cout << enemy.getName() << " has been defeated!\n";
    }

    return 0;
}