/*Tim Dodge
CS2433
PA10
Write a C++ class student. The class should have fields to include last
name, first name, student ID, major and gpa. The class needs a constructor
to set all fields to blanks. The class should have methods to change the
major and gpa. Ten students should be enough. read data from a file. For
several students change their major and change their gpa. Print the
original student data, change the majors and the gpa's and print the
student data again. Keep the data stored in an ordered list by student ID.*/

#include <fstream>
#include <iostream>
#include <iomanip>
#include <string>
#include <cstddef>

using namespace std;

void me(); //function prototype

class Student //data structure of type student with 5 different data strings
{
private:
    string lastName;
    string firstName;
    int studentID;
    string major;
    float gpa;


public:
    Student* next = NULL; //pointer called next
    
    //constructor for Student class
    Student (string a, string b, int c, string d, float e)
    {
        lastName = a;
        firstName = b;
        studentID = c;
        major = d;
        gpa = e;
    }
    //null constructor
    Student()
    {
        firstName = "";
        lastName = "";
        studentID = 0;
        major = "";
        gpa = 0.00;
    }

    //__________________________________________________________________
    //Getters of setters of all the attributes of the Student class
    //__________________________________________________________________
    string getLastName() 
		{return lastName;}
    string getFirstName() 
		{return firstName;}
    int getStudentID() 
		{return studentID;}
    void setStudentID(int id) 
		{ studentID = id;}
    float getGPA() 
		{ return gpa;}
    void setGPA(float g) 
		{gpa = g;}
    string getMajor() 
		{ return major;}
    void setMajor(string m) 
		{major = m;}

    Student* getNextStudent() //getter function to return the next object in the list
    	{return next;}

    void setNextStudent(Student* s) //setter function to set the next object
    	{next = s;}
};

/// function prototype
Student* IDfinder(Student *top, int found);
/// function prototype
Student* input(ifstream &indata);
/// function prototype
void PrintStudentList(Student *s, ofstream &outdata);

int main()
{
    me();//signature

    ifstream indata10; //input file
    ofstream outdata10; //output file
    indata10.open("indata10.txt"); //open source file
    outdata10.open("outdata10.txt"); //open output file

    Student* top = input(indata10);//pointer for the top of the list
    Student* bottom = top; //pointer for the bottom of the list

    while(!indata10.eof()) //while loop to input all the data from the file into a list of objects
    {
        Student* next = input(indata10); //next student pulls from the data file

        //cases to check on data insert 1-4 insertion sorting while inserting each new student

        if(next == NULL) //case 1 end of students
        {
            break;
        }

        if (next->getStudentID() < top->getStudentID()) //case 2 insert to the top of the list if the Student ID is smaller
        {
            next->setNextStudent(top); //point the next pointer to the top of the heap
            top = next; //set the top pointer to next
            continue;
        }

        if (next->getStudentID() > bottom->getStudentID()) //case 3 insert at the bottom of the list if the Student ID is bigger
        {
            bottom->setNextStudent(next); //point the next pointer to the bottom
            bottom = next; //set the bottom pointer to the next
            continue;
        }

        Student* current = top; //initialized new pointer to check between the first and last
        Student* lastChecked = top; //initialized new pointer to keep track of previous checked location

        while (next->getStudentID() > current->getStudentID()) //case 4 check between the top and bottom of the of the list and insert new student before the last one
        {
            lastChecked = current; //the last checked pointer is set to equal the value in current
            current = current->getNextStudent(); //the current pointer is set to equal the value of the next pointer
        }

        //after sorting in between, set the pointers to the appropriate fields
        lastChecked->setNextStudent(next); //last checked pointer is pointing to next
        next->setNextStudent(current); //next pointer now points at the current placement of the student
    }


    PrintStudentList(top, outdata10); //print out the list in cout and to an output file

    //coding to change majors of some of the students and reprint them

    Student* finder = NULL; //initialize finder pointer for IDfinder function to change elements.

    //Major Changes
		//____________________________________________
		
		//change Mickey Mouse's major 
	    finder = IDfinder(top, 1400);
	    finder->setMajor("Mousing");
		
		//change Donald Duck's major 
		finder = IDfinder(top, 1200);
		finder->setMajor("Ducking");
		
		//change Pluto Dog's major
		finder = IDfinder(top, 1250);
		finder->setMajor("Dogging");
		
		//change Peter Parker's major
		finder = IDfinder(top, 1090);
		finder->setMajor("Spiderman");
		
		//change Bart Simpon's major
		finder = IDfinder(top, 1111);
		finder->setMajor("Grafiti");
		
		//change Goofy's major
		finder = IDfinder(top, 1500);
		finder->setMajor("Tennis");
	
		//GPA changes
		//___________________________________________
		
		//change Prince Charming's GPA
		finder = IDfinder(top, 1350);
		finder->setGPA(3.78);
		
		//change Captain Kirk's GPA
		finder = IDfinder(top, 1360);
		finder->setGPA(1.25);
		
		//change Zulu's GPA
		finder = IDfinder(top, 1550);
		finder->setGPA(3.03);
		
		//change Richie Rich's GPA
		finder = IDfinder(top, 1175);
		finder ->setGPA(3.91);
		
		//change Little Mermaid's GPA
		finder = IDfinder(top, 1100);
		finder->setGPA(2.37);
		
		//change Xena's GPA
		finder = IDfinder(top, 1325);
		finder->setGPA(4.00);

    PrintStudentList(top, outdata10);

    indata10.close(); //close input files
    outdata10.close(); //close output file

    return 0;
}

void me();

void PrintStudentList(Student *s, ofstream &outdata) //print function to output to both cout and output file
{
    cout << " " << endl;
    cout << "Student ID" << setw (14) <<"Last Name" << setw (16) << "First Name" << setw (10) << "Major" << setw (13) <<  "GPA" << setw (10)  << endl;
    cout << "---------------------------------------------------------------------------" << endl;

    //formating for the data in the output file
    outdata << "Brandon Shearrer \nCS2433 - C++ \nPA10" << endl;

    outdata << " " << endl;
    outdata << "Student ID" << setw (15) <<"Last Name" << setw (15) << "First Name" << setw (15) << "Major" << setw (15) <<  "GPA" << setw (15)  << endl;
    outdata << "-------------------------------------------------------------------------" << endl;

    //loop through all the elements of the
    while (s != NULL)//(true)
    {
        cout << setprecision(2) << fixed << left;
		cout << setw(15) << s->getStudentID(); 
		cout << setw(15) << s->getLastName(); 
		cout << setw(15) << s->getFirstName();
		cout << setw(15) << s->getMajor();
		cout << setw(16) << s->getGPA() << endl;

        outdata << setprecision(2) << fixed << left;
		outdata << setw(15) << s->getStudentID(); 
		outdata << setw(15) << s->getLastName(); 
		outdata << setw(15) << s->getFirstName();
		outdata << setw(15) << s->getMajor();
		outdata << setw(16) << s->getGPA() << endl;

        s = s->getNextStudent();
        
    }
}

Student* input(ifstream &indata) 
{
    if (indata.eof())
    {
        return NULL;
    }
    string ln;
    string fn;
    int id;
    string major;
    float gpa;

    indata >> ln;
    indata >> fn;
    indata >> id;
    indata >> major;
    indata >> gpa;

    return new Student(ln, fn, id, major, gpa);
}

void me() //signature funtion
{
    cout<< "Brandon Shearrer \nCS2433 - C++ \nPA10" << endl;
}

Student* IDfinder(Student *top, int found) 
{
    Student* current = top;
    while(current != NULL )
    {
        if(current->getStudentID() == found)
        {
            return current;
        }
        current = current->getNextStudent();
    }
    return NULL;
}


