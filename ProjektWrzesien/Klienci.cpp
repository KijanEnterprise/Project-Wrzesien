#include "Klienci.h"

void Klienci::DeserializujKlienci()
{
	string dana0,dana1,dana2,dana3,dana4,dana5;
	char separator = ';';
	char konieclini = '\n';
	fstream plik;
	plik.open("dane//klienci.csv");

	while (!plik.eof())
	{		
		getline(plik,dana0,separator);
		getline(plik,dana1,separator);
		getline(plik,dana2,separator);
		getline(plik,dana3,separator);
		getline(plik,dana4,separator);
		getline(plik,dana5,konieclini);
		if(atoi(dana0.c_str())!=0){
			Klient klient(atoi(dana0.c_str()),dana1,dana2,dana3,dana4,dana5);
			listaKlientow.push_back(klient);
		}
	}
	plik.close();
}

void Klienci::SerializujKlienci()
{
	fstream plik;
	plik.open("dane//klienci.csv",std::ios::out);
	for(int i=0;i<listaKlientow.size();i++) 
		plik << listaKlientow[i].getId() << ";" << listaKlientow[i].getImie() << ";" << listaKlientow[i].getNazwisko() << ";" << listaKlientow[i].getTelefon() 
		<< ";" << listaKlientow[i].getEmail() << ";" << listaKlientow[i].getAdres();
	cout << "\n\nLista klientow zostala zapisana!" << endl;
	plik.close();
}

void Klienci::WyswietlKlienci()
{
	cout <<"\t\tLISTA KLIENTOW" << endl << endl;
	for(int i=0;i<listaKlientow.size();i++)
	{
		listaKlientow[i].wyswietl();
	}
}

void Klienci::html_klienci()
{
	fstream plik;
	plik.open("html//klienci.html",std::ios::out);
	plik<<"<html><head><title>Tabela - Klienci</title><link rel='stylesheet' type='text/css' href='style.css' /></head><body>"<<endl;
	plik<<"<h1>Klienci:</h1><table>"<<endl;
	plik<<"<tr><td>Lp.</td><td>ID</td><td>Imie</td><td>Nazwisko</td><td>Nr telefonu</td><td>Email</td><td>Adres</td></tr>"<<endl;
	for(int i=0;i<listaKlientow.size();i++){	
		plik<<"<tr><td>"<< i+1 <<"</td><td>"<< listaKlientow[i].getId() << "</td><td>" << listaKlientow[i].getImie() << "</td><td>" 
			<< listaKlientow[i].getNazwisko() << "</td><td>" << listaKlientow[i].getTelefon() << "</td><td>" << listaKlientow[i].getEmail() 
			<< "</td><td>" << listaKlientow[i].getAdres() << "</td></tr>" << endl;
	}
	plik<<"</table></body></html>"<<endl;
	plik.close();
	system("html\\klienci.html");
}