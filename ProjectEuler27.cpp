/* --------- Project Euler Number 27 -----------
		//Quadratic Primes
		
	Problem Statement-
		Euler discovered the remarkable quadratic formula:

	n² + n + 41

	It turns out that the formula will produce 40 primes for the consecutive values n = 0 to 39. However, when n = 40, 402 + 40 + 41 = 40(40 + 1) + 41 is divisible by 41, and certainly when n = 41, 41² + 41 + 41 is clearly divisible by 41.

	The incredible formula  n² − 79n + 1601 was discovered, which produces 80 primes for the consecutive values n = 0 to 79. The product of the coefficients, −79 and 1601, is −126479.

	Considering quadratics of the form:

	n² + an + b, where |a| < 1000 and |b| < 1000

	where |n| is the modulus/absolute value of n
	e.g. |11| = 11 and |−4| = 4
	Find the product of the coefficients, a and b, for the quadratic expression that produces the maximum number of primes for consecutive values of n, starting with n = 0.
	*/
	
	/*Pseudo-Code: Starting at a = b = -999 and going to a = b = 999, check by brute force which combination produces the most primes, store and keep for the end of the program.*/
	
	/*Solution: -59231 */

 #include <iostream>
 #include <string>
 #include <cmath>
 
 #define MAX  1000
 
 bool isPrime(long value);
 
 int main()
 {
 	bool prime_tester;
 	long value = 0;
 	int max_prime_counter = 0,prime_counter,max_a = 0,max_b = 0;
 	for(int a = -MAX+1;a<MAX;a++)
 		for(int b = -MAX+1;b<MAX;b++)
 		{
 			int n = 0,prime_counter = 0;
 			prime_tester = true;
 			while(prime_tester)
 			{
 				value = n*n+a*n+b;
 				if(value<=0)break;
 				prime_tester = isPrime(value);
 				prime_counter++;
 				n++;
 			}
 			if(prime_counter > max_prime_counter)
 			{
 				max_prime_counter = prime_counter;
 				max_a = a;
 				max_b = b;
 			}
 		}
 		long max_product = max_a*max_b;
 
 std::cout<<"The product of coefficients, a and b, that produces the most number of consecutive primes is equal to "<<max_product<<std::endl;
 
 	return 0;
 }
 
 
 
 bool isPrime(long value)//borrowed from earlier problems
 {
     bool primeIndicator = true;
 
 	unsigned long divisor = 2; //A starting point
 	while(divisor <= sqrt(value))
 	{
 	//Searches up to sqrt(value).  Value can be factored into a*b.  Max a and b can be is sqrt(value).  Only need one leg of the "search", up to a's maximum value.
 
        if(value%divisor==0){primeIndicator = false; break;}
        divisor++;
 	}
 	return primeIndicator ;//Returns the final most prime value.
 }