#ifndef ITALIANCHEF_H
#define ITALIANCHEF_H
#include <iostream>
#include "chef.h"

class ItalianChef : public Chef {
public:
    ItalianChef(string name, int jauhot, int vesi);
    void makePasta();

private:
    int vesi;
    int jauhot;

};

#endif // ITALIANCHEF_H
