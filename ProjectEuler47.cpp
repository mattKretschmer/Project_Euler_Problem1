/*  --------- Project Euler Number 47 -----------

		//Distinct primes factors
		

		 Problem Statement -
		
		The first two consecutive numbers to have two distinct prime factors are:

		14 = 2 × 7
		15 = 3 × 5

		The first three consecutive numbers to have three distinct prime factors are:

		644 = 2² × 7 × 23
		645 = 3 × 5 × 43
		646 = 2 × 17 × 19.

		Find the first four consecutive integers to have four distinct prime factors. What is the first of these numbers?
		*/

//Solution : 134043. 		
 #include <iostream>
 #include "project_euler_functions.h"
 	
 	
 int main()
 {
 	int to_test = 2*3*5*7;
 	int four_primes = 0;
 	while(four_primes!=4)
 	{
 	
 		if(prime_divisors(to_test)==4)
 		{
 			four_primes++;
 			to_test++;
 		}
 		else
 			{
 			four_primes=0;
 			to_test+=1;
 			}
 	}
 	to_test--;
 	for(int i = 0;i<4;i++)std::cout<<to_test--<<" ";
 	std::cout<<std::endl;
 
 	return 0;
 }