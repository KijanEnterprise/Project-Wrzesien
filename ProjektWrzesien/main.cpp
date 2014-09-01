#include "Czlowiek.h"
#include "Const.h"
#include "Pracownik.h"
#include "Klient.h"
#include "Sprzet.h"
#include "Zlecenie.h"

void DeserializujSprzet(vector<Sprzet> &Sprzety)
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
			Sprzety.push_back(sprzet);
		
	}
	plik.close();
}

void DeserializujPracownicy(vector<Pracownik> &Pracownicy) 
{
	string dana0,dana1,dana2,dana3,dana4,dana5,dana6,dana7,dana8;
	char separator = ';';
	char konieclini = '\n';
	time_t czas;
	tm *data;
	fstream plik;
	plik.open("dane//pracownicy.csv");
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
			Pracownicy.push_back(pracownik);
		}
	}
	plik.close();
}

void DeserializujKlienci(vector<Klient> &Klienci)
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
			Klienci.push_back(klient);
		}
	}
	plik.close();
}

void OdczytZlecenia(vector<Zlecenie>&Zlecenia)
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
			Zlecenia.push_back(z);
		}
	}
}



void SerializujPracownicy(vector<Pracownik> &Pracownicy)
{
	fstream plik;
	plik.open("dane//pracownicy.csv",std::ios::out);
	for(int i=0;i<Pracownicy.size();i++) 
		plik << Pracownicy[i].getId() << ";" << Pracownicy[i].getImie() << ";" << Pracownicy[i].getNazwisko() << ";" 
		<< Pracownicy[i].getTelefon() << ";" << Pracownicy[i].getEmail() << ";" << Pracownicy[i].getAdres() << ";" 
		<< Pracownicy[i].getWyplata() << ";" << Pracownicy[i].getNrRachunku() <<  ";" << mktime(&Pracownicy[i].getDataZatrudnienia());
	cout << "\n\nLista pracownikow zostala zapisana!" << endl;
	plik.close();
}

void SerializujKlienci(vector<Klient> &Klienci)
{
	fstream plik;
	plik.open("dane//klienci.csv",std::ios::out);
	for(int i=0;i<Klienci.size();i++) 
		plik << Klienci[i].getId() << ";" << Klienci[i].getImie() << ";" << Klienci[i].getNazwisko() << ";" << Klienci[i].getTelefon() 
		<< ";" << Klienci[i].getEmail() << ";" << Klienci[i].getAdres();
	cout << "\n\nLista klientow zostala zapisana!" << endl;
	plik.close();
}

void SerializujSprzet(vector<Sprzet> &Sprzety)
{
	fstream plik;
	plik.open("dane//sprzet.csv",std::ios::out);
	for(int i=0;i<Sprzety.size();i++) 
		plik << Sprzety[i].getProducent() << ";" << Sprzety[i].getModel()<< ";"<< Sprzety[i].getRodzaj() << ";"<< Sprzety[i].getOpis();
	cout << "\n\nLista sprzetu zostala zapisana!" << endl;
	plik.close();
}

void SerializujZlecenia(vector<Zlecenie> &Zlecenia)
{
	fstream plik;
	plik.open("dane//zlecenia.csv",std::ios::out);
	for(int i=0;i<Zlecenia.size();i++) 
		plik << Zlecenia[i].getIdZlecenia() << ";" << Zlecenia[i].getIdPracownika() << ";" << Zlecenia[i].getIdKlienta() << ";" << Zlecenia[i].getStanZlecenia() 
		<< ";" << Zlecenia[i].getKoszt() << ";" << Zlecenia[i].getUwagi() << ";" << Zlecenia[i].getDataPrzyjecia() << ";" << Zlecenia[i].getDataWydania();
	cout << "\n\nLista klientow zostala zapisana!" << endl;
	plik.close();
}

void WyswietlSprzet(vector<Sprzet> &Sprzety)
{
	cout <<"\t\tLISTA SPRZETU" << endl << endl;
	for(int i=0;i<Sprzety.size();i++)
	{
		Sprzety[i].wyswietl();
	}
}

void WyswietlPracownicy(vector<Pracownik> &Pracownicy)
{
	cout <<"\t\tLISTA PRACOWNIKOW" << endl << endl;
	for(int i=0;i<Pracownicy.size();i++)
	{
		Pracownicy[i].wyswietl();
	}
}

void WyswietlZlecenie(vector<Zlecenie> &Zlecenia)
{
	cout <<"\t\tLISTA ZLECEN" << endl << endl;
	for(int i=0;i<Zlecenia.size();i++)
	{
		Zlecenia[i].wyswietl();
	}
}

void WyswietlKlienci(vector<Klient> &Klienci)
{
	cout <<"\t\tLISTA KLIENTOW" << endl << endl;
	for(int i=0;i<Klienci.size();i++)
	{
		Klienci[i].wyswietl();
	}
}

void html_pracownicy(vector<Pracownik> &Pracownicy)
{
	fstream plik;
	plik.open("html//pracownicy.html",std::ios::out);
	plik<<"<html><head><title>Tabela - Pracownicy</title><link rel='stylesheet' type='text/css' href='style.css' /></head><body>"<<endl;
	plik<<"<h1>Pracownicy:</h1><table>"<<endl;
	plik<<"<tr><td>Lp.</td><td>ID</td><td>Imie</td><td>Nazwisko</td><td>Nr telefonu</td><td>Email</td><td>Adres</td><td>Wyplata</td>" 
		<<"<td>Nr rachunku</td><td>Data zatrudnienia</td></tr>"<<endl;
	for(int i=0;i<Pracownicy.size();i++)
	{	
		char bufor[64];
		strftime(bufor,sizeof(bufor),"%d-%m-%Y",&Pracownicy[i].getDataZatrudnienia());
		plik<<"<tr><td>"<< i+1 <<"</td><td>"<< Pracownicy[i].getId() << "</td><td>" << Pracownicy[i].getImie() << "</td><td>" 
			<< Pracownicy[i].getNazwisko() << "</td><td>" << Pracownicy[i].getTelefon() << "</td><td>" << Pracownicy[i].getEmail() 
			<< "</td><td>" << Pracownicy[i].getAdres() << "</td><td>" << Pracownicy[i].getWyplata() << "</td><td>" 
			<< Pracownicy[i].getNrRachunku() <<  "</td><td>" << bufor << "</td></tr>"<<endl;
	}
	plik<<"</table></body></html>"<<endl;
	plik.close();
	system("html\\pracownicy.html");
}

void html_klienci(vector<Klient> &Klienci)
{
	fstream plik;
	plik.open("html//klienci.html",std::ios::out);
	plik<<"<html><head><title>Tabela - Klienci</title><link rel='stylesheet' type='text/css' href='style.css' /></head><body>"<<endl;
	plik<<"<h1>Klienci:</h1><table>"<<endl;
	plik<<"<tr><td>Lp.</td><td>ID</td><td>Imie</td><td>Nazwisko</td><td>Nr telefonu</td><td>Email</td><td>Adres</td></tr>"<<endl;
	for(int i=0;i<Klienci.size();i++){	
		plik<<"<tr><td>"<< i+1 <<"</td><td>"<< Klienci[i].getId() << "</td><td>" << Klienci[i].getImie() << "</td><td>" 
			<< Klienci[i].getNazwisko() << "</td><td>" << Klienci[i].getTelefon() << "</td><td>" << Klienci[i].getEmail() 
			<< "</td><td>" << Klienci[i].getAdres() << "</td></tr>" << endl;
	}
	plik<<"</table></body></html>"<<endl;
	plik.close();
	system("html\\klienci.html");
}

void html_sprzet(vector<Sprzet> &Sprzety)
{
	fstream plik;
	plik.open("html//sprzet.html",std::ios::out);
	plik<<"<html><head><title>Tabela - Sprzetu</title><link rel='stylesheet' type='text/css' href='style.css' /></head><body>"<<endl;
	plik<<"<h1>Sprzet:</h1><table>"<<endl;
	plik<<"<tr><td>Producent</td><td>Model</td><td>Rodzaj sprzetu</td><td>Opis</td>"<<endl;
	for(int i=0;i<Sprzety.size();i++)
	{	
		plik<<"<tr><td>"<< Sprzety[i].getProducent() << "</td><td>" << Sprzety[i].getModel() << "</td><td>" << Sprzety[i].rodzajNaString() 
			<< "</td><td>" << Sprzety[i].getOpis() << "</td></tr>"<<endl;
	}
	plik<<"</table></body></html>"<<endl;
	plik.close();
	system("html\\sprzet.html");
}

void html_zlecenia(vector<Zlecenie> &Zlecenia)
{
	fstream plik;
	plik.open("html//zlecenia.html",std::ios::out);
	plik<<"<html><head><title>Tabela - Zlecenia</title><link rel='stylesheet' type='text/css' href='style.css' /></head><body>"<<endl;
	plik<<"<h1>Zlecenia:</h1><table>"<<endl;
	plik<<"<tr><td>ID Zlecenia</td><td>ID Pracownika</td><td>ID Klienta</td><td>Stan Zlecenia</td><td>Koszty</td><td>Data Przyjecia</td><td>Data Wydania</td><td>Uwagi</td>"<<endl;
	for(int i=0;i<Zlecenia.size();i++)
	{	
		plik<<"<tr><td>"<< Zlecenia[i].getIdZlecenia() << "</td><td>" << Zlecenia[i].getIdPracownika() << "</td><td>" << Zlecenia[i].getIdKlienta() 
			<< "</td><td>" << Zlecenia[i].getStanZlecenia() << "</td><td>" << Zlecenia[i].getDataPrzyjecia() << "</td><td>" << Zlecenia[i].getDataWydania() 
			<< "</td><td>" << Zlecenia[i].getUwagi() << "</td></tr>"<<endl;
	}
	plik<<"</table></body></html>"<<endl;
	plik.close();
	system("html\\zlecenia.html");
}



int main()
{
	try
	{
		vector<Klient> Klienci;
		vector<Pracownik> Pracownicy;
		vector<Sprzet> Sprzety;
		vector<Zlecenie> Zlecenia;
		
		
		cout << "\tPROJEKT Wykonany przez Kijan Enterpeises!\n\n\n" << endl;
		DeserializujPracownicy(Pracownicy);
		DeserializujKlienci(Klienci);
		DeserializujSprzet(Sprzety);
		OdczytZlecenia(Zlecenia);

		WyswietlPracownicy(Pracownicy);
		cout << endl << endl;
		WyswietlKlienci(Klienci);
		cout << endl << endl;
		WyswietlSprzet(Sprzety);
		cout << endl << endl;
		WyswietlZlecenie(Zlecenia);

		SerializujPracownicy(Pracownicy);
		SerializujKlienci(Klienci);
		SerializujSprzet(Sprzety);
		SerializujZlecenia(Zlecenia);

		//html_pracownicy(Pracownicy);  //dziala ale komentuje zeby sie za kazdym razem przy uruchamianiu nie robilo to ;)
		//html_klienci(Klienci);
		//html_sprzet(Sprzety);
		html_zlecenia(Zlecenia);

	} catch(Error &E)
	{
		E.getWiadomosc();
	}
	cin.get();

}