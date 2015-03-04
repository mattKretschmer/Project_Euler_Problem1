#include <iostream>
#include <sstream>
#include <string>
#include <fstream>
#include <cmath>


//Project Euler Problem 2.  Find the sum of all the fibonacci numbers under 4 million.
int main () {
	unsigned int f1 = 1, f2 = 2, temp = 0; //Initialize the three numbers to count up to four million.
	//A loop to keep going till the fibonacci numbers exceed the upper limit.
	unsigned int sum = 2; //Will start checking at f2 = 3, but 2 is even, so need to add;
	while (f2 <= 4000000){
		temp =f1+f2;
		if(temp%2==0)sum += temp;//Test if the number is even, if so add to sum.
		f1 = f2;
		f2 = temp;

		}
std::cout << "The sum of all the even Fibonacci numbers under four million is " << sum <<std::endl;
	return 0;
}