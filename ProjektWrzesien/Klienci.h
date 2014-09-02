#pragma once
#include "Klient.h"
#include <vector>

class Klienci
{
private:
	vector <Klient> listaKlientow;
public:
	void Deserializuj();
	void Serializuj();
	void Wyswietl();
	void html();

	Klient getKlient(int i);
	void Dodaj();
	void Usun();
};