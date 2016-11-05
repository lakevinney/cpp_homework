#include <iostream>
#include <bitset>
#include <cmath>
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

// Задание 3.
//=================================================================== 
void check_numbers() {

        int f1=0, f2=0;
        for(int i=0; i<1000; ++i) {
                int j = i;
                f1 = f2 = 0;
                while ((j%10) != 0) {

                        if((j%10) == 1)
                                f1 = 1;
                        else if((j%10) == 7)
                                f2 = 1;
                        j = j/10;
                }

                if(f1==1 && f2==1)
                        cout << i << endl;
        }



}
	
// Задание 4.
//===================================================================
void cross_points(double x1, double y1, double r1, double x2, \
double y2, double r2) {

	double dist;
	dist = sqrt(pow((x1 - x2), 2) + pow((y1 - y2), 2));
	if (r1 + r2 >= dist && r1 + dist >= r2 && r2 + dist >= r1)
		cout << "Circles are crossing" << endl;
	else
		cout << "Circles are not crossing" << endl;
	
				
							
}

// Задание 6.
//===================================================================
bool is_two_in_power(int val) {
	if(val <= 0)
    		return false; 
	while((val%2)==0)
	{
 
		 if((val/=2)==1)
    			return true;
	}
	return false;
}

bool is_two_in_power_bit(int val) {
	
	return ( val & (val - 1) ) == 0;
}


	
	
int main(){

//	Задание 1
	int num;
	cout << "Enter the integer number:";
	cin >> num;
	is_even(num); 
	is_even_bitwise(num); 
	cout << "===================================================" << endl;
//	Задание 2
	int h_num;
	cout << "Enter the number: ";
	cin >> h_num;
	cout << "Sum of digits: " << sum_of_digits(h_num) << endl;
	cout << "===================================================" << endl;
//	Задание 3
	check_numbers(); 
//	Задание 4	
	double x1, y1, r1, x2, y2, r2;
	cout << "Circle 1 (x y r): ";
	cin >> x1 >> y1 >> r1;
	cout << "Circle 2 (x y r): ";
	cin >> x2 >> y2 >> r2;
	cross_points(x1, y1, r1, x2, y2, r2);
	cout << "===================================================" << endl;
//	Задание 6
	int N;
	cout << "Enter a number: ";
	cin >> N;
	//cout << "Is 2 in power? ==>" << is_two_in_power(N) << endl;
	cout << "Is 2 in power? ==>" << is_two_in_power_bit(N) << endl;
	return 0;
}
