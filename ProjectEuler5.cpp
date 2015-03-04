#include <iostream>
#include <sstream>
#include <string>
#include <fstream>
#include <cmath>

// ------ Project Euler #5-------
//Need to find the smallest number divisible by every integer up to 20.  I wrote a function to test whether the supplied number is divisible by these numbers.  It returns true if it is, false if it isn't.  I start looking for this smallest number at the product of all of the primes below twenty, plus an extra factor of 3 (know I need to have this, because of 9).  If the number's not divisible by all the numbers, just multiply by 2 and check again.  Eventually the number will hit.  Stop as soon as isDivisible gives a true result.

bool isDivisible(int num);

int main() {
    unsigned int Starting_Point = 2*3*3*5*7*11*13*17*19 ;
    unsigned int Final = 0;//Place to store the final output answer.
    bool Marker= true ;//Way to keep track if Starting_Point meets the criteria.
    
    //Do while structure seemed to work best for this .
    do{
        Marker = isDivisible(Starting_Point);  //check if criteria is met.
        Final = Starting_Point;//Update Final Stored value.
        Starting_Point *=2;// Update the starting point.
    }
    while( Marker == false);//Do all this till we find the smallest answer.
    
    
    std::cout <<"The Smallest Number Divisible by every number less than 20 is "<< Final<<std::endl;
    
    
    
    
}


bool isDivisible(int value){
    bool flag =true;
    int i =1;
    while( (flag ==true) && i<=20){
        if(value%i!=0){
            flag = false;
        }
        i++;
    }
    return flag;
}
