#include <iostream>
#include <string>
#include <fstream>
#include <cstdlib>
#include <sstream>
#include <unistd.h>
#include <vector>
#include <algorithm>
#include "Klient.h"
#include "Zamowienia.h"
#include <map>
using namespace std;
map<int, pair<string, double>> itemMap;
double suma = 0;
int Zamowienie::potwierdzZamowienie(){
    
    cout << " Czy potwierdzasz zamowienie? (1 = Tak, 2 = Nie)" << endl;

    int choice;
    cin >> choice;

   
    while (choice != 1 && choice != 2)
    {
        cout << "Zly wybor, wpisz 1 lub 2." << endl;
        cin >> choice;
    }

    return choice;
}


void Zamowienie::wyswietlZamowienieKlient(string imie)
{
    string path = "../Model/doTrans/" + imie + "_zamowienia.txt";
    ifstream file(path);

    if (!file.is_open())
    {
        cout << "blad otwarcia pliku zamowienia " << path << endl;
        return;
    } else
    {
        cout << "Otwarto plik poprawnie "<< endl;
    }

    int id;
    while (file >> id)
    {
        if (id == 1)
        {
            itemMap[id] = make_pair("Monitor", 700.0);
            suma += 700;
        }
        else if (id == 2)
        {
            itemMap[id] = make_pair("Komputer", 1700.0);
            suma += 1700;
        }
        else if (id == 3)
        {
            itemMap[id] = make_pair("Klawiatura", 200.0);
            suma += 200;
        }
        else if (id == 4)
        {
            itemMap[id] = make_pair("Mysz", 100.0);
            suma += 100;
        }
    }

    // Close the file
    file.close();

    // Print the items and their prices
    for (auto item : itemMap)
    {
        cout << "Item ID: " << item.first;
        cout << "  Item name: " << item.second.first;
        cout << "  Price: " << item.second.second << endl;
    }
    cout << "TotalPrice: " << suma;
}