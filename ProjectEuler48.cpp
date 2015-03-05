/*  --------- Project Euler Number 48 -----------
		//Self Powers
		
		Problem Statement-
	
		The series, 1^1 + 2^2 + 3^3 + ... + 10^10 = 10405071317.

		Find the last ten digits of the series, 11 + 22 + 33 + ... + 10001000.  
	*/
	
 #include <iostream>
 #include <cmath>
 
 #define SERIES_MAX 1000
 
 long long mod_power(int base, int power,long long modulo);
 //Check out wikipedia on modular exponentiation for more info.  REALLY quick!!
 
 /* Useful to know:: c = (a*b) mod m equivalent to c = (a *(b mod m) ) mod m .  A natural extension then is to just keep track of the remainders, and keep adding.  
 
 Other helpful identities -- a = b mod n, a+c = b+c mod (n).  (taken over the whole equation);
 Similarly, a = b modn, a^k = b^k mod n, for integer k;
 
 */
	//solution:: 9110846700

 int main()
 {
 	unsigned long long m =10000000000,sum=0; //Need the last ten digits, or the remainder after division by 10^10;
 	
 	for(int e = 1;e<=SERIES_MAX;e++)
 	{
 		sum+= mod_power(e,e,m);
 		sum=sum%m;	
 	
 	}
 	std::cout<<sum<<std::endl;
 	
 	return 0;
 }
 
 long long mod_power(int base, int power,long long modulo)
 {
 	long long c = 1;
 	for(int e = 1;e<=power;e++)
 	{
 		c =(base*c )%modulo;
 	}
 	return c;
 }
/* Somewhat slow implementation that uses 'big_ints', which are really strings in my implmeentation, to brute force this */
 // #include <sstream>		
//  #include <string>
//  #include "big_int.h"
//  void big_int_power(big_int &b_int, int power);
// 
//  int main()
//  {
//  	std::string start = "0";
//  	big_int sum(start),to_square(start);
//  	
//  	stringstream ss;
//  	for(int power = 1;power<=SERIES_MAX;power++)
//  	{	
//  		ss<<power;//put the int to a stringstream;
//  		to_square.clear_value();
//  		to_square = ss.str();//put the string int into to_square;
//  		big_int_power(to_square,power); //find the power
//  		sum+=to_square;//add to sum
//  		ss.str( std::string() );//clear contents of the string stream, repeat;
//  	}
//  
//  	std::cout<<"The last 10 digits of the sum given above are " <<" ";
//  	for(int i = sum.get_size()-11;i<sum.get_size();i++)std::cout<<sum[i];
//  	std::cout<<std::endl;
//  	return 0;
//  }
// 
//  void big_int_power(big_int &b_int, int power)
//  {
//  	big_int a = b_int;
//  	if(power>1)for(int i = 2;i<=power;i++)
//  	{
//  		b_int *=a;
//  	}
//  }
//here use modular exponentiation, see how much faster it becomes? other one is correct, but runs slooooowwwlly;
