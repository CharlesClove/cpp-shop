#ifndef ZAMOWIENIE_H
#define ZAMOWIENIE_H

#include <string>
#include <vector>

using namespace std;
class Zamowienie
{
public:
    double suma;
    int potwierdzZamowienie();
    void wyswietlZamowienieKlient(string imie);

    
};

#endif // ZAMOWIENIE_H