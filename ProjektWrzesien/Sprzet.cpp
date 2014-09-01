#include "Sprzet.h"

Sprzet::Sprzet(const string _producent, const string _model, const TypSprzetu _rodzaj, const string _opis)
{
	if(_producent=="")
		throw Error("Bledny producent");
	producent=_producent;
	if(_model=="")
		throw Error("Bledny model");
	model=_model;
	if(_rodzaj<0 && _rodzaj>14)
		throw Error("Bledny rodzaj sprzetu");
	rodzaj=_rodzaj;
	opis=_opis;
}

void Sprzet::wyswietl()
{
	cout << "\nProducent: " << getProducent() << "\n\nModel: " << getModel() << "Rodzaj sprzety: " <<  getRodzaj() << "\n\nOpis: " 
		<< getOpis() << "\n\n\n";
} 