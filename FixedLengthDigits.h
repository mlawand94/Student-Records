#ifndef FIXED_LENGTH_DIGITS
#define FIXED_LENGTH_DIGITS
#include "FixedLength.h"

template <int T>
class FixedLengthDigits: public FixedLength<T>
{
public:
	enum		Exceptions	{Non_Digit_Error};

								FixedLengthDigits	();
								FixedLengthDigits	(const FixedLengthDigits<T> &);
								~FixedLengthDigits	();
	void						Read				(istream &)					throw(...);
	ostream &					Display				(ostream &);
	int							Compare				(const FixedLengthDigits<T> &) const;
	FixedLengthDigits<T> &		Copy				(const FixedLengthDigits<T> &);
	FixedLengthDigits<T> &		operator =			(const FixedLengthDigits<T> &);

private:
	
};

template <int T>
FixedLengthDigits<T>::FixedLengthDigits()
{
}

template<int T>
FixedLengthDigits<T>::FixedLengthDigits(const FixedLengthDigits<T> & F)
{
	//strcpy (F.L , L);
}


template <int T>
FixedLengthDigits<T>::~FixedLengthDigits()
{
}

template <int T>
void FixedLengthDigits<T>::Read(istream & in)
{
	FixedLength::Read(in);
	
      if (IsDigit() == false)
   {
      throw (Non_Digit_Error);
   }
	
}

template <int T>
ostream & FixedLengthDigits<T>::Display(ostream & out)
{
	FixedLength::Display(out);
	return out; 
}

template <int T>
int	FixedLengthDigits <T>:: Compare(const FixedLengthDigits<T> &) const
{
	return 0;
}


template <int T>
istream &	operator >> (istream & in, FixedLengthDigits<T> & N)
{
	N.Read(in);
	return in;
}


template <int T>
FixedLengthDigits<T> & FixedLengthDigits<T>:: Copy	(const FixedLengthDigits<T> & N)
{
	FixedLength:: Copy(N);
	return * this; 
}

template <int T>
FixedLengthDigits<T> & FixedLengthDigits <T>:: operator = (const FixedLengthDigits<T> & N)
{
	FixedLength:: operator = (N); 
	return * this; 
}


#endif