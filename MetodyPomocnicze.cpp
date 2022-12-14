#include "MetodyPomocnicze.h"
#include <sstream>

string MetodyPomocnicze::konwerjsaIntNaString(int liczba) {
    ostringstream ss;
    ss << liczba;
    string str = ss.str();
    return str;
}

string MetodyPomocnicze::pobierzLiczbe(string tekst, int pozycjaZnaku) {
    string liczba = "";
    while(isdigit(tekst[pozycjaZnaku]) == true) {
        liczba += tekst[pozycjaZnaku];
        pozycjaZnaku ++;
    }
    return liczba;
}

int MetodyPomocnicze::konwersjaStringNaInt(string liczba) {
    int liczbaInt;
    istringstream iss(liczba);
    iss >> liczbaInt;

    return liczbaInt;
}

string MetodyPomocnicze::wczytajLinie() {
    string wejscie = "";

    getline(cin, wejscie);
    return wejscie;
}

string MetodyPomocnicze::zamienPierwszaLitereNaDuzaAPozostaleNaMale(string tekst) {
    if (!tekst.empty()) {
        transform(tekst.begin(), tekst.end(), tekst.begin(), ::tolower);
        tekst[0] = toupper(tekst[0]);
    }
    return tekst;
}

char MetodyPomocnicze::pobierzZnak() {
    char znak;

    znak = getch();
    cout << znak << endl;
    return znak;
}

int MetodyPomocnicze::wczytajLiczbe() {
    int liczba;

    while (!(cin >> liczba)) {
        cout << "Niepoprawne dane. Sprobuj jeszcze raz: ";
        cin.clear();
        cin.ignore(1000, '\n');
    }
    cin.get();
    return liczba;
}
