//Brandon Shearrer
//CS 2433 - C++
//PA9

#include <iostream>
#include <fstream>
#include <iomanip>
using namespace std;

//Create student structure
struct Student 
{
	string firstName;
	string lastName;
	string hometown;
	string state;
	int year;
	string major;
};

//Declare Functions
void myInfo();
void print(Student myArr[], int size);
void input(Student myArr[]);
void sortName(Student myArr[], int size);

//Main Method
int main()
{
	myInfo();					//Prints basic header -> name, class, program #
		
	Student myArr[18];
	int size = sizeof(myArr)/sizeof(myArr[18]); 
    		
    input(myArr);				//inputfile goes into myArr
    sortName(myArr, size);		//myArr gets sorted by last name, then by first name
    print(myArr, size);			//sorted myArr gets printed to console and output file
	
	return 0;
}

void input(Student myArr[])
{
	ifstream inFile;
	inFile.open("indata9.txt");
	int i = 0;
	while (inFile)
	{
		inFile >> myArr[i].firstName;
		inFile >> myArr[i].lastName;
		inFile >> myArr[i].hometown;
		inFile >> myArr[i].state;
		inFile >> myArr[i].year;
		inFile >> myArr[i].major;
		i++;
	}
}

void sortName(Student myArr[], int size)
{
	Student example;
	
	for(int i=0; i<size; i++)
	{
		for(int j=i+1; j<size; j++)
		{
			if(myArr[i].lastName > myArr[j].lastName)
			{
				example = myArr[i];
				myArr[i] = myArr[j];
				myArr[j] = example;
			}
			else if(myArr[i].lastName == myArr[j].lastName)
			{
				if(myArr[i].firstName > myArr[j].firstName)
				{
					example = myArr[i];
					myArr[i] = myArr[j];
					myArr[j] = example;
				}
			}
		}
	}
}

void print(Student students[], int size)
{		
    ofstream outFile;
    outFile.open("outdata9.txt");
    
    outFile << "Brandon Shearrer \nCS2433 - C++ \nPA9\n" << endl;
    
    cout << "   Last      First       Hometown          State        Year     Major" << endl;
    cout <<"--------------------------------------------------------------------------" << endl;
    
    outFile << "   Last      First       Hometown          State        Year     Major" << endl;
    outFile <<"--------------------------------------------------------------------------" << endl;
	for (int i = 0; i<size; i++)
	{
		cout << setw(8) << students[i].lastName << setw(10) << students[i].firstName << setw(15) << students[i].hometown << setw(15) <<students[i].state << setw(10) << students[i].year << setw(16) << students[i].major << endl;
	
		outFile << setw(8) << students[i].lastName << setw(10) << students[i].firstName << setw(15) << students[i].hometown << setw(15) <<students[i].state << setw(10) << students[i].year << setw(16) << students[i].major << endl;			
	}
	cout <<"--------------------------------------------------------------------------" << endl;
	outFile <<"--------------------------------------------------------------------------" << endl;

}

void myInfo()
{
	cout << "Brandon Shearrer \nCS2433 - C++ \nPA9\n" << endl;
}

		

