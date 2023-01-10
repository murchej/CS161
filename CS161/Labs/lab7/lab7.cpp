/*****************************************************************
 * Program: lab7.cpp
 * Author: Joseph Murche
 * Date: May 14th, 2020
 * Purpose: Read in a string and report the percentage of characters the string that are "*".
 * ***************************************************************/
#include <iostream>
#include <cstring>
#include <cstdlib>
using namespace std;

int main(){
	
/*Part A)
 * Input:fd*, return 33
 * Input:fd**, return 50
 * Input:f***, return 75
 */

	char str[21] = {};
	cout << "Please enter a string (less than or equal to 20 chars): ";
	cin.getline(str, 21);
	cout << "String length: "<< strlen(str) << endl;
	float star = 0;
		for(int i = 0; i<strlen(str); i++)
		{	

			if(str[i] == '*'){
			star +=1;
			}
		}

	cout << "Stars: " << star << endl;
	float length =  strlen(str);
	float percentage;
	percentage = star/length*100;
	cout << "Star-Factor (percentage): " << percentage << "%" << endl;



	srand(time(NULL));
	
	int classes;
	
	cout << "How many classes are you taking? " << endl;
	cin >> classes;

	float *grades = new float[classes];

	for (int i = 0; i < classes; i++) {

	grades[i] = float (rand()% 100)/1.0 + 1;

	cout << "Your grade for class " << i << "is " << grades[i] << endl;
	}

	delete [] grades;

return 0;
}
