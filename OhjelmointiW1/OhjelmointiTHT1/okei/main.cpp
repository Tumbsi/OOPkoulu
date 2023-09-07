#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

int game(int maxnum) {
    srand(static_cast<unsigned int>(time(0)));

    int arvottuLuku = rand() % maxnum + 1;

    int pelaajanArvaus;
    int arvaustenMaara = 0;

    cout << "Tervetuloa arvauspeliin! Arvaa luku valilta 1-" << maxnum << "." << endl;

    while (true) {
        cout << "Syota arvauksesi: ";
        cin >> pelaajanArvaus;
        arvaustenMaara++;

        if (pelaajanArvaus < arvottuLuku) {
            cout << "Luku on suurempi." << endl;
        } else if (pelaajanArvaus > arvottuLuku) {
            cout << "Luku on pienempi." << endl;
        } else {
            cout << "Oikea vastaus! Arvasit oikein. Numero oli: " << arvottuLuku << endl;
            break;
        }
    }

    return arvaustenMaara;
}

int main() {
    int korkeinLuku = 40;

    int arvaustenMaara = game(korkeinLuku);

    cout << "Arvausten maara: " << arvaustenMaara << endl;

    return 0;
}
