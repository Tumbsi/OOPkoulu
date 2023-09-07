#include "geim.h"
#include <iostream>
#include <cstdlib>
#include <ctime>

Geim::Geim(int max) : maxNumber(max), numOfGuesses(0) {
    srand(static_cast<unsigned>(time(nullptr)));
    randomNumber = rand() % maxNumber + 1;
    std::cout<< "GAME CONSTRUCOTR: object initialized with "<<randomNumber<<" as maximum value.\n";

    std::cout << "Give your guess between 1 and " << maxNumber << ".\n";
}

Geim::~Geim() {
    std::cout << "GAME DESTRUCTOR: object cleared from stack memory ";
}

void Geim::play() {
    while (true) {
        std::cout << "Enter your guess: ";
        std::cin >> playerGuess;
        numOfGuesses++;

        if (playerGuess == randomNumber) {
            std::cout << "Congratulations! You guessed the correct number.\n";
            printGameResult();
            break;
        } else if (playerGuess < randomNumber) {
            std::cout << "Too low. Try again.\n";
        } else {
            std::cout << "Too high. Try again.\n";
        }
    }
}

void Geim::printGameResult() {
    std::cout << "You guessed the right number and it was = " << randomNumber << ". It took you " << numOfGuesses << " guesses.\n";
}
