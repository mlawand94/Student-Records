#ifndef FIXED_LENGTH
#define FIXED_LENGTH
#include <iostream>
using namespace std; 

// in fixed length and fixed digit length need  read, display, getAt, compare, equal operator, copy
// dont need to repeat compare, getAt, display in fixedLengthdigits ?

template<int T>
class FixedLength
{
public:
							FixedLength			();
							FixedLength			(const FixedLength<T> &);
							~FixedLength		();
	void					Read				(istream &);
	ostream &				Display				(ostream &);
	bool					IsDigit				();
	int						Compare				(const FixedLength<T> &);
	FixedLength<T> &		Copy				(const FixedLength<T> &);
	FixedLength<T> &		operator =			(const FixedLength<T> &); 	
	ostream	&				 Write				(ostream &) const;

private:
	
	char  L[T+1];

};

template<int T>
FixedLength<T>:: FixedLength()
{
	L[T] = '\0'; 
}

template<int T>
FixedLength<T>::FixedLength(const FixedLength<T> & F)
{
	strcpy (F.L , L);
}

template<int T>
FixedLength<T>:: ~FixedLength()
{
}


template<int T>
void FixedLength<T>:: Read(istream & in)
{
	for(int i=0; i <= T; i++)
	{
		L[i]=in.get();
		/*
		if (isspace (L[i]))
		{
			i--;
		}
		else; 
		*/
	}
	
	L[T] = '\0';
	
}

template<int T>
ostream & FixedLength<T>:: Display(ostream & out)
{
	for (int i=0; i < T; i++)
	{
		out << L[i];  
	}
	return out;
}


template <int T>
bool FixedLength<T>::IsDigit()
{
	for (int x = 0; L[x] != '\0'; x++)
	{
		if (isdigit(L[x]))
		{
		}
		else
		{
			return false;
		}

	}
	return true;
}

template<int T>
int FixedLength<T>:: Compare(const FixedLength<T> & I)
{
	int		Result;

	if ((Result = ID.Compare(I.ID)) == 0)
	else;
	return Result;
}

template <int T>
FixedLength<T> & FixedLength<T>:: Copy(const FixedLength<T> & F)
{
	memcpy(L,F.L,T+1);
	return * this;
}


template<int T>
FixedLength<T> & FixedLength<T>:: operator = (const FixedLength<T> & F)
{
	memcpy(L,F.L,T+1);
	return * this;
}

template<int T>
ostream & operator << (ostream & out, const FixedLength<T> & N)
{
	N.Write(out);
	return out;
}

template <int T>
istream &	operator >> (istream & in,FixedLength<T> & N)
{
	N.Read(in);
	return in;
}

template <int T>
ostream	& FixedLength<T>::Write(ostream & out) const // also output operator
{
	out << L;
	return out;
}



#endif