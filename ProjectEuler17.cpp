/*     -------- Project Euler 17 ----------
  
 Problem Statement: If the numbers 1 to 5 are written out in words: one, two, three, four, five, then there are 3 + 3 + 5 + 4 + 4 = 19 letters used in total.
  
  If all the numbers from 1 to 1000 (one thousand) inclusive were written out in words, how many letters would be used?
  
  
  NOTE: Do not count spaces or hyphens. For example, 342 (three hundred and forty-two) contains 23 letters and 115 (one hundred and fifteen) contains 20 letters. The use of "and" when writing out numbers is in compliance with British usage.*/

/*Solution found! 21124 total characters. Checked 12/25/2013 */
 
#include <iostream>
#include <sstream>
#include <string>
#include <fstream>
#include <cmath>
#include <map>  string already included above;
  
  #define LIMIT 1000
  #define SIZE 4
  
  
  int main()
  {
   //These map classes help to quickly look up names for digitsin number, used later. Sort of like a hash table.  Really useful!  
  std::map < int, string > tens,ones,teens,names;
  
   //if tens = 1, ones = 0-->ten; if tens = 1, ones !=0 ->teens[ones];
  tens[1] = "ten";
  tens[2]="twenty";
  tens[3]="thirty";
  tens[4]="forty";
  tens[5]="fifty";
  tens[6]="sixty";
  tens[7]="seventy";
  tens[8]="eighty";
  tens[9] = "ninety";
  
  ones[0]="";
  ones[1]="one";
  ones[2]="two";
  ones[3]="three";
  ones[4]="four";
  ones[5]="five";
  ones[6]="six";
  ones[7]="seven";
  ones[8]="eight";
  ones[9]="nine";
  
  teens[0]="ten";
  teens[1]="eleven";
  teens[2]="twelve";
  teens[3]="thirteen";
  teens[4]="fourteen";
  teens[5]="fifteen";
  teens[6]="sixteen";
  teens[7]="seventeen";
  teens[8]="eighteen";
  teens[9]="nineteen";
  
  names[1]="thousand";
  names[2]="hundred";
  names[3]= "and";
  
  int int_holder[SIZE]={0};
  long int character_sum = 0;
  
  for(int i = 1;i<=LIMIT;i++)
  {
  	 //first, find the number, as stored in an appropriate sized array.
  	int_holder[3]+=1;
  	for(int i = 3;i>0;i--)if(int_holder[i]>9){int_holder[i]=0;int_holder[i-1]++;}
  	 //Make a string to hold the name of the number:
  	std::string out_holder = "";
  	
  	if(int_holder[0]!=0)out_holder.append(ones[ int_holder[0]] + names[1] );  //n thousand, if needed.
  	if(int_holder[1]!=0) //Get the hundreds, if needed
  	{
  		out_holder.append(ones[ int_holder[1]] + names[2] );  n hundred ;
  		if(int_holder[3]!=0 || int_holder[2]!=0)out_holder.append( names[3] );
  	}
  
  	 Figure out last two digits.
  	if( int_holder[2]==0 &&int_holder[3]!=0 )out_holder.append(ones[ int_holder[3] ]); //ones
  	else if( int_holder[2]==1) out_holder.append(teens[ int_holder[3] ]); //teens
  	else out_holder.append(tens[ int_holder[2] ]+ones[int_holder[3]]); 
  	 //Add the sum of the letters for the current number
  	character_sum +=out_holder.size();
  }
  
  std::cout<<"The sum of all the letters for all the numbers under 1000 is equal to = "<<character_sum<<std::endl;
  
  return 0;
  }