#ifndef Record_H
#define	Record_H
#include "FixedLengthDigits.h"
#include "Name.h"
#include "Address.h" 
#include "PhoneNumber.h" 
#include "Array.h"
#include "Record.h" 

class Record : public Array <StudentRecord, 0, 25>
{
public:

					Record		();
					Record		(const Record &);
					~Record		(); 
	void			ReadFromKeyboard	(istream &);
	ostream &		DisplayToScreen		(ostream &);
	ostream	&		WriteToFile			(ostream &);
	void			ReadFromFile		(istream &);
	ostream &		Display				(ostream &); 

	int				Compare				(const Record &);
	void			SortLetters			();
	void			SortNumbers			(); 
	void			SetNumStudents		(int );
	
	

private:
/*
Name								N;
Address								A;		
FixedLengthDigits<9>				ID;
PhoneNumber							PN; */

int									NumStudents; 

};



#endif