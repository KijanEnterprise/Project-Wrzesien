#pragma once
#include "Sprzet.h"
#include "Czlowiek.h"
using namespace std;

class Sprzety
{
private:
	vector<Sprzet> listaSprzetow;
public:
	Sprzety ();
	void Deserializuj();
	void Serializuj();
	void Wyswietl();
	void html();
};