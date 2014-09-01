#include "Sprzety.h"

void Sprzety::DeserializujSprzet()
{
	string dana0,dana1,dana3,dana5;
	int dana4;
	TypSprzetu dana2;
	char separator=';';
	char konieclini='\n';
	fstream plik;
	plik.open("dane//sprzet.csv");
	while (!plik.eof())
	{
		getline(plik,dana0,separator);
		getline(plik,dana1,separator);
		getline(plik,dana5,separator);
		getline(plik,dana3,konieclini);
		dana4=atoi(dana5.c_str());
		dana2=static_cast<TypSprzetu>(dana4);
		
		
			Sprzet sprzet(dana0,dana1,dana2,dana3);  
			listaSprzetow.push_back(sprzet);
		
	}
	plik.close();
}

void Sprzety::SerializujSprzet()
{
	fstream plik;
	plik.open("dane//sprzet.csv",std::ios::out);
	for(int i=0;i<listaSprzetow.size();i++) 
		plik << listaSprzetow[i].getProducent() << ";" << listaSprzetow[i].getModel()<< ";"<< listaSprzetow[i].getRodzaj() << ";"<< listaSprzetow[i].getOpis();
	cout << "\n\nLista sprzetu zostala zapisana!" << endl;
	plik.close();
}

void Sprzety::WyswietlSprzet()
{
	cout <<"\t\tLISTA SPRZETU" << endl << endl;
	for(int i=0;i<listaSprzetow.size();i++)
	{
		listaSprzetow[i].wyswietl();
	}
}

void Sprzety::html_sprzet()
{
	fstream plik;
	plik.open("html//sprzet.html",std::ios::out);
	plik<<"<html><head><title>Tabela - Sprzetu</title><link rel='stylesheet' type='text/css' href='style.css' /></head><body>"<<endl;
	plik<<"<h1>Sprzet:</h1><table>"<<endl;
	plik<<"<tr><td>Producent</td><td>Model</td><td>Rodzaj sprzetu</td><td>Opis</td>"<<endl;
	for(int i=0;i<listaSprzetow.size();i++)
	{	
		plik<<"<tr><td>"<< listaSprzetow[i].getProducent() << "</td><td>" << listaSprzetow[i].getModel() << "</td><td>" << listaSprzetow[i].rodzajNaString() 
			<< "</td><td>" << listaSprzetow[i].getOpis() << "</td></tr>"<<endl;
	}
	plik<<"</table></body></html>"<<endl;
	plik.close();
	system("html\\sprzet.html");
}