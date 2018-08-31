#include "Name.h"
#include<iostream>
using namespace std;

Name::Name()
{	// the default constructors for First, Middle, and Last are automatically called
}	// these constructors are called before anything else in this method is done

Name::Name(const Name & N) : Last(N.Last), First(N.First), Middle(N.Middle)
{
}

Name::Name(const WCS_String & F, const WCS_String & M, const WCS_String & L) : Middle(M), First(F), Last(L)
{
	//	First	= F;
	//	Middle	= M;
	//	Last	= L;
}

Name::~Name()
{	// destructor automatically calls the destructor for First, Middle, Last
}	// these destructors are called after anything written inside this destructor

Name & Name::Copy(const Name & N)
{
	First.Copy(N.First);
	Middle.Copy(N.Middle);
	Last.Copy(N.Last);
	return *this;
}

int Name::Compare(const Name & N) const
{
	int		Result;

	if ((Result = Last.Compare(N.Last)) == 0)
	if ((Result = First.Compare(N.First)) == 0)
		Result = Middle.Compare(N.Middle);
	else;
	else;
	return Result;
}

void	Name::SetFirstName(const WCS_String & N)
{
 
	First = N;
}
const	WCS_String &		Name::GetFirstName()const
{

	return First;
}
void					Name::SetMiddleName(const WCS_String & N)
{
 
	Middle = N;
}
const WCS_String &		Name::GetMiddleName()const
{

	return Middle;
}
void					Name::SetLastName(const WCS_String & N)
{

	Last = N;
}
const WCS_String &		Name::GetLastName()const
{

	return Last;
}
