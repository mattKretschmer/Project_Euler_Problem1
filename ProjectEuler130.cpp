/* 

Composites with prime repunit property
Problem 130
A number consisting entirely of ones is called a repunit. We shall define R(k) to be a repunit of length k; for example, R(6) = 111111.

Given that n is a positive integer and GCD(n, 10) = 1, it can be shown that there always exists a value, k, for which R(k) is divisible by n, and let A(n) be the least such value of k; for example, A(7) = 6 and A(41) = 5.

You are given that for all primes, p > 5, that p − 1 is divisible by A(p). For example, when p = 41, A(41) = 5, and 40 is divisible by 5.

However, there are rare composite values for which this is also true; the first five examples being 91, 259, 451, 481, and 703.

Find the sum of the first twenty-five composite values of n for which
GCD(n, 10) = 1 and n − 1 is divisible by A(n).


*/

#include <iostream>
#include <cmath>

long A( long n);
long gcd(long a, long b);
bool isPrime(long long int value);

int main()
{
	long sum = 91+259+451+481+703;
	int counter = 5;
	long n = 705;//Stay out from evens, which'll have common factors with 10.
	while(counter<25)
	{
		if(n%5==0){n+=2;continue;}//Avoids other common factor of 10.
		if(!isPrime(n) && (n-1)%A(n)==0)
		{
				counter++;
				sum+=n;
		}
		n+=2;
	}
	
	std::cout<<"The sum of the first twenty five-composite values of n with that property is "<<sum<<std::endl;
	return 0;
}

long A( long n)
{
	if(gcd(n,10) !=1)return 0;
	//Going to be doing long division. Tracker will be the sub-radical remainder, k keep track of how many times we've had to do this (and thus how many ones there are going to need to be in the repunit to be divisible by n.
	long k = 1,tracker = 1;
	while(tracker>0)
	{
		tracker = (tracker*10 +1)%n;
		k++;
	}
	return k;
}

long gcd(long a, long b)
{
	if(a ==0) return b;
	
	return gcd(b%a,a);
}

bool isPrime(long long int value)
{
    bool primeIndicator = true;

	long long int divisor = 2; //A starting point
	while(divisor <= sqrt(value))
	{
	//Searches up to sqrt(value).  Value can be factored into a*b.  Max a and b can be is sqrt(value).  So we only need one leg of the "search", up to a's maximum value.

        if(value%divisor==0){primeIndicator = false; break;}
        divisor++;

	}
	return primeIndicator ;
}
