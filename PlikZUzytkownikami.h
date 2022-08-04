#ifndef PLIKZUZYTKOWNIKAMI_H
#define PLIKZUZYTKOWNIKAMI_H

#include <iostream>
#include <vector>
#include <fstream>
#include <cstdlib>
#include "Uzytkownik.h"
#include "MetodyPomocnicze.h"

using namespace std;

class PlikZUzytkownikami {
    const string nazwaPlikuZUzytkownikami;

    bool czyPlikJestPusty();
    string zamienDaneUzytkownikaNaLinieZDanymiOddzielonaPionowymiKreskami(Uzytkownik);

public:
    PlikZUzytkownikami(string);
    void dopiszUzytkownikaDoPliku(Uzytkownik);
    vector<Uzytkownik> wczytajUzytkownikowZPliku();
    Uzytkownik pobierzDaneUzytkownika(string);
};

#endif