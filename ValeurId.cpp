#include "ValeurId.h"

#include "Attribut.h"

ValeurId::ValeurId(unsigned int val)
{
	this->valeur = new unsigned int(val);
}


unsigned int* ValeurId::getValeur()
{
	return valeur;
}

ValeurId::~ValeurId()
{}
