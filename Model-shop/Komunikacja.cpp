#include <iostream>
#include <string>
#include <fstream>
#include <filesystem>
#include "Komunikacja.h"
#include <vector>
#include <unistd.h>
using namespace std;

void Komunikacja::sprawdzUzytkownikow()   
{
    listaklientow.clear(); 

    std::ifstream file("danePomocnik.txt");
    if (file.is_open())
    {
        Klient klient;
        while (file >> klient.imie)
        {
            listaklientow.push_back(klient);
        }
        file.close();

        std::cout << "Lista Klientow:" << std::endl;
        for (const auto &p : listaklientow)
        {
            std::cout << p.imie << std::endl;
        }
    }
    else
    {
        std::cout << "Blad otwarcia pliku." << std::endl;
  
    }
}

void Komunikacja::NapisaniePyt(string imie){

    // Pobierz wiadomość od klienta
    int liczba_wiadomosci;
    string wiadomosc;
    cout << "Witam, wpisz swoją wiadomość: ";
    getline(cin, wiadomosc);

    // Utwórz folder dla klienta
    string folder = "..\\Model\\Wiadomosci\\" + imie;
    if (!filesystem::is_directory(folder))
    {
        filesystem::create_directory(folder);
    }

    // Utwórz plik z wiadomością
    string plik = folder + "\\" + imie + "_wiadomosc_" + to_string(liczba_wiadomosci++) + ".txt";
    ofstream out(plik);
    out << wiadomosc;
    cout<<"Wiadomosc wyslana"<< endl;
    sleep(1);
    out.close();
}

void Komunikacja::OdpKlientowi(){


    // Utwórz wiadomość
    int liczba_odpowiedzi;
    string imie;
    cout << "Wybierz uzytkownika ktorego chcesz sprawdzic: ";
    sprawdzUzytkownikow();
    getline(cin,imie);

    // Wejdź do folderu klienta
    string folder = "..\\Model\\Wiadomosci\\" + imie;
    filesystem::current_path(folder);

    // Wyświetl listę wiadomości
    vector<string> wiadomosci;
    for (const auto &plik : filesystem::directory_iterator(folder))
    {
        if (plik.is_regular_file())
        {
            wiadomosci.push_back(plik.path().filename().string());
        }
    }

    // Wybierz wiadomość
    int wybor;
    do
    {
        cout << "Wybierz wiadomosc: ";
        for (int i = 0; i < wiadomosci.size(); i++)
        {
            cout << i + 1 << ". " << wiadomosci[i] << endl;
        }
        cin >> wybor;
    } while (wybor < 1 || wybor > wiadomosci.size());

    // Wyświetl wiadomość
    cout << endl
         << "Wiadomosc: " << endl;
    ifstream in(wiadomosci[wybor - 1]);
    string tekst;
    while (getline(in, tekst))
    {
        cout << tekst << endl;
    }
    in.close();

    
    // Utwórz folder "Odpowiedź"
    string folder_odpowiedzi = folder + "\\Odpowiedz";
    filesystem::create_directory(folder_odpowiedzi);

    // Utwórz plik "1_odpowiedz.txt"
    string plik = folder_odpowiedzi + to_string(liczba_odpowiedzi++) +"\\_odpowiedz.txt";
    ofstream out(plik);
    cout << "Podaj odpowiedź: ";
    getline(cin, tekst);
    out << tekst;
    cout << "odpowiedz wyslana" << endl;
    sleep(1);
    out.close();
}

void Komunikacja::sprawdzSkrz(string imie)
{
    // Wejdź do folderu klienta
    string folder = "..\\Model\\Wiadomosci\\" + imie;
    filesystem::current_path(folder);

    // Wyświetl listę wiadomości
    vector<string> wiadomosci;
    for (const auto &plik : filesystem::directory_iterator(folder))
    {
        if (plik.is_regular_file())
        {
            wiadomosci.push_back(plik.path().filename().string());
        }
    }

    // Wybierz wiadomość
    int wybor;
    do
    {
        cout << "Wybierz wiadomość: ";
        for (int i = 0; i < wiadomosci.size(); i++)
        {
            cout << i + 1 << ". " << wiadomosci[i] << endl;
        }
        cin >> wybor;
    } while (wybor < 1 || wybor > wiadomosci.size());

    // Wyświetl wiadomość
    cout << endl
         << "Odpowiedź: " << endl;
    ifstream in(wiadomosci[wybor - 1]);
    string tekst;
    while (getline(in, tekst))
    {
        cout << tekst << endl;
    }
    in.close();
    cout << "sprawdzono skrzynie" << endl;
    sleep(1);
}
