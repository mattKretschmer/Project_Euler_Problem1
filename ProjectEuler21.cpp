/* --------- Project Euler Number 21 -----------
Problem Statement:
  Let d(n) be defined as the sum of proper divisors of n (numbers less than n which divide evenly into n).
  If d(a) = b and d(b) = a, where a ≠ b, then a and b are an amicable pair and each of a and b are called amicable numbers.
  
  For example, the proper divisors of 220 are 1, 2, 4, 5, 10, 11, 20, 22, 44, 55 and 110; therefore d(220) = 284. The proper divisors of 284 are 1, 2, 4, 71 and 142; so d(284) = 220.
  
  Evaluate the sum of all the amicable numbers under 10000.*/

/*Answer:: 31626 */


  #include <iostream>
  #include <sstream>
  #include <string>
  #include <fstream>
  #include <cmath>

  #define MAX 10000
  
  void find_amicable_numbers( int limit, int (*list)[2] ); //Passes a pointer to an array of two dimensional ints.
  
  int main() 
  {
  	int list[MAX+1][2]={0}; //Will store numbers, and the sum of their divisors
  	for(int i = 0;i<MAX+1;i++)list[i][0]+=i; //setup left column of list
  	//Find amicable nums under 10k.
  	for(int i = 1;i<MAX+1;i++)find_amicable_numbers(i,list);
  	
  	int total_sum = 0;
  	//Now, list will only hold zeros and amicable numbers, in second column, sum to get answer!
  	for(int i = 1;i<MAX+1;i++)total_sum+=list[i][1];
  	
  	std::cout<<"The total sum of amicable number factors is equal to "<<total_sum<<std::endl;
  
  
  
  
  }
  
  void find_amicable_numbers( int limit, int (*list)[2] )
  {
  
  		int sum = 1;
  		//First, if we haven't done so, find the sum of divisors of a number
  		if(list[limit][1]==0)for( int i = 2;i<= limit/2;i++)if(limit%i==0)sum+=i;
  	
  		int sum_2 = 1;
  		//Find the sum of divisors of that number
  		if(sum<MAX && list[sum][1]==0)for(int i = 2;i<=sum/2;i++)if(sum%i==0)sum_2+=i;
  
  		//if the two numbers are less than 10k, not equal to one another, and amicable, record them.
  		if((sum_2==limit && sum<MAX) && (limit!=sum))
  		{
  		// Need to not be equal to the same number! otherwise we double count.
  			list[limit][1]=sum;
  			list[sum][1]=sum_2;
  		}
  }