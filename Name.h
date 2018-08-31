#ifndef NAME_H
#define NAME_H

#include <iostream>

using namespace std;

#include "WCS_String.h"

class Name
{
public:
	Name();
	Name(const Name &);
	Name(const WCS_String &, const WCS_String &, const WCS_String &);
	//								Name	(const char [], const char [], const char []);
	~Name();
	Name &					Copy		(const Name &);
	int						Compare		(const Name &) const;
	///////////////Read / Write////////////////////////////////
	istream			&		Read		(istream &);
	ostream			&		Write		(ostream &)const;
	///////////////Comparison Operators////////////////////////
	int						operator ==	(const Name &) const;
	int						operator !=	(const Name &) const;
	Name		&			operator =	(const Name & N);

				bool			operator <				(const Name &)	const	throw ();
				bool			operator <=				(const Name &)	const	throw ();
				bool			operator >=				(const Name &)	const	throw ();
				bool			operator >				(const Name &)	const	throw ();
				





	///////////////////////////////////////////////////////////
				void					SetFirstName		(const WCS_String &);
				const WCS_String &		GetFirstName		()const;//const with & pretty much means, they are just looking at the real mona lisa (cant touch).
				void					SetMiddleName		(const WCS_String &);
				const WCS_String &		GetMiddleName		()const;
				void					SetLastName			(const WCS_String &);
				const WCS_String &		GetLastName			()const;
				bool					ifEOF				()const;



private:
	WCS_String		First;
	WCS_String		Middle;
	WCS_String		Last;
};

///////////////Display Operator////////////////////////////
ostream				&	operator << (ostream &, const Name &);

inline ostream & operator << (ostream & out, const Name & N)
{
	N.Write(out);
	return out;
}

istream			&	operator >> (istream &, Name &);

inline istream & operator >> (istream & in, Name & N)
{
	N.Read(in);
	return in;
}

inline int Name::operator == (const Name & N) const
{
	return Compare(N) == 0;
}

inline Name & Name::operator = (const Name & N)
{
	return Copy(N);
}
inline int Name::operator != (const Name & N) const
{
	return Compare(N) != 0;
}
inline istream		&			Name::Read(istream & in)
{
	in >> First;
	if(First == "EOF")
		{return in;} 
	in >> Middle >> Last;
	return in;
	//istream and ostream returns as reference
}

inline bool Name::ifEOF() const
{
	return First == "EOF";
}

inline ostream	&				Name::Write(ostream & out) const // also output operator
{
	out << First << " " << Middle << " " << Last;
	return out;
}


inline bool Name::operator <	(const Name & M) const
	{
	return Compare (M) < 0;
	}




inline bool Name::operator <=	(const Name & M) const
	{
	return Compare (M) <= 0;
	}


inline bool Name::operator >=	(const Name & M) const
	{
	return Compare (M) >= 0;
	}


inline bool Name::operator >	(const Name & M) const
	{
	return Compare (M) > 0;
	}





#endif