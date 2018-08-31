#include "StudentRecord.h"

StudentRecord::StudentRecord()
{
}


StudentRecord::StudentRecord(const StudentRecord & s)
{
}

StudentRecord::~StudentRecord()
{
}

istream & StudentRecord:: ReadFromKeyboard(istream & in)
{
	
		 N.Read(in);
		 if(N.ifEOF())
		 {return in;}
		 A.Read(in);
		 ID.Read(in);
		 PN.Read(in); 
		 return in;
}

bool			StudentRecord::ifEOF				()
{
	return N.ifEOF();
}

ostream & StudentRecord:: DisplayToScreen(ostream & out)
{	
		N.Write(out);
		A.Write(out); 
		ID.Display(out);
		PN.Display(out);
		return out;
}

ostream & StudentRecord:: WriteToFile(ostream & out)
{
	N.Write(out); out << "\n"; 
	A.Write(out); out << "\n"; 
	ID.Display(out); out << "\n";
	PN.Display(out); out << "\n";  
	return out;
}

ostream & StudentRecord:: Display(ostream & out)
{
	N.Write(out); out << "\n"; 
	A.Write(out); out << "\n"; 
	ID.Display(out); out << "\n";
	PN.Display(out); out << "\n";  
	return out;
}

void StudentRecord:: ReadFromFile(istream & in)
{
	N.Read(in); 
	A.Read(in); 
	ID.Read(in); 
	PN.Read(in); 

}

StudentRecord & StudentRecord::Copy (const StudentRecord & Z)
{
	N.Copy(Z.N);
	A.Copy(Z.A);
	ID.Copy(Z.ID);
	PN.Copy(Z.PN);
	return *this;
}


/*void StudentRecord:: SortNumbers()
{
	
}*/


/*void StudentRecord:: SortLetters()
{
		bool sorted = true;
		StudentRecord temp; 
		
	do{
		sorted= true; 
		for (int i=0; i < (NumStudents); i++)
		{
			if ((*this)[i].GetName().GetFirstName() > (*this)[i+1].GetName().GetFirstName()) 
			{ 
				temp.Copy((*this)[i]);
				(*this)[i].Copy ((*this)[i+1]);
				(*this)[i+1].Copy (temp); 
				sorted= false;} 
			else;
		}
		NumStudents -- ;
	}
	
	while (sorted != true);
}*/

Name &	StudentRecord:: GetName()
{
	return N;
}


FixedLengthDigits<9> &	StudentRecord:: GetID()
{
	return ID;
}

void StudentRecord:: SetNumStudents(int N)
{
	N= NumStudents;
}

