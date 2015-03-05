/*  --------- Project Euler Number 25 -----------
		 1000 digit Fibonacci number
		
	Problem Statement-
			The Fibonacci sequence is defined by the recurrence relation:

		Fn = Fn−1 + Fn−2, where F1 = 1 and F2 = 1.
		Hence the first 12 terms will be:

		F1 = 1
		F2 = 1
		F3 = 2
		F4 = 3
		F5 = 5
		F6 = 8
		F7 = 13
		F8 = 21
		F9 = 34
		F10 = 55
		F11 = 89
		F12 = 144
		The 12th term, F12, is the first term to contain three digits. 
		
		What is the first term in the Fibonacci sequence to contain 1000 digits?*/
		
		/* Solution-> 4782.  Got by brute force, although there are some elegant ways to do it.*/
		
  #include <iostream>
  #include <sstream>
  #include <string>
  #include <fstream>
  #include <cmath>	
  #include "big_int.h"/* A new class I wrote that stores "ints" as strings". It got the job done.*/		
  #define MAX_DIG 1000
  
  
  
  int main()
  {
  	std::string a = "1";
  	big_int one(a),two(a),three(a);
  	int counter = 2;
  	while(three.get_size()<=MAX_DIG-1)
  	{
  		three = one + two;
  		 //reset numbers;
  		one = two;
  		two = three;
  		counter++;
  	}
  	std::cout<<"The first Fibonacci Number to have "<< MAX_DIG<< " digits occurs at term " <<counter<<std::endl;
  	
  	return 0;
  }