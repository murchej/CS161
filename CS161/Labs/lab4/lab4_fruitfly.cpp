/***************************************************************
 * Program filename: lab4_fruitfly.cpp
 * Author: Joseph Murche
 * Date: April 23rd, 2020
 * Purpose: Will allow user to input number of flies and output the population for each jar
 * *************************************************************/

#include <iostream>
using namespace std;
int main()
{

	cout << "Hello scientists. You have five jars to fill with fruit flies."<< endl;

	short flies[5] = {};
	int min = flies[5];
	int max = flies[0];

	for(int i= 0; i < 5; i++) {
		cout << "How many fruit flies would you like in a jar " << i << ": "<< endl;
		cin >> flies[i] ;
	} 
	cout << "number of fruit flies per jar: " << endl;
	for(int i = 0; i < 5; i++) {
	 cout << "Jar " << i << ": " << flies[i] << endl;
	}
	for (int i = 0; i < 5; i++) {
	    if (flies[i] > max) {
		max = flies[i];
	     }
	}
	for (int i = 0; i < 5; i++) {
	    if (flies[i] < min) {
		min = flies[i];
	    }
	}
	cout << "Largest jar has " << max << endl;
	cout << "Smallest jar has " << min << endl;

	return 0;
}










