#pragma once
#include "Zlecenie.h"
#include "Klient.h"
#include "Pracownik.h"

class Zlecenia
{
private:
	vector<Zlecenie> listaZlecen;
public:
	Zlecenia();
	void Dodaj();
	void Usun();
	void Deserializuj();
	void Serializuj();
	void Wyswietl();
	void html();
};