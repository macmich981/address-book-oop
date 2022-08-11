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
    const string NAZWA_PLIKU_Z_ADRESATAMI;
    int idOstatniegoAdresata;

    bool czyPlikJestPusty();
    string zamienDaneAdresataNaLinieZDanymiOddzielonymiPionowymiKreskami(Adresat);
    int pobierzIdAdresataZDanychOddzielonychPionowymiKreskami(string);
    int pobierzIdUzytkownikaZDanychOddzielonychPionowymiKreskami(string);
    Adresat pobierzDaneAdresata(string);

public:
    PlikZAdresatami(string nazwaPlikuZAdresatami) : NAZWA_PLIKU_Z_ADRESATAMI(nazwaPlikuZAdresatami) {
        idOstatniegoAdresata = 0;
    };
    bool dopiszAdresataDoPliku(Adresat);
    vector<Adresat> wczytajAdresatowZalogowanegoUzytkownikaZPliku(int);
    int pobierzIdOstatniegoAdresata();
};

#endif
