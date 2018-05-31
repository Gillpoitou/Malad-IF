#include "Attribut.h"
#include "ValeurDouble.h"

ValeurDouble::ValeurDouble(double valeur)
{
	this->valeur =  new double(valeur);
}

ValeurDouble::~ValeurDouble()
{}

void* ValeurDouble::getValeur()
{
	return valeur;
}

void ValeurDouble::setValeur(void * val){

	*valeur = *(double*)val;
}
