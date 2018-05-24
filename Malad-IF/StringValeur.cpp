#include "StringValeur.h"


StringValeur::StringValeur(string val)
{
	this->valeur = new string(val);
}

StringValeur::~StringValeur()
{}

void* StringValeur::getValeur()
{
	return valeur;
}
