#pragma once
#include "Zlecenie.h"

class Zlecenia
{
private:
	vector<Zlecenie> listaZlecen;
public:
	Zlecenia();
	void OdczytZlecenia();
	void SerializujZlecenia();
	void WyswietlZlecenie();
	void html_zlecenia();
};