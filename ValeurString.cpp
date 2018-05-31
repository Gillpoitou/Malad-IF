#include "ValeurString.h"


ValeurString::ValeurString(string val)
{
	this->valeur = new string(val);
}

ValeurString::~ValeurString()
{}

void* ValeurString::getValeur()
{
	return valeur;
}

void ValeurString::setValeur(void* val){

	*valeur = *(string*)val;
}
