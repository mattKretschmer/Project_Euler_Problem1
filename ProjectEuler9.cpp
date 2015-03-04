// ------ Project Euler #9 -------
//Find the pythagorean triple where a +b+c =1000, then find the product abc;

#include <iostream>
#include <sstream>
#include <string>
#include <fstream>
#include <cmath>


int main()
{
    //limits are a result of tuning once I knew the result lol, but cut the execution time drastically
    int k =0;
	for(int i =0;i<500;i++)
		for(int j =0;j<400;j++)
		{
			k=1000-i-j;
    		if(k*k==i*i+j*j && i+j+k==1000)
  			if(k*k == i*i+j*j)std::cout<<"The product answer is :  "<<i*j*k<<", and the three numbers are "<<i<<","<<j<<","<<"and "<<k<<std::endl;
		}

	return 0;
}

