/* --------- Project Euler Number 56 -----------
		//Powerful digit sum
		
		 Problem Statement-
		
		A googol (10100) is a massive number: one followed by one-hundred zeros; 100100 is almost unimaginably large: one followed by two-hundred zeros. Despite their size, the sum of the digits in each number is only 1.

Considering natural numbers of the form, a^b, where a, b < 100, what is the maximum digital sum?
//Solution : 972 Had to use big_int class.
		*/
		
 #include <iostream>
 #include <string>
 #include <sstream>
 #include "big_int.h"
 
 
 int main()
 {
 	
 	std::string ss_a="",holder="1",helper = "";
 	big_int ba(ss_a),bholder(holder);
 	int max_digit_sum = 0,digit_sum;
 
     int limit = 100;
     std::stringstream to_convert;
     for(int a = 1;a<limit;a++)
     {
     
     	to_convert<<a;
         ba.set_value(to_convert.str() );
     	for(int b = 2;b<limit;b++)
     	{
     	        digit_sum = 0;
     		bholder*=ba;//find next power
     		helper= bholder.get_value();
     		for(int i=0;i<helper.size();i++)digit_sum+=helper[i]-'0';
     		if(digit_sum>max_digit_sum)max_digit_sum=digit_sum;
     	
     	}
     	
     	to_convert.str(std::string());
         ba.clear_value();//erase bigint
         holder.clear();
         holder = "1";
         bholder = holder;
         
         
     }
                
         std::cout<<max_digit_sum<<std::endl;
     
 }