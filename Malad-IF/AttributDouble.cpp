#include "AttributDouble.h"


AttributDouble::AttributDouble(string name): Attribut(name)
{}

Valeur* AttributDouble::convert(string val)
{
	double d = stod(val);
	return new DoubleValeur(d);
}

AttributDouble::~AttributDouble()
{}
