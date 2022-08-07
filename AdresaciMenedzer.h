#ifndef ADRESACIMENEDZER_H
#define ADRESACIMENEDZER_H

#include <iostream>
#include <vector>
#include <algorithm>
#include "Adresat.h"
#include "PlikZAdresatami.h"

using namespace std;

class AdresaciMenedzer {
    int idOstatniegoAdresata;
    int idZalogowanegoUzytkownika;
    vector<Adresat> adresaci;
    PlikZAdresatami plikZAdresatami;

    Adresat podajDaneNowegoAdresata(int);
    string zamienPierwszaLitereNaDuzaAPozostaleNaMale(string);

public:
    AdresaciMenedzer(string);
    void dodajAdresata();
    void ustawIdZalogowanegoUzytkownika(int);
    void wczytajAdresatowZalogowanegoUzytkownikaZPliku();
    void wyswietlDaneAdresata(Adresat adresat);
    void wyswietlWszystkichAdresatow();
};

#endif
