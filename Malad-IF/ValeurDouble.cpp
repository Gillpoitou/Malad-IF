#include "Attribut.h"
#include "ValeurDouble.h"

ValeurDouble::ValeurDouble(double valeur)
{
	this->valeur =  new double(valeur);
}

ValeurDouble::~ValeurDouble()
{}

double* ValeurDouble::getValeur()
{
	return valeur;
}
