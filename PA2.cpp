//Brandon Shearrer
//CS 2433
//PA2

#include <iostream>
#include <math.h>

using namespace std;

//Define Constant variables
const double RAD_CM = 17.3;
const double PI = 3.14159;

int main()
{
	//Circumference of the Cirlce in Centimeters(C=2*pi*r)
	double circum = 2 * PI * RAD_CM;
	cout << "Circumference of the Circle in Centimeters: " << circum << endl;
	
	//Area of the Circle in Centimeters(A=pi*r^2)
	double area = PI * pow(RAD_CM, 2);
	cout << "Area of the Cirlce in Centimeters: " << area << endl;
	
	//Convert 17.3cm to inches (1 in = 2.54cm)
	double inches = RAD_CM / 2.54;
	cout << endl << "17.3cm converted to inches is: " << inches << endl;
	
	//Circumference of the Cirlce in Inches(C=2*pi*r)
	double circum_in = 2*PI*inches;
	cout << endl << "Circumference of the Circle in Inches: " << circum_in << endl;
	
	//Area of the Circle in Inches(A=pi*r^2)
	double area_in = PI * pow(inches, 2);
	cout << "Area of the Circle in Inches: " << area_in << endl;
	
	/*----------------------------------------------------------------------------------*/
	
	//Volume of a Sphere in Centimeters(V=4/3*pi*r^3)
	double volume = 1.33333333 * PI * pow(RAD_CM, 3);
	cout << endl << "Volume of a Sphere in Centimeters: " << volume << endl;
	
	//Volume of a Sphere in Inches(V=4/3*pi*r^3)
	double volume_in = 1.3333333 * PI * pow(inches, 3);
	cout << "Volume of a Sphere in Inches: " << volume_in << endl;
	
	/*----------------------------------------------------------------------------------*/

	//Create variable n to use for Square and Cube equations
	double n = 17.3;	
	
	//Perimeter of a Square in Centimeters (P=4n)
	double per = 4*n;
	cout << endl << "Perimeter of a Square in Centimeters: " << per << endl;
	
	//Area of a Square in Centimeters
	double square_area = pow(n,2);
	cout << "Area of a Square in Centimeters: " << square_area << endl;
	
	//Perimeter of a Square in Inches
	double per_in = 4*inches;
	cout << endl << "Perimeter of a Square in Inches: " << per_in << endl;
	
	//Area of a Square in Inches
	double square_area_inch = pow(inches,2);
	cout << "Area of a Square in Inches: " << square_area_inch << endl;
	
	
	/*----------------------------------------------------------------------------------*/
	
	//Surface Area and Volume of a Cube in Centimeters(SA=6*a^2)(V=a^3)
	double cube_area = 6 * pow(n,2);
	double cube_volume = pow(n,3);
	cout << endl << "Surface Area of a Cube in Centimeters: " << cube_area << endl;
	cout << "Volume of a Cube in Centimeters: " << cube_volume << endl;
	
	//Surface Area and Volume of a Cube in Inches(SA=6*a^2)(V=a^3)
	double cube_area_in = 6 * pow(inches,2);
	double cube_volume_in = pow(inches,3);
	cout << endl << "Surface Area of a Cube in Inches: " << cube_area_in << endl;
	cout << "Volume of a Cube in Inches: " << cube_volume_in << endl;
	
	return 0;
}
