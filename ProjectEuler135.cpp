/*Same differences
Problem 135
Given the positive integers, x, y, and z, are consecutive terms of an arithmetic progression, the least value of the positive integer, n, for which the equation, x2 − y2 − z2 = n, has exactly two solutions is n = 27:

342 − 272 − 202 = 122 − 92 − 62 = 27

It turns out that n = 1155 is the least value which has exactly ten solutions.

How many values of n less than one million have exactly ten distinct solutions? */

/*Because of the arithmetic progression, where y = z+a, and x = z+2a, we need ten sets of a,z that satisfy: (3*a-z)(a+z)=n, for each n. */

#include <iostream>
#include <cmath>
#define MAX 1000000

long long storage[MAX+1] = {0};
int main()
{

for( long z = 1;z<MAX;z++)
	{
		for(long a = z/3 +1; ((3*a-z)*(a+z))<MAX;a++)//Ensures that (3a-z) is >0.
		{		
				storage[((3*a-z)*(a+z))]+=1;
		}

	}


	long counter = 0;
	for(int i = 1;i<=MAX;i++)
	{
		if(storage[i]==10)counter++;
	}
	std::cout<<"There are "<<counter<<" values of n with 10 distinct solutions under 1 million"<<std::endl;
	return 0;
}

