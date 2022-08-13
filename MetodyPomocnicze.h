#ifndef METODYPOMOCNICZE_H
#define METODYPOMOCNICZE_H

#include <iostream>
#include <algorithm>
#include <conio.h>

using namespace std;

class MetodyPomocnicze {
public:
    static string konwerjsaIntNaString(int);
    static string pobierzLiczbe(string, int);
    static int konwersjaStringNaInt(string);
    static string wczytajLinie();
    static string zamienPierwszaLitereNaDuzaAPozostaleNaMale(string);
    static char pobierzZnak();
};

#endif
