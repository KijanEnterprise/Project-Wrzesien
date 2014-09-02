#pragma once
#include "Pracownik.h"

class Pracownicy
{
private:
	vector <Pracownik> listaPracownikow;
public:
	void Deserializuj();
	void Serializuj();
	void Wyswietl();
	void html();

	Pracownik getPracownik(int i);
	void Wyszukaj (string nazwisko);
	void Dodaj();
	void Usun(int i);
};