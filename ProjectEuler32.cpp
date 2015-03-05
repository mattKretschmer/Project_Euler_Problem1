/*  --------- Project Euler Number 32 -----------
		//Pandigital Products
		
		Problem Statement-
	
		We shall say that an n-digit number is pandigital if it makes use of all the digits 1 to n exactly once; for example, the 5-digit number, 15234, is 1 through 5 pandigital.

	The product 7254 is unusual, as the identity, 39 × 186 = 7254, containing multiplicand, multiplier, and product is 1 through 9 pandigital.

	Find the sum of all products whose multiplicand/multiplier/product identity can be written as a 1 through 9 pandigital.

	HINT: Some products can be obtained in more than one way so be sure to only include it once in your sum.


	Solution: 45228, in something like 0.2 seconds
	*/
	
	/* Pseudocode: Multiplicand and multiplier wont' be maximally bigger than 10^3, cause 10^3*10^3 = 10^6 (Too many digits)  */
 #include <cmath>
 #include <sstream>
 #include <string>
 #include <iostream>
 #include <vector>
 #include <algorithm>
 
 
 int main()
 {
 	long c;
 	long sum = 0;
 
 	std::stringstream ss;
 	std::string output;
 	std::vector<long> product_list;
 	product_list.push_back(0);	
 
 	//Setup search loop here:
 	for(long a = 2;a<100;a++)
 		for(long b =a+1;b<10000/a ; b++)//Initially limit was 2k, but we can adjust because max product of a & b is 10k.
 		{
 			if(a%10==0 || b%10==0)continue; //skip unncessary cases.
 			
 			c = a*b;
 			ss<<a;
 			ss<<b;
 			ss<<c;
 		 	output = ss.str();
 		 	
 			//Put the multiplicant and multiplier into a string, then we can check if the the resulting number has 9 digits, and if once the duplicates are removed, and it hasn't been found yet, we can add it to the list and add to our running sum.
 			if(output.size()==9)
 			{
 				std::sort(output.begin(),output.end());
 				output.erase( std::unique( output.begin(),output.end() ),output.end() );
 		
 				//if pandigital:
 				if(output.size()==9 && output[0]!='0')
 				{
 					//If we haven't found c already yet, add it to our list, and add it to our sum.
 					if( !(std::find(product_list.begin(),product_list.end(),c)!=product_list.end() ) )
 					{
 						sum+=c;
 						product_list.push_back(c);
 					}
 					//std::cout<<a<<" "<<b<<" "<<c<<" "<<sum<<" "<<output<<std::endl;
 				}
 				
 			}
 			//Get string stream, output ready for next go around.
 			ss.str(std::string());//clear string stream;
 			output.erase();
 		}
   //End Loop here
 
 std::cout<<" The sum of products from pandigital multiplications is equal to "<<sum<<std::endl;
 
 return 0;
 }
