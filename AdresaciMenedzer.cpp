#include "AdresaciMenedzer.h"

AdresaciMenedzer::AdresaciMenedzer(string nazwaPlikuZAdresatami) : plikZAdresatami(nazwaPlikuZAdresatami) {

}

string AdresaciMenedzer::zamienPierwszaLitereNaDuzaAPozostaleNaMale(string tekst) {
    if (!tekst.empty()) {
        transform(tekst.begin(), tekst.end(), tekst.begin(), ::tolower);
        tekst[0] = toupper(tekst[0]);
    }
    return tekst;
}

Adresat AdresaciMenedzer::podajDaneNowegoAdresata(int idZalogowanegoUzytkownika) {
    Adresat adresat;

    adresat.ustawId(++idOstatniegoAdresata);
    adresat.ustawIdUzytkownika(idZalogowanegoUzytkownika);

    cout << "Podaj imie: ";
    string imie;
    getline(cin, imie);
    adresat.ustawImie(zamienPierwszaLitereNaDuzaAPozostaleNaMale(imie));

    cout << "Podaj nazwisko: ";
    string nazwisko;
    getline(cin, nazwisko);
    adresat.ustawNazwisko(zamienPierwszaLitereNaDuzaAPozostaleNaMale(nazwisko));

    cout << "Podaj numer telefonu: ";
    string numerTelefonu;
    getline(cin, numerTelefonu);
    adresat.ustawNumerTelefonu(numerTelefonu);

    cout << "Podaj email: ";
    string email;
    getline(cin, email);
    adresat.ustawEmail(email);

    cout << "Podaj adres: ";
    string adres;
    getline(cin, adres);
    adresat.ustawAdres(adres);

    return adresat;
}

void AdresaciMenedzer::dodajAdresata() {
    Adresat adresat;

    system("cls");
    cout << " >>> DODAWANIE NOWEGO ADRESATA <<<" << endl << endl;
    adresat = podajDaneNowegoAdresata(idZalogowanegoUzytkownika);

    adresaci.push_back(adresat);
    plikZAdresatami.dopiszAdresataDoPliku(adresat);
}

void AdresaciMenedzer::ustawIdZalogowanegoUzytkownika(int id) {
    idZalogowanegoUzytkownika = id;
}

void AdresaciMenedzer::wczytajAdresatowZalogowanegoUzytkownikaZPliku() {
    idOstatniegoAdresata = plikZAdresatami.wczytajAdresatowZalogowanegoUzytkownikaZPliku(adresaci, idZalogowanegoUzytkownika);
}
