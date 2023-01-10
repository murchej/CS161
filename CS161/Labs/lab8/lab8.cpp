/************************************************
 * Program: lab8.cpp
 * Date: May 21st, 2020
 * Author: Joseph Murche
 * Purpose: 2D Arrays
 ***********************************************/

#include <iostream>
#include <cstdlib>

using namespace std;



int main(){

	srand(time(NULL));

	int peopleinhouse[4][3];

		for(int x = 0; x < 4; x++){

			for(int y = 0; y < 3; y++){
			
			peopleinhouse[x][y] = rand()% 11 + 1;
			
			cout << peopleinhouse[x][y] << " poeple live in house " << y << ", ";
			}
			cout << "on Block " << x << "." << endl;
			}	


	int** block2 = new int*[4];
	for(int i = 0; i < 4; i++){

	  block2[i] = new int [3];
	  for( int j = 0; j < 3; j++){

	  block2[i][j] = rand()% 11 + 1;
	  cout << block2[i][j] << " people live in this house " << j << ", ";
	  
	  }

	    cout << "on Block " << i << "." << endl;
	}

	delete[] block2;
		

return 0;
}
