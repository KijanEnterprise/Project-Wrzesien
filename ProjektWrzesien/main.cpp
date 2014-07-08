#include "Czlowiek.h"
#include "Const.h"
#include "Pracownik.h"
#include "Klient.h"
#include "Sprzet.h"
#include "Zlecenie.h"

class dat2
{
public:
	tm *pole;
	dat2(tm *_pole)
	{
	   pole=_pole;
	};
};
int main()
{
	vector<Klient> Klienci;
	vector<Pracownik> Pracownicy;
	cout << "TEST 0.000001e" << endl;
	
	//////testing
	time_t czas;
	time(&czas);

	
	
	//Pracownik prac(1,"imie","nawzisko","222","1@2","aa",22,"1231231",gmtime(&czas));
	//cout << prac.getDataZatrudnienia().tm_min;
	//////testing
	cin.get();
}