#include "Czlowiek.h"

Czlowiek::Czlowiek(const unsigned int _id,const string _imie,const string _nazwisko,const string _telefon,const string _email,const string _adres)
{
	if(_id<=0)
		throw Error();
	id=_id;
	if(_imie=="") 
		throw Error();
	imie=_imie;
	if(_nazwisko=="")
		throw Error();
	nazwisko=_nazwisko;
	if(_telefon=="")
		throw Error();
	telefon=_telefon;
	if(_email=="")
		throw Error();
	email=_email;
	if(_adres=="")
		throw Error();
	adres=_adres;
}

void Czlowiek::setId(const int _id)
{
	if(_id<=0) 
		throw Error();
	id=_id;
}

void Czlowiek::setImie(const string _imie)
{
	if(_imie=="") 
		throw Error();
	imie=_imie;
}

void Czlowiek::setNazwisko(const string _nazwisko)
{
	if(_nazwisko=="")
		throw Error();
	nazwisko=_nazwisko;
}

void Czlowiek::setTelefon(const string _telefon)
{	
	if(_telefon=="")
		throw Error();
	telefon=_telefon;
}

void Czlowiek::setEmail(const string _email)
{
	if(_email=="")
		throw Error();
	email=_email;
}

void Czlowiek::setAdres(const string _adres)
{
	if(_adres=="")
		throw Error();
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