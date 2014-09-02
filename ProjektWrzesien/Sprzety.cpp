#include "Sprzety.h"

Sprzety::Sprzety()
{
	
}

void Sprzety::Dodaj()
{
	string producent, model, opis;
	int temp;
	TypSprzetu rodzaj;
	cout<<"\t\tOkno dodawania nowego Sprzetu\n\n";
	cout<<"Podaj producenta: ";
	cin>>producent;
	cout<<"\nPodaj model: ";
	cin>>model;
	cout<<"\nRodzaje sprzetu:\nPlytaGlowna=0,\nProcesor=1,\nPamiecRAM=2,\nDyskTwardy=3,\nKartaGraficzna=4,\nKartaDzwiekowa=5,\nKartaSieciowa=6,\nNaped=7,\nZasilacz=8"
		<< "\nMyszka=9,\nKlawiatura=10,\nKameraInternetowa=11,\nSluchawki=12,\nGlosniki=13,\nNieSprecyzowano=14.";
	cout<<"\n\n\nPodaj rodzaj sprzetu: ";
	cin>> temp;
	cout<<"\nPodaj opis sprzetu: ";
	cin>>opis;

	rodzaj=static_cast<TypSprzetu>(temp);
	Sprzet obiekt(producent,model,rodzaj,opis);
	listaSprzetow.push_back(obiekt);
}



void Sprzety::Deserializuj()
{
	string dana0,dana1,dana3,dana5;
	int dana4;
	TypSprzetu dana2;
	char separator=';';
	char konieclini='\n';
	fstream plik;
	plik.open("dane//sprzet.csv");
	if(plik!=0)
	{
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
	}else 
		throw Error("Brak pliku sprzetu!");
	plik.close();
}

void Sprzety::Serializuj()
{
	fstream plik;
	plik.open("dane//sprzet.csv",std::ios::out);
	plik.clear();
	for(int i=0;i<listaSprzetow.size();i++) 
		plik << endl << listaSprzetow[i].getProducent() << ";" << listaSprzetow[i].getModel()<< ";"<< listaSprzetow[i].getRodzaj() << ";"<< listaSprzetow[i].getOpis();
	cout << "Lista sprzetu zostala zapisana!\n";
	plik.close();
}

void Sprzety::Wyswietl()
{
	cout <<"\t\tLISTA SPRZETU" << endl << endl;
	for(int i=0;i<listaSprzetow.size();i++)
	{
		listaSprzetow[i].wyswietl();
	}
}

void Sprzety::html()
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