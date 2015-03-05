/*  --------- Project Euler Number 30 -----------
		//Digit fifth Powers		
		Problem Statement-
	
Surprisingly there are only three numbers that can be written as the sum of fourth powers of their digits:

1634 = 14 + 64 + 34 + 44
8208 = 84 + 24 + 04 + 84
9474 = 94 + 44 + 74 + 44
As 1 = 14 is not a sum it is not included.

The sum of these numbers is 1634 + 8208 + 9474 = 19316.

Find the sum of all the numbers that can be written as the sum of fifth powers of their digits.
	*/

//I'd bet that these numbers will be between 100,000 and 999,999;

 #include <cmath>
 #include <iostream>

 #define U_LIMIT 1000000
 #define SIZE 6  //10^6 is max, etc
 
 long int_pow(long base,long exponent);
 
 int main()
 {
 	long test = 100;
 	long second_intermediate = 0,third_intermediate = 0;
 	long long sum = 0;
 	int counter = 0;
 	
 //Loops over all possible numbers from 100 to 10^6
 	while(test<U_LIMIT)
 	{
 		//make sum
 		third_intermediate= test;
 		second_intermediate = 0;
 		//Scan from 10^6 to zero
 		for(int i = SIZE;i>=0;i--)
 		{
 			//Here, we're summing the 5th powers of the digits of third_intermediate, and storing in second_intermediate. The two steps are dividing by 10 hen necessary.
 			second_intermediate +=int_pow( third_intermediate/int_pow(10,i) ,5);
 			if(third_intermediate>=0)third_intermediate-= (third_intermediate/int_pow(10,i))*int_pow(10,i);
 		}
 
	 	if(second_intermediate ==test)
	 	{
 			sum+=test;
 			counter++;
//  			std::cout<<test<<std::endl;
 		}	
 		test++;
 	
 	}	
 	std::cout<<"The sum of these numbers is equal to "<<sum<<std::endl;
 	return 0;
 }
 
 long int_pow(long base,long exponent)
 {
 	long result = base;
 	if(exponent==0)return 1;
 	if(exponent==1)return base;
 	for(int i = 2;i<=exponent;i++)
 	{
 		result *=base;
 	}
 return result;
 }