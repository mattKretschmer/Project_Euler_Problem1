/*      ------- Project Euler 20 --------
  Problem Statement:
       -- Find the sum of the digits of 100!
*/
#include <iostream>
#include <sstream>
#include <string>
#include <fstream>
#include <cmath>

#define LIMIT 100
std::string two_string_mult(std::string &string_1,std::string &string_2);//Admittedly bloated function, comments are in function definition.
  
  int main()
  {
  	std::string ss_1,ss_2="",holder="";
    ss_1="1";
      
    std::stringstream to_convert;
      
      for(int i = 1;i<=LIMIT;i++)
      {
          to_convert<<i;
          ss_2 = to_convert.str();
          holder = two_string_mult(ss_1,ss_2);
          to_convert.str(std::string());
          ss_1.clear();
          ss_2.clear();
          ss_1 = holder; //ss_1 now holds the factorial
          holder.clear();
      }
      
      long int digit_sum = 0;
      for(int i=0;i<ss_1.size();i++)digit_sum+=ss_1[i]-48;
      std::cout<<"The sum of the digits of "<<LIMIT<<" factorial is equal to "<<digit_sum<<std::endl;
  
  }
  
  
  std::string two_string_mult(std::string &string_1,std::string &string_2)
  {
       //First, we find out which of the strings is longer (if any).  If they're congruent, set one to "top" and the other to "bottom"
      int size_1 = string_1.size(),size_2 = string_2.size();
      string top="",bottom="";
      if(size_1<=size_2)
      {
          bottom = string_1;
          top = string_2;
      }
      else
      {
          top = string_1;
          bottom = string_2;
      }
      int top_size = top.size(),bottom_size = bottom.size();
       /*Once we have top and bottom strings, we get their size and store them in top_size and bottom_size;
       Going to initialize an array to hold what we need during multiplication.  Maximum we'll need is top_size+bottom_size, with bottom_size;*/
      
      int total_size = (top_size+bottom_size)*bottom_size,row_size = top_size+bottom_size;
      int *mult_holder=new int[total_size];
      for(int i = 0;i<total_size;i++)mult_holder[i]=0;
      
           mult_holder[i][j]=mult_holder[i*row_size +j]
      
      int holder = 0,carry = 0,row_index=0,col_index;
      for(int i = bottom.size();i>0;i--)
      {
          holder = 0; carry = 0,col_index = row_size-1;
          for(int j = top.size();j>0;j--)
          {
              
              holder = (top[j-1]-48)*(bottom[i-1]-48);
              if(holder>9)
              {
                  carry = holder/10;
                  mult_holder[row_index*row_size+col_index-row_index]+=holder%10;
                  mult_holder[row_index*row_size+col_index-1-row_index]+=carry;
  
              }
              else
              {
                  carry = 0;
                  mult_holder[row_index*row_size+col_index-row_index]+=holder;
  
              }
              col_index--;
          }
          row_index++;
      }
   
       /*the final array, we will store our product in:*/
      int *final_array = new int[row_size];
      for(int i = 0;i<row_size;i++)final_array[i]=0;
      
      carry = 0;holder = 0;
      
      for(int j =(row_size-1);j>=0;j--)
          for(int i = bottom.size()-1;i>=0;i--)
          {
              final_array[j]+=mult_holder[row_size*i +j];
              
          }
  
       //Haven't taken care of instances where numbers are greater than 9, here we do that.
      for(int i = row_size-1;i>0;i--)if(final_array[i]>9)
      {
          final_array[i-1]+= final_array[i]/10;
          final_array[i] = final_array[i] % 10;
          
      }
  
  
      std::stringstream ss;
       //trim the extra zeros in front
      int start = 0;
      for(int i = 0;i<row_size;i++)if(final_array[i]>0){start = i;break;}
      for(int i = start;i<row_size;i++)ss<<final_array[i];
  
      
       //free up memory we allocated for operations
      delete[] final_array;
      delete[] mult_holder;
      
      return ss.str();
  
      
  }