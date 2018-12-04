//Brandon Shearrer
//CS 2433
//PA4

#include <iostream>
#include <fstream>
#include <sstream>
using namespace std;

int main()
{
	
	cout << " Brandon Shearrer \n CS 2433 \n PA4 \n \n";
	//Create Variables & Initialize the file operations
	string line;
	ifstream inputFile;
	
	
	//Input file location
	inputFile.open("/home/bshearr/indata.txt");
	
	//If-Else chain to ensure user has input the correct input file location
	if(inputFile.is_open())
	{
		//create on output file since an input file was found
		ofstream outputFile("outdata.txt");
		
		//While loop to loop through the document line-by-line
		while (getline(inputFile, line))
		{
			istringstream ss(line);
			
			string fname, lname;
			
			//Stores strings according to order they are in the file
			ss >> fname >> lname;
			//Outputs strings according to whatever order coder wants them in
			cout << lname << " " << fname << endl;
			//Outputs strings to the outputFile
			outputFile << lname << " " << fname << endl;
		}
	}
	else
	{
		cout << "Data file could not be found!";
	}
			
	//Close the input file
	inputFile.close();
	
	return 0;
}
