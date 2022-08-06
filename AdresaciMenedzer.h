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
    vector<Adresat> adresaci;
    PlikZAdresatami plikZAdresatami;

    Adresat podajDaneNowegoAdresata(int);
    string zamienPierwszaLitereNaDuzaAPozostaleNaMale(string);

public:
    AdresaciMenedzer(string);
    void dodajAdresata(int);
};

#endif
