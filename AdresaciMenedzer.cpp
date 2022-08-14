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

void AdresaciMenedzer::wyswietlAdresatowOTakimSamymImieniu() {
    string imie = "";
    bool znalezionoAdresata = false;

    system("cls");
    cout << ">>> WYSZUKIWANIE OSOBY PO IMIENIU <<<" << endl << endl;
    cout << "Podaj imie osoby jaka mamy wyszukac: ";
    imie = MetodyPomocnicze::wczytajLinie();

    for (Adresat adresat : adresaci) {
        if (adresat.pobierzImie() == imie) {
            wyswietlDaneAdresata(adresat);
            znalezionoAdresata = true;
        }
    }
    if (!znalezionoAdresata) {
        cout << "Nie znaleziono osob o takim imieniu!" << endl;
    }
    system("pause");
}

void AdresaciMenedzer::wyswietlAdresatowOTakimSamymNazwisku() {
    string nazwisko = "";
    bool znalezionoAdresata = false;

    system("cls");
    cout << ">>> WYSZUKIWANIE OSOBY PO NAZWISKU <<<" << endl << endl;
    cout << "Podaj imie osoby jaka mamy wyszukac: ";
    nazwisko = MetodyPomocnicze::wczytajLinie();

    for (Adresat adresat : adresaci) {
        if (adresat.pobierzNazwisko() == nazwisko) {
            wyswietlDaneAdresata(adresat);
            znalezionoAdresata = true;
        }
    }
    if (!znalezionoAdresata) {
        cout << "Nie znaleziono osob o takim imieniu!" << endl;
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
                plikZAdresatami.zapiszWszystkichAdresatowDoPliku(adresaci);
                cout << "Szukana osoba zostala usunieta" << endl;
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

char AdresaciMenedzer::wybierzOpcjeZMenuEdycja() {
    char wybor;

    cout << endl << "   >>> MENU  EDYCJA <<<" << endl;
    cout << "---------------------------" << endl;
    cout << "Ktore dane zaktualizowac: " << endl;
    cout << "1 - Imie" << endl;
    cout << "2 - Nazwisko" << endl;
    cout << "3 - Numer telefonu" << endl;
    cout << "4 - Email" << endl;
    cout << "5 - Adres" << endl;
    cout << "6 - Powrot " << endl;
    cout << endl << "Twoj wybor: ";
    wybor = MetodyPomocnicze::pobierzZnak();

    return wybor;
}

void AdresaciMenedzer::edytujWybranegoAdresata() {
    system("cls");
    cout << ">>> EDYTUJ DANE WYBRANEJ OSOBY <<<" << endl << endl;
    cout << "Podaj numer ID osoby, ktorej dane chcesz edytowac: ";
    int idEdytowanegoAdresata = MetodyPomocnicze::wczytajLiczbe();
    bool znalezionoAdresata = false;

    for (Adresat &adresat : adresaci) {
        if (adresat.pobierzId() == idEdytowanegoAdresata) {
            znalezionoAdresata = true;
            char wybor = wybierzOpcjeZMenuEdycja();

            switch (wybor) {
            case '1': {
                cout << "Podaj nowe imie: ";
                string imie = MetodyPomocnicze::wczytajLinie();
                imie = MetodyPomocnicze::zamienPierwszaLitereNaDuzaAPozostaleNaMale(imie);
                adresat.ustawImie(imie);
                break;
            }
            case '2': {
                cout << "Podaj nowe nazwisko: ";
                string nazwisko = MetodyPomocnicze::wczytajLinie();
                nazwisko = MetodyPomocnicze::zamienPierwszaLitereNaDuzaAPozostaleNaMale(nazwisko);
                adresat.ustawNazwisko(nazwisko);
                break;
            }
            case '3': {
                cout << "Podaj nowy numer telefonu: ";
                string numerTelefonu = MetodyPomocnicze::wczytajLinie();
                adresat.ustawNumerTelefonu(numerTelefonu);
                break;
            }
            case '4': {
                cout << "Podaj nowy email: ";
                string email = MetodyPomocnicze::wczytajLinie();
                adresat.ustawEmail(email);
                break;
            }
            case '5': {
                cout << "Podaj adres: ";
                string adres = MetodyPomocnicze::wczytajLinie();
                adresat.ustawAdres(adres);
                break;
            }
            case '6':
                return;
            default:
                cout << endl << "Nie ma takiej opcji w menu! Powrot do menu uzytkownika." << endl << endl;
                system("pause");
                return;
            }
        }
    }
    if (znalezionoAdresata) {
        plikZAdresatami.zapiszWszystkichAdresatowDoPliku(adresaci);
        cout << "Dane adresata zostaly zaktualizowane" << endl;
        system("pause");
        return;
    }
    cout << "Adresat o podanym ID nie istnieje." << endl;
    system("pause");
}
