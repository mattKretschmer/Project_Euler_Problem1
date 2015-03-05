/* --------- Project Euler Number 51 -----------
		//Prime Digit Replacements
		
		Problem Statement-
	
	By replacing the 1st digit of the 2-digit number *3, it turns out that six of the nine possible values: 13, 23, 43, 53, 73, and 83, are all prime.

By replacing the 3rd and 4th digits of 56**3 with the same digit, this 5-digit number is the first example having seven primes among the ten generated numbers, yielding the family: 56003, 56113, 56333, 56443, 56663, 56773, and 56993. Consequently 56003, being the first member of this family, is the smallest prime with this property.

Find the smallest prime which, by replacing part of the number (not necessarily adjacent digits) with the same digit, is part of an eight prime value family.

	*/
	
	
 #include <iostream>
 #include "project_euler_functions.h"
 
 int main()
 {	
 	long i = 1001;
 	int indexes[3]={0};
 	int increment,family_counter=0,starting_dig = 0;;
 
 	while(family_counter!=8)
 	{
 		starting_dig= repeating_except_last(i,3);
 		if(starting_dig>=3 ||starting_dig <0){i+=2;continue;}//Allow if there are three repeating digits, and they're 0,1,or2.
 		family_counter=0;
 		if(isPrime(i))//ifthe number is prime and has three repeating digits
 		{
 			family_counter++;
 			find_locations(i,indexes,starting_dig);
 			increment = 1;
 			while(starting_dig+increment<10)
 			{
 				if(isPrime(switch_at_locations(i,indexes,starting_dig,starting_dig+increment ) ))family_counter++;
 				increment++;
 			}
 		}
 			i+=2;
 		
 	}
 	i-=2;
 std::cout<<"The Lowest Prime in the 8-prime family is equal to "<<i<<std::endl;
 	return 0;
 	
 }