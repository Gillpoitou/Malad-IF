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

ValeurDouble* AttributDouble::moyenner(list<Valeur*> valeurs)
{
	double sum = 0;
	for (Valeur* valeur : valeurs)
	{
		ValeurDouble* vi = dynamic_cast<ValeurDouble*>(valeur);
		sum += *(vi->getValeur());
	}

	sum /= valeurs.size();

	return new ValeurDouble(sum); // TODO
}
