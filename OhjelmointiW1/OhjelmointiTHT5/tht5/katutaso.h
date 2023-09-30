// katutaso.h

#ifndef KATUTASO_H
#define KATUTASO_H

#include <iostream>
using namespace std;

#include "kerros.h"

class Katutaso : public Kerros
{
public:
    Katutaso();
    asunto* as1;
    asunto* as2;
    virtual void maaritaAsunnot(void) override;
    double laskeKulutus(double);
};

#endif // KATUTASO_H
