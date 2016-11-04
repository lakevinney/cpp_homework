#include <iostream>
#include <bitset>
#include <stdio.h>
using namespace std;

//Задание 1.
//===================================================================
void is_even(int x){
	
	if (x%2 == 0) 
		cout << x << " is even" << endl;
	else
		cout << x << " is odd" << endl;	
}

void is_even_bitwise(int x){

	cout << "bitwise: " << (x & 1) << endl;
	
}
	

int main(){

	int num;
	cout << "Enter the integer number:";
	cin >> num;
	is_even(num); //Задание 1
	is_even_bitwise(num); // Задание 1
	return 0;
}
