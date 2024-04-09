#include <iostream>
#include <string>
#include <fstream>
#include <cstdlib>
#include <sstream>
#include <unistd.h>
#include <map>
#include <vector>
#include <algorithm>
#include <ctime>
#include "Transakcja.h"

using namespace std;

string Transakcja::getDate()
{
    time_t now = time(NULL);
    struct tm *tm = localtime(&now);

    char dateString[80];
    strftime(dateString, sizeof(dateString), "%Y-%m-%d", tm);

    return string(dateString);
}

map<int, pair<string, double>> itemMapTran;
double totalPrice = 0;
void Transakcja::UtworzTransakcje(string imie)
{
    int choice = Zamowienie::potwierdzZamowienie();
    cout << "Dane odebrane z funkcji Zamowienie:" << choice << endl;
    if (choice == 1)
    {
        cout << "Zamowienie potwierdzono" << endl;
        sleep(1);
        string path = "../Model/doTrans/" + imie + "_zamowienia.txt";
        string outputPath = "../Model/doTrans/gotoweTrans/" + imie + "_transakcja.txt";
        ifstream file(path);
        ofstream outputFile(outputPath);

        if (!file.is_open())
        {   
            cout << "blad otwarcia pliku zamowienia " << path << endl;
            sleep(1);
            return;
        }
        else
        {
            cout << "Otwarto plik poprawnie " << endl;
        }

        int id;
        while (file >> id)
        {
            if (id == 1)
            {
                itemMapTran[id] = make_pair("Monitor", 700.0);
                totalPrice += 700;
            }
            else if (id == 2)
            {
                itemMapTran[id] = make_pair("Komputer", 1700.0);
                totalPrice += 1700;
            }
            else if (id == 3)
            {
                itemMapTran[id] = make_pair("Klawiatura", 200.0);
                totalPrice += 200;
            }
            else if (id == 4)
            {
                itemMapTran[id] = make_pair("Mysz", 100.0);
                totalPrice += 100;
            }
        }
        file.close();
        string dateNow = getDate();
        for (auto item : itemMapTran)
        {
            cout << "Item ID: " << item.first;
            cout << "  Item name: " << item.second.first;
            cout << "  Price: " << item.second.second << endl;
        }
        for (auto item : itemMapTran)
        {
            outputFile << "Date: " << dateNow << endl;
            outputFile << "Item ID: " << item.first << endl;
            outputFile << "   Item name: " << item.second.first << endl;
            outputFile << "   Price: " << item.second.second << endl;
        }
        outputFile << "Total price: " << totalPrice << endl;
        sleep(3);
        outputFile.close();
    }
    else
    {
        
        return;
    }
}
