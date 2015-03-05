/*  --------- Project Euler Number 33 -----------
		//Digit Canceling Fractions
		
		Problem Statement-
		
		The fraction 49/98 is a curious fraction, as an inexperienced mathematician in attempting to simplify it may incorrectly believe that 49/98 = 4/8, which is correct, is obtained by cancelling the 9s.

We shall consider fractions like, 30/50 = 3/5, to be trivial examples.

There are exactly four non-trivial examples of this type of fraction, less than one in value, and containing two digits in the numerator and denominator.

If the product of these four fractions is given in its lowest common terms, find the value of the denominator.

	*/
	
	/*Solution== 100;  However, with clever thinking, can only reduce the search space to 84 searches! Think of cases where amicable numbers happen. */
 	
 #include <cmath>
 #include <iostream>
 
 
 int main()
 {
 	int a_tens,a_ones,b_tens,b_ones;
 	long numerator = 1,denominator = 1;
 	for(int a = 11;a<100;a++)
		for(int b = a+1;b<100;b++)
		{
			if(a%10==0 || b%10==0)continue;//Skips 'trivial ones'
		
			a_tens = a/10;
			a_ones = a%10;
			b_tens = b/10;
			b_ones = b%10;
			
			//Keep a running product of these examples, in the terms of numerator and denominator.
			if( a_tens ==b_tens  && b_ones*a==a_ones*b){numerator*=a_ones;denominator*=b_ones;}
			else if( a_tens == b_ones && b_tens*a==a_ones*b){numerator*=a_ones;denominator*=b_tens;}
			else if( a_ones == b_tens && b_ones*a==a_tens*b){numerator*=a_tens;denominator*=b_ones;}
			else if( (a_ones == b_ones && a_ones!=0) && b_tens*a==a_tens*b){numerator*=a_tens;denominator*=b_tens;}
		}	
 	//Factorize "fraction"
 	int a = 2;
 	
 	while(a<=numerator)
 	{
 		if(numerator%a==0 && denominator%a==0)
 		{
 			numerator/=a;
 			denominator/=a;
 		}
 		a++;
 	}
 	std::cout<<numerator<<" "<<denominator<<std::endl;
 
 	return 0;
 }