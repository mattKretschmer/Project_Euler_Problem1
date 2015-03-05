/*  --------- Project Euler Number 57 -----------
		//Squre root convergents
		
		 Problem Statement-
		
		It is possible to show that the square root of two can be expressed as an infinite continued fraction.

√ 2 = 1 + 1/(2 + 1/(2 + 1/(2 + ... ))) = 1.414213...

By expanding this for the first four iterations, we get:

1 + 1/2 = 3/2 = 1.5
1 + 1/(2 + 1/2) = 7/5 = 1.4
1 + 1/(2 + 1/(2 + 1/2)) = 17/12 = 1.41666...
1 + 1/(2 + 1/(2 + 1/(2 + 1/2))) = 41/29 = 1.41379...

The next three expansions are 99/70, 239/169, and 577/408, but the eighth expansion, 1393/985, is the first example where the number of digits in the numerator exceeds the number of digits in the denominator.

In the first one-thousand expansions, how many fractions contain a numerator with more digits than denominator?
//Solution: 153

		*/
		
		
 #include <iostream>
 #include <sstream>
 #include <string>
 #include "big_int.h"
 int main()
 {
 	int limit = 1000,count=0;	
 	int num_dig, denom_dig,new_n;
 	std::string a, b,c="2";
 	big_int new_num(a),new_denom(b),intermed(a),multiplier(c);
 			
 for(int n = 1;n<=limit;n++)
 {
 	a="1";b="2";
 	new_n = n;
 	new_num.set_value(a),new_denom.set_value(b);
 	while(new_n>0)
 	{
 		if(new_n ==1)new_num = new_denom+new_num;
 
 		else
 		{
 	
 			new_num =new_denom*multiplier +new_num;
 			intermed = new_num;
 			new_num=new_denom;
 			new_denom = intermed;
 		}
 		new_n--;
 	}
 	if(new_num.get_size()>new_denom.get_size() )count++;
 }
 	std::cout<<count<<std::endl;
 
 
 
 	return 0;
 }