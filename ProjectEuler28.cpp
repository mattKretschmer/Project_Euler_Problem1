/*  --------- Project Euler Number 28 -----------
		//Number Spiral diagonals
		
	Problem Statement-


		Starting with the number 1 and moving to the right in a clockwise direction a 5 by 5 spiral is formed as follows:

		21 22 23 24 25
		20  7  8  9 10
		19  6  1  2 11
		18  5  4  3 12
		17 16 15 14 13

		It can be verified that the sum of the numbers on the diagonals is 101.

		What is the sum of the numbers on the diagonals in a 1001 by 1001 spiral formed in the same way?  */
 #include <iostream>		
 #include <cmath>
 	
 #define SPIRAL_SIZE 1001	
// 	long recursive_function(int ring_num);

 
 int main () 
 {
 	int max_ring = SPIRAL_SIZE/2,ring_num = 1,jump_counter,position=1 ;
 	long sum = 1;
 	
 	while(ring_num <=max_ring)
 	{
 		jump_counter =0; //Keeps tracks of turns we've made, so that we know when we've returned and need to jump to the next biggest ring. Here' we'll just add to the sum of the diagonal entries whenever were on the corner.
 		while(jump_counter<4)
 		{
 			position +=2*ring_num;
 			sum +=position;
 			jump_counter++;
 		}
 		ring_num++;
 	
 	}
 	std::cout<<"The diagonal sum of a "<<SPIRAL_SIZE<<" by "<<SPIRAL_SIZE<<" spiral is equal to "<<sum<<std::endl;
 	return 0;
 }
 
 // long recursive_function(int ring_num)
//  {
//  	/*Derived from a recursive formula the sum of the entries at the corner of the nth ring*/
//  	long ret_val = 0;
//  	if(ring_num>0)
//  	{
//  		ret_val = 4*(2*ring_num+1)*(2*ring_num+1)-12*ring_num + recursive_function(ring_num-1);
//  	}
//  	else
//  		ret_val = 1;
//  	return ret_val;
//  }