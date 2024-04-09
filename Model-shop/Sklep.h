#ifndef SKLEP_H
#define SKLEP_H

#include <string>
#include <vector>
#include "Zamowienia.h"
using namespace std;
class Sklep
{
public:
    void ZobaczProdukty();
    void DodajDoZamowienia(string &klient, const vector<int> &wybraneProdukty);
};

#endif // SKLEP_H