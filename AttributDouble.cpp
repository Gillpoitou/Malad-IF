#include "AttributDouble.h"


AttributDouble::AttributDouble(string name): Attribut(name)
{}

Valeur* AttributDouble::creerValeur(string val)
{
	double d = stod(val);
	return new DoubleValeur(d);
}

AttributDouble::~AttributDouble()
{}
