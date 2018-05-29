#include "AttributDouble.h"
#include "ValeurDouble.h"

AttributDouble::AttributDouble(string name): Attribut(name)
{}

Valeur* AttributDouble::creerValeur(string val)
{
	double d = stod(val);
	return new ValeurDouble(d);
}

AttributDouble::~AttributDouble()
{}
