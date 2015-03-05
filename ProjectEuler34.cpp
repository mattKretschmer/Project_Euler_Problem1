/*  --------- Project Euler Number 34 -----------
		//Digit Factorials
		
	Problem Statement-
	
	145 is a curious number, as 1! + 4! + 5! = 1 + 24 + 120 = 145.

Find the sum of all numbers which are equal to the sum of the factorial of their digits.

Note: as 1! = 1 and 2! = 2 are not sums they are not included.
	*/
	
	//Solution: 40730  
	//Solved 1/13/14
	
 #include <cmath>
 #include <iostream>
 	
 long factorial(int n);
 
 int main()
 {
 	long a = 5,b = 1,sum = 0,digit_sum=0,holder;
 	int remainder = 0;
 	//pre_calculate and store the factorials of 0-9.
 	long factorial_holder[10];
 	for(int i = 0;i<10;i++)factorial_holder[i]=factorial(i);
 	
 	//Upper limit of search is determined by the fact that 9!*8 is also a 7 digit number.
 	long upper_limit = 7*factorial_holder[9];
 	for(long i = 10;i<upper_limit;i++)
 	{
 		holder = i;
 		digit_sum=0;
 		while(holder>0)
 		{
 			remainder = holder%10;
 			holder/=10;
 			digit_sum+=factorial_holder[remainder];
 		}
 		if(digit_sum==i)sum+=i;
 	
 	}
 	
 std::cout<<"The sum of all numbers equal to the sum of the factorial of their digits is equal to "<<sum<<std::endl;
 return 0;
 }
 
 long factorial(int n)
 {	//Recursive factorial function
 	if( n==0)return 1;
 	else return n*factorial(n-1);
 
 }