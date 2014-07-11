#pragma once
#include <stdio.h>
#include <conio.h>
#include <iostream>
#include <vector>
#include <time.h>
#include <string>
#include <fstream>
using namespace std;

class Czlowiek
{
private:
	int id;
	string imie;
	string nazwisko;
	string telefon;
	string email;
	string adres;
public:
	Czlowiek(const int _id,const string _imie,const string _nazwisko,const string _telefon,const string _email,const string _adres);
	virtual void serializuj();
	virtual void deserializuj();
	virtual void wyswietl();

	int getId(){ return id;}
	string getImie() { return imie;}
	string getNazwisko(){ return nazwisko;}
	string getTelefon(){ return telefon;}
	string getEmail(){ return email;}
	string getAdres(){ return adres;}

	void setId(const int _id);
	void setImie(const string _imie);
	void setNazwisko(const string _nazwisko);
	void setTelefon(const string _telefon);
	void setEmail(const string _email);
	void setAdres(const string adres);
};