#include <iostream>
#include <string>
#include "Klient.h"
#include "Admin.h"
#include "Pomocnik.h"
#include "Sklep.h"
#include "Transakcja.h"
#include "Zamowienia.h"
#include "Komunikacja.h"
#include <fstream>
#include <cstdlib>
#include <sstream>
#include <unistd.h>
using namespace std;


int main(){
    Klient klient;
    Admin admin;
    Pomocnik pomocnik;
    Sklep sklep;
    Zamowienie zamowienie;
    Transakcja transakcja;
    Komunikacja kom;
    int choice, choice2, choiceadmin;
    bool end = false, adminloop = false;
    char YN;
    string imie, pin;
    

    while (!end)
    {   
        system("cls");
        cout << "\n Wybierz opcje: " << endl;
        cout << " 1 - Zaloguj sie" << endl;
        cout << " 2 - Zarejestruj sie" << endl;
        cout << " 3 - Zaloguj sie jako pomocnik" << endl;
        cout << " 4 - Zaloguj sie jako admin" << endl;
        cout << " 5 - Zamknij" << endl;
        cout << " Podaj numer: ";

        cin >> choice;
        switch (choice)
        {
            
            case 1:
                int klientLoop;

                cout << " Podaj nazwe uzytkownika: ";
                cin >> imie;
                cout << " Podaj pin: ";
                cin >> pin;
                if (klient.ZalogujKlient(imie, pin))
                {
                    do
                    {
                        system("cls");
                        vector<int> listaWybranychProduktow;
                        cout << "\n Witaj " << imie << " milo cie widziec" << endl;

                        cout << "\n Wybierz opcje: " << endl;
                        cout << " 1 - Sklep" << endl;
                        cout << " 2 - Zamowienia" << endl;
                        cout << " 3 - Wiadomosc dla pomocnika" << endl;
                        cout << " 4 - Sprawdzenie odpowiedzi" << endl;
                        cout << " 5 - Usun konto" << endl;
                        cout << " 6 - Zamknij" << endl;
                        cout << " Podaj numer: ";
                        cin >> klientLoop;
                        switch (klientLoop)
                        {
                            int klientLoop2;
                        case 1:
                            do
                            {
                                system("cls");
                                cout << "\nSklep\n"
                                     << endl;
                                sklep.ZobaczProdukty();
                                cout << "\nWpisz numer produktu ktory cie interesuje lub 0 zeby wrocic\n"
                                     << endl;
                                int idProduktu;
                                cin >> idProduktu;
                                if (idProduktu != 0)
                                {
                                    listaWybranychProduktow.push_back(idProduktu);
                                    sklep.DodajDoZamowienia(imie, listaWybranychProduktow);
                                }
                                else
                                {
                                    klientLoop2 = 0;
                                }
                            } while (klientLoop2 != 0);
                            break;
                        case 2:
                            zamowienie.wyswietlZamowienieKlient(imie);
                            sleep(0.5);
                            transakcja.UtworzTransakcje(imie);
                            sleep(0.5);
                            break;
                        case 3:
                            kom.NapisaniePyt(imie);
                            break;
                        case 4:
                            kom.sprawdzSkrz(imie);
                            break;
                        case 5:
                            char usunK;
                            cout << "Czy napewno chcesz usunąc konto [y/n]: ";
                            cin >> usunK;
                            if (usunK == 'y' || usunK == 'Y')
                            {
                                klient.usunKonto(imie);
                            }
                            else
                            {
                                break;
                            }
                        case 6:
                            cout << "Wylogowywanie" << endl;
                            break;
                        }
                        
                    }while(klientLoop != 5);
                        break;
                } else { continue; } break;



            case 2:
                klient.ZarejestrujKlient();
                sleep(1);
                break;
            case 3:
                pomocnik.ZalogujPomoc();
                cout << "Czy chcesz sprawdzic wiadomosci? 1 - tak,  2 - nie" << endl;
                int wyborPomocnik;
                cin >> wyborPomocnik;
                if(wyborPomocnik == 1) {
                    kom.OdpKlientowi();
                }
                sleep(2);
                break;
            case 4:
                admin.ZalogujAdmin();
                adminloop = true; 
                while (adminloop)
                {
                    system("cls");
                    cout << " 1.Zarejestruj Nowego pomocnika " << endl;
                    cout << " 2.Usun Pomocnika " << endl;
                    cout << " 3.Wyswietl Liste pomocnikow" << endl;
                    cout << " 4.Wyjdz" << endl;
                    cout << " Podaj numer: ";
                    cin >> choiceadmin;

                    switch (choiceadmin)
                    {
                    case 1:
                        admin.ZarejestrujPomocnik();
                        break;
                    case 2:
                        char login[20];
                        admin.WyswietlListePomocnikow();
                        cout << "\n Wybierz login ktory chcesz usunac: " << endl;
                        cin >> login;
                        admin.UsunPomocnika(login);
                        break;
                    case 3:
                        admin.WyswietlListePomocnikow();
                        sleep (3);
                        break;
                    case 4:
                        adminloop = false; 
                        break;
                    default:
                        break;
                    }
                }
                sleep(1);
                break;
            case 5:
                end = true;
                break;
            default:
                end = false;
                break;
            }
    }
}