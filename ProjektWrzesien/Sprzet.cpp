#include "Sprzet.h"

Sprzet::Sprzet(const string _producent, const string _model, const TypSprzetu _rodzaj, const string _opis)
{
	if(_producent=="")
		throw Error();
	producent=_producent;
	if(_model=="")
		throw Error();
	model=_model;
	if(_rodzaj<0 && _rodzaj>14)
		throw Error();
	rodzaj=_rodzaj;
	opis=_opis;
}