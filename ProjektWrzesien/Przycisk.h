#pragma once
#include <stdio.h>
#include <iostream>
using namespace std;

class Przycisk
{
private:
	string nazwa;
	bool wybrany;
public:
	Przycisk(const string _nazwa, const bool _wybrany);
};