 // --------- Project Euler Number 23 -----------

/* Problem Statement:
		 Non-abundant sums
		
  		A perfect number is a number for which the sum of its proper divisors is exactly equal to the number. For example, the sum of the proper divisors of 28 would be 1 + 2 + 4 + 7 + 14 = 28, which means that 28 is a perfect number.
  
  A number n is called deficient if the sum of its proper divisors is less than n and it is called abundant if this sum exceeds n.
  
  As 12 is the smallest abundant number, 1 + 2 + 3 + 4 + 6 = 16, the smallest number that can be written as the sum of two abundant numbers is 24. By mathematical analysis, it can be shown that all integers greater than 28123 can be written as the sum of two abundant numbers. However, this upper limit cannot be reduced any further by analysis even though it is known that the greatest number that cannot be expressed as the sum of two abundant numbers is less than this limit.
  
  Find the sum of all the positive integers which cannot be written as the sum of two abundant numbers.

*/
/*Pseudo-code:
	-Go through numbers less than 28123, and check if they're abundant.
		-If a number's abundant, record what it is;
		-Go through this list, and make numbers till you go over 28123.
		-Then go from 1 to 28123.  If its the current numb, don't add and increment, else add and move on
*/
		
/* Solution--4179871.  Got via brute force.  Saw, and coded, a quicker way to arrive at same goal using a boolean array/vector.  Rather than manually storing a list of sums, then having to sort through unique values, it just marks if a number is an abundant sum or not.  Then you can just go through the array, and all the true entries have their indices added to the tally! */
		
		
  #include <iostream>
  #include <sstream>
  #include <string>
  #include <fstream>
  #include <cmath>

  #include <vector>
  #include <algorithm>
  
  #define MAX_TO_CHECK 28123
  		
  bool is_Abundant(int num_to_check);
  
  
  int main()
  {
  bool tester = false;
  	std::vector<int> abundant_list;
  	
  	for(int i = 1;i<=MAX_TO_CHECK;i++)
  	{
  		tester = is_Abundant(i);
  		if(tester==true)
  		{
  			abundant_list.push_back(i);
  			tester=false;  need to reset for next go-around
  		}
  	}
  
    for(std::vector<int>::const_iterator i = abundant_list.begin();i!=abundant_list.end();i++)std::cout<<*i<<std::endl;
    std::cout<<is_Abundant(18)<<std::endl;
  
  std::vector<int> abundant_sum_list;
  	int abundant_sum = 0;
  	 //Loop through the list of abundant numbers, and find all sums of two which are less than 28123;
  	
  	for(int i = 0;i<abundant_list.size();i++)
  		{
  			for(int j = i;j<abundant_list.size();j++)
  			{
  				abundant_sum = abundant_list[i]+abundant_list[j];
  				if(abundant_sum <=MAX_TO_CHECK)abundant_sum_list.push_back(abundant_sum); add the sum to the list!
  			}
  		}
  	 Now, I have a vector holding all of the sums of abundant numbers!
  	
  	std::sort(abundant_sum_list.begin(),abundant_sum_list.end());
  	abundant_sum_list.erase(std::unique( abundant_sum_list.begin(),abundant_sum_list.end() ), abundant_sum_list.end() );
  
  	/*std::vector<bool> can_be_abundant_sum(MAX_TO_CHECK+1);
  	for(int i = 0;i<MAX_TO_CHECK+1;i++)can_be_abundant_sum[i]=false;
  	for(int i = 0;i<abundant_list.size();i++)
  		{
  			for(int j = i;j<abundant_list.size();j++)
  			{
  				abundant_sum = abundant_list[i]+abundant_list[j];
  				if(abundant_sum<=MAX_TO_CHECK)can_be_abundant_sum[abundant_sum] = true;
  				else break;
  			}
  		}
  		long non_abundant_sum = 0;
  		for(int i = 0;i<MAX_TO_CHECK;i++)if(can_be_abundant_sum[i]==false)non_abundant_sum+=i;	
  		 Much faster way to calculate sums, as ~30k bool array.  Doesn't involve sorting!
  		*/
  	
  // Remove duplicate entries.  First sort.  Then , unique removes all duplicate entries in range, and returns an iterator to new "just past end entry".  erase then gets rid of entries from just_pas_end_new to old array.end();
  
  	long non_abundant_sum = 0;
  	
  	for(int i = 0,sum_index=0;i<=MAX_TO_CHECK;i++)
  	{
  		if(i==abundant_sum_list[sum_index])sum_index++;
  		else non_abundant_sum +=i;
  	}
  
  	 //Now, non_abundant_sum should hold all the sum of all of the numbers which cannot be expressed as the sum of two abundant numbers!
  	
  	std::cout<<"The sum of all the numbers which cannot be expressed as the sum of two abundant numbers is equal to "<<non_abundant_sum<<std::endl;
  	return 0;
  }
  	
  		
  bool is_Abundant(int num_to_check)
  {
  	long sum = 1; //1 always a "proper divisor".
  	for(int i = 2;i*i <= num_to_check;i++)
  	{
  		if(num_to_check%i==0)
  		{
  			sum+=i;
  			sum+=num_to_check/i;
  		}
  		if(i == num_to_check/i && num_to_check%i==0)sum-=i; //to make sure we don't double count perfect squares;
  	}
  	bool abundant_or_not = false;
  	if(sum>num_to_check)abundant_or_not = true;
  	return abundant_or_not;
  }