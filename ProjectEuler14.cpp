   //------- Project Euler 14-------
     // Find longest collatz sequence: n ->n/2 if n is even, n->3n+1 if n is odd. Find number with longest collatz chain.
#include <iostream>
#include <sstream>
#include <string>
#include <fstream>
#include <cmath>

#define LIMIT 50

 long find_collatz_sequence_length(long int n);
 long find_collatz_sequence_length_with_memoization(long int n,long *list_of_lengths);
 
 int main()
 {
     long max_seq_length = 0,seq_length=0,max_number = 0;
     long start = 1, list_of_lengths[LIMIT]={0} ;
 
     while(start<=LIMIT)
     {
         seq_length = find_collatz_sequence_length_with_memoization(start,list_of_lengths);
         if(seq_length>max_seq_length)
         {
             max_seq_length = seq_length;
             max_number = start;
         }
         start++;
     }
     std::cout<<"The number under a million with the largest Collatz sequence is : "<<max_number<<" , and the length of its sequence is "<<max_seq_length<<" numbers."<<std::endl;
     return 0;
 }
 
 
  long find_collatz_sequence_length(long int n)
  {
      long sequence_length = 1.;
      while(n!=1)
      {
          if(n%2 == 0){n /=2;sequence_length+=1;}
          else{ n=3*n+1;sequence_length+=1;}
      }
      return sequence_length;
  }
 
 long find_collatz_sequence_length_with_memoization(long int n,long *list_of_lengths)
 {
     long sequence_length = 1.,moveable_index = n;
     
     while(n!=1){
 
         if(n%2 == 0)
         {
                 n /=2;
             sequence_length++;
 
             if(n<moveable_index && n < LIMIT)
             {
                     sequence_length+=list_of_lengths[n-1];
                     break;
             }
         }
         else{ n=3*n+1;sequence_length+=1;}
         
     }
     list_of_lengths[moveable_index-1]=sequence_length;
      std::cout<<list_of_lengths[moveable_index-1]<<'\t'<<moveable_index<<std::endl;
     return sequence_length;
 }