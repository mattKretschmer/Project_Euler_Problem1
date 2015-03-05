 /*    --------- Project Euler 19 -------
Problem Statement:
  You are given the following information, but you may prefer to do some research for yourself.
  
  1 Jan 1900 was a Monday.
  Thirty days has September,
  April, June and November.
  All the rest have thirty-one,
  Saving February alone,
  Which has twenty-eight, rain or shine.
  And on leap years, twenty-nine.
  A leap year occurs on any year evenly divisible by 4, but not on a century unless it is divisible by 400.
  How many Sundays fell on the first of the month during the twentieth century (1 Jan 1901 to 31 Dec 2000)?
*/
/* Notes:
 6 Jan 1901 was first sunday of year.  Keep adding 7, moding appropriately for months, years, etc.  Add when date = 1;

 days of week = 1 to 7, 
 repeat*/
#include <iostream>
#include <sstream>
#include <string>
#include <fstream>
#include <cmath>
 
  inline int mod( const int &n, const int &N ) { return n%N < 0 ? n%N + N : n%N; }

  int get_days(const int month);
  
  int main()
  {
  	int year = 1901,month = 1, days =get_days(1);
  
  	int sunday_counter = 0,current_date = 6; //Starting values.  Get value from problem statement;
  	while(year<2001)
  	{
  		if(current_date==1)sunday_counter++;
  
  		current_date+=7; Go to next week;
  		if(current_date>days)
  		{
  			current_date-=days;
  			month++;
  			days = get_days(month);
  			if(month>12)
  			{
  				year++;
  				month=1;
  				days=get_days(1);
  			}
  		}
  		if((year ==2000 || year%4 ==0)&& month==2)days=29; //leap years
  
  	}
  	std::cout<<"The number of sundays that fall on the first of the month in the 20th century is equal to = "  <<sunday_counter<<std::endl;
  	return 0 ;
  }
  
  
  int get_days(const int month)
  {
  	switch (month)
  	{
  		case 1:	return 31;
  	
  		case 2: return 28;
  	
  		case 3: return 31;
  		
  		case 4: return 30; 
  
  		case 5: return 31;
  
  		case 6: return 30;
  	
  		case 7: return 31;
  
  		case 8: return 31;
  	
  		case 9: return 30;
  	
  		case 10: return 31;
  	
  		case 11: return 30;
  	
  		case 12: return 31;
  	
  	}
  	
  }