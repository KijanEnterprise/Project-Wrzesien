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
	cout << "\nProducent: " << getProducent() << "\n\nModel: " << getModel() << "\n\nRodzaj sprzety: " <<  rodzajNaString() << "\n\nOpis: " 
		<< getOpis() << "\n\n\n";
} 

string Sprzet::rodzajNaString()
{
	switch(rodzaj)
	{
	case PlytaGlowna:
		return "Plyta Glowna";
		break;
	case Procesor:
		return "Procesor";
		break;
	case PamiecRAM:
		return "Pamiec RAM";
		break;
	case DyskTwardy:
		return "Karta Graficzna";
		break;
	case KartaDzwiekowa:
		return "Karta Dzwiekowa";
		break;
	case KartaSieciowa:
		return "Karta Sieciowa";
		break;
	case Naped:
		return "Naped";
		break;
	case Zasilacz:
		return "Zasilacz";
		break;
	case Myszka:
		return "Myszka";
		break;
	case Klawiatura:
		return "Klawiatura";
		break;
	case KameraInternetowa:
		return "KameraInternetowa";
		break;
	case Sluchawki:
		return "Sluchawki";
		break;
	case Glosniki:
		return "Glosniki";
		break;
	default:
		return "Nie sprecyzowano";
		break;
	}
}