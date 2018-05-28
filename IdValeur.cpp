#include "Attribut.h"
#include "IdValeur.h"

IdValeur::IdValeur(unsigned int val)
{
	this->valeur = new unsigned int(val);
}


void* IdValeur::getValeur()
{
	return valeur;
}

IdValeur::~IdValeur()
{}
