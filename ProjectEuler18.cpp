/*     / ------- Project Euler 18 ---------
 
  Problem Statement: Find maximum path sum from the top to the bottom of a triangle, stored in file Triangle.txt;
*/ 
#include <iostream>
#include <sstream>
#include <string>
#include <fstream>
#include <cmath> 
#include <algorithm>
#define SIZE 15 

 
char file_in[]="Triangle.txt";
 
 
 
 std::string mystring;
 int triangle_Array[SIZE][SIZE]={0};
 
int counter = 0;
 int main()
 {
     
     std::ifstream fin;
     fin.open(file_in);
     
 		//Initially load the triangle from the file into a multidimensional array, but this does not load the entries in the right places.
         for(int i = 0;i<SIZE;i++)for(int j = 0;j<=i;j++)fin>>triangle_Array[i][j];
 
 /* Move the triangle so the entries in the two dimensional array are actually triangular! */
     int real_triangle_Array[SIZE][2*SIZE]={0};
     int start = 0;
     for(int i = SIZE-1;i>=0;i-- )
     {
         for(int j = 0 ;j<SIZE;j++)real_triangle_Array[i][2*j + start]=triangle_Array[i][j];
         start++;
 
     }
 
      //  //Print out triangle, to check it was loade din properly
//       for(int i = 0;i<SIZE;i++)
//       {
//           for(int j = 0;j<2*SIZE;j++)
//           {
//               std::cout<<real_triangle_Array[i][j]<<"  ";
//               
//           }
//           std::cout<<'\n';
//           
//       }
     
      //Now that the triangle is properly loaded, go backwards, finding max sum of points below.
     
     start = 1;
     for(int i = SIZE-2;i>=0;i--)
     {
         for(int j = 0;2*j+start<2*SIZE;j++)
         {
             real_triangle_Array[i][2*j +start] += max(real_triangle_Array[i+1][2*j+start+1],real_triangle_Array[i+1][2*j+start-1]);
             
         }
         start++;
     }
     
     /*Print out the maximum path*/
     std::cout<<"The sum of the maximum path through the triangle is equal to "<<real_triangle_Array[0][SIZE-1]<<std::endl;
     
     
 }