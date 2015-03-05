/* --------- Project Euler Number 46 -----------
		//Goldbach's other conjecture
		
		Problem Statement-
	
	It was proposed by Christian Goldbach that every odd composite number can be written as the sum of a prime and twice a square.

9 = 7 + 2×12
15 = 7 + 2×22
21 = 3 + 2×32
25 = 7 + 2×32
27 = 19 + 2×22
33 = 31 + 2×12

It turns out that the conjecture was false.

What is the smallest odd composite that cannot be written as the sum of a prime and twice a square?
//Solution is 5777
	*/
	
 #include <iostream>
 #include "project_euler_functions.h"
 
 
 
 int main()
 {	
 	int pow_list[100] = {0};
 	for(int i = 1;i<100;i++)pow_list[i]= (i+1)*(i+1);
 	
 	int search_num = 33;
 	bool found =false, is_prime = false,tester=false;
 	
 	while(found ==false)
 	{
 		is_prime = isPrime(search_num); 
 		if(is_prime==true){search_num+=2;continue;}
 		
 		long base = 1;
 		tester = false;
 		while(search_num>=2*base*base)
 		{
 			tester=isPrime(search_num- 2*base*base);
 			if(tester==true){break;}
 			base++;
 		}
 		if(tester==false)break;
 	
 	search_num+=2;
 	}
 	
 	std::cout<<"The number we're looking for is "<<search_num<<std::endl;
 
 	return 0;
 }