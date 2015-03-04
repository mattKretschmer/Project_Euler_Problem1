#include <iostream>
#include <sstream>
#include <cmath>
#include <string>
#include "big_int.h"

int main()
{
std::string a = "10",b = "565";
big_int trial_num(a),trial_two(b);
big_int c = trial_num;
c*=c;
c*=c;
c.clear_value();
std::cout<<c<<'\t'<<trial_num-trial_two<<std::endl;


return 0;
}