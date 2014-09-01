#include "Zlecenia.h"

void Zlecenia::OdczytZlecenia()
{
	string d1,d2,d3,d5,d6,d7,d8,tempString;
	int tempInt;
	StanZlecenia d4;
	char oddzielnik=';';
	char koniec='\n';
	fstream tekst;
	tekst.open("dane//zlecenia.csv");
	while(!tekst.eof())
	{
		getline(tekst,d1,oddzielnik);
		getline(tekst,d2,oddzielnik);
		getline(tekst,d3,oddzielnik);
		getline(tekst,tempString,oddzielnik);
		getline(tekst,d5,oddzielnik);
		getline(tekst,d6,oddzielnik);
		getline(tekst,d7,oddzielnik);
		getline(tekst,d8,oddzielnik);
		tempInt=atoi(tempString.c_str());
		d4=static_cast<StanZlecenia>(tempInt);
		//if(atoi(d1.c_str())!=0)
		{
			Zlecenie z(atoi(d1.c_str()),atoi(d2.c_str()),atoi(d3.c_str()),d4,atof(d5.c_str()),d6,d7,d8);
			listaZlecen.push_back(z);
		}
	}
}


void Zlecenia::SerializujZlecenia()
{
	fstream plik;
	plik.open("dane//zlecenia.csv",std::ios::out);
	for(int i=0;i<listaZlecen.size();i++) 
		plik << listaZlecen[i].getIdZlecenia() << ";" << listaZlecen[i].getIdPracownika() << ";" << listaZlecen[i].getIdKlienta() << ";" << listaZlecen[i].getStanZlecenia() 
		<< ";" << listaZlecen[i].getKoszt() << ";" << listaZlecen[i].getUwagi() << ";" << listaZlecen[i].getDataPrzyjecia() << ";" << listaZlecen[i].getDataWydania();
	cout << "\n\nLista klientow zostala zapisana!" << endl;
	plik.close();
}

void Zlecenia::WyswietlZlecenie()
{
	cout <<"\t\tLISTA ZLECEN" << endl << endl;
	for(int i=0;i<listaZlecen.size();i++)
	{
		listaZlecen[i].wyswietl();
	}
}


void Zlecenia::html_zlecenia()
{
	fstream plik;
	plik.open("html//zlecenia.html",std::ios::out);
	plik<<"<html><head><title>Tabela - Zlecenia</title><link rel='stylesheet' type='text/css' href='style.css' /></head><body>"<<endl;
	plik<<"<h1>Zlecenia:</h1><table>"<<endl;
	plik<<"<tr><td>ID Zlecenia</td><td>ID Pracownika</td><td>ID Klienta</td><td>Stan Zlecenia</td><td>Koszty</td><td>Data Przyjecia</td><td>Data Wydania</td><td>Uwagi</td>"<<endl;
	for(int i=0;i<listaZlecen.size();i++)
	{	
		plik<<"<tr><td>"<< listaZlecen[i].getIdZlecenia() << "</td><td>" << listaZlecen[i].getIdPracownika() << "</td><td>" << listaZlecen[i].getIdKlienta() 
			<< "</td><td>" << listaZlecen[i].getStanZlecenia() << "</td><td>" << listaZlecen[i].getDataPrzyjecia() << "</td><td>" << listaZlecen[i].getDataWydania() 
			<< "</td><td>" << listaZlecen[i].getUwagi() << "</td>" << "</td></tr>" << endl;
	}
	plik<<"</table></body></html>"<<endl;
	plik.close();
	system("html\\zlecenia.html");
}