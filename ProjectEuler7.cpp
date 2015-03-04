#include <iostream>
#include <sstream>
#include <string>
#include <fstream>
#include <cmath>



//// ------ Project Euler #7------
//
////  By listing the first six prime numbers: 2, 3, 5, 7, 11, and 13, we can see that the 6th prime is 13.  What is the 10,001st prime number?
//
bool isPrime(long long int value);//Given a value, searches up to value/2 (or maybe sqrt(Value) looking for divisors).  Returns true if its prime, false otherwise
//
////First 6 primes: 2,3,5,7,11,13;
//
int main(){
    int primecounter = 6; //Starting points, given the problem statement.
    long long int largestPrime = 13;
    bool primeTrueFalse=false;
    while(primecounter <10001){
        primeTrueFalse = false; //resets every time.
        largestPrime+=2;//Increment up, won't need to worry about even numbers.
        
        while(primeTrueFalse == false){//Loop to find each prime.  When found, loop exits.
            primeTrueFalse = isPrime(largestPrime);
            if(primeTrueFalse == false)largestPrime+=2;
            
        }
        if(primeTrueFalse==true)primecounter+=1;//update counter accordingly.
    }
    std::cout<<"The 10001st prime number is "<<largestPrime<<std::endl;
    
}

bool isPrime(long long int value){
    bool primeIndicator = true;

	long long int divisor = 2; //A starting point
	while(divisor <= sqrt(value)){//Searches up to sqrt(value).  Value can be factored into a*b.  Max a and b can be is sqrt(value).  So we only need one leg of the "search", up to a's maximum value.
        
        if(value%divisor==0){primeIndicator = false; break;}
        divisor++;
		
	}
	return primeIndicator ;//Returns the final most prime value.
    
}

