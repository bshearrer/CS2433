//Brandon Shearrer
//CS 2433
//Program 5

#include <iostream>
#include <fstream>
#include <iomanip>
using namespace std;

void PrintMessage();
void MoneyCounter();

int main()
{
	PrintMessage();
	
	//Run while loop to count, sort, and organize money
	MoneyCounter();
	
	return 1;
}

void PrintMessage()
{
	cout << " Brandon Shearrer \n CS 2433 \n PA5 \n \n";
}

void MoneyCounter()
{
	//Create Input File | Create int Variables for Denomination & Number
	ifstream indata;
	double den;
	int number;
	double amount;
	double total;
	
	//Set precision = 2 for money
	cout << setprecision(2);

	
	//Open Data File
	indata.open("/home/bshearr/indata.txt");
	
	if(indata.is_open())
	{
		//create on output file since an input file was found
		ofstream outputFile("outdata.txt");
		outputFile << setprecision(2);
		
		cout <<"Denomination      Number       Amount" << endl;
		cout << "-------------------------------------" << endl;
		
		outputFile <<"Denomination      Number       Amount" << endl;
		outputFile << "-------------------------------------" << endl;
		
		while(indata >> den >> number)
		{
			amount = den * number;
			total += amount;
			cout << setw(8) << fixed << den << setw(14) << number << setw(15) << amount << endl;
			outputFile << setw(8) << fixed << den << setw(14) << number << setw(15) << amount << endl;
		}
			
		cout << "-------------------------------------" << endl;	
		cout << fixed << "                  Total = " << setw(5) << "$" << total;
		
		outputFile << "-------------------------------------" << endl;	
		outputFile << fixed << "                  Total = " << setw(5) << "$" << total;
	}
	else
	{
		cout << "File could not be found!";
	}
}

