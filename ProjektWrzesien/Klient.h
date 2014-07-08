#pragma once
#include "Czlowiek.h"


class Klient: public Czlowiek
{
public:
	Klient(const int _id,const string _imie,const string _nazwisko,const string _telefon,const string _email,const string _adres);
	void serializuj();
	void deserializuj(vector<Klient> &Klienci);
	void wyswietl();
	void exportHTML();
	bool operator == (const Klient &L) const;
};