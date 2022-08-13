#ifndef KSIAZKAADRESOWA_H
#define KSIAZKAADRESOWA_H

#include <iostream>
#include "UzytkownikMenedzer.h"
#include "AdresaciMenedzer.h"

using namespace std;

class KsiazkaAdresowa {
    UzytkownikMenedzer uzytkownikMenedzer;
    AdresaciMenedzer *adresaciMenedzer;
    const string NAZWA_PLIKU_Z_ADRESATAMI;

public:
    KsiazkaAdresowa(string nazwaPlikuZUzytkownikami, string nazwaPlikuZAdresatami)
        : uzytkownikMenedzer(nazwaPlikuZUzytkownikami), NAZWA_PLIKU_Z_ADRESATAMI(nazwaPlikuZAdresatami) {
        adresaciMenedzer = NULL;
    }
    ~KsiazkaAdresowa() {
        delete adresaciMenedzer;
        adresaciMenedzer = NULL;
    }
    void rejestracjaUzytkownika();
    void logowanieUzytkownika();
    void zmianaHaslaZalogowanegoUzytkownika();
    void wylogowanieUzytkownika();
    void wypiszWszystkichUzytkownikow();
    bool czyUzytkownikJestZalogowany();
    void wyswietlWszystkichAdresatow();
    void dodajAdresata();
};

#endif
