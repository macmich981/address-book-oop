#include <iostream>

using namespace std;

class Uzytkownik {
    int id;
    string login;
    string haslo;

public:
    void ustawId(int);
    void ustawLogin(string);
    void ustawHaslo(string);

    int pobierzId();
    string pobierzLogin();
    string pobierzHaslo();
};
