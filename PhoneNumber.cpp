#include "PhoneNumber.h"

PhoneNumber::PhoneNumber()
{
}


PhoneNumber::PhoneNumber(const PhoneNumber & s)
{
}

PhoneNumber::~PhoneNumber()
{
}

PhoneNumber &  PhoneNumber::Copy(const PhoneNumber & Y)
{
	AreaCode.Copy(Y.AreaCode);
	DigitNumber.Copy(Y.DigitNumber);
	return * this; 
}

void PhoneNumber:: Read	(istream & in)
{
	AreaCode.Read(in);
	DigitNumber.Read(in);
}

ostream & PhoneNumber:: Display (ostream & out)
{
	AreaCode.Display(out);
	DigitNumber.Display(out); 
	return out; 
}


