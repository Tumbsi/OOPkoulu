// kerrostalo.cpp

#include "kerrostalo.h"

Kerrostalo::Kerrostalo()
{
    cout << "Kerrostalo luotu" << endl;
    eka = new Katutaso;
    toka = new Kerros;
    kolmas = new Kerros;
    cout << "Maaritellaan koko kerrostalon kaikki asunnot" << endl;


    eka->maaritaAsunnot();
    toka->maaritaAsunnot();
    kolmas->maaritaAsunnot();
}


double Kerrostalo::laskeKulutus(double hinta)
{
    double katutasonKulutus = eka->laskeKulutus(hinta);
    double kerrostenKulutus = toka->laskeKulutus(hinta) + kolmas->laskeKulutus(hinta);
    return katutasonKulutus + kerrostenKulutus;
}
