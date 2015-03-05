/* --------- Project Euler Number 50 -----------
		//Consecutive Prime Sum
		
		Problem Statement-
	
	The prime 41, can be written as the sum of six consecutive primes:

41 = 2 + 3 + 5 + 7 + 11 + 13
This is the longest sum of consecutive primes that adds to a prime below one-hundred.

The longest sum of consecutive primes below one-thousand that adds to a prime, contains 21 terms, and is equal to 953.

Which prime, below one-million, can be written as the sum of the most consecutive primes?

	*/
	//solution:997651 can be written as a sum of 543 primes
	
	
 #include <iostream>
 #include <vector>
 #include "project_euler_functions.h"
 
 
 int main()
 {
 	int upper_bound = 1000000;
 	std::vector<int> prime_list = sieve_of_Erasthenes(upper_bound,1);
 	int max_terms=0,current_sum;
 	int trialsum = 0,listsize = prime_list.size(),biggest_int;
 	
 	unsigned long total_sum = 0;
 	int i = 0;
 	for(int start = 0;start<listsize;start++)
 	{
 		total_sum = 0;
 		i= 0;
 		while(total_sum<upper_bound && (start+i)<listsize)
 		{
 			total_sum+=prime_list[start+i];
 			i++;
 		}
 		
 		while(i>0)
 		{
 			if(isPrime(total_sum)==true && (i>max_terms && total_sum<upper_bound))
 			{
 				max_terms = i;
 				biggest_int = total_sum;
 				break;
 			}
 			else
 			{
 				i--;
 				total_sum-=prime_list[start+i];
 			}
 		}
 	}
 	std::cout<<biggest_int<<" can be written as a sum of "<<max_terms<< " primes"<<std::endl;
//   	for(std::vector<int>::const_iterator i = prime_list.begin();i!=prime_list.end();i++)std::cout<<*i<<std::endl;
 
 return 0;	
 }