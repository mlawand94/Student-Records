#include <fstream> 
#include <iostream>
#include <algorithm> 

using namespace std;

#include <string.h>
#include "WCS_String.h" 
#include "Address.h"
#include "Array.h"
#include "Name.h" 
#include "StudentRecord.h"
#include "FixedLength.h"
#include "FixedLengthDigits.h" 
#include "PhoneNumber.h" 
#include "Record.h"


void main()
{
	FixedLength<3>					 A1; 
	FixedLength<5>				  	 Z1;
	FixedLengthDigits<5>			 Z2;
	FixedLength<7>					 D1;
	FixedLength<9>					 ID1;
	Record						AllRecords;
	PhoneNumber						 P1;
	fstream							 File1;
	fstream							 File2; 
	StudentRecord Temp;

	if (AllRecords [1].GetName () < AllRecords [2].GetName ())
	{
		Temp = AllRecords [1];
		AllRecords [1] = AllRecords [2];
		AllRecords [2] = Temp;
	}

File1.open ("Database.txt", ios_base::out);
for ( int i=0; i < 3; i++)
{

	AllRecords[i].ReadFromKeyboard(cin);
	AllRecords[i].WriteToFile(File1);
}
	AllRecords.SortLetters(); 
for ( int i=0; i < 3; i++)
{
	cout << AllRecords[i].Display(cout); 
}


File2.open ("StudentRecords.txt", ios_base::out);
AllRecords.SortLetters(); 

for(int i = 0; i < 2; i++)
{
AllRecords[i].WriteToFile(File2);
}
cout << "EOF" << endl; 

File1.close(); 
File2.close();

system("pause"); 
}
