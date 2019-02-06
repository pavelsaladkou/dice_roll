/*------------------Roll two dice-------------------
Simulate rolling of two six-sided dice and calculate
the number each possible outcome appears alongside
the possibility of each outcome.

Created by Pavel Saladkou, January 2019
--------------------------------------------------*/

#include <iostream>
#include <ctime>
#include <cstdlib>
#include <iomanip>

using namespace std;

const int DIEMIN = 1; 
const int DIEMAX = 6;
const int ROLLNUM = 36000;
const int SUMS = 11; //there are 11 sums possible (2 - 12)

/*-------------------------------------------
Simulate the rolling of a six-sided die

Pre: two random numbers from DIEMIN to DIEMAX
Post: sum DIEMIN + DIEMAX
-------------------------------------------*/
int rollDie(int, int);

/*---------------------------------------------------------
Calculate the actual probability out of ROLLNUM dice rolls

Pre: array of outcomes, number of rolls
Post: calculated probability of each outcome is placed into
	  corresponding element of calculatedProbability array
---------------------------------------------------------*/
void probability(double[], int[], int);

/*-----------------------------------------------------------------
Output the results

Pre: each possible sum, array of how many times the sum was rolled,
	 array of expected probability of each sum, array of calculated
	 probability of each sum
Post: the table with each possible sum and its expected and
	  calculated probability
-----------------------------------------------------------------*/
void output(int SUMS, int[], float[], double[]);

int main() {

	srand(time(NULL));
	int sum;
	int outcomes[SUMS] = { 0 }; //to count the number each possible outcome appears 
	//pre-calculated probablility of each sum 2-12 based on a single roll
	float expectedProbability[SUMS] = { 2.78, 5.56, 8.33, 11.11, 13.89, 16.67, 13.89, 11.11, 8.33, 5.56, 2.78 };         

	double calculatedProbability[SUMS] = { 0 }; 

	//roll die 36000 times and calculate the outcome
	for (int i = 0; i < ROLLNUM; i++) {
		sum = rollDie(DIEMIN, DIEMAX) + rollDie(DIEMIN, DIEMAX);
		outcomes[sum - 2]++; // scale the subscript to start from 0
	}

	//calculate actual probability
	probability(calculatedProbability, outcomes, ROLLNUM);

	//output the results
	output(SUMS, outcomes, expectedProbability, calculatedProbability);
	system("PAUSE");
}

/*-------------------------------------------
Simulate the rolling of a six-sided die

Pre: two random numbers from DIEMIN to DIEMAX
Post: sum DIEMIN + DIEMAX
-------------------------------------------*/
int rollDie(int MINVALUE, int MAXVALUE) {
	return MINVALUE + rand() % MAXVALUE;
}

/*---------------------------------------------------------
Calculate the actual probability out of ROLLNUM dice rolls

Pre: array of outcomes, number of rolls
Post: calculated probability of each outcome is placed into 
      corresponding element of calculatedProbability array
---------------------------------------------------------*/
void probability(double calculatedProbability[], int outcomes[], int rollnum) {
	for (int i = 0; i < SUMS; i++) {
		calculatedProbability[i] = (static_cast<double>(outcomes[i]) / ROLLNUM) * 100;
	}
}

/*-----------------------------------------------------------------
Output the results

Pre: each possible sum, array of how many times the sum was rolled,
     array of expected probability of each sum, array of calculated
	 probability of each sum
Post: the table with each possible sum and its expected and
      calculated probability
-----------------------------------------------------------------*/
void output(int SUMS, int outcomes[], float expectedProbability[], double calculatedProbability[])
{
	cout << "Sum " << " " << "# of appearances " << " " << "Expected Probablility " << "Calculated Probability " << endl;
	cout << "====" << " " << "=================" << " " << "===================== " << "=======================" << endl;
	for (int i = 0; i < SUMS; i++) {
		cout << setw(2) << i + 2 << setw(13) << outcomes[i] << setw(21) << showpoint << setprecision(3) << expectedProbability[i]
			<< setw(22) << showpoint << setprecision(3) << calculatedProbability[i] << endl;
	}
	cout << "\n";
}