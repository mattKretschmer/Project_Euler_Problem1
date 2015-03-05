/*  --------- Project Euler Number 38 -----------
		//Pandigital Multiples
		
	Problem Statement-
	
	Take the number 192 and multiply it by each of 1, 2, and 3:

192 × 1 = 192
192 × 2 = 384
192 × 3 = 576
By concatenating each product we get the 1 to 9 pandigital, 192384576. We will call 192384576 the concatenated product of 192 and (1,2,3)

The same can be achieved by starting with 9 and multiplying by 1, 2, 3, 4, and 5, giving the pandigital, 918273645, which is the concatenated product of 9 and (1,2,3,4,5).

What is the largest 1 to 9 pandigital 9-digit number that can be formed as the concatenated product of an integer with (1,2, ... , n) where n > 1?

	*/
	
 #include <cmath>
 #include <sstream>
 #include <string>
 #include <iostream>
 #include <algorithm>
 
 
 int main()
 {
 	int c;
 
 	std::stringstream ss;
 	std::string output,holder,last_max="1";
 
 //Setup search loop here:
 	for(int a = 2;a<10000;a++)
 	{
 		for(int b =1;b<10 ; b++)
 		{
 			if(a%10==0 || b%10==0)continue; //skip unncessary cases.
 			
 			c = a*b;
 			if(output.size()<9)
 			{
 				ss<<c;
 			}
 			output = ss.str();
 			if(output.size()==9)break;
 		}
 		 	output = ss.str();
 		 	holder = ss.str();
 			//Makes sure that all elements are pandigital;
 			
 			if(output.size()==9)
 			{
 				std::sort(output.begin(),output.end());
 				output.erase( std::unique( output.begin(),output.end() ),output.end() );
 		
 				//if pandigital:
 				if(output.size()==9 && output[0]!='0')
 				{
 					if(holder > last_max)last_max = holder;
 				}
 			}
 				
 			//Get string stream, output ready for next go around.
 			ss.str(std::string());//clear string stream;
 			output.erase();
 			holder.erase();
 	}
 
 std::cout<<last_max<<std::endl;
 return 0;
 }

 //concatenates two longs, by shifting a to the left to add b.  A lot faster than strings.
 long int_concat(long a, long b)
 {
 	long c = b;
 	
 	while(c>0)
 	{
 		a*=10;
 		c/=10;
 	}
 	return a+b;
 }