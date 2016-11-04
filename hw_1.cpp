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

//Задание 2.
//===================================================================
	
int sum_of_digits(int x){
	
	int sum=0;
	int hundreds, tens, ones;
	hundreds = x/100;
	x = x % 100;
	tens = x/10;
	x = x % 10;
	ones = x;
	sum = hundreds + tens + ones;
	
	return sum;
}	
	
int main(){

	int num;
	cout << "Enter the integer number:";
	cin >> num;
	is_even(num); //Задание 1
	is_even_bitwise(num); // Задание 1
	cout << "===================================================" << endl;
//	Задание 2
	int h_num;
	cout << "Enter the number: ";
	cin >> h_num;
	cout << "Sum of digits: " << sum_of_digits(h_num) << endl;	

	return 0;
}
