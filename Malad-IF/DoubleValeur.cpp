#include "Attribut.h"
#include "DoubleValeur.h"

DoubleValeur::DoubleValeur(double valeur)
{
	this->valeur = new double(valeur);
}

DoubleValeur::~DoubleValeur()
{}

void* DoubleValeur::getValeur()
{
	return valeur;
}
