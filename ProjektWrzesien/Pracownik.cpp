#include "Pracownik.h"

Pracownik::Pracownik(const int _id,const string _imie, const string _nazwisko, const string _telefon, const string _email, const string _adres,
	const float _wyplata, const string _nrRachunku, const tm _dataZatrudnienia):
	Czlowiek(_id, _imie, _nazwisko, _telefon, _email, _adres) // UWAGA - Wymagany konstruktor klasy bazowej [do sprawdzenia/poprawy]
{
	setId(_id);
	setImie(_imie);
	setNazwisko(_nazwisko);
	setTelefon(_email);
	setAdres(_adres);
	setWyplata(_wyplata);
	setNrRachunku(_nrRachunku);
	setDataZatrudnienia(_dataZatrudnienia);
}

void Pracownik::setWyplata(const float _wyplata)
{
	wyplata=_wyplata;
}

void Pracownik::setNrRachunku(const string _nrRachunku)
{
	nrRachunku=_nrRachunku;
}

void Pracownik::setDataZatrudnienia(const tm _dataZatrudnienia)
{
	dataZatrudnienia=_dataZatrudnienia;
}

void Pracownik::serializuj()
{

}

void Pracownik::deserializuj()
{

}

void Pracownik::wyswietl()
{

}

void Pracownik::exportHTML()
{

}

bool Pracownik::operator == (const Pracownik &L) const
{
	return 0; //return (id == L.id);											// DO POPRAWY !!!
}