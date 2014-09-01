#pragma once
#include <stdio.h>
#include <iostream>
#include <string>
#include "Const.h"
#include "Error.h"
using namespace std;

class Sprzet
{
private:
	string producent;
	string model;
	TypSprzetu rodzaj;
	string opis;
public:
	Sprzet(const string _producent, const string _model, const TypSprzetu _rodzaj, const string _opis);
	void wyswietl();
	string getProducent(){return producent;}
	string getModel(){return model;}
	TypSprzetu getRodzaj(){return rodzaj;}
	string getOpis(){return opis;}
	string rodzajNaString();
};