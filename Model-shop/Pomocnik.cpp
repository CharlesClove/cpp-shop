#include <iostream>
#include <string>
#include "Pomocnik.h"
#include <fstream>
#include <cstdlib>
#include <sstream>
#include <unistd.h>
using namespace std;

void Pomocnik::ZalogujPomoc()
{
    string login, haslo;
    cout << " Podaj nazwe uzytkownika: ";
    cin >> login;
    cout << " Podaj haslo: ";
    cin >> haslo;

    ifstream file("danePomocnik.txt");
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
                    cout << " Zalogowano jako pomocnik.\n"
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


