/*   --------- Project Euler Number 24 -----------
		 Lexographic Permutations
		
Problem Statement -
		
		A permutation is an ordered arrangement of objects. For example, 3124 is one possible permutation of the digits 1, 2, 3 and 4. If all of the permutations are listed numerically or alphabetically, we call it lexicographic order. The lexicographic permutations of 0, 1 and 2 are:

012   021   102   120   201   210

What is the millionth lexicographic permutation of the digits 0, 1, 2, 3, 4, 5, 6, 7, 8 and 9? */

/* Pseudocode: Scan from left to right, and find furthest entry, k, where its value is less than its immediate right-neighbor.  Then you find the left-most entry greater than entry k. Swap l and k entries, and reverse elements in between.  */

  #include <iostream>
  #include <sstream>
  #include <string>
  #include <cmath>

  #define MAX_PERM 1000000
  
  void string_swap( std::string &string, int location_1,int location_2);
  
  
  int main()
  {
  	std::string permuted_string = "0123456789";
  	int size = permuted_string.size();
  	
  	long iteration_counter = 1;
  	int biggest_k = 0,biggest_l = 0,counter=0;
  	
  	 //Use Djikstra's algorithm
  	while(iteration_counter < MAX_PERM)
  	{
  		 //find largest k, such that permuted_string[k]<permuted_string[k+1];
  		 biggest_k = 0;
  		for(int i = 0;i<size-1;i++)if(permuted_string[i]<permuted_string[i+1] && i>biggest_k)biggest_k = i;
  		
  		 //Stops loop if we've found last permutation,which occurs when numbers are all decreasing
  		counter =0 ;
  		for(int i = 0;i<size-1;i++)if(permuted_string[i]>permuted_string[i+1])counter+=1;
  		if(counter==size-1)break;
  
  		 //Find largest index l such that a[k]<a[l];
  		 biggest_l = biggest_k;
  		for(int i = biggest_k+1;i<size;i++)if(permuted_string[i]>permuted_string[biggest_k] && i >biggest_l)biggest_l = i;
  
  		 //swap these k,l values;
  		string_swap(permuted_string,biggest_k,biggest_l);
  	
  		 //Reverse values from biggest_k + 1 to final element.  
  		int i = biggest_k + 1,j = size-1;
  		while(i !=j)
  		{
  			string_swap(permuted_string,i,j);
  			i++;
  			j--;
  			if(i>j)break; //If this happens we've "walked" by each other
  		}
  		iteration_counter++; 
  	}	
  		
  	std::cout<<"The "<< MAX_PERM <<"th lexicographic permutation is equal to "<<permuted_string<<std::endl;
  
  
  return 0 ;
  }
  
  void string_swap( std::string &string, int location_1,int location_2)
  {
  	char temp = string[location_1];
  	string[location_1]=string[location_2];
  	string[location_2]=temp;
  }