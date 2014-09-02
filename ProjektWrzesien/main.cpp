#include "Czlowiek.h"
#include "Const.h"
#include "Pracownicy.h"
#include "Sprzety.h"
#include "Zlecenia.h"
#include "Klienci.h"

int main()
{
	try
	{	
		int menu=7;

		printf("Wybierz 1 by wyswietlic liste klientow\n");
		printf("\nWybierz 2 by wyswietlic liste pracownikow\n");
		printf("\nWybierz 3 by wyswietlic liste sprzetu\n");
		printf("\nWybierz 4 by wyswietlic liste zlecen\n");
		printf("\nWybierz 5 by zapisac dane do pliku\n");
		printf("\nWybierz 6 by zapisac dane do HTML\n");
		printf("\n\nTwoj wybor: ");

		Klienci a;
		Pracownicy b;
		Sprzety c;
		Zlecenia d;

		a.Deserializuj();
		b.Deserializuj();
		c.Deserializuj();
		d.Deserializuj();

		while(menu!=0)
		{

			switch (menu)
			{
			case 1:
				{
					system("cls");
					a.Wyswietl();
					printf("Nacisnij 0 by powrocic do menu");
					menu=7;
					_getch();
					break;
					
				}
			case 2:
				{
					system("cls");
					b.Wyswietl();
					printf("Nacisnij 0 by powrocic do menu");
					menu=7;
					_getch();
					break;
				}
			case 3:
				{
					system("cls");
					c.Wyswietl();
					printf("Nacisnij 0 by powrocic do menu");
					menu=7;
					_getch();
					break;
				}
			case 4:
				{
					system("cls");
					d.Wyswietl();
					printf("Nacisnij 0 by powrocic do menu");
					menu=7;
					_getch();
					break;
				}
			case 5:
				{
					system("cls");
					a.Serializuj();
					b.Serializuj();
					c.Serializuj();
					d.Serializuj();
					printf("Nacisnij 0 by powrocic do menu");
					menu=7;
					_getch();
					break;
				}
			case 6:
				{
					system("cls");
					a.html();
					b.html();
					c.html();
					d.html();
					printf("Nacisnij 0 by powrocic do menu");
					menu=7;
					_getch();
					break;
				}
			case 7:
				{
					system("cls");
					printf("Wybierz 1 by wyswietlic liste klientow\n");
					printf("\nWybierz 2 by wyswietlic liste pracownikow\n");
					printf("\nWybierz 3 by wyswietlic liste sprzetu\n");
					printf("\nWybierz 4 by wyswietlic liste zlecen\n");
					printf("\nWybierz 5 by zapisac dane do pliku\n");
					printf("\nWybierz 6 by zapisac dane do HTML\n");
					printf("\n\nTwoj wybor: ");
					cin>>menu;
					break;
				}
			}

		} 
	}catch(Error &E)
	{
		cout<<E.getWiadomosc();
	}


	cin.get();
}