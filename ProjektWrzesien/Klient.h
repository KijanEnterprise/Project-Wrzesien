#pragma once
#include "Czlowiek.h"
#include "Error.h"
#include <iostream>


class Klient: public Czlowiek
{
public:
	Klient(const unsigned int _id,const string _imie,const string _nazwisko,const string _telefon,const string _email,const string _adres);
	void wyswietl();
	bool operator == (const Klient &L) const;
};