//FAWZIYAH AHMED
//This program will calculate a bowling league's average bowling scores from the  BowlingScores.txt file. 

#include <fstream>
#include <iostream>
#include <iomanip>

using namespace std;

//Declaring the variables
const int cols = 5;
const int rows = 10;
string filename = "BowlingScores.txt";
string names[rows];
int scores[rows][cols];
double* avg;

//getBowlingData() function will read and store data into two arrays 
bool getBowlingData(string filename, string names[rows], int scores[rows][cols])
{
	// Opening the input file
	ifstream myfile;
	myfile.open(filename, ios::in);

	//checking whether the file name is valid or not
	if (myfile.fail())
	{
		cout << "File Not Found!";
		return false;
	}

	else
	{
		// counting the records from the file
		for (int i = 0; i < rows; i++)
		{
			myfile >> names[i];
			for (int j = 0; j < cols; j++)
			{
				myfile >> scores[i][j];
			}
		}
		// Closing the intput file
		myfile.close();
	}
	return true;
}
//GetAverageScore() function will calculate the average bowling score
double* GetAverageScore(int scores[rows][cols])
{
	double total = 0;
	static double avg[rows];
	int i = 0;
	//using loops to find the average
	while (i < rows)
	{
		total = 0;
		for (int j = 0; j < cols; j++)
		{
			total += scores[i][j];
		}
		avg[i] = total / cols;
		i++;
	}
	return avg;
}

//PrettyPrintResults() function will output the results 
void PrettyPrintResults(string names[rows], int scores[rows][cols], double avg[])
{
	int i = 0;
	//printing out each column's name
	cout << setw(10) << left << "NAME" << setw(6) << "S1" << setw(8) << "S2" << setw(8) << "S3" << setw(8) << "S4" << setw(8) << "S5" << "AVG" << endl;
	cout << endl;
	//using loops
	while (i < rows)
	{// this will list all the names from the file
		cout << setw(10) << left << names[i];
		for (int j = 0; j < cols; j++) {
			//this will output the scores
			cout << scores[i][j] << "\t";
		}
		//this will output the average
		cout << setw(5) << *(avg + i) << endl;
		i++;
	}
}
//here goes the main() function
int main()
{
	//display the value upto 2 decimal places
	cout << setprecision(2) << fixed << showpoint;

	//if the file is valid then the program will display, or else it won't
	if (getBowlingData(filename, names, scores))
	{
		avg = GetAverageScore(scores);
		PrettyPrintResults(names, scores, avg);
	}

	else
	{
		cout << "File Not Found!" << endl;
	}
	return 0;
}
