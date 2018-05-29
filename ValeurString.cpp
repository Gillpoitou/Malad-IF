#include "ValeurString.h"


ValeurString::ValeurString(string val)
{
	this->valeur = new string(val);
}

ValeurString::~ValeurString()
{}

string* ValeurString::getValeur()
{
	return valeur;
}
