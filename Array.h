#pragma once 
#ifndef TEMPLATE_ARRAY_H
#define TEMPLATE_ARRAY_H 
#include "WCS_String.h" 
#include "StudentRecord.h" 
#include "Name.h" 

template <class T = int, int lower = 0, int upper= 25>	// Size must be given with a const value wherever the object is instantiated
	class Array
		{
		public:
			enum Exceptions		{IndexOutOfBounds = 1};
								Array		(const Array <T, lower,upper> &);
								Array		(const T &);
								~Array		();
			Array &				Copy		(const Array <T, lower,upper> &);  
			const T &			GetAt		(int) const;	
			void				SetAt		(int,T );
			void				SortLetters	();
			void				SortNumbers	(); 
			void				Read		(istream &); 
			void				Display		(); 
			void				Write		(ostream &); 

			Array <T,lower,upper > &	operator =	(const Array <T, lower,upper> &);	
			T &							operator []	(int);
			const T &					operator []	(int) const;
			Array		();


		private:
			
			int		s;
			T		Data [(upper-lower)+1];
		};

	template <class T,int lower,int upper>
	Array <T, lower,upper>::Array ()
		{
//			WCS_String temp;
//			char Buffer [81];
			s=0;
			/*
			for(int i= lower; i < upper; i++)
			{
				Data[i].getLastName() = itoa (i, Buffer, 10);
			}
			*/
		//Size	= ((upper-lower)+1);
		//pData	= new T [((upper-lower)+1)];
			// because we don't know what the type of the array is
			// we cannot initialize the elements of the array
		}


template <class T, int lower, int upper>
	Array <T,lower,upper>::Array (const Array <T, lower,upper> & A)
		{
			s=A.s;
		for (int i = lower; i < (upper-lower+1) i++)
			Data [i] = A.Data [i];
		}
	
template <class T, int lower, int upper>
	Array <T, lower, upper>::Array (const T & D)
		{
			s=0;
		for (int i = 0; i < (upper-lower+1); i++)
			Data [i] = D;
		}

template <class T, int lower, int upper>
	Array <T, lower, upper>::~Array ()
		{
		}
	
template <class T, int lower, int upper>
	T & Array <T, lower, upper>::operator [] (int i)
		{
		if ((i >= lower) && (i <= upper))
				return Data [i-lower];
			else
				throw IndexOutOfBounds;
		}

template <class T, int lower, int upper> 	
const	T & Array <T, lower, upper>::operator [] (int i) const
	{
	if ((lower <= i) && (i <= UpperBound))
			return Data [i];
		else
			throw IndexOutOfBounds;
	}

template <class T, int lower, int upper>
	Array <T, lower,upper> & Array <T,lower,upper>::operator = (const Array <T,lower,upper> & A)
		{
			s=A.s;
		for (int i = lower; i < (upper-lower+1); i++)
			Data [i] = A.Data [i];
		return *(this); 
		}

template <class T, int lower, int upper>
	Array <T, lower,upper> & Array <T, lower,upper>::Copy (const Array <T, lower,upper> & A)
		{
		return operator = (A);
		}

template <class T, int lower, int upper>
void Array <T,lower,upper> ::Display ()
	{
		for(int i= 0; i < s; i++)
		{
			Data[i].Display();
		}
		//return out; 
	}


template <class T, int lower, int upper>
const T & Array <T, lower,upper>::GetAt (int i)const 
	{
		if ((i >= lower) && (i <= upper))
				return Data [i-lower];
			else
				throw IndexOutOfBounds;
	}

template <class T, int lower, int upper>
void Array <T, lower, upper>:: SetAt ( int i, T Value) 
{
	if ((i >= lower) && (i <= upper))
				 Data [i-lower]= Value;
			else
				throw IndexOutOfBounds;

}


template <class T, int lower, int upper>
void Func (const Array<T, lower, upper> & A, int i)
{
cout << "Inside Func, it shows " << A [i] << endl;
cout << "Inside Func, it shows " << A.GetAt (i) << endl;
}

/*
template<class T, int lower, int upper>
void Array <T, lower,upper>::SortLetters () 
{
		bool sorted = true;
	do{
		sorted= true; 
		for (int i=0; i < (s-1); i++)
		{
			if ((Data[i].GetName ().Compare(Data[i+1].GetName ())) > 0){ // swap i & i+1
				T temp; 
				temp= Data[i];
				Data[i]= Data[i+1];
				Data[i+1] = temp; 
				sorted= false;} 
			
		}
	}
	while (sorted != true);
}

template <class T, int lower, int upper>
void Array <T, lower,upper>::SortNumbers () 
{ 
	bool sorted = true;
	do{
		sorted= true;
		for (int i=0; i < (s-1); i++)
		{
			if ((Data[i].GetID().Compare(Data[i+1].GetID())) > 0)
			{
				T temp;
				temp = Data[i];
				Data[i] = Data[i+1];
				Data[i+1] = temp; 
				sorted = false; 
			}

		}

	}
	while (sorted != true); 
}
*/

template <class T, int lower, int upper>
void Array <T, lower, upper>:: Read (istream & in)
{
	for (int i=0; i< upper; i++)
	{if (Data[i].Read(in) == true)
	{
	s+=1;
	}
	else break;
	}

}

template <class T, int lower, int upper>
void Array <T, lower, upper>:: Write (ostream & out)
{
	for (int i=0; i< s; i++)
	{
	(Data[i].Write(out) );
	}
	out << "EOF"; 
}

#endif


