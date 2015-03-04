#include <iostream>
#include <sstream>
#include <string>
#include <fstream>
#include <cmath>

// ----- Project Euler # 4: Find the largest Palindromic number made from a product of 2 three digit numbers.  Probbaly going to be from two in the 900s rather than near the 100s.  So start high, and decrement, going through each combination and checking for values.  A brute force approach.  Required writing/copying a function for converting an integer into a string.  Explained in function definition.  Also, for reversing the order of a string, we use a constructor that takes two iterators, which reverses the order of the string.  These are "rbegin()" and "rend()."
std::string convertFromInt( int number);

int main() {

     int SearchValue = 0;
    std::string SValue, reversed;
    int max = 0;
    
    for(int i = 999;i>99;i--){
        for(int j = 999;j>99 ;j--){
            SearchValue = i*j;
            SValue = convertFromInt(SearchValue);
            reversed= std::string(SValue.rbegin(),SValue.rend());
            if((SValue ==reversed) && (SearchValue>max)){
                max = SearchValue;
                std::cout << "Largest Palindrome is product of "<< i<< " and "<< j <<" and equals "<< SValue<<std::endl;
                //Check if the palindrome is larger than the previous max, if it is, store it.  Once the search is done, we have the maximum Palindrome!.
            }
        }
    }
    //Way to reverse a string.  rbegin() and rend() are iterators.  rbegin() points to the beginning of the reverse string, rend to the end of the reverse string.  string() has a range constructor, which picks a section of the string from (first, last) elements.  Need to input iterators for first, last.
    
    //To convert integers to strings, use string streams.  Read about it some more soon!
    
    
    
    
    return 0;
}

std::string convertFromInt( int number)
{//Uses string streams.  Throws the int onto the stream, then extracts it as a string.  Very convenient formulation!.  Very useful in the future too.
    std::stringstream ss;//create a stringstream
    ss << number;//add number to the stream
    return ss.str();//return a string with the contents of the stream
}