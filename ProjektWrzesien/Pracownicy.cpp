#include "Pracownicy.h"

void Pracownicy::Wyszukaj (string nazwisko)
{
	bool znaleziona=false;
	vector <Pracownik> ::iterator t;
	int j=0;
	for(t=listaPracownikow.begin();t!=listaPracownikow.end();t++)
	{
		if (nazwisko == t->getNazwisko())
		{
			t->wyswietl();
			znaleziona=true;
		} 
	}
	if(znaleziona==false)
		cout << "Nie znaleziono pracownika!";
}

void Pracownicy::Usun(int i)
{
	bool znaleziona=false;
	vector <Pracownik> ::iterator t;
	int j=0;
	for(t=listaPracownikow.begin();t!=listaPracownikow.end();t++)
	{
		if (i == t->getId())
		{
			listaPracownikow[j]=listaPracownikow[listaPracownikow.size()-1];
			listaPracownikow.pop_back();
			znaleziona=true;
		} else
			j++;
	}
	if(znaleziona==false)
		cout << "Podano bledne ID pracownika!";
}

void Pracownicy::Dodaj()
{
	int ID;
	string imie,nazwisko,telefon,email,adres,rachunek;
	float wyplata;
	tm *data;
	cout<<"\t\tOkno dodawania nowego klienta\n\n";
	cout<<"Podaj ID: ";
	cin>>ID;
	cout<<"\nPodaj imie: ";
	cin>>imie;
	cout<<"\nPodaj nazwisko: ";
	cin>>nazwisko;
	cout<<"\nPodaj telefon: ";
	cin>>telefon;
	cout<<"\nPodaj email: ";
	cin>>email;
	cout<<"\nPodaj adres: ";
	cin>>adres;
	cout<<"\nPodaj wysokosc wyplaty: ";
	cin>>wyplata;
	cout<<"\nPodaj nr rachunku: ";
	cin>>rachunek;
	cout<<"\Podaj date zatrudnienia: ";
	//cin>>data;


	Pracownik obiekt(ID,imie,nazwisko,telefon,email,adres,wyplata,rachunek,data);
	listaPracownikow.push_back(obiekt);
}


Pracownik Pracownicy::getPracownik(int i)
{
	vector <Pracownik> ::iterator t;
	int licznik;
	for(t=listaPracownikow.begin();t!=listaPracownikow.end();t++)
	{
		if (i == t->getId())
			return *t;
		licznik++;
	}cout << "Bledne ID pracownika";
}


void Pracownicy::Deserializuj() 
{
	string dana0,dana1,dana2,dana3,dana4,dana5,dana6,dana7,dana8;
	char separator = ';';
	char konieclini = '\n';
	time_t czas;
	tm *data;
	fstream plik;
	plik.open("dane//pracownicy.csv");
	if(plik!=0)
	{
		while (!plik.eof())
		{
			getline(plik,dana0,separator);
			getline(plik,dana1,separator);
			getline(plik,dana2,separator);
			getline(plik,dana3,separator);
			getline(plik,dana4,separator);
			getline(plik,dana5,separator);
			getline(plik,dana6,separator);
			getline(plik,dana7,separator);
			getline(plik,dana8,konieclini);
			czas=atoi(dana8.c_str());
			if(atoi(dana0.c_str())!=0)
			{
				Pracownik pracownik(atoi(dana0.c_str()),dana1,dana2,dana3,dana4,dana5,atof(dana6.c_str()),dana7,gmtime(&czas));
				listaPracownikow.push_back(pracownik);
			}
		} 
	}else
		throw Error("Brak pliku pracownikow!");

	plik.close();
}

void Pracownicy::Serializuj()
{
	fstream plik;
	plik.open("dane//pracownicy.csv",std::ios::out);
	for(int i=0;i<listaPracownikow.size();i++) 
		plik << endl << listaPracownikow[i].getId() << ";" << listaPracownikow[i].getImie() << ";" << listaPracownikow[i].getNazwisko() << ";" 
		<< listaPracownikow[i].getTelefon() << ";" << listaPracownikow[i].getEmail() << ";" << listaPracownikow[i].getAdres() << ";" 
		<< listaPracownikow[i].getWyplata() << ";" << listaPracownikow[i].getNrRachunku() <<  ";" << mktime(&listaPracownikow[i].getDataZatrudnienia());
	cout << "Lista pracownikow zostala zapisana!\n" << endl;
	plik.close();
}

void Pracownicy::Wyswietl()
{
	cout <<"\t\tLISTA PRACOWNIKOW" << endl << endl;
	for(int i=0;i<listaPracownikow.size();i++)
	{
		listaPracownikow[i].wyswietl();
	}
}


void Pracownicy::html()
{
	fstream plik;
	plik.open("html//pracownicy.html",std::ios::out);
	plik<<"<html><head><title>Tabela - Pracownicy</title><link rel='stylesheet' type='text/css' href='style.css' /></head><body>"<<endl;
	plik<<"<h1>Pracownicy:</h1><table>"<<endl;
	plik<<"<tr><td>Lp.</td><td>ID</td><td>Imie</td><td>Nazwisko</td><td>Nr telefonu</td><td>Email</td><td>Adres</td><td>Wyplata</td>" 
		<<"<td>Nr rachunku</td><td>Data zatrudnienia</td></tr>"<<endl;
	for(int i=0;i<listaPracownikow.size();i++)
	{	
		char bufor[64];
		strftime(bufor,sizeof(bufor),"%d-%m-%Y",&listaPracownikow[i].getDataZatrudnienia());
		plik<<"<tr><td>"<< i+1 <<"</td><td>"<< listaPracownikow[i].getId() << "</td><td>" << listaPracownikow[i].getImie() << "</td><td>" 
			<< listaPracownikow[i].getNazwisko() << "</td><td>" << listaPracownikow[i].getTelefon() << "</td><td>" << listaPracownikow[i].getEmail() 
			<< "</td><td>" << listaPracownikow[i].getAdres() << "</td><td>" << listaPracownikow[i].getWyplata() << "</td><td>" 
			<< listaPracownikow[i].getNrRachunku() <<  "</td><td>" << bufor << "</td></tr>"<<endl;
	}
	plik<<"</table></body></html>"<<endl;
	plik.close();
	system("html\\pracownicy.html");
}