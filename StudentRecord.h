#ifndef StudentRecord_H
#define	StudentRecord_H
#include "FixedLengthDigits.h"
#include "Name.h"
#include "Address.h" 
#include "PhoneNumber.h" 
#include "Array.h"

class StudentRecord
{
public:

					StudentRecord		();
					StudentRecord		(const StudentRecord &);
					~StudentRecord		(); 
	istream &		ReadFromKeyboard	(istream &);
	bool			ifEOF				();
	ostream &		DisplayToScreen		(ostream &);
	ostream	&		WriteToFile			(ostream &);
	void			ReadFromFile		(istream &);
	ostream &		Display				(ostream &); 
	StudentRecord & Copy				(const StudentRecord &);
	int				Compare				(const StudentRecord &);
//	void			SortLetters			();
//	void			SortNumbers			(); 
	Name &			GetName				();
	void			SetNumStudents		(int );
	StudentRecord & operator[]			(const StudentRecord &);

	FixedLengthDigits<9>	&			GetID				();	
	

private:

Name								N;
Address								A;		
FixedLengthDigits<9>				ID;
PhoneNumber							PN; 
int									NumStudents; 

};



#endif