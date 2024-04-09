#include <iostream>
#include <string>
#include <fstream>
#include <cstdlib>
#include "Sklep.h"
#include <sstream>
#include <unistd.h>
#include <vector>
#include <algorithm>

using namespace std;
struct Produkt
{
    int id;
    string nazwa;
    double cena;
};

vector<Produkt> produkty = {
    {1, "Monitor", 700.0},
    {2, "Komputer", 1700.0},
    {3, "Klawiatura", 200.0},
    {4, "Mysz", 100.0},
};

void Sklep::DodajDoZamowienia(string &klient, const vector<int> &wybraneProdukty)
{
    ofstream plik("../Model/doTrans/" + klient + "_zamowienia.txt", ios::trunc); // Open file for appending

    if (plik.is_open())
    {
        cout << "Plik otwarto" << endl;
        
        for (int id : wybraneProdukty)
        {
            plik << id << " ";
        }
        plik << "\n";
        plik.close();
    }
    else
    {
        cout << "Nie udalo sie otworzyc pliku." << endl;
    }
}

void Sklep::ZobaczProdukty(){
    for (const auto &produkt : produkty)
    {
        std::cout << "ID: " << produkt.id << ", Nazwa: " << produkt.nazwa << ", Cena: " << produkt.cena << std::endl;
    }
}



