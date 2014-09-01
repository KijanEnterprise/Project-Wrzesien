#pragma once
#include "Zlecenie.h"


Zlecenie::Zlecenie(int _idZlecenia, const int _idPracownika, const int _idKlienta, const StanZlecenia _stanZlecenia, const float _koszt, 
	const string _uwagi, const string _dataPrzyjecia, const string _dataWydania)
{
	if(_idZlecenia<0)
		throw Error("Bledne ID zlecenia");
	idZlecenia=_idZlecenia;
	if(_idPracownika<0)
		throw Error("Bledne ID pracownika");
	idPracownika=_idPracownika;
	if(_idKlienta<0)
		throw Error("Bledne ID klienta");
	idKlienta=_idKlienta;
	if(_stanZlecenia<0 && _stanZlecenia>4)
		throw Error("Bledny stan zlecenia");
	stanZlecenia=_stanZlecenia;
	if(_koszt<0)
		throw Error("Bledny koszt");
	koszt=_koszt;
	uwagi=_uwagi;
	//Sytuacja wyjatkowa dla dat      DOPISAC !!!
	dataPrzyjecia=_dataPrzyjecia;
	dataWydania=_dataWydania;
}

void Zlecenie::wyswietl()
{
	cout << "\n\tID Zlecenia: "<< getIdZlecenia() << "\n\nID pracownika: " << getIdPracownika() << "\n\nID klienta: " <<  getIdKlienta() << "\n\nStan zlecenia: " << stanToString() << "\n\nKoszt calkowity zlecenia: " 
		<< getKoszt() << "\n\nData Przyjecia: " << getDataPrzyjecia() << "\n\nData wydania: " << getDataWydania() << "\n\nUwagi: " << getUwagi() << "\n\n\n";

}

void Zlecenie::setIdZlecenia(const int _idZlecenia)
{
	if(_idZlecenia<0)
		throw Error("Bledne ID zlecenia");
	idZlecenia=_idZlecenia;
}

void Zlecenie::setIdPracownika(const int _idPracownika)
{
	if(_idPracownika<0)
		throw Error("Bledne ID pracownika");
	idPracownika=_idPracownika;
}

void Zlecenie::setIdKlienta(const int _idKlienta)
{
	if(_idKlienta<0)
		throw Error("Bledne ID klienta");
	idKlienta=_idKlienta;
}

void Zlecenie::setStanZlecenia(const StanZlecenia _stanZlecenia)
{
	if(_stanZlecenia<0 && _stanZlecenia>4)
		throw Error("Bledny stan zlecenia");
	stanZlecenia=_stanZlecenia;
}

void Zlecenie::setKoszt(const float _koszt)
{
	if(_koszt<0)
		throw Error("Bledny koszt");
	koszt=_koszt;
}

void Zlecenie::setUwagi(const string _uwagi)
{
	uwagi=_uwagi;
}

void Zlecenie::setDataPrzyjecia(const string _dataPrzyjecia)
{
	dataPrzyjecia=_dataPrzyjecia;
}

void Zlecenie::setDataWydania(const string _dataWydania)
{
	dataWydania=_dataWydania;
}

string Zlecenie::stanToString()
{
	switch(stanZlecenia)
	{
	case Przyjety:
		return "Przyjety";
		break;
	case Diagnozowany:
		return "Diagnozowany";
		break;
	case OczekujacyNaCzesci:
		return "Oczekujacy na czesci";
		break;
	case GotowyDoOdbioru:
		return "Gotowy do odbioru";
		break;
	case Wydany:
		return "Wydany";
		break;
	default:
		return "Zly stan zlecenia";
	}
}
 
//vector <Zlecenie> Zlecenie::deserializuj(vecotr <Zlecenie> &Zlecenia)
//{
//	string d1,d2,d3,d5,d6,d7,d8,tempString;
//	int tempInt;
//	StanZlecenia d4;
//	char oddzielnik=';';
//	char koniec='\n';
//	fstream tekst;
//	tekst.open("dane//zlecenia.csv");
//	while(!tekst.eof())
//	{
//		getline(tekst,d1,oddzielnik);
//		getline(tekst,d2,oddzielnik);
//		getline(tekst,d3,oddzielnik);
//		getline(tekst,tempString,oddzielnik);
//		getline(tekst,d5,oddzielnik);
//		getline(tekst,d6,oddzielnik);
//		getline(tekst,d7,oddzielnik);
//		getline(tekst,d8,oddzielnik);
//		tempInt=atoi(tempString.c_str());
//		d4=static_cast<StanZlecenia>(tempInt);
//		if(atoi(d1.c_str())!=0)
//		{
//			//Zlecenie z(1,2,3,0,10.0,"abc","bcx","ser");
//		}
//		
//	}
//}