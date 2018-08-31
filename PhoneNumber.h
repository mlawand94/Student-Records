#ifndef PHONE_NUMBER_H
#define PHONE_NUMBER_H
#include <iostream> 
#include "FixedLengthDigits.h" 

using namespace std;

class PhoneNumber

{
public:
					PhoneNumber			();
					PhoneNumber			(const PhoneNumber &);
					~PhoneNumber		(); 
	void			Read				(istream &);
	ostream &		Display				(ostream &);
	int				Compare				(const PhoneNumber &);
	PhoneNumber &	Copy				(const PhoneNumber &);

private:

FixedLengthDigits<3>				AreaCode;
FixedLengthDigits<7>				DigitNumber;

};



#endif;