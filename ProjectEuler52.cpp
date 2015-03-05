/*  --------- Project Euler Number 52 -----------
		//Permuted Multiples
		
		Problem Statement-
It can be seen that the number, 125874, and its double, 251748, contain exactly the same digits, but in a different order.

Find the smallest positive integer, x, such that 2x, 3x, 4x, 5x, and 6x, contain the same digits.

	*/
	//Solution:142857
	
	//Side note: since numbers divisible by three have digit sum divisible by three, x must also be divisible by three. So we can start at 3, and increment by three! Checking this many cases cuts execution time even further! Digits divisible by 6 are evens with digit sums divisible by three.
 #include <iostream>
 #include "project_euler_functions.h"
 
 int main()
 {
 	int max_multiple = 6,counter=0;
 	long test =3;
 
 	while(counter!= max_multiple-1)
 	{
 		counter =0;
 		for(long i = 2;i<=max_multiple;i++)
 		{
 			if( permutation_finder(test,i*test) )counter++;
 			else break;
 		}
 		test+=3;
 	}
 		test-=3; //test increments once after we find our solution
 	std::cout<<"The Smallest positive integer x that has several multiples that are permutations is equal to "<<test<<std::endl;
 	return 0;
 }