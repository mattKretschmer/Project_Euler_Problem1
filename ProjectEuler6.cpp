#include <iostream>
#include <sstream>
#include <string>
#include <fstream>
#include <cmath>

// ------ Project Euler #6------
    //Find the difference between the square of the sum and the sum of the squares of the first 100 consecutive integers.  Code is simple, and shown below.  Only 1 loops is shown, and it calculates both the sums of the squres, as well as the sum of the normal integers, and is itself then squared.

int main() {
	int UpperLimit = 100;
	unsigned int suma = 0, sumb = 0;
	for(int i = 1; i <= UpperLimit; i++){
        suma += i*i;
        sumb += i;
	}
	std::cout <<sumb<< std::endl;
	sumb *=sumb;
    int difference = sumb-suma;
	
	std::cout <<"The difference the sum of the squares and the square of the sum of the first" <<UpperLimit<< " numbers is " << difference <<std::endl;
    
	return 0; 
    
}