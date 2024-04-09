#include <iostream>
#include <string>
#include "Klient.h"
#include <fstream>
#include <cstdlib>
#include <sstream>
#include <unistd.h>
#include <vector>
using namespace std;


void Klient::usunKonto(string imie)
{
        ifstream fileIn("dane.txt");
        vector<string> lines;
        if (fileIn.is_open()) {
            string line;
            while (getline(fileIn, line)){
                
                if (line.find(imie) != string::npos) {
                    cout << "Usunieto uzytkownika: " << imie << endl;
                    sleep(1);
                }else{
                    lines.push_back(line);
                }
            }

            fileIn.close();
            ofstream fileOut("dane.txt");
            if (fileOut.is_open()){
                for (const string &l : lines)
                {
                    fileOut << l << endl;
                }
                fileOut.close();
            }
            else
            {
                cout << "Blad otwarcia pliku do zapisu." << endl;
            }
        }
        else
        {
            cout << "Blad otwarcia pliku." << endl;
        }
    
}

void Klient::ZarejestrujKlient()
{
    Klient newKlient;
    cout << " Podaj nazwe uzytkownika: ";
    cin >> newKlient.imie;
    cout << " Podaj pin(tylko cyfry): ";
    cin >> newKlient.pin;

    

    ofstream file("dane.txt", ios::app);
    if (file.is_open())
    {
        file << newKlient.imie << " " << newKlient.pin << endl;
        file.close();
        cout << " Zarejestrowano uzytkownika." << endl;
        sleep(2);
    }
    else
    {
        cout << " Blad otwarcia pliku." << endl;
    }
}

bool Klient::ZalogujKlient(string imie, string pin)
{
    ifstream file("dane.txt");
    if (file.is_open())
    {
        string line;
        while (getline(file, line))
        {
            istringstream iss(line);
            string storedUsername, storedPassword;
            if (iss >> storedUsername >> storedPassword)
            {
                if (storedUsername == imie && storedPassword == pin)
                {
                    cout << " Zalogowano jako uzytkownik.\n"
                         << endl;
                    sleep(2);
                    file.close();
                    return true; 
                }
            }
        }
        file.close();
        cout << " Bledne dane logowania." << endl;
        sleep(1);
        return false; 
    }
    else
    {
        cout << " Blad otwarcia pliku." << endl;
        return false; 
    }
}
