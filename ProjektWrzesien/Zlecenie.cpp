#include "Zlecenie.h"


Zlecenie::Zlecenie(const int _idZlecenia, const int _idPracownika, const int _idKlienta, const StanZlecenia _stanZlecenia, const float _koszt, 
	const string _uwagi, const tm _dataPrzyjecia, const tm _dataWydania)
{
	idZlecenia=_idZlecenia;
	idPracownika=_idPracownika;
	idKlienta=_idKlienta;
	stanZlecenia=_stanZlecenia;
	koszt=_koszt;
	uwagi=_uwagi;
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
	idZlecenia=_idZlecenia;
}

void Zlecenie::setIdPracownika(const int _idPracownika)
{
	idPracownika=_idPracownika;
}

void Zlecenie::setIdKlienta(const int _idKlienta)
{
	idKlienta=_idKlienta;
}

void Zlecenie::setStanZlecenia(const StanZlecenia _stanZlecenia)
{
	stanZlecenia=_stanZlecenia;
}

void Zlecenie::setKoszt(const float _koszt)
{
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