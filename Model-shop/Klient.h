
#ifndef _KLIENT_H
#define _KLIENT_H

using namespace std;
#include<string>
#include "Zamowienia.h"
#include "Transakcja.h"
class Klient 
{
public: 
    string imie;
    int pin;
    

    void usunKonto(string imie);
    void ZarejestrujKlient();
    bool ZalogujKlient(string imie, string pin);
   
    
};

#endif //_KLIENT_H