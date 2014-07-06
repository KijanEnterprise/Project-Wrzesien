#include "Czlowiek.h"

Czlowiek::Czlowiek(const int _id,const string _imie,const string _nazwisko,const string _telefon,const string _email,const string _adres)
{
	id=_id;
	imie=_imie;
	nazwisko=_nazwisko;
	telefon=_telefon;
	email=_email;
	adres=_adres;
}

void Czlowiek::setId(const int _id)
{
	id=_id;
}

void Czlowiek::setImie(const string _imie)
{
	imie=_imie;
}

void Czlowiek::setNazwisko(const string _nazwisko)
{
	nazwisko=_nazwisko;
}

void Czlowiek::setTelefon(const string _telefon)
{
	telefon=_telefon;
}

void Czlowiek::setEmail(const string _email)
{
	email=_email;
}

void Czlowiek::setAdres(const string _adres)
{
	adres=_adres;
}

void Czlowiek::serializuj()
{

}

void Czlowiek::deserializuj()
{

}

void Czlowiek::wyswietl()
{

}