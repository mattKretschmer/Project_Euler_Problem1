/*Large repunit factors
Problem 132
A number consisting entirely of ones is called a repunit. We shall define R(k) to be a repunit of length k.

For example, R(10) = 1111111111 = 11×41×271×9091, and the sum of these prime factors is 9414.

Find the sum of the first forty prime factors of R(109). */

/* Pseudo-code: R(n) = (10^n -1 )/9. So, a prime factor will have R(n)%p =0, and 10^n - 1 = 0 mod(9*p), so 10^n = 1 mod(9*p). So for each prime, we'll raise 10^n and take it mod 9p. We'll then check and if the remainder is 1, we then "store" the product). */

/* Solution : 843296 */

#include <iostream>
#include <cmath>
#include <vector>
#include <algorithm>

 long long mod_power(long long base, std::vector<int> bin_power,long long modulo);
 std::vector<int> tobinary(long long num);
bool isPrime(long long int value);

int main()
{

	long long ten_base = 10,counter = 0;
	long product_storage = 0;
	long long ten_pow = 1000000000;
	long long current_prime = 3;

	std::vector<int> bin_holder = tobinary(ten_pow);

	while(counter <40)
	{
			std::cout<<mod_power(ten_base,bin_holder,9*current_prime)<<'\t'<<counter<<'\t'<<current_prime<<std::endl;

		if( mod_power(ten_base,bin_holder,9*current_prime)==1 && isPrime(current_prime) )
		{
			counter++;
			product_storage+=current_prime;
		}
			current_prime+=2;
	}
	std::cout<<"The factor of the first 40 prime factors of R(10^9) is "<<product_storage<<std::endl;
	return 0;
}

 long long mod_power(long long base, std::vector<int> bin_power,long long modulo)
 {
 	//Efficient modulo exponentiation, using the binary expansion of the binary power, stored in the vector bin_power.
 	int sz = bin_power.size()-1;
 	long result = 1;
 	for(int i = sz;i>=0;i--)
 	{
 		if(bin_power[i]==1)
 		{
 			result = result*base%modulo;
 		}
 		base = (base*base)%modulo;
 	}
 	
 	return result;
 }
 
 std::vector<int> tobinary(long long num)
 {
 	//Returns a vector holding the binary representation of num.
 	std::vector<int> ss; 
 	long holder = 0;	
 	while(num>0)
 	{
 		holder = num%2;
 		ss.push_back(holder);
 		num/=2;
 	}
 	std::reverse(ss.begin(),ss.end());
 	return ss; 
 }
 
bool isPrime(long long int value)
{
    bool primeIndicator = true;

	long long int divisor = 2; //A starting point
	while(divisor <= sqrt(value))
	{
	//Searches up to sqrt(value).  Value can be factored into a*b.  Max a and b can be is sqrt(value).  So we only need one leg of the "search", up to a's maximum value.

        if(value%divisor==0){primeIndicator = false; break;}
        divisor++;

	}
	return primeIndicator ;
}
