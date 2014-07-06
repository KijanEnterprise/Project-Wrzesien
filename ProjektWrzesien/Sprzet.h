#pragma once
#include <stdio.h>
#include <iostream>
#include "Const.h"
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
};