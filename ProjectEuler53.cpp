/* --------- Project Euler Number 53 -----------
		//Combinatoric selections
		
		 Problem Statement-

		There are exactly ten ways of selecting three from five, 12345:

		123, 124, 125, 134, 135, 145, 234, 235, 245, and 345

		In combinatorics, we use the notation, 5C3 = 10.

		In general,

		nCr =	
		n!
		r!(n−r)!
		,where r ≤ n, n! = n×(n−1)×...×3×2×1, and 0! = 1.
		It is not until n = 23, that a value exceeds one-million: 23C10 = 1144066.

		How many, not necessarily distinct, values of  nCr, for 1 ≤ n ≤ 100, are greater than one-million?
	*/
	//Solution: 4075.  Interestingly, doubles work! even though the precision isn't the same as always dealing with ints.  One way to work is solve Pascal's triangle, looking for entries above 1 million
	
 #include <iostream>
 #include <cmath>
 
 double log_factorial(double X);
 
 int main()
 {
 	double numerator = 0.,d_r = 0.,d_nmr = 0.;
 	int limit = 100,counter = 0;
 	double max = log(1000000);
 	//Take log_10 of nCr, then check if the result is greater than 6.
 	for(int n = 1;n<=limit;n++)
 	for(int r = 1;r<=n;r++)
 	{
 		if(log_factorial(1.*n)-log_factorial(1.*r)-log_factorial(1.*(n-r)) >max)counter++;
 		
 	}
 std::cout<<counter<<std::endl;
 	return 0;
 }
 
 double log_factorial(double X)
 {
 	double newX = 0.;
 	while(X>0.)
 	{
 		newX+= log(X);
 		X-=1.;
 	}
 	
 	return newX;
 
 }