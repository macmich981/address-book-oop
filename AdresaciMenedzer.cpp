#include "AdresaciMenedzer.h"

Adresat AdresaciMenedzer::podajDaneNowegoAdresata() {
    Adresat adresat;
    string imie, nazwisko, numerTelefonu, email, adres;

    adresat.ustawId(plikZAdresatami.pobierzIdOstatniegoAdresata() + 1);
    adresat.ustawIdUzytkownika(ID_ZALOGOWANEGO_UZYTKOWNIKA);

    cout << "Podaj imie: ";
    imie = MetodyPomocnicze::wczytajLinie();
    imie = MetodyPomocnicze::zamienPierwszaLitereNaDuzaAPozostaleNaMale(imie);

    cout << "Podaj nazwisko: ";
    nazwisko = MetodyPomocnicze::wczytajLinie();
    nazwisko = MetodyPomocnicze::zamienPierwszaLitereNaDuzaAPozostaleNaMale(nazwisko);

    cout << "Podaj numer telefonu: ";
    numerTelefonu = MetodyPomocnicze::wczytajLinie();

    cout << "Podaj email: ";
    email = MetodyPomocnicze::wczytajLinie();

    cout << "Podaj adres: ";
    adres = MetodyPomocnicze::wczytajLinie();

    adresat.ustawImie(imie);
    adresat.ustawNazwisko(nazwisko);
    adresat.ustawNumerTelefonu(numerTelefonu);
    adresat.ustawEmail(email);
    adresat.ustawAdres(adres);

    return adresat;
}

void AdresaciMenedzer::dodajAdresata() {
    Adresat adresat;

    system("cls");
    cout << " >>> DODAWANIE NOWEGO ADRESATA <<<" << endl << endl;
    adresat = podajDaneNowegoAdresata();

    adresaci.push_back(adresat);
    if (plikZAdresatami.dopiszAdresataDoPliku(adresat)) {
        cout << "Nowy adresat zostal dodany" << endl;
    } else {
        cout << "Blad. Nie udalo sie dodac nowego adresata do pliku" << endl;
    }
    system("pause");
}

void AdresaciMenedzer::wyswietlDaneAdresata(Adresat adresat) {
    cout << endl << "Id:                 " << adresat.pobierzId() << endl;
    cout << "Imie:               " << adresat.pobierzImie() << endl;
    cout << "Nazwisko:           " << adresat.pobierzNazwisko() << endl;
    cout << "Numer telefonu:     " << adresat.pobierzNumerTelefonu() << endl;
    cout << "Email:              " << adresat.pobierzEmail() << endl;
    cout << "Adres:              " << adresat.pobierzAdres() << endl;
}

void AdresaciMenedzer::wyswietlWszystkichAdresatow() {
    system("cls");
    if (!adresaci.empty()) {
        cout << "             >>> ADRESACI <<<" << endl;
        cout << "-----------------------------------------------" << endl;
        for (Adresat adresat : adresaci) {
            wyswietlDaneAdresata(adresat);
        }
        cout << endl;
    } else {
        cout << endl << "Ksiazka adresowa jest pusta." << endl << endl;
    }
    system("pause");
}

void AdresaciMenedzer::usunAdresata() {
    system("cls");
    cout << ">>> USUWANIE WYBRANEJ OSOBY <<<" << endl << endl;
    cout << "Podaj numer ID osoby, ktora chcesz usunac: ";
    int idUsuwanegoAdresata = MetodyPomocnicze::wczytajLiczbe();

    for (vector <Adresat>::iterator itr = adresaci.begin(); itr != adresaci.end(); itr++) {
        if (itr->pobierzId() == idUsuwanegoAdresata) {
            cout << "Potwierdz naciskajac klawisz 't': ";
            char znak;
            znak = MetodyPomocnicze::pobierzZnak();
            if (znak == 't') {
                adresaci.erase(itr);
                cout << "Szukana osoba zostala usunieta" << endl;
                plikZAdresatami.usunWybranegoAdresataZPliku(idUsuwanegoAdresata);
                system("pause");
                return;
            } else {
                cout << "Anulowano usuwanie!" << endl;
                system("pause");
                return;
            }
        }
    }
    cout << "Nie znaleziono adresata o takim ID" << endl;
    system("pause");
}
