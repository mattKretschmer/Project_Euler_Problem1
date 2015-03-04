#include <cmath>
#include <iostream>
using namespace std;

//Function declarations
double sine(double theta);
double twopimod(double x);
double factorial(int x);

const double pi = 3.14159265358979323846264338327950288419;
	int main()
{

cout << "What would you like to mod?" << endl;
double n = 0;  //Angle to initialize
cin >> n ;

double x = sin(n);
cout << "The sine of " <<  n  << " is " << x<<endl;
cout<< "We calculated the sine of " << n << " as " <<sine(n)<<endl;




return 0;
}


double cosine(double theta)
{	double newtheta = twopimod(theta);
	double xvalue ;
	xvalue = 1-pow(newtheta,2)/factorial(2) + pow(newtheta,4)/factorial(4) -pow(newtheta,6)/factorial(6) + pow(newtheta,8)/factorial(8);
	return xvalue;

}

double sine(double theta)
{	double newtheta = twopimod(theta);
	double xvalue = twopimod(theta) ,previous_xvalue ;
	int n = 1;
	double epsilon = pow(10,-8);
	
	//Adaptively adds terms to the taylor series representation of sine, until the terms cease to change by a given amount, epsilon.
	do{
	previous_xvalue = xvalue;
	xvalue += pow(-1,n)*pow(newtheta,2*n+1)/factorial(2*n+1);
	n+=1;
	std::cout<<n<<'\t'<<xvalue<<'\t'<<epsilon<<std::endl;

	}
	while(abs(xvalue-previous_xvalue)>epsilon);
	return xvalue;
    
}


double twopimod(double x)
{	double y;
	if(x> 0 && x< 2.0*pi)y = x;
	if(x > 2.0*pi){ 
	y = twopimod(x-2.0*pi);
	}
	if(x < 0){ y =twopimod(x+2.0*pi);}
	return y; 
	
}

double factorial(int x)
{	double y;
	if( (x ==0 ||x ==1.0 ) ? y = 1.0: y = factorial(x-1)* x)
	return y;
}

