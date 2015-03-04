  //------ Project Euler #12 -------
     // Find the first 'triangle' number with > 500 divisors.  Triangle numbers are calculated by adding up the (consecutive) natural numbers

#include <iostream>
#include <sstream>
#include <string>
#include <fstream>
#include <cmath>

int num_of_divisors(long long int test_case);
 long long int make_triangle_num(int seed);
 
 int main(){
     long long int i = 36;
     int seed = 1,number_of_divisors = 1;
     while(number_of_divisors<=501)
     {
         i = make_triangle_num(seed);
         number_of_divisors =num_of_divisors(i);
         seed++;
     }
 
     std::cout<<"The first triangle number with > 500 divisors is : "<< i<<std::endl;
     return 0;
 }
 
 int num_of_divisors(long long int test_case)
 {
     int divise_num = 2;
     
     for(int i =2;i<sqrt(test_case);i++)if(test_case%i==0)divise_num+=2;
     return divise_num;
     
 }
 long long int make_triangle_num(int seed)
 {
     long long int triang_num = 0;
     
     for(int i = 1;i<=seed;i++)triang_num+=i;
         return triang_num;
 }