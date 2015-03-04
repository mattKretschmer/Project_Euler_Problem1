#include <iostream>
#include <sstream>
#include <string>
#include <fstream>
#include <cmath>

//Project Euler Problem 1. Find the sum of all numbers divisible by 3 or 5.
int main () 
{
	int sum = 0;
	int index = 1;
	int i = 1.0;
	while (i < 1000) {
	if (i%3 ==0  || i%5 ==0)sum += i;
	i++;	
}
	
std::cout << "The sum of the multiples of 3 or 5 are : " << sum << std::endl;

return 0;
}