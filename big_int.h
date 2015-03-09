#ifndef BIG_INT
#define BIG_INT

#include <string>
#include <cstdlib>
#include <iostream>

using namespace std;

class big_int
{
string value;

public:
string get_value() const;
void set_value(std::string string);
int get_size() const;
void clear_value();
big_int(std::string val_string);//constructor
~big_int();//destructor
int operator[] (const int &index) const;
big_int &operator = (const big_int &rhs);


//mult operator, mult function

};

big_int operator *(const big_int &value_1 , const big_int &value_2);
big_int operator +(const big_int &value_1 , const big_int &value_2);
big_int operator -(const big_int &value_1 , const big_int &value_2);
std::ostream& operator <<(std::ostream& os, const big_int &value_1);
big_int &operator *= (big_int &a, const big_int &b);
big_int &operator += (big_int &a, const big_int &b);



#endif