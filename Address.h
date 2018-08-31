#ifndef ADDRESS_H
#define ADDRESS_H

#include <iostream>
#include "WCS_String.h"
#include "FixedLengthDigits.h" 
using namespace std;

class Address
{
public:
	Address();
	Address(const Address &);
	Address(const WCS_String &, const WCS_String &, const WCS_String &, const FixedLengthDigits<5> &);
	//								Address	(const char [], const char [], const char []);
	~Address();
	Address &					Copy	(const Address &);
	int						Compare		(const Address &) const;
	///////////////Read / Write////////////////////////////////
	istream			&		Read(istream &);
	ostream			&		Write(ostream &)const;
	///////////////Comparison Operators////////////////////////
	int						operator ==	(const Address &) const;
	int						operator !=	(const Address &) const;

	Address		&			operator =	(const Address & N);

	//////////////Setters and Getters//////////////////////////
	void					SetStreet(const WCS_String &);
	const WCS_String &		GetStreet()const;//const with & pretty much means, they are just looking at the real mona lisa (cant touch).
	void					SetCity(const WCS_String &);
	const WCS_String &		GetCity()const;
	void					SetState(const WCS_String &);
	const WCS_String &		GetState()const;
	void					SetZip(const FixedLengthDigits<5> &);
	const FixedLengthDigits<5> &		GetZip()const;

private:
	WCS_String		Street;
	WCS_String		City;
	WCS_String		State;
	FixedLengthDigits<5>		Zip;

};

inline Address & Address::operator = (const Address & N)
{
	return Copy(N);
}
///////////////Display Operator////////////////////////////

inline ostream & operator << (ostream & out, const Address & N)
{
	N.Write(out);
	return out;
}
inline istream & operator >> (istream & in, Address & N)
{
	N.Read(in);
	return in;
}

inline istream			&		Address::Read(istream & in)
{
	in >> Street >> City >> State >> Zip;
	return in;
}
inline ostream			&		Address::Write(ostream & out) const // also output operator
{
	out << Street << " " << City << " " << State << " " << Zip;
	return out;
}
inline int Address::operator == (const Address & N) const
{
	return Compare(N) == 0;
}
inline int Address::operator != (const Address & N) const
{
	return Compare(N) != 0;
}

#endif
