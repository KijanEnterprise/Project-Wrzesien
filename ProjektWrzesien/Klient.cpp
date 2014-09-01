#include "Klient.h"

Klient::Klient(const unsigned int _id,const string _imie,const string _nazwisko,const string _telefon,const string _email,const string _adres):
	Czlowiek(_id,_imie,_nazwisko,_telefon,_email,_adres)
{
	if(_id<0)
		throw Error("Bledne ID klienta");
	setId(_id);
	if(_imie=="")
		throw Error("Puste pole imie klienta");
	setImie(_imie);
	if(_nazwisko=="")
		throw Error("Puste pole nazwisko klienta");
	setNazwisko(_nazwisko);
	if(_telefon=="")
		throw Error("Puste pole telefonu klienta");
	setTelefon(_telefon);
	if(_email=="")
		throw Error("Puste pole email klienta");
	setEmail(_email);
	if(_adres=="")
		throw Error("Puste pole adresu klienta");
	setAdres(_adres);
}

void Klient::wyswietl()
{
	cout << "\n\tID klienta "<< getId() << "\n\n" << getImie() << " " <<  getNazwisko() << "\n\nNr telefonu: " << getTelefon() << "\n\nEmail: " 
		<< getEmail() << "\n\nAdres: " << getAdres() << "\n\n\n";
} 

bool Klient::operator == (const Klient &L) const
{
	return (id == L.id);											
}