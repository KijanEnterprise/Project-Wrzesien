#pragma once
#include "Pracownik.h"

class Pracownicy
{
private:
	vector <Pracownik> listaPracownikow;
public:
	void DeserializujPracownicy();
	void SerializujPracownicy();
	void WyswietlPracownicy();
	void html_pracownicy();
};