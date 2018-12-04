//Brandon Shearrer
//CS 2433
//PA3
 #include <iostream>
 #include <iomanip>
 
 using namespace std;
 
int main()
{ 

	cout << "Brandon Shearrer \nCS 2433 \nPA3 \n \n";
	//List of needed doubles, int, or string
	string empname = "Brandon S.";
	int empid = 33;
	double hourlywage = 10.50;
	double hoursworked = 25;
	double sswitholds = 0.0625;
	double taxrate = .17;
	double grosspay;
	double taxwithheld;
	double netpay;
	
	//Set precision = 2 for money
	cout << setprecision(2);
	
	//Calculate Grosspay, Taxwithheld, and Netpay
	grosspay = hourlywage * hoursworked;
	taxwithheld = (grosspay * sswitholds) + (grosspay * taxrate);
	netpay = grosspay - taxwithheld;
	
	//Column Header
	cout << "ID " << setw(10) << "Name " << setw(12) << "Wage" << setw(12) << "Hours " << setw(13) << "Gross Pay " << setw(17) << "Tax Withheld " << setw(13) << "Net Pay " << endl;
	cout << "_______________________________________________________________________________" << endl;
	
	//List of employee information neatly printed within columns
	cout << fixed << empid << setw(16) << empname << setw(30) << setw(8) <<hourlywage << setw(10) <<hoursworked << setw(5) << "$" << grosspay << setw(8) << "$" << taxwithheld << setw(13) << "$" << netpay << endl;
	cout << fixed << empid << setw(16) << empname << setw(30) << setw(8) <<hourlywage << setw(10) <<hoursworked << setw(5) << "$" << grosspay << setw(8) << "$" << taxwithheld << setw(13) << "$" << netpay << endl;
	cout << fixed << empid << setw(16) << empname << setw(30) << setw(8) <<hourlywage << setw(10) <<hoursworked << setw(5) << "$" << grosspay << setw(8) << "$" << taxwithheld << setw(13) << "$" << netpay << endl;
	cout << fixed << empid << setw(16) << empname << setw(30) << setw(8) <<hourlywage << setw(10) <<hoursworked << setw(5) << "$" << grosspay << setw(8) << "$" << taxwithheld << setw(13) << "$" << netpay << endl;
	cout << fixed << empid << setw(16) << empname << setw(30) << setw(8) <<hourlywage << setw(10) <<hoursworked << setw(5) << "$" << grosspay << setw(8) << "$" << taxwithheld << setw(13) << "$" << netpay << endl;
			
 	return 0;
}


