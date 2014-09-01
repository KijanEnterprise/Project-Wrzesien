#pragma once
#include "Klient.h"

class Klienci
{
private:
	vector<Klient> listaKlientow;
public:
	void DeserializujKlienci();
	void SerializujKlienci();
	void WyswietlKlienci();
	void html_klienci();
};