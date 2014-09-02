#include "Czlowiek.h"
#include "Const.h"
#include "Pracownicy.h"
#include "Sprzety.h"
#include "Zlecenia.h"
#include "Klienci.h"
#include <iostream>
using namespace std;


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
		char menu='8';

		Klienci klient;
		Pracownicy pracownik;
		Sprzety sprzet;
		Zlecenia zlecenie;

		klient.Deserializuj();
		pracownik.Deserializuj();
		sprzet.Deserializuj();
		zlecenie.Deserializuj();

		while(menu!='0')
		{
			switch (menu)
			{
			case '1':
				{
					system("cls");
					klient.Wyswietl();
					printf("Nacisnij dowolny klawisz by powrocic do menu");
					menu='8';
					_getch();
					break;

				}
			case '2':
				{
					system("cls");
					pracownik.Wyswietl();
					printf("Nacisnij dowolny klawisz by powrocic do menu");
					menu='8';
					_getch();
					break;
				}
			case '3':
				{
					system("cls");
					sprzet.Wyswietl();
					printf("Nacisnij dowolny klawisz by powrocic do menu");
					menu='8';
					_getch();
					break;
				}
			case '4':
				{
					system("cls");
					zlecenie.Wyswietl();
					printf("Nacisnij dowolny klawisz by powrocic do menu");
					menu='8';
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
					menu='8';
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
					menu='8';
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
					menu='8';
					_getch();
					break;
				}   
			case '8':
				{
					system("cls");
					printf("Wybierz 1 by wyswietlic liste klientow\n");
					printf("\nWybierz 2 by wyswietlic liste pracownikow\n");
					printf("\nWybierz 3 by wyswietlic liste sprzetu\n");
					printf("\nWybierz 4 by wyswietlic liste zlecen\n");
					printf("\nWybierz 5 by zapisac dane do pliku\n");
					printf("\nWybierz 6 by zapisac dane do HTML\n");
					printf("\nWybierz 7 by dodac dane\n");
					printf("\nWybierz 0 by wyjsc z programu\n");
					printf("\n\n\nTwoj wybor: ");
					menu=getch();
					break;
				}
			}

		} 
	}catch(Error &E)
	{
		cout<<E.getWiadomosc();
	}
}