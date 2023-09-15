#include "chef.h"
#include "italianchef.h"
#include <iostream>
using namespace std;

int main() {
    Chef chef("Gordon");
    ItalianChef italianChef("Luigi", 250, 100);

    chef.makeSalad();
    chef.makeSoup();

    italianChef.makeSalad();
    italianChef.makePasta();

    return 0;
}
