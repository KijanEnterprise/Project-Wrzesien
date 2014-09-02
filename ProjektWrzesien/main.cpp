#include "Czlowiek.h"
#include "Const.h"
#include "Pracownicy.h"
#include "Sprzety.h"
#include "Zlecenia.h"
#include "Klienci.h"
#include <iostream>
using namespace std;


int main()
{
	try
	{ 
		char menu='0';

		Klienci klient;
		Pracownicy pracownik;
		Sprzety sprzet;
		Zlecenia zlecenie;

		klient.Deserializuj();
		pracownik.Deserializuj();
		sprzet.Deserializuj();
		zlecenie.Deserializuj();

		while(menu!='x')
		{
			switch (menu)
			{
			case '1':
				{
					system("cls");
					klient.Wyswietl();
					printf("Nacisnij dowolny klawisz by powrocic do menu");
					menu='0';
					_getch();
					break;

				}
			case '2':
				{
					system("cls");
					pracownik.Wyswietl();
					printf("Nacisnij dowolny klawisz by powrocic do menu");
					menu='0';
					_getch();
					break;
				}
			case '3':
				{
					system("cls");
					sprzet.Wyswietl();
					printf("Nacisnij dowolny klawisz by powrocic do menu");
					menu='0';
					_getch();
					break;
				}
			case '4':
				{
					system("cls");
					zlecenie.Wyswietl();
					printf("Nacisnij dowolny klawisz by powrocic do menu");
					menu='0';
					_getch();
					break;
				}
			case '5':
				{
					system("cls");
					klient.Serializuj();
					pracownik.Serializuj();
					sprzet.Serializuj();
					zlecenie.Serializuj();
					printf("Nacisnij dowolny klawisz by powrocic do menu");
					menu='0';
					_getch();
					break;
				}
			case '6':
				{
					system("cls");
					klient.html();
					pracownik.html();
					sprzet.html();
					zlecenie.html();
					printf("Nacisnij dowolny klawisz by powrocic do menu");
					menu='0';
					_getch();
					break;
				}
			case '7':
				{
					system("cls");
					printf("\nWybierz 1 by dodac klienta\n\nWybierz 2 by dodac pracownika\n\nWybierz 3 by dodac sprzet\n\nWybierz 4 by dodac zlecenie\n\nTwoj wybor: ");
					char znak;
					znak=getch();
					switch(znak)
					{
					case '1':
						{
							system("cls");
							klient.Dodaj();
							klient.Serializuj();
							_getch();
							break;
						}
					case '2':
						{
							system("cls");
							pracownik.Dodaj();
							pracownik.Serializuj();
							_getch();
							break;
						}
					case '3':
						{
							system("cls");
							sprzet.Dodaj();
							sprzet.Serializuj();
							_getch();
							break;
						}
					case '4':
						{
							system("cls");
							zlecenie.Dodaj();
							zlecenie.Serializuj();
							_getch();
							break;
						}
					}
					printf("Nacisnij dowolny klawisz by powrocic do menu");
					menu='0';
					_getch();
					break;
				}   
			case '8':
				{
					system("cls");
					printf("\nWybierz 1 by usunac klienta\n\nWybierz 2 by usunac pracownika\n\nWybierz 3 by usunac zlecenie\n\nTwoj wybor: ");
					char znak;
					znak=getch();
					switch(znak)
					{
					case '1':
						{
							system("cls");
							cout << "Podaj ID klienta do usuniecia: ";
							int IDKlientaUsun;
							cin>>IDKlientaUsun;
							klient.Usun(IDKlientaUsun);
							klient.Serializuj();
							_getch();
							break;
						}
					case '2':
						{
							cout << "Podaj ID pracownika do usuniecia: ";
							int IDpracownikaUsun;
							cin>>IDpracownikaUsun;
							system("cls");
							pracownik.Usun(IDpracownikaUsun);
							pracownik.Serializuj();
							_getch();
							break;
						}
					case '3':
						{
							system("cls");
							int usuwanie;
							printf("\t\tOkno usuwania zlecenia\n\n");
							printf("Podaj ID zlecenia, ktore chcesz usunac: ");
							cin>>usuwanie;
							zlecenie.Usun(usuwanie);
							_getch();
							zlecenie.Serializuj();
							break;
						}
					}
					printf("Nacisnij dowolny klawisz by powrocic do menu");
					menu='0';
					_getch();
					break;
				}   
			case '9':
				{
					system("cls");
					printf("\nWybierz 1 by szukac klienta\n\nWybierz 2 by szukac pracownika\n\nWybierz 3 by szukac sprzet\n\nWybierz 4 by szukac zlecenie\n\nTwoj wybor: ");
					char znak;
					znak=getch();
					switch(znak)
					{
					case '1':
						{
							system("cls");
							cout <<"Podaj szukane nazwisko klienta: ";
							string nazwisko;
							cin>>nazwisko;
							klient.Wyszukaj(nazwisko);
							_getch();
							break;
						}
					case '2':
						{
							system("cls");
							cout <<"Podaj szukane nazwisko pracownika: ";
							string nazwisko2;
							cin>>nazwisko2;
							pracownik.Wyszukaj(nazwisko2);
							_getch();
							break;
						}
					case '3':
						{
							system("cls");
							cout <<"Podaj szukany sprzet: ";
							TypSprzetu typ;
							//cin>>typ;
							sprzet.Wyszukaj(typ);
							_getch();
							break;
						}
					case '4':
						{
							system("cls");
							int idZlecenia;
							cout <<"Podaj szukane ID zlecenia: ";
							cin>>idZlecenia;
							zlecenie.Wyszukaj(idZlecenia);
							_getch();
							break;
						}
					}
					printf("Nacisnij dowolny klawisz by powrocic do menu");
					menu='0';
					_getch();
					break;
				}   
			case '0':
				{
					system("cls");
					printf("Wybierz 1 by wyswietlic liste klientow\n");
					printf("\nWybierz 2 by wyswietlic liste pracownikow\n");
					printf("\nWybierz 3 by wyswietlic liste sprzetu\n");
					printf("\nWybierz 4 by wyswietlic liste zlecen\n");
					printf("\nWybierz 5 by zapisac dane do pliku\n");
					printf("\nWybierz 6 by zapisac dane do HTML\n");
					printf("\nWybierz 7 by dodac dane\n");
					printf("\nWybierz 8 by usunac dane\n");
					printf("\nWybierz 9 by szukac dane\n");
					printf("\nWybierz x by wyjsc z programu\n");
					printf("\n\n\nTwoj wybor: ");
					menu=getch();
					break;
				}
			default:
				{
					printf("Bledne polecenie!");
					menu=getch();
				}
			}

		} 
	}catch(Error &E)
	{
		cout<<E.getWiadomosc();
	}
}