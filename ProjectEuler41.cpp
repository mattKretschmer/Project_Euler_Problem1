/* --------- Project Euler Number 41 -----------
		//Pandigital Prime
		Problem Statement-
	
	We shall say that an n-digit number is pandigital if it makes use of all the digits 1 to n exactly once. For example, 2143 is a 4-digit pandigital and is also prime.

What is the largest n-digit pandigital prime that exists?

	*/

//Solution: 7652413

 #include <iostream>
 #include <sstream>
 #include <string>
 #include <cmath>
 
 #define MAX_PERM 1000000
 
 void string_swap( std::string &string, int location_1,int location_2);
 bool isPrime(long value);
 void next_string_perm( std::string &permuted_string);
 
 int main()
 {
 	std::string permuted_string = "987654321",original_string = "987654321",swapped_string = "123456789";
 	std::stringstream ss;
 	int isprime = false;
 	long num_to_test = 0, pow = 1,string_length,counter = 1;
 	
 while(isprime ==false)
  	{
 		next_string_perm( permuted_string );
 		//make string into long
 		pow = 1;
 		num_to_test = 0;
 		for(int i = permuted_string.size()-1;i>=0;i--)
 		{
 			num_to_test += pow *(permuted_string[i]-'0');
 			pow*=10;
 		}
 		//test
 		isprime = isPrime(num_to_test);
 		if(permuted_string == swapped_string)
 		{
 			string_length = permuted_string.size();
 
 			swapped_string.clear();
 			permuted_string.clear();
 			for(int i = counter;i<9;i++)
 			{
 				ss<<original_string[i];
 			}
 			permuted_string = ss.str();
 			ss.str(std::string());
 			
 			for(int i = 1;i<string_length;i++)
 			{
 				ss<<i;
 			}
 			swapped_string = ss.str();
 			ss.str(std::string() );
 			counter++;
 
 		}
 	
  }
 	std::cout<<"The Biggest pandigital prime number is "<<permuted_string<<std::endl;	
 return 0 ;
 }
 
 bool isPrime(long value)
 {
     bool primeIndicator = true;
 	long long int divisor = 2; //A starting point
 	while(divisor <= sqrt(value))
 	{
         if(value%divisor==0){primeIndicator = false; break;}
         divisor++;
 	}
 	return primeIndicator ;//Returns the final most prime value.
 }
 
 void next_string_perm( std::string &permuted_string)
 {
 		int size = permuted_string.size();
 		int biggest_k = 0,biggest_l = 0,counter=0,index_i,index_j;
 	
 	
 			//find largest k, such that permuted_string[k]>permuted_string[k+1];
 			 biggest_k = 0;
 			for(int i = 0;i<size-1;i++)if(permuted_string[i]>permuted_string[i+1] && i>biggest_k)biggest_k = i;
 		
 			//Stops loop if we've found lowest permutation,which occurs when numbers are all increasing
 			counter =0 ;
 			for(int i = 0;i<size-1;i++)if(permuted_string[i]<permuted_string[i+1])counter+=1;
 			if(counter==size-1)goto end; //can't use break, not in a loop!
 
 			//Find largest index l such that a[k]>a[l];
 			 biggest_l = biggest_k;
 			for(int i = biggest_k+1;i<size;i++)if(permuted_string[i]<permuted_string[biggest_k] && i >biggest_l)biggest_l = i;
 
 			//swap these k,l values;
 			string_swap(permuted_string,biggest_k,biggest_l);
 	
 			//Reverse values from biggest_k + 1 to final element.  
 			 index_i = biggest_k + 1,index_j = size-1;
 			while(index_i !=index_j)
 			{
 				string_swap(permuted_string,index_i,index_j);
 				index_i++;
 				index_j--;
 				if(index_i>index_j)break;//If this happens we've "walked" by each other
 			}
 		end: ;
 
 }
 void string_swap( std::string &string, int location_1,int location_2)
 {
 	char temp = string[location_1];
 	string[location_1]=string[location_2];
 	string[location_2]=temp;
 }