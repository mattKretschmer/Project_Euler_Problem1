/*  --------- Project Euler Number 76 -----------
		//Counting Summations
		
		Problem Statement-
	
	It is possible to write five as a sum in exactly six different ways:

4 + 1
3 + 2
3 + 1 + 1
2 + 2 + 1
2 + 1 + 1 + 1
1 + 1 + 1 + 1 + 1

How many different ways can one hundred be written as a sum of at least two positive integers?

*/
//Using dynamic programming, with summations not including 100, because that would be 0 and 100, need to add at least 1. Very similar to finding combinations of coins to make 2 dollars from earlier problem.
 #include <cmath>
 #include <iostream>
 int main()
 {
 
 	long newways[101]={0};
 	newways[0]=1;
 	goal = 100;
 	for(int i = 1;i<100;i++)for(int j = i;j<=goal;j++)newways[j]+=newways[ j-i];
 	std::cout<<newways[100]<<std::endl;
 
 }