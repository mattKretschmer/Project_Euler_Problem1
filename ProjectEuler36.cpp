/*  --------- Project Euler Number 37
	//Double-base palindromes
	
	 Problem Statement
	
	The decimal number, 585 = 10010010012 (binary), is palindromic in both bases.

Find the sum of all numbers, less than one million, which are palindromic in base 10 and base 2.

(Please note that the palindromic number, in either base, may not include leading zeros.)

*/
 #include <cmath>
 #include <iostream>
 #include <string>
 #include <sstream>
 #define MAX 100
 
 int	mirror_num(int test, int size);
 bool palindromic( std::string &array1, int start,int end);
 int num_of_digits(int holder);
 bool palindromic2( int tester,int base);
 std::string	dec_to_bin(int to_convert);
 
 
 int main()
 {
	 int switched,num_dig;
	 long sum_overall=0;
	 bool is_Palindromic = false;
	 std::string bin_number;
	 for(int i = 1;i<MAX;i++)
	 {
		 num_dig = num_of_digits(i);
	
		switched = mirror_num(i,num_dig);
	
		//Convert i to binary appropriately;
		bin_number = dec_to_bin(i);
		//Test if binary is palindromic:
		is_Palindromic = palindromic(bin_number,0,bin_number.size()-1);
		if(switched==i && is_Palindromic==true)sum_overall+=i;
// 		if(palindromic2(i,2)==true && palindromic2(i,10)==true)sum_overall+=i;
	 }
 
	 std::cout<<" The sum of all double base palindromes less than 1 million is " <<sum_overall<<std::endl;
 
	 return 0;
 }
 
 
 std::string	dec_to_bin(int to_convert)
 {	//Finds the closes power of 2 to to_convert, then makes an array holding the binary representation, before transferring to a string to return.
 	int holder = to_convert,counter = 0;
 	
 	while(to_convert>=1)
 	{
 		to_convert/=2;
 		counter++;
 	}
 	
 	int* bin_array = new int[counter];
 	int index = counter-1;
 	while(holder>=1)
 	{
 		bin_array[index--]= holder%2;
 		holder/=2;
 	}
 	std::stringstream ss;
 	for(int i = 0;i<counter;i++)ss<< bin_array[i];
 
 	delete [] bin_array;
 	return ss.str();
 }
 int num_of_digits(int holder)
 {
 		int digit_sum=0;
 		while(holder>0)
 		{
 			holder/=10;
 			digit_sum++;
 		}
 		return digit_sum;
 }
 
 int	mirror_num(int test, int size)
 	{ //Mirrors the number inputed.
 		int* new_num = new int[size];
 		int remainder = 0;
 		int new_new_num = 0;
 
 		for(int i = 0;i<size;i++)
 		{
 			new_num[i] = test%10;
 			test/=10;
 		}
 		long pow = 1;
 		
 		for(int i = size-1;i>=0;i--)
 		{
 			new_new_num += new_num[i]*pow;
 			pow*=10;
 		}
 	
 		
 		delete [] new_num;
 	return new_new_num ;
 	}
 	
 bool palindromic2( int tester,int base)
 {	/*Clever function for checking in arbitrary base if the number is palindromic. Speedy! */
 	long reversed = 0;
 	int k = tester;
 	//finds last digit of tester, multiplies it by base, effectively making it first, etc. Does this process in an arbitrary base.  
 	while(k>0)
 	{
 		reversed = base* reversed + k%base;
 		k/=base;
 	}
 	return tester==reversed;
 
 
 }	
 bool palindromic( std::string &array1, int start,int end)
 {//Checks if a string is palindromic.
 	bool indicator = false;
 	if(start>=end) indicator = true;
 	
 	else if(array1[start]==array1[end])
 	{
 		return palindromic(array1, start+1,end-1);
 	}
 	else indicator =false;
 	
 	return indicator;
 
 }