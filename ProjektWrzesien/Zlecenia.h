#pragma once
#include "Zlecenie.h"

class Zlecenia
{
private:
	vector<Zlecenie> listaZlecen;
public:
	Zlecenia();
	void Deserializuj();
	void Serializuj();
	void Wyswietl();
	void html();
};