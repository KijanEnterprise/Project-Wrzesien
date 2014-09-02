#pragma once
#include "Const.h"
#include "Error.h"
#include <stdio.h>
#include <conio.h>
#include <iostream>
#include <vector>
#include <time.h>
#include <string>
#include <fstream>
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