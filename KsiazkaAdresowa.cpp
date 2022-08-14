#include "KsiazkaAdresowa.h"

void KsiazkaAdresowa::rejestracjaUzytkownika() {
    uzytkownikMenedzer.rejestracjaUzytkownika();
}

void KsiazkaAdresowa::logowanieUzytkownika() {
    uzytkownikMenedzer.logowanieUzytkownika();
    if (uzytkownikMenedzer.czyUzytkownikJestZalogowany()) {
        adresaciMenedzer = new AdresaciMenedzer(NAZWA_PLIKU_Z_ADRESATAMI, uzytkownikMenedzer.pobierzIdZalogowanegoUzytkownika());
    }
}

void KsiazkaAdresowa::zmianaHaslaZalogowanegoUzytkownika() {
    uzytkownikMenedzer.zmianaHaslaZalogowanegoUzytkownika();
}

void KsiazkaAdresowa::wylogowanieUzytkownika() {
    uzytkownikMenedzer.wylogowanieUzytkownika();
    delete adresaciMenedzer;
    adresaciMenedzer = NULL;
}

void KsiazkaAdresowa::wypiszWszystkichUzytkownikow() {
    uzytkownikMenedzer.wypiszWszystkichUzytkownikow();
}

bool KsiazkaAdresowa::czyUzytkownikJestZalogowany() {
    return uzytkownikMenedzer.czyUzytkownikJestZalogowany();
}

void KsiazkaAdresowa::wyswietlWszystkichAdresatow() {
    adresaciMenedzer->wyswietlWszystkichAdresatow();
}

void KsiazkaAdresowa::dodajAdresata() {
    if (uzytkownikMenedzer.czyUzytkownikJestZalogowany()) {
        adresaciMenedzer->dodajAdresata();
    } else {
        cout << "Aby dodac adresata nalezy najpierw sie zalogowac" << endl;
        system("pause");
    }
}

void KsiazkaAdresowa::usunAdresata() {
    adresaciMenedzer->usunAdresata();
}

void KsiazkaAdresowa::edytujAdresata() {
    adresaciMenedzer->edytujWybranegoAdresata();
}
