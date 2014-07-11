#pragma once
#include "Czlowiek.h"

class Pracownik: public Czlowiek
{
private:
	float wyplata;
	string nrRachunku;
	tm *dataZatrudnienia;
public:
	Pracownik(const unsigned int _id,const string _imie, const string _nazwisko, const string _telefon, const string _email, const string _adres,
		const float _wyplata, const string _nrRachunku, tm *_dataZatrudnienia);
	void serializuj();
	void deserializuj();
	void wyswietl();
	void exportHTML();
	bool operator == (const Pracownik &L) const;

	float getWyplata(){ return wyplata;}
	string getNrRachunku(){ return nrRachunku;}
	tm getDataZatrudnienia(){ return *dataZatrudnienia;}

	void setWyplata(const float _wyplata);
	void setNrRachunku(const string _nrRachunku);
	void setDataZatrudnienia(tm *_dataZatrudnienia);
};
