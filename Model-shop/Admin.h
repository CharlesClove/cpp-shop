#ifndef _ADMIN_H
#define _ADMIN_H
using namespace std;
#include <string>
#include <vector>
#include <algorithm>
#include "Pomocnik.h"

class Admin
{
public:
    string login;
    string haslo;

    void UsunPomocnika(const std::string &login);
    void ZarejestrujPomocnik();
    void ZalogujAdmin();
    void WyswietlListePomocnikow();
    vector<Pomocnik> listaPomocnikow;
};

#endif //_ADMIN_H