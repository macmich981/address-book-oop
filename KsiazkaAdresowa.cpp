#include "KsiazkaAdresowa.h"

KsiazkaAdresowa::KsiazkaAdresowa(string nazwaPlikuZUzytkownikami) : uzytkownikMenedzer(nazwaPlikuZUzytkownikami) {
    uzytkownikMenedzer.wczytajUzytkownikowZPliku();
}

void KsiazkaAdresowa::rejestracjaUzytkownika() {
    uzytkownikMenedzer.rejestracjaUzytkownika();
}

void KsiazkaAdresowa::logowanieUzytkownika() {
    uzytkownikMenedzer.logowanieUzytkownika();
    uzytkownikMenedzer.pobierzAdresaciMenedzer().ustawIdZalogowanegoUzytkownika(uzytkownikMenedzer.pobierzIdZalogowanegoUzytkownika());
}

void KsiazkaAdresowa::zmianaHaslaZalogowanegoUzytkownika() {
    uzytkownikMenedzer.zmianaHaslaZalogowanegoUzytkownika();
}

void KsiazkaAdresowa::wylogowanieUzytkownika() {
    uzytkownikMenedzer.wylogowanieUzytkownika();
}

void KsiazkaAdresowa::wypiszWszystkichUzytkownikow() {
    uzytkownikMenedzer.wypiszWszystkichUzytkownikow();
}

void KsiazkaAdresowa::dodajAdresata() {
    uzytkownikMenedzer.pobierzAdresaciMenedzer().dodajAdresata();
}
