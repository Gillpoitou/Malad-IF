
#include <string>

#include "Attribute.cpp"
#include "DoubleValeur.cpp"

using namespace std;


#if ! defined ( DOUBLE_H_ )
#define DOUBLE_H_

class Double : public Attribut
{
	public:

		Double(string name): Attribut(name)
		{
			;
		}

		Valeur* convert(string val)
		{
			double d = stod(val);
			return new DoubleVal(d);
		}

		virtual ~Double()
		{
			;
		}
};

#endif // DOUBLE_H_

