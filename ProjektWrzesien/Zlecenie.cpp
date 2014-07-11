#include "Zlecenie.h"


Zlecenie::Zlecenie(const int _idZlecenia, const int _idPracownika, const int _idKlienta, const StanZlecenia _stanZlecenia, const float _koszt, 
	const string _uwagi, const tm _dataPrzyjecia, const tm _dataWydania)
{
	if(_idZlecenia==0)
		throw Error();
	idZlecenia=_idZlecenia;
	if(_idPracownika==0)
		throw Error();
	idPracownika=_idPracownika;
	if(_idKlienta==0)
		throw Error();
	idKlienta=_idKlienta;
	if(_stanZlecenia<0 && _stanZlecenia>4)
		throw Error();
	stanZlecenia=_stanZlecenia;
	if(_koszt<0)
		throw Error();
	koszt=_koszt;
	uwagi=_uwagi;
	//Sytuacja wyjatkowa dla dat      DOPISAC !!!
	dataPrzyjecia=_dataPrzyjecia;
	dataWydania=_dataWydania;
}

void Zlecenie::serializuj()
{

}

void Zlecenie::deserializuj()
{

}

void Zlecenie::wyswietl()
{

}

void Zlecenie::exportHTML()
{

}

void Zlecenie::setIdZlecenia(const int _idZlecenia)
{
	if(_idZlecenia==0)
		throw Error();
	idZlecenia=_idZlecenia;
}

void Zlecenie::setIdPracownika(const int _idPracownika)
{
	if(_idPracownika==0)
		throw Error();
	idPracownika=_idPracownika;
}

void Zlecenie::setIdKlienta(const int _idKlienta)
{
	if(_idKlienta==0)
		throw Error();
	idKlienta=_idKlienta;
}

void Zlecenie::setStanZlecenia(const StanZlecenia _stanZlecenia)
{
	if(_stanZlecenia<0 && _stanZlecenia>4)
		throw Error();
	stanZlecenia=_stanZlecenia;
}

void Zlecenie::setKoszt(const float _koszt)
{
	if(_koszt<0)
		throw Error();
	koszt=_koszt;
}

void Zlecenie::setUwagi(const string _uwagi)
{
	uwagi=_uwagi;
}

void Zlecenie::setDataPrzyjecia(const tm _dataPrzyjecia)
{
	dataPrzyjecia=_dataPrzyjecia;
}

void Zlecenie::setDataWydania(const tm _dataWydania)
{
	dataWydania=_dataWydania;
}