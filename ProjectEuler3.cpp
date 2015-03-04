#include <iostream>
#include <sstream>
#include <string>
#include <fstream>
#include <cmath>

//Project Euler Problem 3.  Find the largest prime factor of 600851475143
  long long int BiggestPrime(long long int value);

int main() {

	long long int Value = 600851475143;//Need long longs to store such a big value!
	int trial = 13195;
	 long long int maxprime = BiggestPrime(Value);

	std::cout << "The Max prime is " << maxprime << std::endl;
	return 0;
}
//Function for calculating the Biggest prime factor

  long long int BiggestPrime(long long int value){
	std::cout<<value<<std::endl;//For fun, prints out where you're at;
	int divisor = 2; //A starting point
	long long int biggestfactor = 2;//Same thing, an initial place to store the biggest factor;
	while(divisor*divisor <= value){
	
	if(value%divisor==0){//Recursively calls itself.  If the divisor goes in evenly, it calls itself
	//for smaller value.
			if((value/divisor) > biggestfactor)biggestfactor = value/divisor;
			return BiggestPrime(value/divisor);
			}
	else
		divisor++;	
		
	}
	return value ;//Returns the final most prime value.

	}
