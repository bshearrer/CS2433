/*
Write a C++ program that reads in a series of test scores. 
If the test score is >= 90 && , <= 100;
print the letter grade 'A'. 
If the score is >= 80 but < 90, 
print the letter grade 'B'. 
if the tsest score is >= 70 and < 80, 
print the letter grade 'C'.
If the test score is >= 60 but < 70
print the letter grade 'D'
If the test score is < 60
print the letter grade 'F'.


Print the score and the corresponding grade.
Determine and print the max score,
the min score, the average score,
and the number of tests.
Terminate on a negative test score.
*/

//Brandon Shearrer
//CS2433
//PA6


#include <iostream>
#include <fstream>
#include <iomanip>
using namespace std;

void PrintMessage();

int main()
{
	//Calls the PrintMessage to display {Name, Class, Program}
	PrintMessage();
	
	ifstream indata;
	indata.open("/home/bshearr/indata.txt");
	
	cout << setprecision(2);
	
	int score;
	int maxScore = 0;
	int minScore = 100;
	double avgScore = 0;
	int numTest = 0;
	
	if(indata.is_open())
	{
		while(indata >> score)
		{
			if(score >= 90 && score <= 100)
			{
				cout << score << " A" << endl;
			}
			else if(score >= 80 && score < 90)
			{
				cout << score << " B" << endl;
			}
			else if(score >= 70 && score < 80)
			{
				cout << score << " C" << endl;
			}
			else if(score >= 60 && score < 70)
			{
				cout << score << " D" << endl;
			}
			else if(score < 60 && score > 0)
			{
				cout << score << " F" << endl;
			}
			else if(score < 0)
			{
				cout << score << " < Negative Score . . . System Terminated." << endl;
				break;
			}
		}
	}
	indata.close();
	
	indata.open("/home/bshearr/indata.txt");
	if(indata.is_open())
	{
		while(indata >> score)
		{
			if(score > maxScore)
			{
				maxScore = score;
			}
			else if(score < minScore && score >= 0)
			{
				minScore = score;
			}
		}	
	}
	indata.close();
	
	indata.open("/home/bshearr/indata.txt");
	if(indata.is_open())
	{
		while(indata >> score)
		{
			if(score > 0)
			{
			avgScore += score;
			numTest ++;
			}
		}
	}
	indata.close();
		
		cout << "Max Score       > " << maxScore << endl;
		cout << "Min Score       > " << minScore << endl;
		cout << fixed << "Average Score   > " << avgScore/numTest << endl;
		cout << "Amount of Tests > " << numTest << endl;
	
	return 1;
}

void PrintMessage()
{
	cout << "> Brandon Shearrer \n> CS 2433 \n> PA6 \n \n";
}
