#include "Pracownik.h"

Pracownik::Pracownik(const unsigned int _id,const string _imie, const string _nazwisko, const string _telefon, const string _email, const string _adres,
	const float _wyplata, const string _nrRachunku, tm *_dataZatrudnienia):
	Czlowiek(_id, _imie, _nazwisko, _telefon, _email, _adres) // UWAGA - Wymagany konstruktor klasy bazowej [do sprawdzenia/poprawy]
{
	setId(_id);
	setImie(_imie);
	setNazwisko(_nazwisko);
	setTelefon(_telefon);
	setEmail(_email);
	setAdres(_adres);
	if (_wyplata<=0)
		throw Error("Bledna wyplata");
	wyplata=_wyplata;
	if(_nrRachunku=="")
		throw Error("Bledny numer rachunku");
	nrRachunku=_nrRachunku;
//	if Sytuacja wyj¹tkowa dla daty           UZUPELNIC !!!
	dataZatrudnienia=_dataZatrudnienia;
}

void Pracownik::setWyplata(const float _wyplata)
{
	if (_wyplata<=0)
		throw Error("Bledna wyplata");
	wyplata=_wyplata;
}

void Pracownik::setNrRachunku(const string _nrRachunku)
{
	if(_nrRachunku=="")
		throw Error("Bledny numer rachunku");
	nrRachunku=_nrRachunku;
}

void Pracownik::setDataZatrudnienia(tm *_dataZatrudnienia)
{
//	if Sytuacja wyj¹tkowa dla daty           UZUPELNIC !!!
	dataZatrudnienia=_dataZatrudnienia;
}

void Pracownik::wyswietl()
{
	char bufor[64];
	strftime(bufor,sizeof(bufor),"%d-%m-%Y",dataZatrudnienia);
	cout << "\tID pracownika "<< getId() << "\n\n" << getImie() << " " << getNazwisko() << "\n\nTelefon kontaktowy: " << getTelefon() << "\n\nEmail: " << getEmail() << "\n\nAdres: " << getAdres() << "\n\nRachunek: " <<getNrRachunku() << "\n\nWynagrodzenie: " <<  getWyplata() <<" zl" << "\n\nData zatrudnienia: " << bufor << "\n\n\n\n";
}

bool Pracownik::operator == (const Pracownik &L) const
{
	return 0; //return (id == L.id);											// DO POPRAWY !!!
}