/********************************
 * Program filename: lab4_functions.cpp
 * Author: Joseph Murche
 * Date: April 23,2020
 * Purpose: Function implementation
 * *********************************/

#include <iostream>
#include <cmath>
using namespace std;


bool is_even(int num){

if(num%2 == 0){

return cout << num << " is even.";
}


else{
return cout << num << " is odd.";
}	
return 0;
}	

	
int product(int num1,int num2){

return  num1 * num2;
}	





int main(){

int num;
cout << "Enter a number to check if it is even: "<< endl;
cin >> num;


is_even(num);
cout << endl;

int num1 = 0;
int num2 = 0;
cout << "Enter a number to multiply: "<< endl;
cin >> num1;

cout << "Enter a number to multiply: "<< endl;
cin >> num2;

cout << "The product of "<< num1 <<" and "<< num2 <<" is "<< product(num1, num2) << "." << endl; 



return 0;
}
