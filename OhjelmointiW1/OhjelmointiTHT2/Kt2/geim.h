#ifndef GEIM_H
#define GEIM_H

class Geim {
private:
    int maxNumber;
    int playerGuess;
    int randomNumber;
    int numOfGuesses;

public:
    Geim(int max);
    ~Geim();
    void play();

private:
    void printGameResult();
};

#endif
