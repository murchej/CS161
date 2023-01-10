/************************************************************
 * Program Filename: assign4_restaurant.cpp
 * Author: Joseph Murche
 * Date: May 17th, 2020
 * Purpose: Create restaurant with menu.
 * **********************************************************
 */

#include <iostream>
#include <cmath>
#include <cstring>

using namespace std;

/**************************************************
 *Function: welcomelines
 *Description: Prints out two welcome lines
 *Parameters: n/a
 *Return: void
***************************************************/

void welcomelines(){//welcoming lines. void type for no return value.

	cout << "Welcome to Benny's Tavern! The coolest place in Corvallis. "<< endl;
	cout << "Your server will be right with you. "<< endl;
}

/**************************************************
 *Function: getorders
 *Description: Takes in user input for orders
 *Parameters: people, dishnameArr, dishpriceArr, eachorder
 *Return: void
***************************************************/
void getorders(short people, string dishnameArr[], float dishpriceArr[], int*& eachorder){

		
	for(int i = 0; i < people; i++){
 	
	cout << "Customer "<< i << ", please make your choice: "<< endl;
	cout << "0) " << dishnameArr[0] << ": $" << dishpriceArr[0] << endl; 
	cout << "1) " << dishnameArr[1] << ": $" << dishpriceArr[1] << endl;								
	cout << "2) " << dishnameArr[2] << ": $" << dishpriceArr[2] << endl;
	cout << "3) " << dishnameArr[3] << ": $" << dishpriceArr[3] << endl;
	cin >> eachorder[i];
	}
}

/*****************************************************
 *Function: finalbill
 *Description: calculates final bill, and split bill
 *Parameters: people, dishnameArr, dishpriceArr, eachorder
 *Return: float
******************************************************/
float finalbill(short people, string dishnameArr[], float dishpriceArr[], int*& eachorder){

	cout << "\n" << "We hope you enjoyed your meal!" << endl;
	cout << "\n" << "The bill for your meal. The gratuity is included." << endl;
	cout << "-------------------------------------------------------------------" << endl;
	
	for(int i = 0; i < people; i++){

	cout << "Customer "<< i << ")" << dishnameArr[eachorder[i]] << ": $" << dishpriceArr[eachorder[i]] << endl; 

	}	

	cout << "-------------------------------------------------------------------" << endl;

	float totalbill = 0;	
	short splitbill = 0;
		for(int i = 0; i < people; i++){

		totalbill += dishpriceArr[eachorder[i]];

		}				
	
			totalbill += totalbill *0.20; 
			cout << "Total amount due: $" << totalbill << endl;
			cout << "Would you like to split the bill amongst the party?" << endl;
			cout << "Enter \"1\" if yes, enter \"2\" if no." << endl;
			cin >> splitbill;
				
					if(splitbill == 1){
					cout <<"The split bill is $" << totalbill/people << endl; 
					
					}	
			else if(splitbill == 2){
			cout << "--------------------------------------------------------------------" << endl;
			cout << "See you next time! Go Beavs!" << endl;
			}
}

int main(){

	welcomelines();

string dishnameArr[4]={"The Benny Burger", "Dixon Dirty Mac", "Reser Rotisserie Chicken", "Weatherford Chicken and Waffles"};
//using string to allow for words.

float dishpriceArr[4]={8.75, 6.55, 12.25, 9.55};//using float to allow for decimals. Min is 1.2e-38. Max is 3.4e38

short people;//using short for more efficient memory use. Min is -32,768. Max is 32,767.
	
	
	cout << "\n" << "How many people will be dining tonight?(1-20): " << endl;
	cin >> people;	

	int* eachorder = new int[people];//using int to allow space in the array's memory. Min is -2,147,483,648. Max is 2,147,483,647.
	 
	getorders(people, dishnameArr, dishpriceArr, eachorder);//getting orders from customers
	
	float totalbill = finalbill(people, dishnameArr, dishpriceArr, eachorder);//printing bill.
	
	delete[] eachorder;

return 0;
}
