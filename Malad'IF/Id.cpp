
#include <string>

#include "Attribute.cpp"
#include "IdValeur.cpp"

using namespace std;


#if ! defined ( ID_H_ )
#define ID_H_

class Id : public Attribut
{
	public:

		Id(string name): Attribut(name)
		{
			;
		}

		Valeur* convert(string val)
		{
			unsigned int i = stoi(val);
			return new IdVal(i);
		}

		virtual ~Id()
		{
			;
		}
};

#endif // ID_H_

