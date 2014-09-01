#include "Czlowiek.h"
#include "Const.h"
#include "Pracownik.h"
#include "Klient.h"
#include "Sprzet.h"
#include "Zlecenie.h"

void DeserializujSprzet(vector<Sprzet> &Sprzety)
{
	string dana0,dana1,dana2,dana3;
	char separator=';';
	char konieclini='\n';
	fstream plik;
	plik.open("dane//sprzet.csv");
	while (!plik.eof())
	{
		getline(plik,dana0,separator);
		getline(plik,dana1,separator);
		getline(plik,dana2,separator);
		getline(plik,dana3,separator);
		if(atoi(dana0.c_str())!=0)
		{
			//Sprzet Sprzet(dana0,dana1,dana2,dana3);  DO POPRAWY !!!!!!!
			//Sprzety.push_back(Sprzet);
		}
	}
	plik.close();
}

void DeserializujPracownicy(vector<Pracownik> &Pracownicy)  // ta funkcja nie moze byc w klasie bcs vector jest tak jakby tablica obiektow i wtedy kazdy obiekt by chcial wykonywac ta sama operacje..
{
	string dana0,dana1,dana2,dana3,dana4,dana5,dana6,dana7,dana8;
	char separator = ';';
	char konieclini = '\n';
	time_t czas;
	tm *data;
	fstream plik;
	plik.open("dane//pracownicy.csv");
	while (!plik.eof())
	{
		getline(plik,dana0,separator);
		getline(plik,dana1,separator);
		getline(plik,dana2,separator);
		getline(plik,dana3,separator);
		getline(plik,dana4,separator);
		getline(plik,dana5,separator);
		getline(plik,dana6,separator);
		getline(plik,dana7,separator);
		getline(plik,dana8,konieclini);
		czas=atoi(dana8.c_str());
		if(atoi(dana0.c_str())!=0){
			Pracownik Pracownik(atoi(dana0.c_str()),dana1,dana2,dana3,dana4,dana5,atof(dana6.c_str()),dana7,gmtime(&czas));
			Pracownicy.push_back(Pracownik);
		}
	}
	plik.close();
}

void DeserializujKlienci(vector<Klient> &Klienci)
{
	string dana0,dana1,dana2,dana3,dana4,dana5;
	char separator = ';';
	char konieclini = '\n';
	fstream plik;
	plik.open("dane//klienci.csv");

	while (!plik.eof())
	{		
		getline(plik,dana0,separator);
		getline(plik,dana1,separator);
		getline(plik,dana2,separator);
		getline(plik,dana3,separator);
		getline(plik,dana4,separator);
		getline(plik,dana5,konieclini);
		if(atoi(dana0.c_str())!=0){
			Klient Klient(atoi(dana0.c_str()),dana1,dana2,dana3,dana4,dana5);
			Klienci.push_back(Klient);
		}
	}
	plik.close();
}

void SerializujPracownicy(vector<Pracownik> &Pracownicy)
{
	fstream plik;
	plik.open("dane//pracownicy.csv",std::ios::out);
	for(int i=0;i<Pracownicy.size();i++) 
		plik << Pracownicy[i].getId() << ";" << Pracownicy[i].getImie() << ";" << Pracownicy[i].getNazwisko() << ";" 
		<< Pracownicy[i].getTelefon() << ";" << Pracownicy[i].getEmail() << ";" << Pracownicy[i].getAdres() << ";" 
		<< Pracownicy[i].getWyplata() << ";" << Pracownicy[i].getNrRachunku() <<  ";" << mktime(&Pracownicy[i].getDataZatrudnienia()) << endl;
	cout << "\n\nLista pracownikow zostala zapisana!" << endl;
	plik.close();
}

void SerializujKlienci(vector<Klient> &Klienci)
{
	fstream plik;
	plik.open("dane//klienci.csv",std::ios::out);
	for(int i=0;i<Klienci.size();i++) 
		plik << Klienci[i].getId() << ";" << Klienci[i].getImie() << ";" << Klienci[i].getNazwisko() << ";" << Klienci[i].getTelefon() 
		<< ";" << Klienci[i].getEmail() << ";" << Klienci[i].getAdres() << endl;
	cout << "\n\nLista klientow zostala zapisana!" << endl;
	plik.close();
}

void SerializujSprzet(vector<Sprzet> &Sprzety)
{
	fstream plik;
	plik.open("dane//sprzet.csv",std::ios::out);
	for(int i=0;i<Sprzety.size();i++) 
		plik << Sprzety[i].getProducent() << ";" << Sprzety[i].getModel()<< ";"<< Sprzety[i].getRodzaj() << ";"<< Sprzety[i].getOpis() << endl;
	cout << "\n\nLista sprzetu zostala zapisana!" << endl;
	plik.close();
}

void WyswietlSprzet(vector<Sprzet> &Sprzety)
{
	cout <<"\t\tLISTA SPRZETU" << endl << endl;
	for(int i=0;i<Sprzety.size();i++)
	{
		Sprzety[i].wyswietl();
	}
}

void WyswietlPracownicy(vector<Pracownik> &Pracownicy)
{
	cout <<"\t\tLISTA PRACOWNIKOW" << endl << endl;
	for(int i=0;i<Pracownicy.size();i++)
	{
		Pracownicy[i].wyswietl();
	}
}

void WyswietlKlienci(vector<Klient> &Klienci)
{
	cout <<"\t\tLISTA KLIENTOW" << endl << endl;
	for(int i=0;i<Klienci.size();i++)
	{
		Klienci[i].wyswietl();
	}
}

void html_pracownicy(vector<Pracownik> &Pracownicy)
{
	fstream plik;
	plik.open("html//pracownicy.html",std::ios::out);
	plik<<"<html><head><title>Tabela - Pracownicy</title><link rel='stylesheet' type='text/css' href='style.css' /></head><body>"<<endl;
	plik<<"<h1>Pracownicy:</h1><table>"<<endl;
	plik<<"<tr><td>Lp.</td><td>ID</td><td>Imie</td><td>Nazwisko</td><td>Nr telefonu</td><td>Email</td><td>Adres</td><td>Wyplata</td>" 
		<<"<td>Nr rachunku</td><td>Data zatrudnienia</td></tr>"<<endl;
	for(int i=0;i<Pracownicy.size();i++)
	{	
		char bufor[64];
		strftime(bufor,sizeof(bufor),"%d-%m-%Y",&Pracownicy[i].getDataZatrudnienia());
		plik<<"<tr><td>"<< i+1 <<"</td><td>"<< Pracownicy[i].getId() << "</td><td>" << Pracownicy[i].getImie() << "</td><td>" 
			<< Pracownicy[i].getNazwisko() << "</td><td>" << Pracownicy[i].getTelefon() << "</td><td>" << Pracownicy[i].getEmail() 
			<< "</td><td>" << Pracownicy[i].getAdres() << "</td><td>" << Pracownicy[i].getWyplata() << "</td><td>" 
			<< Pracownicy[i].getNrRachunku() <<  "</td><td>" << bufor << "</td></tr>"<<endl;
	}
	plik<<"</table></body></html>"<<endl;
	plik.close();
	system("html\\pracownicy.html");
}

void html_klienci(vector<Klient> &Klienci)
{
	fstream plik;
	plik.open("html//klienci.html",std::ios::out);
	plik<<"<html><head><title>Tabela - Klienci</title><link rel='stylesheet' type='text/css' href='style.css' /></head><body>"<<endl;
	plik<<"<h1>Klienci:</h1><table>"<<endl;
	plik<<"<tr><td>Lp.</td><td>ID</td><td>Imie</td><td>Nazwisko</td><td>Nr telefonu</td><td>Email</td><td>Adres</td></tr>"<<endl;
	for(int i=0;i<Klienci.size();i++){	
		plik<<"<tr><td>"<< i+1 <<"</td><td>"<< Klienci[i].getId() << "</td><td>" << Klienci[i].getImie() << "</td><td>" 
			<< Klienci[i].getNazwisko() << "</td><td>" << Klienci[i].getTelefon() << "</td><td>" << Klienci[i].getEmail() 
			<< "</td><td>" << Klienci[i].getAdres() << "</td></tr>" << endl;
	}
	plik<<"</table></body></html>"<<endl;
	plik.close();
	system("html\\klienci.html");
}

void html_sprzet(vector<Sprzet> &Sprzety)
{
	fstream plik;
	plik.open("html//sprzet.html",std::ios::out);
	plik<<"<html><head><title>Tabela - Sprzetu</title><link rel='stylesheet' type='text/css' href='style.css' /></head><body>"<<endl;
	plik<<"<h1>Sprzet:</h1><table>"<<endl;
	plik<<"<tr><td>Producent</td><td>Model</td><td>Rodzaj sprzetu</td><td>Opis</td>"<<endl;
	for(int i=0;i<Sprzety.size();i++)
	{	
		plik<<"<tr><td>"<< Sprzety[i].getProducent() << "</td><td>" << Sprzety[i].getModel() << "</td><td>" << Sprzety[i].getRodzaj() 
			<< "</td><td>" << Sprzety[i].getOpis() << "</td></tr>"<<endl;
	}
	plik<<"</table></body></html>"<<endl;
	plik.close();
	system("html\\sprzet.html");
}


int main()
{
	try
	{
		vector<Klient> Klienci;
		vector<Pracownik> Pracownicy;

		cout << "\tPROJEKT Wykonany przez Kijan Enterpeises!\n\n\n" << endl;
		DeserializujPracownicy(Pracownicy);
		DeserializujKlienci(Klienci);

		WyswietlPracownicy(Pracownicy);
		cout << endl << endl;
		WyswietlKlienci(Klienci);

		SerializujPracownicy(Pracownicy);
		SerializujKlienci(Klienci);

		//html_pracownicy(Pracownicy);  //dziala ale komentuje zeby sie za kazdym razem przy uruchamianiu nie robilo to ;)
		//html_klienci(Klienci);

	} catch(Error &E)
	{
		E.getWiadomosc();
	}
	cin.get();

};