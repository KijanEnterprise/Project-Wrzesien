#include "Klient.h"

Klient::Klient(const int _id,const string _imie,const string _nazwisko,const string _telefon,const string _email,const string _adres):
	Czlowiek(_id,_imie,_nazwisko,_telefon,_email,_adres)
{
	setId(_id);
	setImie(_imie);
	setNazwisko(_nazwisko);
	setTelefon(_email);
	setAdres(_adres);
}

void Klient::serializuj()	
{

}

void Klient::deserializuj()
{

}

void Klient::exportHTML()
{

}

bool Klient::operator == (const Klient &L) const
{
	return 0; //return (id == L.id);											// DO POPRAWY !!!
}