/*  --------- Project Euler Number 39 -----------
		//Integer Right Triangles		
		Problem Statement-
	
	If p is the perimeter of a right angle triangle with integral length sides, {a,b,c}, there are exactly three solutions for p = 120.

{20,48,52}, {24,45,51}, {30,40,50}

For which value of p ≤ 1000, is the number of solutions maximised?

	*/
	
	//Think about pythagorean law, (if a&b are even, c even. If a&b odd, c even.  If a ||b odd, c odd.  Pythagorean triples ony occur for even p.
//solution: 840	
 #include <iostream>
 
 #define P_MAX 1000
 
 int main()
 {
 
 int max_p_sum = 0,local_sol_sum = 0,max_p_value=0,c = 0;
 for(int p = 3;p<=P_MAX;p+=2)
 {
 	//Scan through side one, then side two, with side 2 starting at side 1.
 	local_sol_sum = 0;
 	for(int a = 1;a<p/2;a++)
 		for(int b = a;b<p/2; b++)
 		{
 			 c = (p -a -b);
 			if(a*a + b*b ==c*c)local_sol_sum++;
 		
 		}
 		
 		if(local_sol_sum>max_p_sum)
 		{
 			max_p_sum=local_sol_sum;
 			max_p_value = p;
 		}
 }
 
 std::cout<<max_p_sum<<" "<<max_p_value<<std::endl;
 
 return 0;
 }