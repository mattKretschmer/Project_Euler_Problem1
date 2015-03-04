#include <iostream>
#include <sstream>
#include <string>
#include <fstream>
#include <cmath>
/*
//Project Euler Problem 1. Find the sum 
int main () {
	int sum = 0;
	int index = 1;
	int i = 1.0;
	while (i < 1000) {
	if (i%3 ==0  || i%5 ==0)sum += i;
	i++;	
	}
	
cout << "The sum of the multiples of 3 or 5 are : " << sum << endl;

return 0;
}
*/

/*

//Project Euler Problem 3.  Find the largest prime factor of 600851475143
  long long int BiggestPrime(long long int value);

int main() {

	long long int Value = 600851475143;//Need long longs to store such a big value!
	int trial = 13195;
	 long long int maxprime = BiggestPrime(Value);

	cout << "The Max prime is " << maxprime << endl;
	return 0;
}
//Function for calculating the Biggest prime factor

  long long int BiggestPrime(long long int value){
	cout<<value<<endl;//For fun, prints out where you're at;
	int divisor = 2; //A starting point
	long long int biggestfactor = 2;//Same thing, an initial place to store the biggest factor;
	while(divisor*divisor <= value){
	
	if(value%divisor==0){//Recursively calls itself.  If the divisor goes in evenly, it calls itself
	//for smaller value.
			if((value/divisor) > biggestfactor)biggestfactor = value/divisor;
			return BiggestPrime(value/divisor);
			}
	else
		divisor++;	
		
	}
	return value ;//Returns the final most prime value.

	}

*/
/*

// ----- Project Euler # 4: Find the largest Palindromic number made from a product of 2 three digit numbers.  Probbaly going to be from two in the 900s is rather than near the 100s.  So start high, and decrement, going through each combination and checking for values.  A brute force approach.  Required writing/copying a function for converting an integer into a string.  Explained in function definition.  Also, for reversing the order of a string, we use a constructor that takes two iterators, which reverses the order of the string.  These are "rbegin()" and "rend()."
string convertFromInt( int number);

int main() {

     int SearchValue = 0;
    string SValue, reversed;
    int max = 0;
    
    for(int i = 999;i>99;i--){
        for(int j = 999;j>99 ;j--){
            SearchValue = i*j;
            SValue = convertFromInt(SearchValue);
            reversed= string(SValue.rbegin(),SValue.rend());
            if((SValue ==reversed) && (SearchValue>max)){
                max = SearchValue;
                cout << "Largest Palindrome is product of "<< i<< " and "<< j <<" and equals "<< SValue<<endl;
                //Check if the palindrome is larger than the previous max, if it is, store it.  Once the search is done, we have the maximum Palindrome!.
            }
        }
    }
    //Way to reverse a string.  rbegin() and rend() are iterators.  rbegin() points to the beginning of the reverse string, rend to the end of the reverse string.  string() has a range constructor, which picks a section of the string from (first, last) elements.  Need to input iterators for first, last.
    
    //To convert integers to strings, use string streams.  Read about it some more soon!
    
    
    
    
    return 0;
}

string convertFromInt( int number)
{//Uses string streams.  Throws the int onto the stream, then extracts it as a string.  Very convenient formulation!.  Very useful in the future too.
    stringstream ss;//create a stringstream
    ss << number;//add number to the stream
    return ss.str();//return a string with the contents of the stream
}
*/

/*

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
    
    
    cout <<"The Smallest Number Divisible by every number less than 20 is "<< Final<<endl;
    
    
    
    
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

*/

/*
 
// ------ Project Euler #6------
    //Find the difference between the square of the sum and the sum of the squares of the first 100 consecutive integers.  Code is simple, and shown below.  Only 1 loops is shown, and it calculates both the sums of the squres, as well as the sum of the normal integers, and is itself then squared.

int main() {
	int UpperLimit = 100;
	unsigned int suma = 0, sumb = 0;
	for(int i = 1; i <= UpperLimit; i++){
        suma += i*i;
        sumb += i;
	}
	cout <<sumb<< endl;
	sumb *=sumb;
    int difference = sumb-suma;
	
	cout <<"The difference the sum of the squares and the square of the sum of the first" <<UpperLimit<< " numbers is " << difference <<endl;
    
	return 0; 
    
}

*/

//// ------ Project Euler #7------
//
////  By listing the first six prime numbers: 2, 3, 5, 7, 11, and 13, we can see that the 6th prime is 13.  What is the 10,001st prime number?
//
//bool isPrime(long long int value);//Given a value, searches up to value/2 (or maybe sqrt(Value) looking for divisors).  Returns true if its prime, false otherwise
//
////First 6 primes: 2,3,5,7,11,13;
//
//int main(){
//    int primecounter = 6; //Starting points, given the problem statement.
//    long long int largestPrime = 13;
//    bool primeTrueFalse=false;
//    while(primecounter <10001){
//        primeTrueFalse = false; //resets every time.
//        largestPrime+=2;//Increment up, won't need to worry about even numbers.
//        
//        while(primeTrueFalse == false){//Loop to find each prime.  When found, loop exits.
//            primeTrueFalse = isPrime(largestPrime);
//            if(primeTrueFalse == false)largestPrime+=2;
//            
//        }
//        if(primeTrueFalse==true)primecounter+=1;//update counter accordingly.
//    }
//    cout<<"The 10001st prime number is "<<largestPrime<<endl;
//    
//}
//bool isPrime(long long int value){
//    bool primeIndicator = true;
//	cout<<value<<endl;//For fun, prints out where you're at;
//	long long int divisor = 2; //A starting point
//	while(divisor <= sqrt(value)){//Searches up to sqrt(value).  Value can be factored into a*b.  Max a and b can be is sqrt(value).  So we only need one leg of the "search", up to a's maximum value.
//        
//        if(value%divisor==0){primeIndicator = false; break;}
//        divisor++;
//		
//	}
//	return primeIndicator ;//Returns the final most prime value.
//    
//}


// ------ Project Euler #8------
    ///Find the greatest product of 5 consecutive digits in the number listed on the webpage, or here, as :
//73167176531330624919225119674426574742355349194934
//96983520312774506326239578318016984801869478851843
//85861560789112949495459501737958331952853208805511
//12540698747158523863050715693290963295227443043557
//66896648950445244523161731856403098711121722383113
//62229893423380308135336276614282806444486645238749
//30358907296290491560440772390713810515859307960866
//70172427121883998797908792274921901699720888093776
//65727333001053367881220235421809751254540594752243
//52584907711670556013604839586446706324415722155397
//53697817977846174064955149290862569321978468622482
//83972241375657056057490261407972968652414535100474
//82166370484403199890008895243450658541227588666881
//16427171479924442928230863465674813919123162824586
//17866458359124566529476545682848912883142607690042
//24219022671055626321111109370544217506941658960408
//07198403850962455444362981230987879927244284909188
//84580156166097919133875499200524063689912560717606
//05886116467109405077541002256983155200055935729725
//71636269561882670428252483600823257530420752963450
//#include <cstring>
//#define NUM_SIZE 1000
//char file_in[]="1000_digit_number.txt";
//
//int main(){
//std::ifstream fin;
//fin.open(file_in);
//    std::string mystring;
//int big_num[NUM_SIZE];
//    int counter = 0;
//    while(getline(fin,mystring)){
////        std::cout<<mystring<<'\n';
//        counter++;
//        for(int i = 0;i<mystring.size();i++)
//        {
//            big_num[(counter-1)*mystring.size()+i]= mystring[i]-48;
//        }
//    }
//    
//    //Now that I've read in my 1000 digit number, I'll just need to calculate successive products!;
//    int current_product = 0, max_product = big_num[0]*big_num[1]*big_num[2]*big_num[3]*big_num[4];
//    for(int i =0;i<NUM_SIZE-5;i++){
//        current_product = big_num[i]*big_num[i+1]*big_num[i+2]*big_num[i+3]*big_num[i+4];
//        if(current_product>max_product)max_product = current_product;
//    }
//    cout<<max_product<<endl;
//return 0;
//}

//All Correct, ps!


// ------ Project Euler #9 -------
//Find the pythagorean triple where a +b+c =1000, then find the product abc;
//int main(){
//    //limits are a result of tuning once I knew the result lol, but cut the execution time drastically
//    int k =0;
//for(int i =0;i<500;i++)
//for(int j =0;j<400;j++)
//{k=1000-i-j;
////    if(k*k==i*i+j*j && i+j+k==1000)
//  if(k*k == i*i+j*j)std::cout<<"The product answer is :  "<<i*j*k<<", and the three numbers are "<<i<<","<<j<<","<<"and "<<k<<std::endl;
//}
//
//return 0;
//}

//------ Project Euler #10 -------

//Find the sum of all primes below two million

//bool isPrime(long long int value);
//
//int main(){
//    bool prime_indicate = false;
//    long long int sum = 5; // because 2 and three are primes, but not 1!  ALso, get to reuse prime testing function oh yeah!!
//    long long int i = 5;
//    while(i<=2000000){
//        prime_indicate = isPrime(i);
//        if(prime_indicate==true)sum+=i;
//        prime_indicate = false;
//        i+=2;
//    }
//    cout<<sum<<endl;
//    return 0;
//    
//}
//
//bool isPrime(long long int value){
//    bool primeIndicator = true;
////	cout<<value<<endl;//For fun, prints out where you're at;
//	long long int divisor = 2; //A starting point
//	while(divisor <= sqrt(value)){//Searches up to sqrt(value).  Value can be factored into a*b.  Max a and b can be is sqrt(value).  So we only need one leg of the "search", up to a's maximum value.
//
//        if(value%divisor==0){primeIndicator = false; break;}
//        divisor++;
//
//	}
//	return primeIndicator ;//Returns the final most prime value.
//}
//

// -------- Project Euler #11 --------
// 
// //Look through the big grid, find greatest project of four numbers. (loop up, down, left, or right); Answer: 70600674
// #define SIZE 20
// 
// char file_in[] = "p_euler_11-number.txt";
// 
// int main()
// {
// ifstream fin;
// fin.open(file_in);
// int block[SIZE][SIZE]={0};
// long int max = 0,product = 0;
// 	for(int i = 0;i<SIZE;i++)for(int j = 0;j<SIZE;j++)fin>>block[i][j];//Get the info in file into the array "block".
// 	//Search for products
// 	for(int i = 0;i<SIZE;i++)for(int j = 0;j<SIZE;j++)
// 	{
// 	//Look right
// 	if(j+3<SIZE){product = block[i][j]*block[i][j+1]*block[i][j+2]*block[i][j+3];if(product>max)max =product;}
// 	//Look Down
// 	if(i+3<SIZE){product = block[i][j]*block[i+1][j]*block[i+2][j]*block[i+3][j];if(product>max)max =product;}
// 	//Look Up
// 	if(i-3>0){product = block[i][j]*block[i-1][j]*block[i-2][j]*block[i-3][j];if(product>max)max =product;}
// 	//Look Left
// 	if(j-3>0){product = block[i][j]*block[i][j-1]*block[i][j-2]*block[i][j-3];if(product>max)max =product;}
// 	//Down Right
// 	if( (j+3<SIZE) && (i+3<SIZE) ){product = block[i][j]*block[i+1][j+1]*block[i+2][j+2]*block[i+3][j+3];if(product>max)max =product;}
// 	//Down Left
// 	if( (j-3>0) && (i+3<SIZE) ){	product = block[i][j]*block[i+1][j-1]*block[i+2][j-2]*block[i+3][j-3];if(product>max)max =product;}
// 	//Up Right
// 	if( (j+3<SIZE) && (i-3>0) ){product = block[i][j]*block[i-1][j+1]*block[i-2][j+2]*block[i-3][j-3];if(product>max)max =product;}
// 	//Up Left
// 	if( (j-3>0) && (i-3>0) ){product = block[i][j]*block[i-1][j-1]*block[i-2][j-2]*block[i-3][j-3];if(product>max)max =product;}
// 	}
// 	cout<<"The maximum product of four consecutive numbers is equal to "<<max<<endl;;
// 
// }


////------ Project Euler #12 -------
//    //Find the first 'triangle' number with > 500 divisors.  Triangle numbers are calculated by adding up the (consecutive) natural numbers
//int num_of_divisors(long long int test_case);
//long long int make_triangle_num(int seed);
//
//int main(){
//    long long int i = 36;
//    int seed = 1,number_of_divisors = 1;
//    while(number_of_divisors<=501)
//    {
//        i = make_triangle_num(seed);
//        number_of_divisors =num_of_divisors(i);
//        seed++;
//    }
//
//    cout<<"The first triangle number with > 500 divisors is : "<< i<<endl;
//    return 0;
//}
//
//int num_of_divisors(long long int test_case)
//{
//    int divise_num = 2;
//    
//    for(int i =2;i<sqrt(test_case);i++)if(test_case%i==0)divise_num+=2;
//    return divise_num;
//    
//}
//long long int make_triangle_num(int seed)
//{
//    long long int triang_num = 0;
//    
//    for(int i = 1;i<=seed;i++)triang_num+=i;
//        return triang_num;
//}

// ----------Project Euler #13 --------------
// 
// Find the sum of the first 10 digits of 100 50-digit numbers. Just load them into an array, then perform addition like a person would. SUm up a column, then if over 10, add modulo extra bit to next column and continue. Contune for 50 places.. At place 50, sum then put ino remainding spaces.*/
// 
// #define ROWS 100
// #define COLUMNS 50
// #define DIG_TO_PRINT 10
// char file_in[] = "p_euler-13.txt";
//  
//  int main()
//  {
// 	std::ifstream fin;
// 	fin.open(file_in);
// 	char c;// = fin.get();
// 	int num_block[ROWS][COLUMNS]={0};
// 	for(int i = 0;i<ROWS;i++)for(int j = 0;j<COLUMNS;j++)
// 		{
// 			fin>>c;
// 			num_block[i][j]=c-'0';
// 			// c=fin.get();
// 		}
// 	fin.close();
// 	//  for(int i = 0;i<ROWS;i++)for(int j = 0;j<COLUMNS;j++)fin>>num_block[i][j];
// 	//   for(int i = 0;i<ROWS;i++){for(int j = 0;j<COLUMNS;j++)std::cout<<num_block[i][j];std::cout<<std::endl;}
// 	// 
// 	 int sum_list[COLUMNS] = {0};
// 	 int sum = 0,pre_sum = 0;
// 	 for(int i = (COLUMNS-1);i>=0;i--)
// 	 {
// 		sum = 0;
// 		sum+=pre_sum;
// 		for(int j = 0;j<ROWS;j++)
// 		{
// 			sum+=num_block[j][i];
// 		}
// 		sum_list[i] = sum%10;
// 		pre_sum = (sum-(sum%10))/10;
// 	 }
//   	//Need to add pre_sum digits to the front!
// 
// 	//how many digits are there?
// 		int psdc = 0,test=pre_sum;
// 		while(test>0)
// 		{
// 			test/=10;
// 			psdc+=1;
// 		}
// 		std::cout<<pre_sum;
//  		for(int i = 0;i<(DIG_TO_PRINT-psdc);i++)std::cout<<sum_list[i];
//  		std::cout<<std::endl;
//  }


//////------- Project Euler 14-------
//    //Find longest collatz sequence: n ->n/2 if n is even, n->3n+1 if n is odd. Find number with longest collatz chain.
//#define LIMIT 50
//
//long find_collatz_sequence_length(long int n);
//long find_collatz_sequence_length_with_memoization(long int n,long *list_of_lengths);
//
//int main(){
//    long max_seq_length = 0,seq_length=0,max_number = 0;
//    long start = 1, list_of_lengths[LIMIT]={0} ;
//
//    while(start<=LIMIT){
//        seq_length = find_collatz_sequence_length_with_memoization(start,list_of_lengths);
//        if(seq_length>max_seq_length){
//            max_seq_length = seq_length;
//            max_number = start;
//        }
//        start++;
//    }
//    cout<<"The number under a million with the largest Collatz sequence is : "<<max_number<<" , and the length of its sequence is "<<max_seq_length<<" numbers."<<endl;
//    return 0;
//}
//
////long find_collatz_sequence_length(long int n){
////    long sequence_length = 1.;
////    while(n!=1){
////        if(n%2 == 0){n /=2;sequence_length+=1;}
////        else{ n=3*n+1;sequence_length+=1;}
////    }
////    return sequence_length;
////}
//
//long find_collatz_sequence_length_with_memoization(long int n,long *list_of_lengths){
//    long sequence_length = 1.,moveable_index = n;
//    
//    while(n!=1){
//
//        if(n%2 == 0){
//                n /=2;
//            sequence_length++;
//
//            if(n<moveable_index && n < LIMIT){
//                    sequence_length+=list_of_lengths[n-1];
//                    break;
//            }
//        }
//        else{ n=3*n+1;sequence_length+=1;}
//        
//    }
//    list_of_lengths[moveable_index-1]=sequence_length;
////    cout<<list_of_lengths[moveable_index-1]<<'\t'<<moveable_index<<endl;
//    return sequence_length;
//}

////// ------- Project Euler 15 -------

//-- Lattice paths- How many paths are there through  a 20 x 20 lattice, only moving down and right, and starting at the top left? THere are 6 for a two x two lattice.

//Number Left = 2*(num of square n-1 size) + 2*(Downs + Rights-1)
//#define N 20
//
//int main()
//{
//	//Set-up grid, putting ones along the edges.  Remember, there are N+1 nodes ! ._._. is a side of a 2 x 2 grid, for example.  Also, bottom index is at N.
//    
//	long int grid[N+1][N+1];
//	//An easily parallelizable loop with OpenMP!
//    //	#pragma omp parallel for
//	for(int i =0;i<(N+1);i++){
//		grid[N][i] = 1;
//		grid[i][N] = 1;
//	}
//    
//	// Now, back track through grid, adding filling in other entries:
//    
//	for(int i = N-1;i>=0;i--)for(int j = N-1;j>=0;j--){
//		grid[i][j]=grid[i+1][j]+grid[i][j+1];
//        
//	}
//	std::cout<<"The total number of paths through an N x N grid are:"<<grid[0][0]<<std::endl;
//	return 0;
//}

//////// ------- Project Euler 16 --------
//
//    //-- Sum of Digits of 2^1000.  In short: Find 2^1000, then sum all of the digis
//
//#define N 1000
//#define ARRAY_SIZE 10*N
//void mult_by_two(int *array);
//
//int big_num[ARRAY_SIZE]={0};
//
//int main()
//{
//	big_num[N-1]=1; //initialize, 2^0;
//	for(int i = 0;i<N;i++)mult_by_two(big_num);
//	
//	long int sum = 0;
//	for(int i = 0;i<ARRAY_SIZE;i++)sum +=big_num[i];
//    
//    std::cout<<"The sum of the digits of 2^ "<<N<< " is "<<sum<<std::endl;
//    
//    
//}
//
//
//void mult_by_two(int *array)
//{
//	int carry = 0,holder;
//	
//	for(int i= ARRAY_SIZE-1;i>=0;i--)
//	{
//		holder = array[i]*2 + carry;
//		if(holder>=10)
//        {
//			array[i]= holder-10;
//			carry = 1;
//		}
//		else
//        {
//            carry = 0;
//            array[i]=holder;
//	
//        }
//    }
//    
//}

/////////// -------- Project Euler 17 ----------
// 
// If the numbers 1 to 5 are written out in words: one, two, three, four, five, then there are 3 + 3 + 5 + 4 + 4 = 19 letters used in total.
// 
// If all the numbers from 1 to 1000 (one thousand) inclusive were written out in words, how many letters would be used?
// 
// 
// NOTE: Do not count spaces or hyphens. For example, 342 (three hundred and forty-two) contains 23 letters and 115 (one hundred and fifteen) contains 20 letters. The use of "and" when writing out numbers is in compliance with British usage.

//Solution found! 21124 total characters. Checked 12/25
// #include <map> //string already included above;
// 
// #define LIMIT 1000
// #define SIZE 4
// 
// 
// int main()
// {
// //These map classes help to quickly look up names for digitsin number, used later. Sort of like a hash table.  Really useful!  
// std::map < int, string > tens,ones,teens,names;
// 
// //if tens = 1, ones = 0-->ten; if tens = 1, ones !=0 ->teens[ones];
// tens[1] = "ten";
// tens[2]="twenty";
// tens[3]="thirty";
// tens[4]="forty";
// tens[5]="fifty";
// tens[6]="sixty";
// tens[7]="seventy";
// tens[8]="eighty";
// tens[9] = "ninety";
// 
// ones[0]="";
// ones[1]="one";
// ones[2]="two";
// ones[3]="three";
// ones[4]="four";
// ones[5]="five";
// ones[6]="six";
// ones[7]="seven";
// ones[8]="eight";
// ones[9]="nine";
// 
// teens[0]="ten";
// teens[1]="eleven";
// teens[2]="twelve";
// teens[3]="thirteen";
// teens[4]="fourteen";
// teens[5]="fifteen";
// teens[6]="sixteen";
// teens[7]="seventeen";
// teens[8]="eighteen";
// teens[9]="nineteen";
// 
// names[1]="thousand";
// names[2]="hundred";
// names[3]= "and";
// 
// int int_holder[SIZE]={0};
// long int character_sum = 0;
// 
// for(int i = 1;i<=LIMIT;i++)
// {
// 	//first, find the number, as stored in an appropriate sized array.
// 	int_holder[3]+=1;
// 	for(int i = 3;i>0;i--)if(int_holder[i]>9){int_holder[i]=0;int_holder[i-1]++;}
// 	//Make a string to hold the name of the number:
// 	string out_holder = "";
// 	
// 	if(int_holder[0]!=0)out_holder.append(ones[ int_holder[0]] + names[1] ); //n thousand, if needed.
// 	if(int_holder[1]!=0)//Get the hundreds, if needed
// 	{
// 		out_holder.append(ones[ int_holder[1]] + names[2] ); //n hundred ;
// 		if(int_holder[3]!=0 || int_holder[2]!=0)out_holder.append( names[3] );
// 	}
// 
// 	//Figure out last two digits.
// 	if( int_holder[2]==0 &&int_holder[3]!=0 )out_holder.append(ones[ int_holder[3] ]);//ones
// 	else if( int_holder[2]==1) out_holder.append(teens[ int_holder[3] ]);//teens
// 	else out_holder.append(tens[ int_holder[2] ]+ones[int_holder[3]]); 
// 	//Add the sum of the letters for the current number
// 	character_sum +=out_holder.size();
// }
// 
// cout<<"The sum of all the letters for all the numbers under 1000 is equal to = "<<character_sum<<endl;
// 
// return 0;
// }



/////////// ------- Project Euler 18 and Project Euler 67---------
//
////Find maximum path sum from the top of a triange, stored in file Triangle.txt (or big_triangle.txt, which has 100 rows);
//#include <algorithm>
////#define SIZE 15 //Problem 18
//#define SIZE 100 // Problem 67
//
////char file_in[]="Triangle.txt";  //Problem 18
//char file_in[] = "big_triangle.txt"; //Problem 67
//
//
//std::string mystring;
//int triangle_Array[SIZE][SIZE]={0};
//
//    int counter = 0;
//int main(){
//    
//    std::ifstream fin;
//    fin.open(file_in);
//    
//
//        for(int i = 0;i<SIZE;i++)for(int j = 0;j<=i;j++)fin>>triangle_Array[i][j];
//
//
//    int real_triangle_Array[SIZE][2*SIZE]={0};
//    int start = 0;
//    for(int i = SIZE-1;i>=0;i-- )
//    {
//        
//        for(int j = 0 ;j<SIZE;j++)
//        {
//        
//            real_triangle_Array[i][2*j + start]=triangle_Array[i][j];
//        }
//        start++;
//
//    }
//
////    //Print out triangle:
////    for(int i = 0;i<SIZE;i++)
////    {
////        for(int j = 0;j<2*SIZE;j++)
////        {
////            cout<<real_triangle_Array[i][j]<<"  ";
////            
////        }
////        cout<<'\n';
////        
////    }
//    
//    //Now that the triangle is in, go backwards, finding max sum of points below.
////    
//    
//    start = 1;
//    for(int i = SIZE-2;i>=0;i--)
//    {
//        for(int j = 0;2*j+start<2*SIZE;j++)
//        {
//            real_triangle_Array[i][2*j +start] += max(real_triangle_Array[i+1][2*j+start+1],real_triangle_Array[i+1][2*j+start-1]);
//            
//        }
//        start++;
//        
//    }
//    
//    
//    cout<<"The sum of the maximum path through the triangle is equal to "<<real_triangle_Array[0][SIZE-1]<<endl;
//    
//    
//}

//////// --------- Project Euler 19 -------

// You are given the following information, but you may prefer to do some research for yourself.
// 
// 1 Jan 1900 was a Monday.
// Thirty days has September,
// April, June and November.
// All the rest have thirty-one,
// Saving February alone,
// Which has twenty-eight, rain or shine.
// And on leap years, twenty-nine.
// A leap year occurs on any year evenly divisible by 4, but not on a century unless it is divisible by 400.
// How many Sundays fell on the first of the month during the twentieth century (1 Jan 1901 to 31 Dec 2000)?

//6 Jan 1901 was first sunday of year.  Keep adding 7, moding appropriately for months, years, etc.  Add when date = 1;

//days of week = 1 to 7, repeat
// inline int mod( const int &n, const int &N ) { return n%N < 0 ? n%N + N : n%N; }

// int get_days(const int month);
// 
// int main()
// {
// 	int year = 1901,month = 1, days =get_days(1);
// 
// 	int sunday_counter = 0,current_date = 6;//Starting values.  Get value from problem statement;
// 	while(year<2001)
// 	{
// 		if(current_date==1)sunday_counter++;
// 
// 		current_date+=7;//Go to next week;
// 		if(current_date>days)
// 		{
// 			current_date-=days;
// 			month++;
// 			days = get_days(month);
// 			if(month>12)
// 			{
// 				year++;
// 				month=1;
// 				days=get_days(1);
// 			}
// 		}
// 		if((year ==2000 || year%4 ==0)&& month==2)days=29;//leap years;
// 
// 	}
// 	std::cout<<"The number of sundays that fall on the first of the month in the 20th century is equal to = "  <<sunday_counter<<endl;
// 	return 0 ;
// }
// 
// 
// int get_days(const int month)
// {
// 	switch (month)
// 	{
// 		case 1:	return 31;
// 	
// 		case 2: return 28;
// 	
// 		case 3: return 31;
// 		
// 		case 4: return 30; 
// 
// 		case 5: return 31;
// 
// 		case 6: return 30;
// 	
// 		case 7: return 31;
// 
// 		case 8: return 31;
// 	
// 		case 9: return 30;
// 	
// 		case 10: return 31;
// 	
// 		case 11: return 30;
// 	
// 		case 12: return 31;
// 	
// 	}
// 	
// }

// ////// ------- Project Euler 20 --------
// 
//     //-- Sum of the digits of 100!-- Works to 100! Boo-yah.  Work over break to extend arbitrary integer class.
// #define LIMIT 100
// string two_string_mult(string &string_1,string &string_2);
// 
// 
// int main()
// {
// 	string ss_1,ss_2="",holder="";
//     ss_1="1";
//     
//     stringstream to_convert;
//     
//     for(int i = 1;i<=LIMIT;i++)
//     {
//         to_convert<<i;
//         ss_2 = to_convert.str();
//         holder = two_string_mult(ss_1,ss_2);
//         to_convert.str(std::string());
//         ss_1.clear();
//         ss_2.clear();
//         ss_1 = holder;//ss_1 now holds the factorial
//         holder.clear();
//     }
//     
//     long int digit_sum = 0;
//     for(int i=0;i<ss_1.size();i++)digit_sum+=ss_1[i]-48;
//     cout<<"The sum of the digits of "<<LIMIT<<" factorial is equal to "<<digit_sum<<endl;
// 
// }
// 
// 
// string two_string_mult(string &string_1,string &string_2)
// {
//     //First, we find out which of the strings is longer (if any).  If they're congruent, set one to "top" and the other to "bottom"
//     int size_1 = string_1.size(),size_2 = string_2.size();
//     string top="",bottom="";
//     if(size_1<=size_2)
//     {
//         bottom = string_1;
//         top = string_2;
//     }
//     else
//     {
//         top = string_1;
//         bottom = string_2;
//     }
//     int top_size = top.size(),bottom_size = bottom.size();
//     //Once we have top and bottom strings, we get their size and store them in top_size and bottom_size;
//     //Going to initialize an array to hold what we need during multiplication.  Maximum we'll need is top_size+bottom_size, with bottom_size;
//     
//     int total_size = (top_size+bottom_size)*bottom_size,row_size = top_size+bottom_size;
//     int *mult_holder=new int[total_size];
//     for(int i = 0;i<total_size;i++)mult_holder[i]=0;
//     
//         //mult_holder[i][j]=mult_holder[i*row_size +j]
//     
//     int holder = 0,carry = 0,row_index=0,col_index;
//     for(int i = bottom.size();i>0;i--)
//     {
//         holder = 0; carry = 0,col_index = row_size-1;
//         for(int j = top.size();j>0;j--)
//         {
//             
//             holder = (top[j-1]-48)*(bottom[i-1]-48);
//             if(holder>9)
//             {
//                 carry = holder/10;
//                 mult_holder[row_index*row_size+col_index-row_index]+=holder%10;
//                 mult_holder[row_index*row_size+col_index-1-row_index]+=carry;
// 
//             }
//             else
//             {
//                 carry = 0;
//                 mult_holder[row_index*row_size+col_index-row_index]+=holder;
// 
//             }
//             col_index--;
//         }
//         row_index++;
//     }
//  
//     //the final array, we will store our product in:
//     int *final_array = new int[row_size];
//     for(int i = 0;i<row_size;i++)final_array[i]=0;
//     
//     carry = 0;holder = 0;
//     
//     for(int j =(row_size-1);j>=0;j--)
//         for(int i = bottom.size()-1;i>=0;i--)
//         {
//             final_array[j]+=mult_holder[row_size*i +j];
//             
//         }
// 
//     //Haven't taken care of instances where numbers are greater than 9, here we do that.
//     for(int i = row_size-1;i>0;i--)if(final_array[i]>9)
//     {
//         final_array[i-1]+= final_array[i]/10;
//         final_array[i] = final_array[i] % 10;
//         
//     }
// 
// 
//     stringstream ss;
//     //trim the extra zeros in front
//     int start = 0;
//     for(int i = 0;i<row_size;i++)if(final_array[i]>0){start = i;break;}
//     for(int i = start;i<row_size;i++)ss<<final_array[i];
// 
//     
//     //free up memory we allocated for operations
//     delete[] final_array;
//     delete[] mult_holder;
//     
//     
//     return ss.str();
// 
//     
// }





