/* Palindromic sums     ---------Problem 125
The palindromic number 595 is interesting because it can be written as the sum of consecutive squares: 62 + 72 + 82 + 92 + 102 + 112 + 122.

There are exactly eleven palindromes below one-thousand that can be written as consecutive square sums, and the sum of these palindromes is 4164. Note that 1 = 02 + 12 has not been included as this problem is concerned with the squares of positive integers.

Find the sum of all the numbers less than 108 that are both palindromic and can be written as the sum of consecutive squares. */

#include <iostream>
#include <fstream>
#include <sstream>
#include <string>

#define MAX 100000000 //10^8
bool storage[MAX] = {false};

bool palindromic( long long tester,int base);

int main()
{
	long long sum = 0,running_num_sum=0;
	for(long long i = 1;i<10000;i++)//Remember, problem only deals with POSITIVE squares! Also need sum =i^2, to avoid counting a square as a sum of two numbers (this is where over counting had been coming from.
	{	
		sum=i*i;
		for(long long j = i+1;j<10000;j++)
		{
			sum +=j*j;
			if(sum>=MAX)break;
			if( palindromic(sum,10) && storage[sum]==false )
			{
				storage[sum]=true;
				running_num_sum +=sum;
			}
		}
	}
	
	std::cout<<"The sum of the numbers that meet both of these criteria is "<<running_num_sum<<std::endl;
	return 0;
}



bool palindromic( long long tester,int base)
 {
 	long reversed = 0;
 	long long k = tester;
 	//finds last digit of tester, multiplies it by base, effectively making it first, etc. Does this process in an arbitrary base.  
 	while(k>0)
 	{
 		reversed = base* reversed + k%base;
 		k/=base;
 	}
 	return tester==reversed;
 
 }	