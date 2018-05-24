#include "Attribute.cpp"

#if ! defined ( IDVAL_H_ )
#define IDVAL_H_


class IdVal : public Valeur
{
	public:

		IdVal(unsigned int val)
		{
			this->val = new unsigned int(val);
		}

		virtual ~IdVal()
		{
			;
		}

		void* value()
		{
			return val;
		}

};

#endif // IDVAL_H_
