#include <iostream>
#include <string>
#include "Pomocnik.h"
#include "Admin.h"
#include <fstream>
#include <cstdlib>
#include <sstream>
#include <unistd.h>
#include <vector>
#include <algorithm>

using namespace std;

void Admin::UsunPomocnika(const std::string &login)
{
    auto it = std::find_if(listaPomocnikow.begin(), listaPomocnikow.end(),
                           [&login](const Pomocnik &p)
                           { return p.login == login; });

    if (it != listaPomocnikow.end())
    {
        listaPomocnikow.erase(it);

        std::ofstream file("danePomocnik.txt", std::ofstream::out | std::ofstream::trunc);
        if (file.is_open())
        {
            for (const auto &p : listaPomocnikow)
            {
                file << p.login << " " << p.haslo << std::endl;
            }
            file.close();
            std::cout << "Usunieto Pomocnika o loginie: " << login << std::endl;
            sleep(1);
        }
        else
        {
            std::cout << "Blad otwarcia pliku." << std::endl;
        }
    }
    else
    {
        std::cout << "Nie znaleziono Pomocnika o loginie: " << login << std::endl;
    }
}

void Admin::WyswietlListePomocnikow()
{
    listaPomocnikow.clear(); 

    std::ifstream file("danePomocnik.txt");
    if (file.is_open())
    {
        Pomocnik pomocnik;
        while (file >> pomocnik.login >> pomocnik.haslo)
        {
            listaPomocnikow.push_back(pomocnik);
        }
        file.close();

        std::cout << "Lista Pomocnikow:" << std::endl;
        for (const auto &p : listaPomocnikow)
        {
            std::cout << p.login << std::endl;
        }
    }
    else
    {
        std::cout << "Blad otwarcia pliku." << std::endl;
    }
}

void Admin::ZarejestrujPomocnik(){
    Pomocnik newPomocnik;
    cout << " Podaj nazwe uzytkownika: ";
    cin >> newPomocnik.login;
    cout << " Podaj pin: ";
    cin >> newPomocnik.haslo;

    ofstream file("danePomocnik.txt", ios::app);
    if (file.is_open())
    {
        file << newPomocnik.login << " " << newPomocnik.haslo << endl;
        file.close();
        cout << " Zarejestrowano Pomocnika." << endl;
        sleep(2);
    }
    else
    {
        cout << " Blad otwarcia pliku." << endl;
    }
}
void Admin::ZalogujAdmin(){
    string login, haslo;
    cout << " Podaj nazwe uzytkownika: ";
    cin >> login;
    cout << " Podaj haslo: ";
    cin >> haslo;

    ifstream file("daneadmin.txt");
    if (file.is_open())
    {
        string line;
        bool loggedIn = false;
        while (getline(file, line))
        {
            istringstream iss(line);
            string storedUsername, storedPassword;
            if (iss >> storedUsername >> storedPassword)
            {
                if (storedUsername == login && storedPassword == haslo)
                {
                    loggedIn = true;
                    cout << " Zalogowano jako admin.\n"
                         << endl;
                    sleep(1);
                    break;
                }
            }
        }
        file.close();

        if (loggedIn)
        {
            cout << " Zalogowano poprawnie.\n"
                 << endl;
            sleep(1);
        }
        else
        {
            cout << " Bledne dane logowania." << endl;
            sleep(1);
        }
    }
    else
    {
        cout << " Blad otwarcia pliku." << endl;
    }
}