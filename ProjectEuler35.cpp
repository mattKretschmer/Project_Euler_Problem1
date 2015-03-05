/*  --------- Project Euler Number 35 -----------
		//Circular Primes
		
		Problem Statement-
	
	The number, 197, is called a circular prime because all rotations of the digits: 197, 971, and 719, are themselves prime.

There are thirteen such primes below 100: 2, 3, 5, 7, 11, 13, 17, 31, 37, 71, 73, 79, and 97.

How many circular primes are there below one million?
	*/
	
/* Solution::55 */	
 #include <cmath>
 #include <iostream>
 #include <vector>
 
 #define UPPER_LIMIT 1000000
 
 int num_of_digits(long holder);
 bool isPrime(long long int value);
 long circ_shift_num(long test, int size);
 
 int main()
 {
 	int circ_prime_counter = 13,rot_counter,p_counter,num_dig,rot2_counter;
 	bool prime_or_not = false,prime_or_not2=false;
 	long temp;
 	
 	int checked_or_not[UPPER_LIMIT +1]={0};
 				
 	//start loop at 100;//Perfect usage for this!! Careful though, may end up testing values that really don't need to be tested.
 	#pragma omp parallel for firstprivate(rot_counter,p_counter,num_dig,rot2_counter,temp,prime_or_not,prime_or_not2) reduction(+: circ_prime_counter)  
	 for(long i = 100;i<UPPER_LIMIT;i++)
	 {
			if(checked_or_not[i]==0)
			{   //If that number hasn't been checked. Start checking if its prime and shifting.
				prime_or_not=false;
				num_dig=num_of_digits(i);
		
				//first test i;
				prime_or_not = isPrime(i);
		
				rot_counter = 1;
				//if that number is prime, shift and check.
				if(prime_or_not==true)
				{
					temp =i;
					prime_or_not2=false;
					p_counter=1;
			
					//permute others and test;
					while(rot_counter < num_dig)
					{
						temp = circ_shift_num(temp,num_dig);
						prime_or_not2 = isPrime(temp);
						if(prime_or_not2==true)p_counter++;
						rot_counter++;
					}
					//if all permutations are prime, add to the counter, and mark that the number has been checked. Use list to check if a permuation is prime or not, without explicitly checking.
					if(p_counter==rot_counter)
					{
						circ_prime_counter+=p_counter;//This is how many we found!
						 rot2_counter=0;			
						//permute others and test;
						while(rot2_counter < num_dig)
						{
							temp = circ_shift_num(temp,num_dig);
							checked_or_not[temp]=1;
							rot2_counter++;
						}
					}
				}
				else
				{
				//Go through and mark others
						 rot2_counter = 0;			
						//permute others and test;
						temp = i;
						while(rot2_counter < num_dig)
						{
							temp = circ_shift_num(temp,num_dig);
							checked_or_not[temp]=1;
							rot2_counter++;
						}
		
				}
		
			}
	 }
 
  std::cout<<"The number of Circular Primes below " <<UPPER_LIMIT<< " is equal to "<< circ_prime_counter<<std::endl;
 
 return 0;
 }
 
 int num_of_digits(long holder)
 {
 		
 		int digit_num=0;
 		while(holder>0)
 		{
 			holder/=10;
 			digit_num++;
 		}
 		return digit_num;
 }
 
 long	circ_shift_num(long test, int size)
 	{
 		int* new_num = new int[size];
 		int remainder = 0;
 		long new_new_num = 0;
 
  		//Fill in array with digits of test.
 		for(int i = 0;i<size;i++)
 		{
 			new_num[i] = test%10;
 			test/=10;
 		}
 		long pow = 1;
 		//Make new number that's had the digits shifted
 		for(int i = 1;i<size;i++)
 		{
 			new_new_num += new_num[i]*pow;
 			pow*=10;
 		}
 	
 		new_new_num +=new_num[0]*pow;
 		
 		delete [] new_num;
 	return new_new_num ;
 	}

 bool isPrime(long long int value)
 {	//Checks if value is prime. Same as in previous.
     bool primeIndicator = true;
 	long long int divisor = 2; //A starting point
 	while(divisor <= sqrt(value))
 	{
         if(value%divisor==0){primeIndicator = false; break;}
         divisor++;
 	}
 	return primeIndicator ;//Returns the final most prime value.
 }
