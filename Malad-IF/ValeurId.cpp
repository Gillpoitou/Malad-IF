#include "ValeurId.h"

#include "Attribut.h"

ValeurId::ValeurId(unsigned int val)
{
	this->valeur = new unsigned int(val);
}


void* ValeurId::getValeur()
{
	return valeur;
}

ValeurId::~ValeurId()
{}

void ValeurId::setValeur(void* val){

	*valeur = *(int*)val;
}
