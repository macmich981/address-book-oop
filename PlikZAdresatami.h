#ifndef PLIKZADRESATAMI_H
#define PLIKZADRESATAMI_H

#include <iostream>
#include <vector>
#include <fstream>
#include <cstdlib>
#include "Adresat.h"
#include "MetodyPomocnicze.h"

class PlikZAdresatami
{
    const string nazwaPlikuZAdresatami;
    bool czyPlikJestPusty();
    string zamienDaneAdresataNaLinieZDanymiOddzielonymiPionowymiKreskami(Adresat);
    int pobierzIdAdresataZDanychOddzielonychPionowymiKreskami(string);
    int pobierzIdUzytkownikaZDanychOddzielonychPionowymiKreskami(string);
    Adresat pobierzDaneAdresata(string);

public:
    PlikZAdresatami(string);
    void dopiszAdresataDoPliku(Adresat);
    int wczytajAdresatowZalogowanegoUzytkownikaZPliku(vector<Adresat>&, int);
};

#endif
