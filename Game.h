//
//GAME.CPP/H MAIN FILE FOR CORE GAME LOGIC INC. MAP AND ROOMS.
//

#ifndef GAME_H
#define GAME_H

#include <iostream>
using namespace std;

class Game {
    public:
        Game(); //Constructor för att Initiera Spelet
        ~Game(); //Destructor för att Rensa upp om det behövs?

    void run(); // Spelets Huvud Loop

    private:
        bool isRunning; //Kontrollera om Spelet körs
};

#endif //GAME_H
