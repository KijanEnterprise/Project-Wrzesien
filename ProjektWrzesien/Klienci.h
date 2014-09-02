#pragma once
#include "Klient.h"

class Klienci
{
private:
	vector<Klient> listaKlientow;
public:
	void Deserializuj();
	void Serializuj();
	void Wyswietl();
	void html();
};