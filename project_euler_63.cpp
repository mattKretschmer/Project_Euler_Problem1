/*

Powerful digit counts
Problem 63
The 5-digit number, 16807=75, is also a fifth power. Similarly, the 9-digit number, 134217728=89, is a ninth power.

How many n-digit positive integers exist which are also an nth power?

*/
/*
Can do this by hand I think?  
n^1 = 1,2,3,4,5,6,7,8,9
n^2 = 4,5,6,7,8,9
n^3 = 5,6,7,8,9
n^4 = 6,7,8,9
n^5 = 7,8,9
n^6 = 7,8,9
n^7 = 8,9
n^8 = 8,9
n^9 = 8,9
n^10 = 8,9
n^11 = 9
n^12 = 9


There are 49 solutions! Can do it by "brute" force, or by looking at 10^(n-1)<x^n<10^n (what I was doing impliicily)
Upper bound is given by x = 9;

for lower bound of x, find log(10^(n-1) = x^n ) => n-1 = n*log(x), or x = 10^( (n-1)/n ); We can stop when x>9

*/
#include <iostream>
#include <cmath>

int main()
{
	int nums_fitting = 0;
	int n = 1, max = 9,low_limit;
	
	while( (int)ceil(pow(10, 1.*(n-1)/n))<= max)
	{
		low_limit = ceil(pow(10, 1.*(n-1)/n));
		nums_fitting += (max-low_limit+1);
		std::cout<<n<<" "<<(max-low_limit+1)<<" "<<low_limit<<std::endl;
		n++;
	}
	std::cout<<"The number of n-digit positive integers that are also an nth power is "<<nums_fitting<<std::endl;
	
	return 0;	
}
