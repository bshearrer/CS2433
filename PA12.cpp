// Brandon Shearrer
// CS 2433 - C/C++
// PA12 - Final Program

#include <iostream> 
#include <fstream>
using namespace std; 

// A tail recursive function to calculate n th fibnacci number 
long long fib(long long n, long long a = 0, long long b = 1) 
{ 
	if (n == 0) 
		return a; 
	if (n == 1) 
		return b; 
	return fib(n - 1, b, a + b); 
} 

// Driver Code 
int main() 
{ 
    ofstream outFile;
    outFile.open("outdata12.txt");
    
	cout<<"Brandon Shearrer \nCS 2433 - C/C++ \nPA12 - Final Program\n" << endl;
	outFile<<"Brandon Shearrer \nCS 2433 - C/C++ \nPA12 - Final Program\n" << endl;

	for(int i = 0; i<51; i++)
	{
		cout << "f(" << i << ") = " << fib(i) << endl;
		outFile << "f(" << i << ") = " << fib(i) << endl;
	}
	return 0; 
} 

