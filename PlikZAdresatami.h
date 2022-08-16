#ifndef PLIKZADRESATAMI_H
#define PLIKZADRESATAMI_H

#include <iostream>
#include <vector>
#include <fstream>
#include <cstdlib>
#include <cstring>
#include "Adresat.h"
#include "MetodyPomocnicze.h"
#include "PlikTekstowy.h"

class PlikZAdresatami : public PlikTekstowy {
    int idOstatniegoAdresata;

    string zamienDaneAdresataNaLinieZDanymiOddzielonymiPionowymiKreskami(Adresat);
    int pobierzIdAdresataZDanychOddzielonychPionowymiKreskami(string);
    int pobierzIdUzytkownikaZDanychOddzielonychPionowymiKreskami(string);
    Adresat pobierzDaneAdresata(string);

public:
    PlikZAdresatami(string nazwaPlikuZAdresatami) : PlikTekstowy(nazwaPlikuZAdresatami) {
        idOstatniegoAdresata = 0;
    };
    bool dopiszAdresataDoPliku(Adresat);
    vector<Adresat> wczytajAdresatowZalogowanegoUzytkownikaZPliku(int);
    int pobierzIdOstatniegoAdresata();
    void zapiszWszystkichAdresatowDoPliku(Adresat&, int);
};

#endif
