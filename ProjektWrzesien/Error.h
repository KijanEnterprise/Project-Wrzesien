#pragma once
#include <iostream>
using namespace std;

class Error
{
private:
	string wiadomosc;
public:
	Error(string wiadomosc);
	string getWiadomosc();
};