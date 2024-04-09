#ifndef _KOMUNIKACJA_H
#define _KOMUNIKACJA_H
#include <iostream>
#include <string>
#include <fstream>
#include <filesystem>
#include <vector>
#include "Klient.h"
using namespace std;

class Komunikacja
{
public:
    
    static int liczba_wiadomosci;
    static int liczba_odpowiedzi;
    vector<Klient> listaklientow;
    void sprawdzUzytkownikow();
    void NapisaniePyt(string imie);
    void OdpKlientowi();
    void sprawdzSkrz(string imie);
};

#endif //_KOMUNIKACJA_H