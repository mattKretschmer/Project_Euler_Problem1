/*Repunit divisibility
Problem 129
A number consisting entirely of ones is called a repunit. We shall define R(k) to be a repunit of length k; for example, R(6) = 111111.

Given that n is a positive integer and GCD(n, 10) = 1, it can be shown that there always exists a value, k, for which R(k) is divisible by n, and let A(n) be the least such value of k; for example, A(7) = 6 and A(41) = 5.

The least value of n for which A(n) first exceeds ten is 17.

Find the least value of n for which A(n) first exceeds one-million. */
#include <iostream>
#define MAX 1000000

long A( long n);
long gcd(long a, long b);

int main()
{
	long n=MAX+1;/*GCD(n,10) can't be 10!*/
	
	//A(n) < n
	
	while( A(n)< MAX)
	{
		n+=2; //Quickly see that we can cut out all even numbers, as they'll have a gcd of 2!
	}
	std::cout<<"The least value of n for which A(n) is less than 1000000 is "<<n<<std::endl;
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


/*greatest common divisor--- */