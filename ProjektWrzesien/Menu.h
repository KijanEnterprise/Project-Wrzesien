#pragma once
#include "Przycisk.h"
#include <list>


class Menu
{
private:
	list <Przycisk> przyciski;
	int wybor;
public:
	void operation();
	void dodajPrzycisk();
};
