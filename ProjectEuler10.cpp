//------ Project Euler #10 -------

//Find the sum of all primes below two million


#include <iostream>
#include <sstream>
#include <string>
#include <fstream>
#include <cmath>

bool isPrime(long long int value);

int main()
{
    bool prime_indicate = false;
    long long int sum = 5; // because 2 and three are primes, but not 1!  ALso, get to reuse prime testing function oh yeah!!
    long long int i = 5;
    while(i<=2000000)
    {
        prime_indicate = isPrime(i);
        if(prime_indicate==true)sum+=i;
        prime_indicate = false;
        i+=2;
    }
    std::cout<<sum<<std::endl;
    return 0;
    
}

bool isPrime(long long int value)
{
    bool primeIndicator = true;

	long long int divisor = 2; //A starting point
	while(divisor <= sqrt(value)){//Searches up to sqrt(value).  Value can be factored into a*b.  Max a and b can be is sqrt(value).  So we only need one leg of the "search", up to a's maximum value.

        if(value%divisor==0){primeIndicator = false; break;}
        divisor++;

	}
	return primeIndicator ;//Returns the final most prime value.
}