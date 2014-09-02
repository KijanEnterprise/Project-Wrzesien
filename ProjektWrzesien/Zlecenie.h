#pragma once
#include "Sprzet.h"
#include "Pracownik.h"
#include "Const.h"

class Zlecenie
{
protected:
	int idZlecenia;
	int idPracownika;
	int idKlienta;
	StanZlecenia stanZlecenia;
	float koszt;
	string uwagi;
	string dataPrzyjecia;
	string dataWydania;
public:
	Zlecenie(int _idZlecenia, const int _idPracownika, const int _idKlienta, const StanZlecenia _stanZlecenia, const float _koszt, 
		const string _uwagi, const string _dataPrzyjecia, const string _dataWydania);

	string stanToString();
	int getIdZlecenia(){ return idZlecenia;}
	int getIdPracownika(){ return idPracownika;}
	int getIdKlienta(){ return idKlienta;}
	StanZlecenia getStanZlecenia(){ return stanZlecenia;}
	float getKoszt(){ return koszt;}
	string getUwagi(){ return uwagi;}
	string getDataPrzyjecia(){ return dataPrzyjecia;}
	string getDataWydania(){ return dataWydania;}

	void wyswietl();

	void setIdZlecenia(const int _idZlecenia);
	void setIdPracownika(const int _idPracownika);
	void setIdKlienta(const int _idKlienta);
	void setStanZlecenia(const StanZlecenia _stanZlecenia);
	void setKoszt(const float _koszt);
	void setUwagi(const string _uwagi);
	void setDataPrzyjecia(const string _dataPrzyjecia);
	void setDataWydania(const string _dataWydania);
};