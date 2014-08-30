#include "Error.h"

Error::Error(string _wiadomosc):wiadomosc(_wiadomosc)
{}

string Error::getWiadomosc()
{
	return wiadomosc;
}