#ifndef TRANSAKCJA_H
#define TRANSAKCJA_H

#include <string>
#include <vector>
#include "Zamowienia.h"
using namespace std;
class Transakcja: public Zamowienie
{
public:
   int idTran;
   string status;
   string getDate();
   void UtworzTransakcje(string imie);
};

#endif // TRANSAKCJA_H