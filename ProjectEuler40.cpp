/* --------- Project Euler Number 40 -----------
		//Champernowne's constant		
		Problem Statement-
	
	An irrational decimal fraction is created by concatenating the positive integers:

0.123456789101112131415161718192021...

It can be seen that the 12th digit of the fractional part is 1.

If dn represents the nth digit of the fractional part, find the value of the following expression.

d1 × d10 × d100 × d1000 × d10000 × d100000 × d1000000

	*/
	
	//Anser: 210!  Run time 0.005 seconds (or less)
	
	/*Searches while the total digit numbers is less than 100000.  Since numbers change digits at 9,99,999,pow-1, we address that there.  Each iteration we also update how many digits we've added to our sequence, as well as what numbers we've added.  If we've overshot where we are searching, we find out what digit satisfies the power of tenth-digit, and update the new search limit. */
 #include <iostream>
 
 #define MAX  1000000
 
 int	nth_dig(int num,int dig_diff);
 
 
 int main()
 {
 	int dig_to_add = 1,pow = 10,dig_count = 0;
 	int i = 0,n_dig,product = 1;
 	int dig_to_search = pow,dig_diff ;
 	
 	while(dig_count<=MAX)
 	{
 
 		if(i==pow-1)
 		{
 			dig_to_add++;
 			pow*=10;
 		}
 				
 		dig_count+=dig_to_add;	
 		i++;
 		if(dig_count>=dig_to_search)
 		{
 			dig_diff = dig_count-dig_to_search+1;
 			n_dig = nth_dig(i,dig_diff);
 			product*=n_dig;
 			dig_to_search*=10;
 		}
 		std::cout<<i<<std::endl;
 		
 	}
 	std::cout<<product<<std::endl;
 return 0;
 }
 
 int	nth_dig(int num,int dig_diff)
 {	
 	for(int i = 1;i<dig_diff;i++)
 	{
 		num/=10;
 	}
 	
 	return num%10;
 }