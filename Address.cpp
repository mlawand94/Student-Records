#include "Address.h"


Address::Address()
{	// the default constructors for First, Middle, and Last are automatically called
}	// these constructors are called before anything else in this method is done

Address::Address(const Address & N) : Street(N.Street), City(N.City), State(N.State), Zip(N.Zip)
{
}

Address::Address(const WCS_String & S, const WCS_String & C, const WCS_String & s, const FixedLengthDigits<5> & Z) : Street(S), City(C), State(s), Zip(Z)
{
	//	Street	= S;
	//	City	= C;
	//	State	= s;
	//	Zip		= Z;
}

Address::~Address()
{	// destructor automatically calls the destructor for First, Middle, Last
}	// these destructors are called after anything written inside this destructor


Address & Address::Copy(const Address & N)
{
	Street.Copy(N.Street);
	City.Copy(N.City);
	State.Copy(N.State);
	Zip.Copy(N.Zip);
	return *this;
}

int Address::Compare(const Address & N) const
{
	int		Result;

	if ((Result = Street.Compare(N.Street)) == 0)
	if ((Result = City.Compare(N.City)) == 0)
	if ((Result = State.Compare(N.State)) == 0)
	if ((Result = Zip.Compare(N.Zip)) == 0)
		return Result;
	else;
	else;
	else;	
	else;
	return Result;
}

void	Address::SetStreet(const WCS_String & N)
{
	Street = N;
}
const	WCS_String &		Address::GetStreet()const
{
	return Street;
}
void	Address::SetCity(const WCS_String & N)
{
	City = N;
}
const	WCS_String &		Address::GetCity() const
{
	return City;
}
void	Address::SetState(const WCS_String & N)
{
	State = N;
}
const	WCS_String &		Address::GetState()const
{
	return State;
}
void	Address::SetZip(const FixedLengthDigits<5> & N)
{
	Zip = N;
}
const	FixedLengthDigits<5> & Address::GetZip()const
{
	return Zip;
}


