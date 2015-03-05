////// ------- Project Euler 15 -------

//-- Lattice paths- How many paths are there through  a 20 x 20 lattice, only moving down and right, and starting at the top left? THere are 6 for a two x two lattice.

#include <iostream>
#include <sstream>
#include <string>
#include <fstream>
#include <cmath>

 #define N 20
 
 int main()
 {
 	 //Set-up grid, putting ones on the bottom and right edges.  Remember, there are N+1 nodes ! ._._. is a side of a 2 x 2 grid, for example.  Also, bottom index is at N.
     
 	long int grid[N+1][N+1];

      	#pragma omp parallel for
 	for(int i =0;i<(N+1);i++)
 	{
 		grid[N][i] = 1;
 		grid[i][N] = 1;
 	}
     
 	 // Now, back track through grid, adding filling in other entries:
     
 	for(int i = N-1;i>=0;i--)for(int j = N-1;j>=0;j--)grid[i][j]=grid[i+1][j]+grid[i][j+1];
         
 	std::cout<<"The total number of paths through an N x N grid are:"<<grid[0][0]<<std::endl;
 	return 0;
 }