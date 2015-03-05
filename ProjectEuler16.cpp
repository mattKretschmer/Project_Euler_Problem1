/*       ------- Project Euler 16 --------
 
      -- Sum of Digits of 2^1000.  In short: Find 2^1000, then sum all of the digis */
#include <iostream>
#include <sstream>
#include <string>
#include <fstream>
#include <cmath>

 #define N 1000
 #define ARRAY_SIZE 10*N
 void mult_by_two(int *array);
 
 int big_num[ARRAY_SIZE]={0};
 
 /*
 	Will do multiplication the old school way, in an array and storing the result.
 */
 int main()
 {
 	big_num[N-1]=1;  initialize, 2^0;
 	for(int i = 0;i<N;i++)mult_by_two(big_num);
 	
 	long int sum = 0;
 	for(int i = 0;i<ARRAY_SIZE;i++)sum +=big_num[i];
     
     std::cout<<"The sum of the digits of 2^ "<<N<< " is "<<sum<<std::endl;
     
     
 }
 
 
 void mult_by_two(int *array)
 {
 	int carry = 0,holder;
 	
 	for(int i= ARRAY_SIZE-1;i>=0;i--)
 	{
 		holder = array[i]*2 + carry;
 		if(holder>=10)
         {
 			array[i]= holder-10;
 			carry = 1;
 		}
 		else
         {
             carry = 0;
             array[i]=holder;
 	
         }
     }
     
 }