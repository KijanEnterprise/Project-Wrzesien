#include "Klient.h"

Klient::Klient(const int _id,const string _imie,const string _nazwisko,const string _telefon,const string _email,const string _adres):
	Czlowiek(_id,_imie,_nazwisko,_telefon,_email,_adres)
{
	setId(_id);
	setImie(_imie);
	setNazwisko(_nazwisko);
	setTelefon(_telefon);
	setEmail(_email);
	setAdres(_adres);
}

void Klient::serializuj()	
{

}

void Klient::deserializuj(vector<Klient> &Klienci)
{
	string dana0,dana1,dana2,dana3,dana4,dana5;
	int rodzaj;
	char separator = ';';
	char konieclini = '\n';
	fstream plik;
	plik.open("klienci.csv");
	while (!plik.eof())
	{
		getline(plik,dana0,separator);
		getline(plik,dana1,separator);
		getline(plik,dana2,separator);
		getline(plik,dana3,separator);
		getline(plik,dana4,separator);
		getline(plik,dana5,separator);		
		Klient Klient(atoi(dana0.c_str()),dana1,dana2,dana3,dana4,dana5);
		Klienci.push_back(Klient);
	}
	plik.close();
}

void Klient::exportHTML()
{

}

void Klient::wyswietl()
{

}

bool Klient::operator == (const Klient &L) const
{
	return 0; //return (id == L.id);											// DO POPRAWY !!!
}