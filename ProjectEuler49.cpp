/*  --------- Project Euler Number 49 -----------
		//Prime permutations
		
		Problem Statement-

		The arithmetic sequence, 1487, 4817, 8147, in which each of the terms increases by 3330, is unusual in two ways: (i) each of the three terms are prime, and, (ii) each of the 4-digit numbers are permutations of one another.

	There are no arithmetic sequences made up of three 1-, 2-, or 3-digit primes, exhibiting this property, but there is one other 4-digit increasing sequence.

	What 12-digit number do you form by concatenating the three terms in this sequence?

	*/
	//Solution : 296962999629 (have to avoid finding the one from the example!
 #include <iostream>
 #include <vector>
 #include "project_euler_functions.h"
 
 #define MAX 10000
 
 int main()
 {
 
 	//make list of primes from 1000-9999 with sieve of erasthones (in function library)
 	//Go through list, and find permutions of each? looking for 
 	std::vector<int> test = sieve_of_Erasthenes( 10000,1000);
 
 	int max_interval = (test[test.size()-1]-test[0])/2, test_interval,c_i,c_j;
 	bool prime_test,found = false;
 	//starting at test[0], find interval test[i]-test[0] till interval >max or test[i]
 for(int i = 0;i<test.size();i++)
 	{
 		for(int j = i+1;j<test.size();j++)
 		{
 			test_interval = test[j]-test[i];
 			prime_test = isPrime(test[i]+2*test_interval);
 			if(prime_test==true && test[i]+2*test_interval<MAX)
 			{
 				if( (test[i]!=1487 && permutation_finder(test[i],test[j])) && permutation_finder(test[i],test[i]+2*test_interval))
 				{
 					found=true;
 					c_i=i;
 					c_j=j;
 					break;
 				}
 			} 
 			if(test_interval >max_interval || test[i]+2*test_interval>MAX)break;
 		}
 		if(found ==true)break;
 	}
 		std::cout<<test[c_i]<<test[c_j]<<test[c_i]+2*test_interval<<std::endl;
  	for(std::vector<int>::const_iterator i = test.begin();i!=test.end();i++)std::cout<<*i<<std::endl;
  std::cout<<test.size()<<std::endl;
 
 	
 
 	return 0;
 	
 }