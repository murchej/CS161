/*
 * Program: lab3.cpp
 * Author: Joseph Murche, Jingxuan Chen
 * Date: 4/16/2020
 * Description: Create loops, and mirror text.
 * */
#include <iostream>
#include <cmath>
using namespace std;
int main()
{

int i;
int j;

cout << "How many times would you like to see my message? ";
cin >> i;
j=i;

if(i < 0.0)
{
 cout << "Error"<< endl;
return 1;
}

for(i = 1; i<=j; i++)
{
 cout << "Go Beavs!"<< endl;
}


return 0;
}
