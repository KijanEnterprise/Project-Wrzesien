#pragma once
#include "Sprzet.h"
#include "Czlowiek.h"
using namespace std;

class Sprzety
{
private:
	vector<Sprzet> listaSprzetow;
public:
	void DeserializujSprzet();
	void SerializujSprzet();
	void WyswietlSprzet();
	void html_sprzet();
};