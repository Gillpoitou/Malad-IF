#include "Attribute.cpp"

#if ! defined ( DOUBLEVAL_H_ )
#define DOUBLEVAL_H_

class DoubleVal : public Valeur
{
	public:

		DoubleVal(double val)
		{
			this->val = new double(val);
		}

		virtual ~DoubleVal()
		{
			;
		}

		void* value()
		{
			return val;
		}

};

#endif // DOUBLEVAL_H_
