#include "Game.h"
#include <iostream>
using namespace std;
//GAME.CPP/H MAIN FILE FOR CORE GAME LOGIC INC. MAP AND ROOMS.


//Constructor - Startar Spelet
Game::Game() {
    isRunning = true; //Sätter SpelFlaggan till Running
}

//Destructor - Rensar Resources om det behöves
Game::~Game() {
    //PLACEHOLDER för Dynamisk Minneshantering
}

//Main Game-Loop - Håller igång spelet tills spelaren avslutar
void Game::run() {
    cout << "Welcome to the Adventure Game! \n";

        while (isRunning) {
            cout << "Type 'QUIT' to Exit the Game\n";

            //Hantera Spelarens Input
            string input;
            cout << "> ";
            getline (cin, input);

            //Kollar om Spelaren vill avsluta Spelet
            if (input == "QUIT") {
                isRunning = false;
            } else {
                cout << "Invalid Input\n";
            }
        }

    cout << "The Game has Ended, Thank you for Playing!";
}