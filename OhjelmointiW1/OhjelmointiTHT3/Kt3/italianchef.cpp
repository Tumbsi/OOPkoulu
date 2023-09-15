#include "italianchef.h"
#include <iostream>
using namespace std;

ItalianChef::ItalianChef(string name, int jauhot, int vesi) : Chef(name), jauhot(jauhot), vesi(vesi) {

}

void ItalianChef::makePasta() {
    cout << "Chef " << getName() << " makes pasta with special recipe" << endl;
    cout <<"Chef "<<getName() << "uses jauhot = "<< jauhot <<endl;
    cout <<"Chef "<<getName() << "uses vesi = "<< vesi <<endl;

}
