/*  --------- Project Euler Number 58 -----------
		//Spiral Primes
		
		/* Problem Statement-
Starting with 1 and spiralling anticlockwise in the following way, a square spiral with side length 7 is formed.

37 36 35 34 33 32 31
38 17 16 15 14 13 30
39 18  5  4  3 12 29
40 19  6  1  2 11 28
41 20  7  8  9 10 27
42 21 22 23 24 25 26
43 44 45 46 47 48 49

It is interesting to note that the odd squares lie along the bottom right diagonal, but what is more interesting is that 8 out of the 13 numbers lying along both diagonals are prime; that is, a ratio of 8/13 ≈ 62%.

If one complete new layer is wrapped around the spiral above, a square spiral with side length 9 will be formed. If this process is continued, what is the side length of the square spiral for which the ratio of primes along both diagonals first falls below 10%?
//Solution 26241
		*/
		
 #include <iostream>
 #include "project_euler_functions.h"
 
 int main()
 {
 	//reused from problem 29.  Start in ring number two to apply proper condition.  Remember2*ring_num-1 is side lentgh!
 		int ring_num = 2,jump_counter,position=9,diag_terms = 4 ;
 	long sum = 3;
 	
 	while(10.*sum > diag_terms)
 	{
 		jump_counter =0;
 		while(jump_counter<4)
 		{
 			position +=2*ring_num;
 			if(isPrime(position))sum +=1;
 			diag_terms++;
 			jump_counter++;
 		}
 		ring_num++;
 	
 	}
 	std::cout<<"At ring number "<<2*ring_num-1<<" the ratio of primes along both diagonals falls below 10%"<<std::endl;
 	return 0;
 }	