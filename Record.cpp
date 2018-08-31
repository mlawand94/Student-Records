#include "Record.h"

Record::Record()
{
}


Record::Record(const Record & s)
{
}

Record::~Record()
{
}

void Record:: ReadFromKeyboard(istream & in)
{
	NumStudents = 0;
	operator[](0).ReadFromKeyboard(in);

	for(int i = 1 ; i < 25 && !operator[](i-1).ifEOF(); i++)
	{
operator[](i).ReadFromKeyboard(in);
		
		NumStudents=i;
	}
	if (NumStudents == 24 && !operator[](24).ifEOF())
	{
		NumStudents = 25;
	}

}

ostream & Record:: DisplayToScreen(ostream & out)
{	
	for(int x=0;x<NumStudents;x++)
	{
		operator[](x).Display(out);
	}
		return out;
}

ostream & Record:: WriteToFile(ostream & out)
{
	for(int x=0;x<NumStudents;x++)
	{
		operator[](x).WriteToFile(out); out << "\n";
	}
	return out;
}


void Record:: ReadFromFile(istream & in)
{

	for(int x=0;x<NumStudents;x++)
	{
		operator[](x).ReadFromFile(in);
	}

}


/*
void Record:: SortNumbers()
	
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

void Record:: SortLetters()
{
		bool sorted = true;
		StudentRecord temp; 
		
	do{
		sorted= true; 
		for (int i=0; i < (NumStudents); i++)
		{
			if ((*this)[i].GetName().Compare( (*this)[i+1].GetName()) > 0) 
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
}


void Record:: SetNumStudents(int N)
{
	N= NumStudents;
}

