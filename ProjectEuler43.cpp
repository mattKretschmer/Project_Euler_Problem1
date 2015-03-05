/*  --------- Project Euler Number 43 -----------
		//Sub-string divisibility
		
		Problem Statement-

The number, 1406357289, is a 0 to 9 pandigital number because it is made up of each of the digits 0 to 9 in some order, but it also has a rather interesting sub-string divisibility property.

Let d1 be the 1st digit, d2 be the 2nd digit, and so on. In this way, we note the following:

d2d3d4=406 is divisible by 2
d3d4d5=063 is divisible by 3
d4d5d6=635 is divisible by 5
d5d6d7=357 is divisible by 7
d6d7d8=572 is divisible by 11
d7d8d9=728 is divisible by 13
d8d9d10=289 is divisible by 17
Find the sum of all 0 to 9 pandigital numbers with this property.

//Solution:16695334890 //Also possible to do by hand

	*/
 #include <iostream>
 #include <string>
 #include "project_euler_functions.h"
 	
 long make_num(std::string &permuted_string,int index,int dist);
 
 int main()
 {
 	int divisor_num = 7,test_prod;
 	int divisor_list[7] = {2,3,5,7,11,13,17};
 	std::string permuted_string = "9876543210";
 	long long sum = 0,test_num;
 
 while(permuted_string != "0123456789")
  	{
  		int counter = 0;
 		for(int i = 0;i<divisor_num;i++)
 		{	
 			test_prod =make_num(permuted_string,i+3,3);
 			if(test_prod%divisor_list[i]!=0)break;
 			else counter++;
 		}
 
 		if(counter ==divisor_num)//make number from string, add to sum.
 		{
 			test_num =make_num(permuted_string,9,10);
 			sum+=test_num;
 		}
 		next_descending_string_perm(permuted_string);
 
 
 	}
 	std::cout<<" The sum of all pandigital primes with the specified property is equal to "<<sum<<std::endl;
 	return 0;
 }
 
 long make_num(std::string &permuted_string,int start,int dist)
 {
 	long pow = 1;
 	long  num = 0;
 	
 	for(int i = 0;i<dist;i++)
 	{
 		num+=pow*(permuted_string[start-i]-'0');
 		pow*=10;
 	}
 	return num;
 }
