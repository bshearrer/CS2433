//Brandon Shearrer
//CS2433
//PA8

#include<iostream>
#include<fstream>
#include<string>

using namespace std;

void PrintMessage();
ofstream outputFile("outdata.txt");

// Move elements that are greater than key to 
// one position ahead of their current position.
void insertionSort(int arr[], int n) 
{ 
   int i, key, j; 
   for (i = 1; i < n; i++) 
   { 
       key = arr[i]; 
       j = i-1; 
       while (j >= 0 && arr[j] > key) 
       { 
           arr[j+1] = arr[j]; 
           j = j-1; 
       } 
       arr[j+1] = key; 
   } 
} 

// Print's out the array with a specified size 'n'.
void printArray(int arr[], int n) 
{ 

	int i; 
	for (i=0; i < n; i++) 
   	{
   		//printf("%d ", arr[i]);
		cout << arr[i] << " ";
		outputFile << arr[i] << " "; 
	}
   //printf("\n"); 
} 

int main()
{    
	//Calls the PrintMessage to display {Name, Class, Program}
	PrintMessage();

	//Declare and Initialize Variables (HINT: Array holds 25 b/c input file is 25 numbers!)
    int number;
    int arr[25];
    int n = sizeof(arr)/sizeof(arr[0]);

	//Create and Open File Reader
    ifstream inFile;
    inFile.open("indata8.txt");
    
    int i = 0;
    
    bool thirteen;
    int x;
    //While loop to 
    while(inFile >> number)
	{
		arr[i] = number;
		//If statement to see if the number 13 was found.
		if(number == 13)
		{
			cout << "Number 13 found!" << endl;
			outputFile << "Number 13 found!" << endl;
			bool thirteen = true;
			x = 9000;
			continue;
		}
		i++;
	}
	
	if(x != 9000)
	{
		cout << "\nThirteen was not found." << endl;
		outputFile << "\nThirteen was not found." << endl;
	}
		
	//Call sorting method and printing method
	insertionSort(arr, n);
	printArray(arr, n);
	
	return 0;
}

void PrintMessage()
{
	cout << "> Brandon Shearrer \n> CS 2433 \n> PA8 \n \n";
	outputFile << "> Brandon Shearrer \n> CS 2433 \n> PA8 \n \n";
}

