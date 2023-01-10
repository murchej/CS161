/**********************************************************
 ** Program: lab2_values.cpp
 ** Authors: Joseph Murche, Kevin Chann, Finn Lawless, Wade Jacobus
 ** Date: 4/6/2020
 ** Description: Calculate min/max values.
 ***********************************************************/

#include <iostream>
#include <cmath> 
using namespace std; 

int main() 
{
  int num = 0;
  int num2 = 0;
  int num3 = 0;
  int max_int = 1;
  int min_int = -1;

  int n_bits = 0; /* Number of bits to use for calculation.
		   * Initialize to 0 before the user input. */
  cout << "Enter the number of bits: ";
  cin >> n_bits;

 num = pow(2,n_bits)-1;

  cout << num << endl;

 num2 = pow(-2,n_bits)-1;
 
   cout << num2 << endl;

 num3 = pow(2,n_bits);

  cout << num3 << endl;

 max_int = pow(2,n_bits)-1;

  cout << max_int << endl;

 min_int = pow(-2,n_bits);

  cout << min_int << endl;

 

  /* Write your code here to calculate and print: */

  /* 1) Minimum signed value that can be stored in b bits */

  /* 2) Maximum signed value that can be stored in b bits */

  /* 3) Maximum unsigned value that can be stored in b bits */
  
  return 0;
} 
