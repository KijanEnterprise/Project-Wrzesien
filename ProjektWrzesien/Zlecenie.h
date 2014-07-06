#pragma once
#include "Sprzet.h"

class Zlecenie
{
private:
	int idZlecenia;
	int idPracownika;
	int idKlienta;
	StanZlecenia stanZlecenia;
	float koszt;
	string uwagi;
	tm dataPrzyjecia;
	tm dataWydania;
public:
	Zlecenie(const int _idZlecenia, const int _idPracownika, const int _idKlienta, const StanZlecenia _stanZlecenia, const float _koszt, 
		const string _uwagi, const tm _dataPrzyjecia, const tm _dataWydania);
	void serializuj();
	void deserializuj();
	void wyswietl();
	void exportHTML();

	int getIdZlecenia(){ return idZlecenia;}
	int getIdPracownika(){ return idPracownika;}
	int getIdKlienta(){ return idKlienta;}
	StanZlecenia getStanZlecenia(){ return stanZlecenia;}
	float getKoszt(){ return koszt;}
	string getUwagi(){ return uwagi;}
	tm getDataPrzyjecia(){ return dataPrzyjecia;}
	tm getDataWydania(){ return dataWydania;}

	void setIdZlecenia(const int _idZlecenia);
	void setIdPracownika(const int _idPracownika);
	void setIdKlienta(const int _idKlienta);
	void setStanZlecenia(const StanZlecenia _stanZlecenia);
	void setKoszt(const float _koszt);
	void setUwagi(const string _uwagi);
	void setDataPrzyjecia(const tm _dataPrzyjecia);
	void setDataWydania(const tm _dataWydania);
};