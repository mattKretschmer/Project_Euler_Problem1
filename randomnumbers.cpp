//
//  randomnumbers.cpp
//  
//
//  Created by matt Kretschmer on 9/27/13.
//
//

#include <iostream>
#include <random>
#include <vector>

int main()
{
    std::default_random_engine generator;
    std::uniform_int_distribution<int> distribution(-10,10);
    
    for(int i = 0;i<100;++i){
        
        int number = distribution(generator);
        std::cout<<i<<'\t'<<number<<std::endl;
        
    }
    
    std::vector<int> loc( 15 );
    for( std::vector<int>::const_iterator i = loc.begin(); i != loc.end(); ++i)
        std::cout << *i << ' ';
    
    
    
    return 0;
}
