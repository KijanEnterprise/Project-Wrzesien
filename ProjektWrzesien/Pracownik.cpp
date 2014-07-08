#include "Pracownik.h"

Pracownik::Pracownik(const int _id,const string _imie, const string _nazwisko, const string _telefon, const string _email, const string _adres,
	const float _wyplata, const string _nrRachunku, tm *_dataZatrudnienia):
	Czlowiek(_id, _imie, _nazwisko, _telefon, _email, _adres) // UWAGA - Wymagany konstruktor klasy bazowej [do sprawdzenia/poprawy]
{
	setId(_id);
	setImie(_imie);
	setNazwisko(_nazwisko);
	setTelefon(_telefon);
	setEmail(_email);
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

void Pracownik::setDataZatrudnienia(tm *_dataZatrudnienia)
{
	dataZatrudnienia=_dataZatrudnienia;
}

void Pracownik::serializuj()
{

}

void Pracownik::deserializuj(vector<Pracownik> &Pracownicy)
{
	string dana0,dana1,dana2,dana3,dana4,dana5,dana6,dana7,dana8;
	char separator = ';';
	char konieclini = '\n';
	time_t czas;
	tm *data;
	fstream plik;
	plik.open("pracownicy.csv");
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
		getline(plik,dana8,separator);
		czas=atoi(dana8.c_str());
		Pracownik Pracownik(atoi(dana0.c_str()),dana1,dana2,dana3,dana4,dana5,atof(dana6.c_str()),dana7,gmtime(&czas));
		Pracownicy.push_back(Pracownik);
	}
	plik.close();
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