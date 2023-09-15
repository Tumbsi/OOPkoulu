#ifndef CHEF_H
#define CHEF_H
#include <iostream>
#include <string>

using namespace std;

class Chef {
public:
    Chef(string name);
    ~Chef();
    void makeSalad();
    void makeSoup();
    string getName();

protected:
    string name;
};

#endif // CHEF_H
