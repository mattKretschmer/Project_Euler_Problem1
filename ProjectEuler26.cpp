/*--------- Project Euler Number 26 -----------
		//Reciprocal Cycles
		
	Problem Statement-
			A unit fraction contains 1 in the numerator. The decimal representation of the unit fractions with denominators 2 to 10 are given:

	1/2	= 	0.5
	1/3	= 	0.(3)
	1/4	= 	0.25
	1/5	= 	0.2
	1/6	= 	0.1(6)
	1/7	= 	0.(142857)
	1/8	= 	0.125
	1/9	= 	0.(1)
	1/10	= 	0.1
	Where 0.1(6) means 0.166666..., and has a 1-digit recurring cycle. It can be seen that 1/7 has a 6-digit recurring cycle.

	Find the value of d < 1000 for which 1/d contains the longest recurring cycle in its decimal fraction part.
	*/

 #include <iostream>
 #include <sstream>
 #include <string>
 #include <cmath>
 #include <vector>
 
 #define D_MAX 1000
 
 int find_sequence_length(int d);
 
 int main()
 {
 	std::vector<int> decimal_list;
 	int max_sequence_length = 0,sequence_length = 0,max_d;
 	//Count down from 1000.  Maximum recurring sequence is d-1.  Stop when our max is >d.
 	for(int d = D_MAX - 1;d>11;d--)
 	{
 		sequence_length = find_sequence_length(d);
 		if(sequence_length>max_sequence_length)
 			{
 				max_sequence_length = sequence_length;
 				max_d = d;
 			}
 		if(max_sequence_length>d)break;
 	}
 	std::cout<<"The maximum repeating length is equal to "<<max_sequence_length<<", at number "<<max_d<<std::endl;
 }
 
 
 int find_sequence_length(int d)
 {
 	std::vector<int> modulo_list,denominator_list;
 	modulo_list.push_back(0);
 	denominator_list.push_back(0);
 	
 	int denominator = 10; 
 	int modulo = 0,remain,start;
 	bool repeat =false,non_repeat = false;
 	while(!(repeat))//while repeat is not true (or hasn't been found
 	{
 		modulo = denominator/d;
 		remain = denominator %d;
 
 		if(remain==0)
 			{
 				non_repeat=true;
 				break;//No more repeats!
 			}
 		for(int i =0;i<modulo_list.size();i++)
 			{
 				if( modulo_list[i]==modulo && denominator_list[i]==denominator)
 				{
 					repeat=true;
 					start = i;
 				}
 			}
 		//if a repeat hasn't been found, add what we have and continue.
 		modulo_list.push_back(modulo);
 		denominator_list.push_back(denominator);
 		denominator = 10*remain;
 		if(repeat==true)break;
 
 	}
 	if(non_repeat==true)return 0;
 	else return modulo_list.size()-(1+start); //start is 0-based, so add 1.  Size is position of last element, in 1-based index.
 