// --------- Project Euler Number 21 -----------

// Let d(n) be defined as the sum of proper divisors of n (numbers less than n which divide evenly into n).
// If d(a) = b and d(b) = a, where a ≠ b, then a and b are an amicable pair and each of a and b are called amicable numbers.
// 
// For example, the proper divisors of 220 are 1, 2, 4, 5, 10, 11, 20, 22, 44, 55 and 110; therefore d(220) = 284. The proper divisors of 284 are 1, 2, 4, 71 and 142; so d(284) = 220.
// 
// Evaluate the sum of all the amicable numbers under 10000.

//Answer:: 31626


// #include <iostream>
// #include <sstream>
// #include <string>
// #include <fstream>
// #include <cmath>

// #define MAX 10000
// 
// void find_amicable_numbers( int limit, int (*list)[2] );//Passes a pointer to an array of two dimensional int arrays.
// 
// int main() 
// {
// 	int list[MAX+1][2]={0};//Will store numbers, and the sum of their divisors
// 	for(int i = 0;i<MAX+1;i++)list[i][0]+=i;//setup left column of list
// 	//Find amicable nums under 10k.
// 	for(int i = 1;i<MAX+1;i++)find_amicable_numbers(i,list);
// 	
// 	int total_sum = 0;
// 	//Now, list will only hold zeros and amicable numbers, in second column, sum to get answer!
// 	for(int i = 1;i<MAX+1;i++)total_sum+=list[i][1];
// 	
// 	cout<<"The total sum of amicable number factors is equal to "<<total_sum<<endl;
// 
// 
// 
// 
// }
// 
// void find_amicable_numbers( int limit, int (*list)[2] )
// {
// 
// 		int sum = 1;
// 		//First, if we haven't done so, find the sum of divisors of a number
// 		if(list[limit][1]==0)for( int i = 2;i<= limit/2;i++)if(limit%i==0)sum+=i;
// 	
// 		int sum_2 = 1;
// 		//Find the sum of divisors of that number
// 		if(sum<MAX && list[sum][1]==0)for(int i = 2;i<=sum/2;i++)if(sum%i==0)sum_2+=i;
// 
// 		//if the two numbers are less than 10k, not equal to one another, and amicable, record them.
// 		if((sum_2==limit && sum<MAX) && (limit!=sum))//Need to not be equal to the same number! otherwise we double count.
// 		{
// 			list[limit][1]=sum;
// 			list[sum][1]=sum_2;
// 		}
// 	
// }

// --------- Project Euler Number 22 -----------


// Using names.txt (right click and 'Save Link/Target As...'), a 46K text file containing over five-thousand first names, begin by sorting it into alphabetical order. Then working out the alphabetical value for each name, multiply this value by its alphabetical position in the list to obtain a name score.
// 
// For example, when the list is sorted into alphabetical order, COLIN, which is worth 3 + 15 + 12 + 9 + 14 = 53, is the 938th name in the list. So, COLIN would obtain a score of 938 × 53 = 49714.
// 
// What is the total of all the name scores in the file?.

	/*names.txt has names separated by commas.

	std::remove- takes a range, and removes all values equal to third input argument. Doesn't change the size of the array/string.Returns an iterator/pointer to end of new array.  I then use a.erase to delete extra space when I store the name.

	std::getline(fin,a,',');//std::getline(input stream, "destination string, (optional) termination character);  Need to use this, else fin<< just gets all 5k names.*/
	
	//Success! the correct answer is 871198282
// #include <iostream>
// #include <sstream>
// #include <string>
// #include <fstream>
// #include <cmath>
// #include <vector>
// #include <algorithm> //presumably for erase method, remove, etc
// const char names_list[] = "names.txt";
// int main()
// {
// 	std::ifstream fin;
// 	fin.open(names_list);
// 	std::string temp = "";
// 	std::vector<std::string> name_list ;
// 	while(getline(fin,temp,','))//while the read succeeds,store what's left
// 	{
// 		temp.erase(std::remove(temp.begin(),temp.end(),'\"'),temp.end() );//Take the string we have, and looking between beginning and end, remove the double parenthesis instances.
// 		name_list.push_back(temp);//Reads each name into an entry.  Adds the name to the end of the vector
// 			
// 	}
// 	fin.close();//self_explanatory- close the input file.
// 	int name_num = name_list.size(); //how many names are we dealing with? 
// 	temp.clear();//clears the contents of temp, so I can use it later in the sorting process;
// 	
// 	//Next--- Sort the list into alphabetical order.  Use relational operators.  A bubble sort implementation- Not complex or fast, but simple to implement.  Swap adjacent elements till no elements are swapped
// 	
// 	// int sort_counter ; //repeat sorting till I pass through the array with no changes.
// // 	do
// // 	{
// // 		sort_counter = 0;
// // 		for(int i = 0;i<name_num-1;i++)
// // 		if(name_list[i]>name_list[i+1])
// // 		{
// // 			temp = name_list[i+1];
// // 			name_list[i+1]=name_list[i];
// // 			name_list[i]=temp;
// // 			sort_counter++;
// // 		}
// // 	}
// // 	while(sort_counter!=0);
// 
// std::sort(name_list.begin(),name_list.end());//USE THIS, like 20x faster than my self-implemented sort!!
// 	
// 	//As a debug-- Print out the contents of the now sorted list:
// 	
// // 	for( std::vector<std::string>::const_iterator i = name_list.begin();i !=name_list.end();i++)std::cout<<*i<<std::endl;
// 	
// 	//Now that names are sorted, calculate their "scores"
// 		//Strings are holding ascii capitals.  To convert to position in the alphabet subtract 64.
// 
// // std::string b = *name_list.begin();
// // std::cout<<b.size()<<std::endl;	
// // 	for(std::vector<std::string>::const_iterator i = name_list.begin();i !=name_list.end();i++)
// long *name_score = new long[name_num];//stores scores.  Use longs, because 5k * a score of easily 50 > int limit
// for(int i = 0;i<name_num;i++)name_score[i]=0;//initialize
// 
// 	for(int i = 0;i<name_num;i++)
// 	{
// 		long multiplier = 0;
// 		//Calculate multiplier for each position in the list
//  		for(int j = 0;j<name_list[i].size();j++)
//  		{
//  			multiplier+=(int)name_list[i][j]-64;
//  		}
// 		name_score[i] =(i+1)*multiplier;
// 	
// 	}
// 	//now, name_score has all the scores, scan through and sum them all up.
// 	
// 	long score_sum=0;
// 	
// 	for(int i = 0;i<name_num;i++)score_sum+=name_score[i];
// 	std::cout<<"The total score of all the names is equal to " <<score_sum<<std::endl;
// 
// 
// 	delete[] name_score; //Vital! to not have memory leak!
// 	return 0;
// }


// --------- Project Euler Number 23 -----------
		//Non-abundant sums
		
// 		A perfect number is a number for which the sum of its proper divisors is exactly equal to the number. For example, the sum of the proper divisors of 28 would be 1 + 2 + 4 + 7 + 14 = 28, which means that 28 is a perfect number.
// 
// A number n is called deficient if the sum of its proper divisors is less than n and it is called abundant if this sum exceeds n.
// 
// As 12 is the smallest abundant number, 1 + 2 + 3 + 4 + 6 = 16, the smallest number that can be written as the sum of two abundant numbers is 24. By mathematical analysis, it can be shown that all integers greater than 28123 can be written as the sum of two abundant numbers. However, this upper limit cannot be reduced any further by analysis even though it is known that the greatest number that cannot be expressed as the sum of two abundant numbers is less than this limit.
// 
// Find the sum of all the positive integers which cannot be written as the sum of two abundant numbers.


/*Pseudo-code:
	-Go through numbers less than 28123, and check if they're abundant.
		-If a number's abundant, record what it is;
		-Go through this list, and make numbers till you go over 28123.
		-Then go from 1 to 28123.  If its the current numb, don't add and increment, else add and move on
		*/
		
/* Solution--4179871.  Got via brute force.  Saw, and coded, a quicker way to arrive at same goal using a boolean array/vector.  Rather than manually storing a list of sums, then having to sort through unique values, it just marks if a number is an abundant sum or not.  Then you can just go through the array, and all the true entries have their indices added to the tally! */
		
		
// #include <iostream>
// #include <sstream>
// #include <string>
// #include <fstream>
// #include <cmath>

// #include <vector>
// #include <algorithm>
// 
// #define MAX_TO_CHECK 28123
// 		
// bool is_Abundant(int num_to_check);
// 
// 
// int main()
// {
// bool tester = false;
// 	std::vector<int> abundant_list;
// 	
// 	for(int i = 1;i<=MAX_TO_CHECK;i++)
// 	{
// 		tester = is_Abundant(i);
// 		if(tester==true)
// 		{
// 			abundant_list.push_back(i);
// 			tester=false; //need to reset for next go-around
// 		}
// 	}
// 
// // for(std::vector<int>::const_iterator i = abundant_list.begin();i!=abundant_list.end();i++)std::cout<<*i<<std::endl;
// // std::cout<<is_Abundant(18)<<std::endl;
// std::vector<int> abundant_sum_list;
// 	int abundant_sum = 0;
// 	//Loop through the list of abundant numbers, and find all sums of two which are less than 28123;
// 	
// 	for(int i = 0;i<abundant_list.size();i++)
// 		{
// 			for(int j = i;j<abundant_list.size();j++)
// 			{
// 				abundant_sum = abundant_list[i]+abundant_list[j];
// 				if(abundant_sum <=MAX_TO_CHECK)abundant_sum_list.push_back(abundant_sum);//add the sum to the list!
// 			}
// 		}
// 	//Now, I have a vector holding all of the sums of abundant numbers!
// 	
// 	std::sort(abundant_sum_list.begin(),abundant_sum_list.end());
// 	abundant_sum_list.erase(std::unique( abundant_sum_list.begin(),abundant_sum_list.end() ), abundant_sum_list.end() );
// 
// 	/*std::vector<bool> can_be_abundant_sum(MAX_TO_CHECK+1);
// 	for(int i = 0;i<MAX_TO_CHECK+1;i++)can_be_abundant_sum[i]=false;
// 	for(int i = 0;i<abundant_list.size();i++)
// 		{
// 			for(int j = i;j<abundant_list.size();j++)
// 			{
// 				abundant_sum = abundant_list[i]+abundant_list[j];
// 				if(abundant_sum<=MAX_TO_CHECK)can_be_abundant_sum[abundant_sum] = true;
// 				else break;
// 			}
// 		}
// 		long non_abundant_sum = 0;
// 		for(int i = 0;i<MAX_TO_CHECK;i++)if(can_be_abundant_sum[i]==false)non_abundant_sum+=i;	
// 		//Much faster way to calculate sums, as ~30k bool array.  Doesn't involve sorting!
// 		*/
// 	
// //Remove duplicate entries.  First sort.  Then , unique removes all duplicate entries in range, and returns an iterator to new "just past end entry".  erase then gets rid of entries from just_pas_end_new to old array.end();
// 
// 	long non_abundant_sum = 0;
// 	
// 	for(int i = 0,sum_index=0;i<=MAX_TO_CHECK;i++)
// 	{
// 		if(i==abundant_sum_list[sum_index])sum_index++;
// 		else non_abundant_sum +=i;
// 	}
// 
// 	//Now, non_abundant_sum should hold all the sum of all of the numbers which cannot be expressed as the sum of two abundant numbers!
// 	
// 	std::cout<<"The sum of all the numbers which cannot be expressed as the sum of two abundant numbers is equal to "<<non_abundant_sum<<std::endl;
// 	return 0;
// }
// 	
// 		
// bool is_Abundant(int num_to_check)
// {
// 	long sum = 1;//1 always is a "proper divisor".
// 	for(int i = 2;i*i <= num_to_check;i++)
// 	{
// 		if(num_to_check%i==0)
// 		{
// 			sum+=i;
// 			sum+=num_to_check/i;
// 		}
// 		if(i == num_to_check/i && num_to_check%i==0)sum-=i;//to make sure we don't double count perfect squares;
// 	}
// 	bool abundant_or_not = false;
// 	if(sum>num_to_check)abundant_or_not = true;
// 	return abundant_or_not;
// }

// --------- Project Euler Number 24 -----------
		//Lexographic Permutations
		
		/* Problem Statement -
		
		A permutation is an ordered arrangement of objects. For example, 3124 is one possible permutation of the digits 1, 2, 3 and 4. If all of the permutations are listed numerically or alphabetically, we call it lexicographic order. The lexicographic permutations of 0, 1 and 2 are:

012   021   102   120   201   210

What is the millionth lexicographic permutation of the digits 0, 1, 2, 3, 4, 5, 6, 7, 8 and 9? */

/* Here I use an algorithm to find successive permutations in lexographic order found online.  Pretty much what you do is scan from left to right, and find furthest entry, k, where its value is less than its immediate right-neighbor.  Then you find the left-most entry greater than entry k. Swap l and k entries, and reverse elements in between.  */
// #include <iostream>
// #include <sstream>
// #include <string>
// #include <cmath>

// #define MAX_PERM 1000000
// 
// void string_swap( std::string &string, int location_1,int location_2);
// 
// 
// int main()
// {
// 	std::string permuted_string = "0123456789";
// 	int size = permuted_string.size();
// 	
// 	long iteration_counter = 1;
// 	int biggest_k = 0,biggest_l = 0,counter=0;
// 	
// 	std::cout<<permuted_string<<std::endl;

// 	//Use Djikstra's? algorithm
// 	while(iteration_counter < MAX_PERM)
// 	{
// 		//find largest k, such that permuted_string[k]<permuted_string[k+1];
// 		 biggest_k = 0;
// 		for(int i = 0;i<size-1;i++)if(permuted_string[i]<permuted_string[i+1] && i>biggest_k)biggest_k = i;
// 		
// 		//Stops loop if we've found last permutation,which occurs when numbers are all decreasing
// 		counter =0 ;
// 		for(int i = 0;i<size-1;i++)if(permuted_string[i]>permuted_string[i+1])counter+=1;
// 		if(counter==size-1)break;
// 
// 		//Find largest index l such that a[k]<a[l];
// 		 biggest_l = biggest_k;
// 		for(int i = biggest_k+1;i<size;i++)if(permuted_string[i]>permuted_string[biggest_k] && i >biggest_l)biggest_l = i;
// 
// 		//swap these k,l values;
// 		string_swap(permuted_string,biggest_k,biggest_l);
// 	
// 		//Reverse values from biggest_k + 1 to final element.  
// 		int i = biggest_k + 1,j = size-1;
// 		while(i !=j)
// 		{
// 			string_swap(permuted_string,i,j);
// 			i++;
// 			j--;
// 			if(i>j)break;//If this happens we've "walked" by each other
// 		}
// 		iteration_counter++; 
// 	}	
// 		
// 	std::cout<<"The "<< MAX_PERM <<"th lexicographic permutation is equal to "<<permuted_string<<std::endl;
// 
// 
// return 0 ;
// }
// 
// void string_swap( std::string &string, int location_1,int location_2)
// {
// 	char temp = string[location_1];
// 	string[location_1]=string[location_2];
// 	string[location_2]=temp;
// }


// --------- Project Euler Number 25 -----------
		//1000 digit Fibonacci number
		
	/*	Problem Statement-
			The Fibonacci sequence is defined by the recurrence relation:

		Fn = Fn−1 + Fn−2, where F1 = 1 and F2 = 1.
		Hence the first 12 terms will be:

		F1 = 1
		F2 = 1
		F3 = 2
		F4 = 3
		F5 = 5
		F6 = 8
		F7 = 13
		F8 = 21
		F9 = 34
		F10 = 55
		F11 = 89
		F12 = 144
		The 12th term, F12, is the first term to contain three digits. 
		
		What is the first term in the Fibonacci sequence to contain 1000 digits?*/
		
		//Solution-> 4782.  Got by brute force, although there are some elegant ways to do it.
		
// #include <iostream>
// #include <sstream>
// #include <string>
// #include <fstream>
// #include <cmath>
		
// #include "big_int.h"		
// #define MAX_DIG 1000
// 
// 
// 
// int main()
// {
// 	std::string a = "1";
// 	big_int one(a),two(a),three(a);
// 	int counter = 2;
// 	while(three.get_size()<=MAX_DIG-1)
// 	{
// 		three = one + two;
// 		
// 		//reset numbers;
// 		one = two;
// 		two = three;
// 		counter++;
// 	}
// 	std::cout<<three<<"  "<<three.get_size()<<std::endl;
// 	std::cout<<"The first Fibonacci Number to have "<< MAX_DIG<< " digits occurs at term " <<counter<<std::endl;
// 	
// 	return 0;
// }

// --------- Project Euler Number 26 -----------
		//Reciprocal Cycles
		
	/*	Problem Statement-
			A unit fraction contains 1 in the numerator. The decimal representation of the unit fractions with denominators 2 to 10 are given:

	1/2	= 	0.5
	1/3	= 	0.(3)
	1/4	= 	0.25
	1/5	= 	0.2
	1/6	= 	0.1(6)
	1/7	= 	0.(142857)
	1/8	= 	0.125
	1/9	= 	0.(1)
	1/10	= 	0.1
	Where 0.1(6) means 0.166666..., and has a 1-digit recurring cycle. It can be seen that 1/7 has a 6-digit recurring cycle.

	Find the value of d < 1000 for which 1/d contains the longest recurring cycle in its decimal fraction part.
	*/

// #include <iostream>
// #include <sstream>
// #include <string>
// #include <cmath>
// #include <vector>
// 
// #define D_MAX 1000
// 
// int find_sequence_length(int d);
// 
// int main()
// {
// 	std::vector<int> decimal_list;
// 	int max_sequence_length = 0,sequence_length = 0,max_d;
// 	//Count down from 1000.  Maximum recurring sequence is d-1.  Stop when our max is >d.
// 	for(int d = D_MAX - 1;d>11;d--)
// 	{
// 		sequence_length = find_sequence_length(d);
// 		if(sequence_length>max_sequence_length)
// 			{
// 				max_sequence_length = sequence_length;
// 				max_d = d;
// 			}
// 		if(max_sequence_length>d)break;
// 	}
// 	std::cout<<"The maximum repeating length is equal to "<<max_sequence_length<<", at number "<<max_d<<std::endl;
// }
// 
// 
// int find_sequence_length(int d)
// {
// 	std::vector<int> modulo_list,denominator_list;
// 	modulo_list.push_back(0);
// 	denominator_list.push_back(0);
// 	
// 	int denominator = 10; //1 * 10//this would be what I change in the future.
// 	int modulo = 0,remain,start;
// 	bool repeat =false,non_repeat = false;
// 	while(!(repeat))//while repeat is not true (or hasn't been found
// 	{
// 		modulo = denominator/d;
// 		remain = denominator %d;
// 
// 		if(remain==0)
// 			{
// 				non_repeat=true;
// 				break;//No more repeats!
// 			}
// 		for(int i =0;i<modulo_list.size();i++)
// 			{
// 				if( modulo_list[i]==modulo && denominator_list[i]==denominator)
// 				{
// 					repeat=true;
// 					start = i;
// 				}
// 			}
// 		//if a repeat hasn't been found, add what we have and continue.
// 		modulo_list.push_back(modulo);
// 		denominator_list.push_back(denominator);
// 		denominator = 10*remain;
// 		if(repeat==true)break;
// 
// 	}
// 	if(non_repeat==true)return 0;
// 	else return modulo_list.size()-(1+start);// start is 0-based, so add 1.  Size is position of last element, in 1-based index.
// }


// --------- Project Euler Number 27 -----------
		//Quadratic Primes
		
	/*	Problem Statement-
		Euler discovered the remarkable quadratic formula:

	n² + n + 41

	It turns out that the formula will produce 40 primes for the consecutive values n = 0 to 39. However, when n = 40, 402 + 40 + 41 = 40(40 + 1) + 41 is divisible by 41, and certainly when n = 41, 41² + 41 + 41 is clearly divisible by 41.

	The incredible formula  n² − 79n + 1601 was discovered, which produces 80 primes for the consecutive values n = 0 to 79. The product of the coefficients, −79 and 1601, is −126479.

	Considering quadratics of the form:

	n² + an + b, where |a| < 1000 and |b| < 1000

	where |n| is the modulus/absolute value of n
	e.g. |11| = 11 and |−4| = 4
	Find the product of the coefficients, a and b, for the quadratic expression that produces the maximum number of primes for consecutive values of n, starting with n = 0.
	*/
	
	//Solution: -59231

// #include <iostream>
// #include <string>
// #include <cmath>
// 
// #define MAX  1000
// 
// bool isPrime(long value);
// 
// int main()
// {
// 	bool prime_tester;
// 	long value = 0;
// 	int max_prime_counter = 0,prime_counter,max_a = 0,max_b = 0;
// 	for(int a = -MAX+1;a<MAX;a++)
// 		for(int b = -MAX+1;b<MAX;b++)
// 		{
// 			int n = 0,prime_counter = 0;
// 			prime_tester = true;
// 			while(prime_tester)
// 			{
// 				value = n*n+a*n+b;
// 				if(value<=0)break;
// 				prime_tester = isPrime(value);
// 				prime_counter++;
// 				n++;
// 			}
// 			if(prime_counter > max_prime_counter)
// 			{
// 				max_prime_counter = prime_counter;
// 				max_a = a;
// 				max_b = b;
// 			}
// 		}
// 		long max_product = max_a*max_b;
// 
// std::cout<<"The product of coefficients, a and b, that produces the most number of consecutive primes is equal to "<<max_product<<std::endl;
// 
// 	return 0;
// }
// 
// 
// 
// bool isPrime(long value)//borrowed from earlier problems
// {
//     bool primeIndicator = true;
// 
// 	unsigned long divisor = 2; //A starting point
// 	while(divisor <= sqrt(value))
// 	{
// 	//Searches up to sqrt(value).  Value can be factored into a*b.  Max a and b can be is sqrt(value).  So we only need one leg of the "search", up to a's maximum value.
// 
//        if(value%divisor==0){primeIndicator = false; break;}
//        divisor++;
// 	}
// 	return primeIndicator ;//Returns the final most prime value.
// }

// --------- Project Euler Number 28 -----------
		//Number Spiral diagonals
		
	/*	Problem Statement-


		Starting with the number 1 and moving to the right in a clockwise direction a 5 by 5 spiral is formed as follows:

		21 22 23 24 25
		20  7  8  9 10
		19  6  1  2 11
		18  5  4  3 12
		17 16 15 14 13

		It can be verified that the sum of the numbers on the diagonals is 101.

		What is the sum of the numbers on the diagonals in a 1001 by 1001 spiral formed in the same way?  */
// #include <iostream>		
// #include <cmath>
// 	
// #define SPIRAL_SIZE 1001	
// 
// 
// int main () 
// {
// 	int max_ring = SPIRAL_SIZE/2,ring_num = 1,jump_counter,position=1 ;
// 	long sum = 1;
// 	
// 	while(ring_num <=max_ring)
// 	{
// 		jump_counter =0;
// 		while(jump_counter<4)
// 		{
// 			position +=2*ring_num;
// 			sum +=position;
// 			jump_counter++;
// 		}
// 		ring_num++;
// 	
// 	}
// 	std::cout<<"The diagonal sum of a "<<SPIRAL_SIZE<<" by "<<SPIRAL_SIZE<<" spiral is equal to "<<sum<<std::endl;
// 	
// 	return 0;
// }	

// --------- Project Euler Number 29 -----------
		//Distinct Powers
		
	/*	Problem Statement-
		Consider all integer combinations of ab for 2 ≤ a ≤ 5 and 2 ≤ b ≤ 5:

		2^2=4, 2^3=8, 2^4=16, 2^5=32
		3^2=9, 3^3=27, 3^4=81, 3^5=243
		4^2=16, 4^3=64, 4^4=256, 4^5=1024
		5^2=25, 5^3=125, 5^4=625, 5^5=3125
		If they are then placed in numerical order, with any repeats removed, we get the following sequence of 15 distinct terms:

		4, 8, 9, 16, 25, 27, 32, 64, 81, 125, 243, 256, 625, 1024, 3125

		How many distinct terms are in the sequence generated by a^b for 2 ≤ a ≤ 100 and 2 ≤ b ≤ 100?

*/
//Solution-9183

// #include <iostream>
// #include <cmath>
// 
// #define MAX 100 
// int pow_factors(int tb_fact);
// int simple_test(int test_int,int max_divisor);
// 
// int main()
// {
// int counter =0,fact_num,exp = 1;
// int test_bool;
// for(int a = 2;a<=MAX;a++)
// 	{
// 		fact_num = pow_factors(a);
// 		for(int b = 2;b<=MAX;b++)
// 		{
// 			if(fact_num ==0)counter++;
// 			
// 			if(fact_num !=0)
// 			{
// 			 exp = b*fact_num;
// 			 if(exp > ((fact_num-1)*MAX ) )counter++;//if greater than max last power
// 			 
// 			 test_bool = simple_test(exp,fact_num);
// 			 if( (exp>MAX && exp< (fact_num-1) * MAX ))
// 			  {
// 			   if(test_bool !=0) if( exp > MAX*test_bool ){counter++;}//if divisible, but greater than max*low_divisor
// 			   if(test_bool ==0){counter++;}//if not divisible, but in lower range/
// 			 	}
// 			 }
// 		}
// 	}
// std::cout<<counter<<std::endl;
// 	return 0;
// 
// }
// 
// int simple_test(int test_int,int max_divisor)
// {
// 	int result = 0;
// 	for(int i = max_divisor-1;i>=2;i--)
// 	{
// 		if(test_int%i ==0){result=i;break;}
// 	}
// 	
// 	
// 	return result;
// }
// int pow_factors(int tb_fact)
// {
// 	int base = 2,pow = 1,other=base;
// 	while(base*base<=tb_fact)
// 	{
// 	if(other<tb_fact)
// 	{
// 		other*=base;
// 		pow++;
// 	}
// 	if(other==tb_fact)
// 	{
// 		break;
// 	}
// 	if(other>tb_fact)
// 	{
// 		base++;
// 		other = base;
// 		pow = 1;
// 		//reset, essentially
// 	}
// 	}
// 	if(pow==1)pow=0;
// 	return pow;
// }

// --------- Project Euler Number 31 -----------
		//Coin Sums		
	/*	Problem Statement-
		In England the currency is made up of pound, £, and pence, p, and there are eight coins in general circulation:

		1p, 2p, 5p, 10p, 20p, 50p, £1 (100p) and £2 (200p).
		It is possible to make £2 in the following way:

		1×£1 + 1×50p + 2×20p + 1×5p + 1×2p + 3×1p
		How many different ways can £2 be made using any number of coins?  

	*/
// #include <iostream>
// #include <cmath>
// 	
// int find_combinations(int amount, int denoms[],int index);
// int main()
// {
// 	int p1 = 1,p2 = 2,p5 = 5, p10 = 10, p20 = 20, p50 = 50,L1 = 100,L2 = 200;
// 	
// 	int counter = 0,num_coins = 8,goal = 200;
// 	//use dynamic programming here
// 	int *coin_options = new int[num_coins];
// 	long ways[201]={0};
// 	ways[0]=1;
// 	coin_options[0]=p1;
// 	coin_options[1]=p2;
// 	coin_options[2]=p5;
// 	coin_options[3]=p10;
// 	coin_options[4]=p20;
// 	coin_options[5]=p50;
// 	coin_options[6]=L1;
// 	coin_options[7]=L2;
// //FOr each coin, calculate the ways to make i change using that coin.  Much simpler than the recursive solution, i think
// for(int coin_in = 0;coin_in<num_coins; coin_in++)
// for(int i = coin_options[coin_in];i<=goal;i++)
// {
// 	ways[i] +=ways[ i-coin_options[coin_in]];
// 	std::cout<<i-coin_options[coin_in]<<std::endl;
// }
// 
// std::cout<<ways[200]<<std::endl;
// // std::cout<<find_combinations(goal,coin_options,7)<<std::endl;
// //The power of recursion!
// 
// delete [] coin_options;
// return 0;
// }
// 
// int find_combinations(int amount ,int denoms[],int index)
// {	
// 	int total_combs = 0;
// 	if(index==0)return 1;
// 	if(amount<0)return 0;
// 	int k = amount/denoms[index];
// 	int cur_denom = denoms[index];
// 	for(int i = 0;i<=k;i++)
// 	{
// 		total_combs +=find_combinations(amount-i*cur_denom,denoms,index-1);
// 	}
// 
// return total_combs;
// }

// --------- Project Euler Number 30 -----------
		//Digit fifth Powers		
	/*	Problem Statement-
	
Surprisingly there are only three numbers that can be written as the sum of fourth powers of their digits:

1634 = 14 + 64 + 34 + 44
8208 = 84 + 24 + 04 + 84
9474 = 94 + 44 + 74 + 44
As 1 = 14 is not a sum it is not included.

The sum of these numbers is 1634 + 8208 + 9474 = 19316.

Find the sum of all the numbers that can be written as the sum of fifth powers of their digits.
	*/

//I'd bet that these numbers will be between 100,000 and 999,999;

// #include <cmath>
// #include <iostream>

// #define U_LIMIT 1000000
// #define SIZE 6  //10^6 is max, etc
// 
// long int_pow(long base,long exponent);
// 
// int main()
// {
// 	long test = 100;
// 	long second = 0,third = 0;
// 	long long sum = 0;
// 	int counter = 0;
// 	
// 
// while(test<U_LIMIT)
// {
// 	//make sum
// 	third= test;
// 	second = 0;
// 	for(int i = SIZE;i>=0;i--)
// 	{
// 		second +=int_pow( third/int_pow(10,i) ,5);
// 		if(third>=0)third-= (third/int_pow(10,i))*int_pow(10,i);
// 	}
// 
// 	if(second ==test)
// 	{
// 		sum+=test;
// 		counter++;
// 		std::cout<<test<<std::endl;
// 	}	
// 	test++;
// 	
// }	
// 	std::cout<<"The sum of these numbers is equal to "<<sum<<std::endl;
// return 0;
// }
// 
// long int_pow(long base,long exponent)
// {
// 	long result = base;
// 	if(exponent==0)return 1;
// 	if(exponent==1)return base;
// 	for(int i = 2;i<=exponent;i++)
// 	{
// 		result *=base;
// 	}
// return result;
// }

// --------- Project Euler Number 32 -----------
		//Pandigital Products
		
	/*	Problem Statement-
	
		We shall say that an n-digit number is pandigital if it makes use of all the digits 1 to n exactly once; for example, the 5-digit number, 15234, is 1 through 5 pandigital.

	The product 7254 is unusual, as the identity, 39 × 186 = 7254, containing multiplicand, multiplier, and product is 1 through 9 pandigital.

	Find the sum of all products whose multiplicand/multiplier/product identity can be written as a 1 through 9 pandigital.

	HINT: Some products can be obtained in more than one way so be sure to only include it once in your sum.


	Solution: 45228, in something like 0.2 seconds
	*/
// #include <cmath>
// #include <sstream>
// #include <string>
// #include <iostream>
// #include <vector>
// #include <algorithm>
// 
// 
// int main()
// {
// 	long c;
// 	long sum = 0;
// 
// 	std::stringstream ss;
// 	std::string output;
// 	std::vector<long> product_list;
// 	product_list.push_back(0);	
// 
// //Setup search loop here:
// 	for(long a = 2;a<100;a++)
// 		for(long b =a+1;b<10000/a ; b++)//INitially limit was 2k, but we can adjust because max product of a & b is 10k.
// 		{
// 			if(a%10==0 || b%10==0)continue; //skip unncessary cases.
// 			
// 			c = a*b;
// 			ss<<a;
// 			ss<<b;
// 			ss<<c;
// 		 	output = ss.str();
// 			//Makes sure that all elements are pandigital;
// 			
// 			if(output.size()==9)
// 			{
// 				std::sort(output.begin(),output.end());
// 				output.erase( std::unique( output.begin(),output.end() ),output.end() );
// 		
// 				//if pandigital:
// 				if(output.size()==9 && output[0]!='0')
// 				{
// 					//If we haven't found c already yet, add it to our list, and add it to our sum.
// 					if( !(std::find(product_list.begin(),product_list.end(),c)!=product_list.end() ) )
// 					{
// 						sum+=c;
// 						product_list.push_back(c);
// 					}
// 					std::cout<<a<<" "<<b<<" "<<c<<" "<<sum<<" "<<output<<std::endl;
// 				}
// 				
// 			}
// 			//Get string stream, output ready for next go around.
// 			ss.str(std::string());//clear string stream;
// 			output.erase();
// 		}
//   //End Loop here
// 
// std::cout<<" The sum of products from pandigital multiplications is equal to "<<sum<<std::endl;
// 
// return 0;
// }


// --------- Project Euler Number 33 -----------
		//Digit Canceling Fractions
		
	/*	Problem Statement-
		
		The fraction 49/98 is a curious fraction, as an inexperienced mathematician in attempting to simplify it may incorrectly believe that 49/98 = 4/8, which is correct, is obtained by cancelling the 9s.

We shall consider fractions like, 30/50 = 3/5, to be trivial examples.

There are exactly four non-trivial examples of this type of fraction, less than one in value, and containing two digits in the numerator and denominator.

If the product of these four fractions is given in its lowest common terms, find the value of the denominator.

	*/
	
	//Solution== 100!;  However, with clever thinking, can only reduce the search space to 84 searches! Think of cases where amicable numbers happen.
// 	
// #include <cmath>
// #include <iostream>
// 
// 
// int main()
// {
// 	int a_tens,a_ones,b_tens,b_ones;
// 	long numerator = 1,denominator = 1;
// for(int a = 11;a<100;a++)
// 	for(int b = a+1;b<100;b++)
// 	{
// 		if(a%10==0 || b%10==0)continue;
// 		
// 		a_tens = a/10;
// 		a_ones = a%10;
// 		b_tens = b/10;
// 		b_ones = b%10;
// 	
// 		if( a_tens ==b_tens  && b_ones*a==a_ones*b){numerator*=a_ones;denominator*=b_ones;}
// 	
// 		else if( a_tens == b_ones && b_tens*a==a_ones*b){numerator*=a_ones;denominator*=b_tens;}
// 		else if( a_ones == b_tens && b_ones*a==a_tens*b){numerator*=a_tens;denominator*=b_ones;}
// 		else if( (a_ones == b_ones && a_ones!=0) && b_tens*a==a_tens*b){numerator*=a_tens;denominator*=b_tens;}
// 	}	
// 	//Factorize "fraction"
// 	int a = 2;
// 	
// 	while(a<=numerator)
// 	{
// 		if(numerator%a==0 && denominator%a==0)
// 		{
// 			numerator/=a;
// 			denominator/=a;
// 		}
// 		a++;
// 	}
// 	std::cout<<numerator<<" "<<denominator<<std::endl;
// 
// 	return 0;
// }

// --------- Project Euler Number 34 -----------
		//Digit Factorials
		
	/*	Problem Statement-
	
	145 is a curious number, as 1! + 4! + 5! = 1 + 24 + 120 = 145.

Find the sum of all numbers which are equal to the sum of the factorial of their digits.

Note: as 1! = 1 and 2! = 2 are not sums they are not included.
	*/
	
	//Solution: 40730  
	//Solved 1/13/14
	
// #include <cmath>
// #include <iostream>
// 	
// long factorial(int n);
// 
// int main()
// {
// 	long a = 5,b = 1,sum = 0,digit_sum=0,holder;
// 	int remainder = 0;
// 	//pre_calculate factorial, and memo-ize.
// 	long factorial_holder[10];
// 	for(int i = 0;i<10;i++)factorial_holder[i]=factorial(i);
// 	
// 	long upper_limit = 7*factorial_holder[9];
// 	for(long i = 10;i<upper_limit;i++)
// 	{
// 		holder = i;
// 		digit_sum=0;
// 		while(holder>0)
// 		{
// 			remainder = holder%10;
// 			holder/=10;
// 			digit_sum+=factorial_holder[remainder];
// 		}
// 		if(digit_sum==i)sum+=i;
// 	
// 	}
// 	
// std::cout<<"The sum of all numbers equal to the sum of the factorial of their digits is equal to "<<sum<<std::endl;
// return 0;
// }
// 
// long factorial(int n)
// {
// 	if( n==0)return 1;
// 	else return n*factorial(n-1);
// 
// }

// --------- Project Euler Number 35 -----------
		//Circular Primes
		
	/*	Problem Statement-
	
	The number, 197, is called a circular prime because all rotations of the digits: 197, 971, and 719, are themselves prime.

There are thirteen such primes below 100: 2, 3, 5, 7, 11, 13, 17, 31, 37, 71, 73, 79, and 97.

How many circular primes are there below one million?
	*/
	
//Solution::55!
// #include <cmath>
// #include <iostream>
// #include <vector>
// 
// #define UPPER_LIMIT 1000000
// 
// int num_of_digits(long holder);
// bool isPrime(long long int value);
// long circ_shift_num(long test, int size);
// 
// int main()
// {
// 	int circ_prime_counter = 13,rot_counter,p_counter,num_dig,rot2_counter;
// 	bool prime_or_not = false,prime_or_not2=false;
// 	long temp;
// 	
// int checked_or_not[UPPER_LIMIT +1]={0};
// 				
// 	//start loop at 100;
// 	#pragma omp parallel for firstprivate(rot_counter,p_counter,num_dig,rot2_counter,temp,prime_or_not,prime_or_not2) reduction(+: circ_prime_counter)  //Perfect usage for this!! Careful though, may end up testing values that really don't need to be tested.
// for(long i = 100;i<UPPER_LIMIT;i++)
// {
// 		if(checked_or_not[i]==0)
// 		{
// 			prime_or_not=false;
// 			num_dig=num_of_digits(i);
// 		
// 			//first test i;
// 			prime_or_not = isPrime(i);
// 		
// 			rot_counter = 1;
// 			if(prime_or_not==true)
// 			{
// 				temp =i;
// 				prime_or_not2=false;
// 				p_counter=1;
// 			
// 				//permute others and test;
// 				while(rot_counter < num_dig)
// 				{
// 					temp = circ_shift_num(temp,num_dig);
// 					prime_or_not2 = isPrime(temp);
// 					if(prime_or_not2==true)p_counter++;
// 					rot_counter++;
// 				}
// 			
// 				if(p_counter==rot_counter)
// 				{
// 					circ_prime_counter+=p_counter;//This is how many we found!
// 					 rot2_counter=0;			
// 					//permute others and test;
// 					while(rot2_counter < num_dig)
// 					{
// 						temp = circ_shift_num(temp,num_dig);
// 						checked_or_not[temp]=1;
// 						rot2_counter++;
// 					}
// 				}
// 			}
// 			else
// 			{
// 			//Go through and mark others
// 					 rot2_counter = 0;			
// 					//permute others and test;
// 					temp = i;
// 					while(rot2_counter < num_dig)
// 					{
// 						temp = circ_shift_num(temp,num_dig);
// 						checked_or_not[temp]=1;
// 						rot2_counter++;
// 					}
// 		
// 			}
// 		
// 		}
// }
// 
// 	std::cout<<circ_prime_counter<<std::endl;
// // std::cout<<"The number of Circular Primes below " <<UPPER_LIMIT<< " is equal to "<< circ_prime_counter<<std::endl;
// 
// return 0;
// }
// 
// int num_of_digits(long holder)
// {
// 		
// 		int digit_sum=0;
// 		while(holder>0)
// 		{
// 			holder/=10;
// 			digit_sum++;
// 		}
// 		return digit_sum;
// }
// 
// long	circ_shift_num(long test, int size)
// 	{
// 		int* new_num = new int[size];
// 		int remainder = 0;
// 		long new_new_num = 0;
// 
// 		for(int i = 0;i<size;i++)
// 		{
// 			new_num[i] = test%10;
// 			test/=10;
// 		}
// 		long pow = 1;
// 		
// 		for(int i = 1;i<size;i++)
// 		{
// 			new_new_num += new_num[i]*pow;
// 			pow*=10;
// 		}
// 	
// 		new_new_num +=new_num[0]*pow;
// 		
// 		delete [] new_num;
// 	return new_new_num ;
// 	}
// 
// bool isPrime(long long int value)
// {
//     bool primeIndicator = true;
// 	long long int divisor = 2; //A starting point
// 	while(divisor <= sqrt(value))
// 	{
//         if(value%divisor==0){primeIndicator = false; break;}
//         divisor++;
// 	}
// 	return primeIndicator ;//Returns the final most prime value.
// }

// --------- Project Euler Number 37
	//Double-base palindromes
	
	/* Problem Statement
	
	The decimal number, 585 = 10010010012 (binary), is palindromic in both bases.

Find the sum of all numbers, less than one million, which are palindromic in base 10 and base 2.

(Please note that the palindromic number, in either base, may not include leading zeros.)

*/
// #include <cmath>
// #include <iostream>
// #include <string>
// #include <sstream>
// #define MAX 1000000
// 
// int	mirror_num(int test, int size);
// bool palindromic( std::string &array1, int start,int end);
// int num_of_digits(int holder);
// bool palindromic2( int tester,int base);
// std::string	dec_to_bin(int to_convert);
// 
// 
// int main()
// {
// int switched,num_dig;
// long sum_overall=0;
// bool is_Palindromic = false;
// std::string bin_number;
// for(int i = 1;i<MAX;i++)
// {
// 	// num_dig = num_of_digits(i);
// // 	
// // 	switched = mirror_num(i,num_dig);
// // 	
// // 	//Convert i to binary appropriately;
// // 	bin_number = dec_to_bin(i);
// // 	//Test if binary is palindromic:
// // 	is_Palindromic = palindromic(bin_number,0,bin_number.size()-1);
// // 	if(switched==i && is_Palindromic==true)sum_overall+=i;
// 	if(palindromic2(i,2)==true && palindromic2(i,10)==true)sum_overall+=i;
// }
// 
// std::cout<<" The sum of all double base palindromes less than 1 million is " <<sum_overall<<std::endl;
// 
// return 0;
// }
// 
// 
// std::string	dec_to_bin(int to_convert)
// {
// 	int holder = to_convert,counter = 0;
// 	
// 	while(to_convert>=1)
// 	{
// 		to_convert/=2;
// 		counter++;
// 	}
// 	
// 	int* bin_array = new int[counter];
// 	int index = counter-1;
// 	while(holder>=1)
// 	{
// 		bin_array[index--]= holder%2;
// 		holder/=2;
// 	}
// std::stringstream ss;
// for(int i = 0;i<counter;i++)ss<< bin_array[i];
// 
// 	delete [] bin_array;
// 	return ss.str();
// }
// int num_of_digits(int holder)
// {
// 		
// 		int digit_sum=0;
// 		while(holder>0)
// 		{
// 			holder/=10;
// 			digit_sum++;
// 		}
// 		return digit_sum;
// }
// 
// int	mirror_num(int test, int size)
// 	{
// 		int* new_num = new int[size];
// 		int remainder = 0;
// 		int new_new_num = 0;
// 
// 		for(int i = 0;i<size;i++)
// 		{
// 			new_num[i] = test%10;
// 			test/=10;
// 		}
// 		long pow = 1;
// 		
// 		for(int i = size-1;i>=0;i--)
// 		{
// 			new_new_num += new_num[i]*pow;
// 			pow*=10;
// 		}
// 	
// 		
// 		delete [] new_num;
// 	return new_new_num ;
// 	}
// 	
// bool palindromic2( int tester,int base)
// {
// 	long reversed = 0;
// 	int k = tester;
// 	//finds last digit of tester, multiplies it by base, effectively making it first, etc. Does this process in an arbitrary base.  
// 		while(k>0)
// 	{
// 		reversed = base* reversed + k%base;
// 		k/=base;
// 	}
// 	return tester==reversed;
// 
// }	
// bool palindromic( std::string &array1, int start,int end)
// {
// 	bool indicator = false;
// 	if(start>=end) indicator = true;
// 	
// 	else if(array1[start]==array1[end])
// 	{
// 		return palindromic(array1, start+1,end-1);
// 	}
// 	else indicator =false;
// 	
// 	return indicator;
// 
// }

/* // --------- Project Euler Number 37
	//Truncatable Primes
	
	 Problem Statement
	
	The number 3797 has an interesting property. Being prime itself, it is possible to continuously remove digits from left to right, and remain prime at each stage: 3797, 797, 97, and 7. Similarly we can work from right to left: 3797, 379, 37, and 3.

Find the sum of the only eleven primes that are both truncatable from left to right and right to left.

NOTE: 2, 3, 5, and 7 are not considered to be truncatable primes.

*/
	
	/* Solution (no code): Based on what's given in the problem statement, we know that 3797, 37, and 797 are going to be truncatable, so we need to look for 8 more. Also, these numbers in general won't end in 5, since they'd then be divisible by multiples of 5, and hence not be prime. Each digit will need to be made up only of prime numbers. Looking at two digit numbers first, we can quickly see that that 23, 53, and 73 are also truncatable and prime from both sides as well, bring our total number of found primes to 7. In three digits, we can also readily see that 313, 317 and 373 are also both primes, bringing us to 9 truncatable primes.
	
	
37
3797
797

23
53
73

313
317
373

3137

739397

*/


// --------- Project Euler Number 38 -----------
		//Pandigital Multiples
		
	/*	Problem Statement-
	
	Take the number 192 and multiply it by each of 1, 2, and 3:

192 × 1 = 192
192 × 2 = 384
192 × 3 = 576
By concatenating each product we get the 1 to 9 pandigital, 192384576. We will call 192384576 the concatenated product of 192 and (1,2,3)

The same can be achieved by starting with 9 and multiplying by 1, 2, 3, 4, and 5, giving the pandigital, 918273645, which is the concatenated product of 9 and (1,2,3,4,5).

What is the largest 1 to 9 pandigital 9-digit number that can be formed as the concatenated product of an integer with (1,2, ... , n) where n > 1?

	*/
	
// #include <cmath>
// #include <sstream>
// #include <string>
// #include <iostream>
// #include <algorithm>
// 
// 
// int main()
// {
// 	int c;
// 
// 	std::stringstream ss;
// 	std::string output,holder,last_max="1";
// 
// //Setup search loop here:
// 	for(int a = 2;a<10000;a++)
// 	{
// 		for(int b =1;b<10 ; b++)
// 		{
// 			if(a%10==0 || b%10==0)continue; //skip unncessary cases.
// 			
// 			c = a*b;
// 			if(output.size()<9)
// 			{
// 				ss<<c;
// 			}
// 			output = ss.str();
// 			if(output.size()==9)break;
// 		}
// 		 	output = ss.str();
// 		 	holder = ss.str();
// 			//Makes sure that all elements are pandigital;
// 			
// 			if(output.size()==9)
// 			{
// 				std::sort(output.begin(),output.end());
// 				output.erase( std::unique( output.begin(),output.end() ),output.end() );
// 		
// 				//if pandigital:
// 				if(output.size()==9 && output[0]!='0')
// 				{
// 					if(holder > last_max)last_max = holder;
// 				}
// 			}
// 				
// 			//Get string stream, output ready for next go around.
// 			ss.str(std::string());//clear string stream;
// 			output.erase();
// 			holder.erase();
// 	}
//   //End Loop here
// 
// std::cout<<last_max<<std::endl;
// return 0;
// }

// //concatenates two longs, by shifting a to the left to add b.  Probably a lot faster than strings.
// long int_concat(long a, long b)
// {
// 	long c = b;
// 	
// 	while(c>0)
// 	{
// 		a*=10;
// 		c/=10;
// 	}
// 	return a+b;
// }

// --------- Project Euler Number 39 -----------
		//Integer Right Triangles		
	/*	Problem Statement-
	
	If p is the perimeter of a right angle triangle with integral length sides, {a,b,c}, there are exactly three solutions for p = 120.

{20,48,52}, {24,45,51}, {30,40,50}

For which value of p ≤ 1000, is the number of solutions maximised?

	*/
	
	//Think about pythagorean law, (if a&b are even, c even. If a&b odd, c even.  If a ||b odd, c odd.  Pythagorean triples ony occur for even p.
//solution: 840	
// #include <iostream>
// 
// #define P_MAX 1000
// 
// int main()
// {
// 
// int max_p_sum = 0,local_sol_sum = 0,max_p_value=0,c = 0;
// for(int p = 3;p<=P_MAX;p+=2)
// {
// 	//Scan through side one, then side two, with side 2 starting at side 1.
// 	local_sol_sum = 0;
// 	for(int a = 1;a<p/2;a++)
// 		for(int b = a;b<p/2; b++)
// 		{
// 			 c = (p -a -b);
// 			if(a*a + b*b ==c*c)local_sol_sum++;
// 		
// 		}
// 		
// 		if(local_sol_sum>max_p_sum)
// 		{
// 			max_p_sum=local_sol_sum;
// 			max_p_value = p;
// 		}
// }
// 
// std::cout<<max_p_sum<<" "<<max_p_value<<std::endl;
// 
// return 0;
// }

// --------- Project Euler Number 40 -----------
		//Champernowne's constant		
	/*	Problem Statement-
	
	An irrational decimal fraction is created by concatenating the positive integers:

0.123456789101112131415161718192021...

It can be seen that the 12th digit of the fractional part is 1.

If dn represents the nth digit of the fractional part, find the value of the following expression.

d1 × d10 × d100 × d1000 × d10000 × d100000 × d1000000

	*/
	
	//Anser: 210!  Run time 0.005 seconds (or less)
	
	/*Searches while the total digit numbers is less than 100000.  Since numbers change digits at 9,99,999,pow-1, we address that there.  Each iteration we also update how many digits we've added to our sequence, as well as what numbers we've added.  If we've overshot where we are searching, we find out what digit satisfies the power of tenth-digit, and update the new search limit. */
// #include <iostream>
// 
// #define MAX  1000000
// 
// int	nth_dig(int num,int dig_diff);
// 
// 
// int main()
// {
// 	int dig_to_add = 1,pow = 10,dig_count = 0;
// 	int i = 0,n_dig,product = 1;
// 	int dig_to_search = pow,dig_diff ;
// 	
// 	while(dig_count<=MAX)
// 	{
// 
// 		if(i==pow-1)
// 		{
// 			dig_to_add++;
// 			pow*=10;
// 		}
// 				
// 		dig_count+=dig_to_add;	
// 		i++;
// 		if(dig_count>=dig_to_search)
// 		{
// 			dig_diff = dig_count-dig_to_search+1;
// 			n_dig = nth_dig(i,dig_diff);
// 			product*=n_dig;
// 			dig_to_search*=10;
// 		}
// 		std::cout<<i<<std::endl;
// 		
// 	}
// 	std::cout<<product<<std::endl;
// return 0;
// }
// 
// int	nth_dig(int num,int dig_diff)
// {	
// 	for(int i = 1;i<dig_diff;i++)
// 	{
// 		num/=10;
// 	}
// 	
// 	return num%10;
// }
// --------- Project Euler Number 41 -----------
		//Pandigital Prime
	/*	Problem Statement-
	
	We shall say that an n-digit number is pandigital if it makes use of all the digits 1 to n exactly once. For example, 2143 is a 4-digit pandigital and is also prime.

What is the largest n-digit pandigital prime that exists?

	*/

//Solution: 7652413

// #include <iostream>
// #include <sstream>
// #include <string>
// #include <cmath>
// 
// #define MAX_PERM 1000000
// 
// void string_swap( std::string &string, int location_1,int location_2);
// bool isPrime(long value);
// void next_string_perm( std::string &permuted_string);
// 
// int main()
// {
// 	std::string permuted_string = "987654321",original_string = "987654321",swapped_string = "123456789";
// 	std::stringstream ss;
// 	int isprime = false;
// 	long num_to_test = 0, pow = 1,string_length,counter = 1;
// 	
// while(isprime ==false)
//  	{
// 		next_string_perm( permuted_string );
// 		//make string into long
// 		pow = 1;
// 		num_to_test = 0;
// 		for(int i = permuted_string.size()-1;i>=0;i--)
// 		{
// 			num_to_test += pow *(permuted_string[i]-'0');
// 			pow*=10;
// 		}
// 		//test
// 		isprime = isPrime(num_to_test);
// 		if(permuted_string == swapped_string)
// 		{
// 			string_length = permuted_string.size();
// 
// 			swapped_string.clear();
// 			permuted_string.clear();
// 			for(int i = counter;i<9;i++)
// 			{
// 				ss<<original_string[i];
// 			}
// 			permuted_string = ss.str();
// 			ss.str(std::string());
// 			
// 			for(int i = 1;i<string_length;i++)
// 			{
// 				ss<<i;
// 			}
// 			swapped_string = ss.str();
// 			ss.str(std::string() );
// 			counter++;
// 
// 		}
// 	
//  }
// 	std::cout<<"The Biggest pandigital prime number is "<<permuted_string<<std::endl;	
// return 0 ;
// }
// 
// bool isPrime(long value)
// {
//     bool primeIndicator = true;
// 	long long int divisor = 2; //A starting point
// 	while(divisor <= sqrt(value))
// 	{
//         if(value%divisor==0){primeIndicator = false; break;}
//         divisor++;
// 	}
// 	return primeIndicator ;//Returns the final most prime value.
// }
// 
// void next_string_perm( std::string &permuted_string)
// {
// 		int size = permuted_string.size();
// 		int biggest_k = 0,biggest_l = 0,counter=0,index_i,index_j;
// 	
// 	
// 			//find largest k, such that permuted_string[k]>permuted_string[k+1];
// 			 biggest_k = 0;
// 			for(int i = 0;i<size-1;i++)if(permuted_string[i]>permuted_string[i+1] && i>biggest_k)biggest_k = i;
// 		
// 			//Stops loop if we've found lowest permutation,which occurs when numbers are all increasing
// 			counter =0 ;
// 			for(int i = 0;i<size-1;i++)if(permuted_string[i]<permuted_string[i+1])counter+=1;
// 			if(counter==size-1)goto end; //can't use break, not in a loop!
// 
// 			//Find largest index l such that a[k]>a[l];
// 			 biggest_l = biggest_k;
// 			for(int i = biggest_k+1;i<size;i++)if(permuted_string[i]<permuted_string[biggest_k] && i >biggest_l)biggest_l = i;
// 
// 			//swap these k,l values;
// 			string_swap(permuted_string,biggest_k,biggest_l);
// 	
// 			//Reverse values from biggest_k + 1 to final element.  
// 			 index_i = biggest_k + 1,index_j = size-1;
// 			while(index_i !=index_j)
// 			{
// 				string_swap(permuted_string,index_i,index_j);
// 				index_i++;
// 				index_j--;
// 				if(index_i>index_j)break;//If this happens we've "walked" by each other
// 			}
// 		end: ;
// 
// }
// void string_swap( std::string &string, int location_1,int location_2)
// {
// 	char temp = string[location_1];
// 	string[location_1]=string[location_2];
// 	string[location_2]=temp;
// }
// --------- Project Euler Number 42 -----------
		//Coded triangle numbers
		
	/*	Problem Statement-

	The nth term of the sequence of triangle numbers is given by, tn = ½n(n+1); so the first ten triangle numbers are:

1, 3, 6, 10, 15, 21, 28, 36, 45, 55, ...

By converting each letter in a word to a number corresponding to its alphabetical position and adding these values we form a word value. For example, the word value for SKY is 19 + 11 + 25 = 55 = t10. If the word value is a triangle number then we shall call the word a triangle word.

Using words.txt (right click and 'Save Link/Target As...'), a 16K text file containing nearly two-thousand common English words, how many are triangle words?

	*/

// std::remove- takes a range, and removes all values equal to third input argument. Doesn't change the size of the array/string.Returns an iterator/pointer to end of new array.  I then use a.erase to delete extra space when I store the name.
// 
// 	std::getline(fin,a,',');//std::getline(input stream, "destination string, (optional) termination character);  Need to use this, else fin<< just gets all 5k names.
	
	
//Can check quickly if its a triangle number, by inverse of tn = (1/2)n(n+1): think about arithmetic, if (sqrt(8*score+1)-1 )/2 is integer, its a triangle num! 	
// Solution:162 triangle words in list;

// #include <iostream>
// #include <string>
// #include <fstream>
// #include <cmath>
// #include <vector>
// #include <algorithm> //presumably for erase method, remove, etc
// const char names_list[] = "words.txt";
// 
// int main()
// {
// 	std::ifstream fin;
// 	fin.open(names_list);
// 	std::string temp = "";
// 	std::vector<std::string> name_list ;
// 	int counter = 0;
// 	while(getline(fin,temp,','))//while the read succeeds,store what's left
// 	{
// 		temp.erase(std::remove(temp.begin(),temp.end(),'\"'),temp.end() );//Take the string we have, and looking between beginning and end, remove the double parenthesis instances.
// 		name_list.push_back(temp);//Reads each name into an entry.  Adds the name to the end of the vector
// 			
// 	}
// 	fin.close();//self_explanatory- close the input file.
// 	int name_num = name_list.size(); //how many names are we dealing with?
// 	//create triangle numbers (like 50 lets say)
// 	
// 	// int triangle_num_list[75] = {0};
// // 	for(int i = 1;i<=75;i++)triangle_num_list[i-1]=i*(i+1)/2;
// 	
// 	for(int i = 0;i<name_num;i++)
// 	{
// 		//Now that names are sorted, calculate their "scores"
// 		//Strings are holding ascii capitals.  To convert to position in the alphabet subtract 64.
// 		int score=0;
// 
// 			//Calculate multiplier for each position in the list
//  			for(int j = 0;j<name_list[i].size();j++)score+=(int)name_list[i][j]-64;
// 	
// 		//Now that we have the score, is it a triangle number? if so
// 		// for(int i = 0;i<75;i++)
// // 		{
// // 			if(triangle_num_list[i]==score)
// // 			{
// // 				counter++;
// // 				break;
// // 			}
// // 		}
// 		double word_score = (sqrt(8*score+1)-1) /2;
// 		if( word_score==(int)word_score)counter++;
// 		
// 	}	
// 	
// 	std::cout<<"The total number of triangle words is " <<counter<<std::endl;
// 
// 
// 	return 0;
// }

// --------- Project Euler Number 43 -----------
		//Sub-string divisibility
		
	/*	Problem Statement-

The number, 1406357289, is a 0 to 9 pandigital number because it is made up of each of the digits 0 to 9 in some order, but it also has a rather interesting sub-string divisibility property.

Let d1 be the 1st digit, d2 be the 2nd digit, and so on. In this way, we note the following:

d2d3d4=406 is divisible by 2
d3d4d5=063 is divisible by 3
d4d5d6=635 is divisible by 5
d5d6d7=357 is divisible by 7
d6d7d8=572 is divisible by 11
d7d8d9=728 is divisible by 13
d8d9d10=289 is divisible by 17
Find the sum of all 0 to 9 pandigital numbers with this property.

//Solution:16695334890 //Also possible to do by hand

	*/
// #include <iostream>
// #include <string>
// #include "project_euler_functions.h"
// 	
// long make_num(std::string &permuted_string,int index,int dist);
// 
// int main()
// {
// 	int divisor_num = 7,test_prod;
// 	int divisor_list[7] = {2,3,5,7,11,13,17};
// 	std::string permuted_string = "9876543210";
// 	long long sum = 0,test_num;
// 
// while(permuted_string != "0123456789")
//  	{
//  		int counter = 0;
// 		for(int i = 0;i<divisor_num;i++)
// 		{	
// 			test_prod =make_num(permuted_string,i+3,3);
// 			if(test_prod%divisor_list[i]!=0)break;
// 			else counter++;
// 		}
// 
// 		if(counter ==divisor_num)//make number from string, add to sum.
// 		{
// 			test_num =make_num(permuted_string,9,10);
// 			sum+=test_num;
// 		}
// 		next_descending_string_perm(permuted_string);
// 
// 
// 	}
// 	std::cout<<" The sum of all pandigital primes with the specified property is equal to "<<sum<<std::endl;
// 	return 0;
// }
// 
// long make_num(std::string &permuted_string,int start,int dist)
// {
// 	long pow = 1;
// 	long  num = 0;
// 	
// 	for(int i = 0;i<dist;i++)
// 	{
// 		num+=pow*(permuted_string[start-i]-'0');
// 		pow*=10;
// 	}
// 	return num;
// }

// --------- Project Euler Number 44 -----------
		//Pentagon Numbers
		
	/*	Problem Statement-
	
	
	Pentagonal numbers are generated by the formula, Pn=n(3n−1)/2. The first ten pentagonal numbers are:

1, 5, 12, 22, 35, 51, 70, 92, 117, 145, ...

It can be seen that P4 + P7 = 22 + 70 = 92 = P8. However, their difference, 70 − 22 = 48, is not pentagonal.

Find the pair of pentagonal numbers, Pj and Pk, for which their sum and difference are pentagonal and D = |Pk − Pj| is minimised; what is the value of D?

	*/
//Generate a number, and search all possible combinations less than it?
//Solution: The Value of D is equal to 5482660

// #include <iostream>
// #include "project_euler_functions.h"
// 
// long make_pentagonal(long n);
// 
// int main()
// {
// 
// 	long n = 1, m, diff,sum,Pn,Qm;
// 	bool both_pentagonal = false;
// 	
// 	while(both_pentagonal ==false)
// 	{
// 		m = n-1;
// 		Pn = make_pentagonal(n);
// 		while(m>1)
// 		{
// 			Qm = make_pentagonal(m);
// 			sum = Qm + Pn;
// 			diff =Pn - Qm;
// 			if(is_pentagon(sum) ==true && is_pentagon(diff)==true)
// 			{
// 				both_pentagonal =true;
// 				std::cout<<diff<<" "<<sum<<" "<<Pn<<" "<<Qm<<" "<<m<<" "<<n<<std::endl;
// 				break;
// 			}
// 			m--;
// 		}
// 		n++;
// 	}
// 	std::cout<<"The Value of D is equal to "<<diff<<std::endl;
// 
// }
// 
// long make_pentagonal(long n){return n*(3*n-1)/2;}


// --------- Project Euler Number 45 -----------
		//Triangular,pentagonal, and hexagonal
		
	/*	Problem Statement-

Triangle, pentagonal, and hexagonal numbers are generated by the following formulae:

Triangle	 	Tn=n(n+1)/2	 	1, 3, 6, 10, 15, ...
Pentagonal	 	Pn=n(3n−1)/2	 	1, 5, 12, 22, 35, ...
Hexagonal	 	Hn=n(2n−1)	 	1, 6, 15, 28, 45, ...
It can be verified that T285 = P165 = H143 = 40755.

Find the next triangle number that is also pentagonal and hexagonal.

*/
//Just use relations to check if a given number is also Pn and Hn: solution : 1533776805

// #include <iostream>
// #include <cmath>
// 
// int main()
// {
// 	bool found = false;
// 	long n = 286;//Starting point from problem statement
// 	double test_case1 = 0.,test_case2 = 0.;
// 	while(found ==false)
// 	{
// 		test_case1 = (1. + sqrt(1.+12.*n*n + 12.*n))/6.;
// 		test_case2 = (1. + sqrt(1.+4.*n*n + 4.*n))/4.;
// 		if(test_case1 ==(long)test_case1 && test_case2 ==(long)test_case2)
// 		{
// 			found =true;
// 		}
// 		n++;
//  	}
// 	n--;
// 	long next_num =n*(n+1)/2; 
// 	std::cout<<"The next triangle number that is also pentagonal and hexagonal is equal to "<< next_num<<std::endl;
// 
// 	return 0;
// }

// --------- Project Euler Number 46 -----------
		//Goldbach's other conjecture
		
	/*	Problem Statement-
	
	It was proposed by Christian Goldbach that every odd composite number can be written as the sum of a prime and twice a square.

9 = 7 + 2×12
15 = 7 + 2×22
21 = 3 + 2×32
25 = 7 + 2×32
27 = 19 + 2×22
33 = 31 + 2×12

It turns out that the conjecture was false.

What is the smallest odd composite that cannot be written as the sum of a prime and twice a square?
//Solution is 5777
	*/
	
// #include <iostream>
// #include "project_euler_functions.h"
// 
// 
// 
// int main()
// {	
// 	int pow_list[100] = {0};
// 	for(int i = 1;i<100;i++)pow_list[i]= (i+1)*(i+1);
// 	
// 	int search_num = 33;
// 	bool found =false, is_prime = false,tester=false;
// 	
// 	while(found ==false)
// 	{
// 		is_prime = isPrime(search_num);
// 				std::cout<<search_num<<std::endl;
// 
// 		if(is_prime==true){search_num+=2;continue;}
// 		
// 		long base = 1;
// 		tester = false;
// 		while(search_num>=2*base*base)
// 		{
// 			tester=isPrime(search_num- 2*base*base);
// 			if(tester==true){break;}
// 			base++;
// 		}
// 		if(tester==false)break;
// 	
// 	search_num+=2;
// 	}
// 	
// 	std::cout<<"The number we're looking for is "<<search_num<<std::endl;
// 
// 	return 0;
// }

// --------- Project Euler Number 47 -----------

		//Distinct primes factors
		

		/* Problem Statement -
		
		The first two consecutive numbers to have two distinct prime factors are:

		14 = 2 × 7
		15 = 3 × 5

		The first three consecutive numbers to have three distinct prime factors are:

		644 = 2² × 7 × 23
		645 = 3 × 5 × 43
		646 = 2 × 17 × 19.

		Find the first four consecutive integers to have four distinct prime factors. What is the first of these numbers?
		*/

//SOlution : 134043. 		
// #include <iostream>
// #include "project_euler_functions.h"
// 	
// 	
// int main()
// {
// int to_test = 2*3*5*7;
// int four_primes = 0;
// 	while(four_primes!=4)
// 	{
// 	
// 		if(prime_divisors(to_test)==4)
// 		{
// 			four_primes++;
// 			to_test++;
// 		}
// 		else
// 			{
// 			four_primes=0;
// 			to_test+=1;
// 			}
// 	}
// 	to_test--;
// 	for(int i = 0;i<4;i++)std::cout<<to_test--<<" ";
// 	std::cout<<std::endl;
// 
// 	return 0;
// }	


// --------- Project Euler Number 48 -----------
		//Self Powers
		
	/*	Problem Statement-
	
		The series, 1^1 + 2^2 + 3^3 + ... + 10^10 = 10405071317.

		Find the last ten digits of the series, 11 + 22 + 33 + ... + 10001000.  
	*/
	
// #include <iostream>
// #include <cmath>
// 
// #define SERIES_MAX 1000
// 
// long long mod_power(int base, int power,long long modulo);
// //Check out wikipedia on modular exponentiation for more info.  REALLY quick!!
// 
// /* Useful to know:: c = (a*b) mod m equivalent to c = (a *(b mod m) ) mod m .  A natural extension then is to just keep track of the remainders, and keep adding.  
// 
// Other helpful identities -- a = b mod n, a+c = b+c mod (n).  (taken over the whole equation);
// Similarly, a = b modn, a^k = b^k mod n, for integer k;
// 
// */
	//solution:: 9110846700

// int main()
// {
// 	unsigned long long m =10000000000,sum=0; //Need the last ten digits, or the remainder after division by 10^10;
// 	
// 	for(int e = 1;e<=SERIES_MAX;e++)
// 	{
// 		sum+= mod_power(e,e,m);
// 		sum=sum%m;	
// 	
// 	}
// 	std::cout<<sum<<std::endl;
// 	
// 	return 0;
// }
// 
// long long mod_power(int base, int power,long long modulo)
// {
// 	long long c = 1;
// 	for(int e = 1;e<=power;e++)
// 	{
// 		c =(base*c )%modulo;
// 	}
// 	return c;
// }

// #include <sstream>		
// #include <string>
// #include "big_int.h"
// void big_int_power(big_int &b_int, int power);

// int main()
// {
// 	std::string start = "0";
// 	big_int sum(start),to_square(start);
// 	
// 	stringstream ss;
// 	for(int power = 1;power<=SERIES_MAX;power++)
// 	{	
// 		ss<<power;//put the int to a stringstream;
// 		to_square.clear_value();
// 		to_square = ss.str();//put the string int into to_square;
// 		big_int_power(to_square,power); //find the power
// 		sum+=to_square;//add to sum
// 		ss.str( std::string() );//clear contents of the string stream, repeat;
// 	}
// 
// 	std::cout<<"The last 10 digits of the sum given above are " <<" ";
// 	for(int i = sum.get_size()-11;i<sum.get_size();i++)std::cout<<sum[i];
// 	std::cout<<std::endl;
// 	return 0;
// }

// void big_int_power(big_int &b_int, int power)
// {
// 	big_int a = b_int;
// 	if(power>1)for(int i = 2;i<=power;i++)
// 	{
// 		b_int *=a;
// 	}
// }
//here use modular exponentiation, see how much faster it becomes? other one is correct, but runs slooooowwwlly;

// --------- Project Euler Number 49 -----------
		//Prime permutations
		
	/*	Problem Statement-

		The arithmetic sequence, 1487, 4817, 8147, in which each of the terms increases by 3330, is unusual in two ways: (i) each of the three terms are prime, and, (ii) each of the 4-digit numbers are permutations of one another.

	There are no arithmetic sequences made up of three 1-, 2-, or 3-digit primes, exhibiting this property, but there is one other 4-digit increasing sequence.

	What 12-digit number do you form by concatenating the three terms in this sequence?

	*/
	//Solution : 296962999629 (had to avoid finding the one from the example!
// #include <iostream>
// #include <vector>
// #include "project_euler_functions.h"
// 
// #define MAX 10000
// 
// int main()
// {
// 
// 	//make list of primes from 1000-9999 with sieve of erasthones (add to function library)
// 	//Go through list, and find permutions of each? looking for 
// 	std::vector<int> test = sieve_of_Erasthenes( 10000,1000);
// 	
// 	//test[0] = minimum
// 	//test[test.size()-1]=max.
// 	//max_interval = (max-min)/2
// 	int max_interval = (test[test.size()-1]-test[0])/2, test_interval,c_i,c_j;
// 	bool prime_test,found = false;
// 	//starting at test[0], find interval test[i]-test[0] till interval >max or test[i]
// for(int i = 0;i<test.size();i++)
// 	{
// 		for(int j = i+1;j<test.size();j++)
// 		{
// 			test_interval = test[j]-test[i];
// 			prime_test = isPrime(test[i]+2*test_interval);
// 			if(prime_test==true && test[i]+2*test_interval<MAX)
// 			{
// 				if( (test[i]!=1487 && permutation_finder(test[i],test[j])) && permutation_finder(test[i],test[i]+2*test_interval))
// 				{
// 					found=true;
// 					c_i=i;
// 					c_j=j;
// 					break;
// 				}
// 			} 
// 			if(test_interval >max_interval || test[i]+2*test_interval>MAX)break;
// 		}
// 		if(found ==true)break;
// 	}
// 		std::cout<<test[c_i]<<test[c_j]<<test[c_i]+2*test_interval<<std::endl;
// // 	for(std::vector<int>::const_iterator i = test.begin();i!=test.end();i++)std::cout<<*i<<std::endl;
// // std::cout<<test.size()<<std::endl;
// 
// 	
// 
// 	return 0;
// 	
// }

// --------- Project Euler Number 50 -----------
		//Consecutive Prime Sum
		
	/*	Problem Statement-
	
	The prime 41, can be written as the sum of six consecutive primes:

41 = 2 + 3 + 5 + 7 + 11 + 13
This is the longest sum of consecutive primes that adds to a prime below one-hundred.

The longest sum of consecutive primes below one-thousand that adds to a prime, contains 21 terms, and is equal to 953.

Which prime, below one-million, can be written as the sum of the most consecutive primes?

	*/
	//solution:997651 can be written as a sum of 543 primes
	
	
// #include <iostream>
// #include <vector>
// #include "project_euler_functions.h"
// 
// 
// int main()
// {
// 	int upper_bound = 1000000;
// 	std::vector<int> prime_list = sieve_of_Erasthenes(upper_bound,1);
// 	int max_terms=0,current_sum;
// 	int trialsum = 0,listsize = prime_list.size(),biggest_int;
// 	
// 	unsigned long total_sum = 0;
// 	int i = 0;
// 	for(int start = 0;start<listsize;start++)
// 	{
// 		total_sum = 0;
// 		i= 0;
// 		while(total_sum<upper_bound && (start+i)<listsize)
// 		{
// 			total_sum+=prime_list[start+i];
// 			i++;
// 		}
// 		
// 		while(i>0)
// 		{
// 			if(isPrime(total_sum)==true && (i>max_terms && total_sum<upper_bound))
// 			{
// 				max_terms = i;
// 				biggest_int = total_sum;
// 				break;
// 			}
// 			else
// 			{
// 				i--;
// 				total_sum-=prime_list[start+i];
// 			}
// 		}
// 	}
// 	std::cout<<biggest_int<<" can be written as a sum of "<<max_terms<< " primes"<<std::endl;
// // 	for(std::vector<int>::const_iterator i = prime_list.begin();i!=prime_list.end();i++)std::cout<<*i<<std::endl;
// 
// return 0;	
// }

// --------- Project Euler Number 51 -----------
		//Prime Digit Replacements
		
	/*	Problem Statement-
	
	By replacing the 1st digit of the 2-digit number *3, it turns out that six of the nine possible values: 13, 23, 43, 53, 73, and 83, are all prime.

By replacing the 3rd and 4th digits of 56**3 with the same digit, this 5-digit number is the first example having seven primes among the ten generated numbers, yielding the family: 56003, 56113, 56333, 56443, 56663, 56773, and 56993. Consequently 56003, being the first member of this family, is the smallest prime with this property.

Find the smallest prime which, by replacing part of the number (not necessarily adjacent digits) with the same digit, is part of an eight prime value family.

	*/
	
	//Help from reading online- First prime has three repeating digits, and these will be 0,1,2.  Repeating digits won't be in last digit.  Will start search at first 4 digit prime, 1001, incrementing and prime testing.
	
// #include <iostream>
// #include "project_euler_functions.h"
// 
// int main()
// {	
// 	long i = 1001;
// 	int indexes[3]={0};
// 	int increment,family_counter=0,starting_dig = 0;;
// 
// 	while(family_counter!=8)
// 	{
// 		starting_dig= repeating_except_last(i,3);
// 		if(starting_dig>=3 ||starting_dig <0){i+=2;continue;}//Allow if there are three repeating digits, and they're 0,1,or2.
// 		family_counter=0;
// 		if(isPrime(i))//ifthe number is prime and has three repeating digits
// 		{
// 			family_counter++;
// 			find_locations(i,indexes,starting_dig);
// 			increment = 1;
// 			while(starting_dig+increment<10)
// 			{
// 				if(isPrime(switch_at_locations(i,indexes,starting_dig,starting_dig+increment ) ))family_counter++;
// 				increment++;
// 			}
// 		}
// 			i+=2;
// 		
// 	}
// 	i-=2;
// std::cout<<"The Lowest Prime in the 8-prime family is equal to "<<i<<std::endl;
// 	return 0;
// 	
// }

// --------- Project Euler Number 52 -----------
		//Permuted Multiples
		
	/*	Problem Statement-
It can be seen that the number, 125874, and its double, 251748, contain exactly the same digits, but in a different order.

Find the smallest positive integer, x, such that 2x, 3x, 4x, 5x, and 6x, contain the same digits.

	*/
	//Solution:142857
	
	//Side note: since numbers divisible by three have digit sum divisible by three, x must also be divisible by three. So we can start at 3, and increment by three!Checking this many cases cuts execution time even further!
// #include <iostream>
// #include "project_euler_functions.h"
// 
// int main()
// {
// 	int max_multiple = 6,counter=0;
// 	long test =3;
// 
// 	while(counter!= max_multiple-1)
// 	{
// 		counter =0;
// 		for(long i = 2;i<=max_multiple;i++)
// 		{
// 			if( permutation_finder(test,i*test) )counter++;
// 			else break;
// 		}
// 		test+=3;
// 	}
// 		test-=3; //test increments once after we find our solution
// 	std::cout<<"The Smallest positive integer x that has several multiples that are permutations is equal to "<<test<<std::endl;
// 	return 0;
// }

// --------- Project Euler Number 53 -----------
		//Combinatoric selections
		
		/* Problem Statement-

		There are exactly ten ways of selecting three from five, 12345:

		123, 124, 125, 134, 135, 145, 234, 235, 245, and 345

		In combinatorics, we use the notation, 5C3 = 10.

		In general,

		nCr =	
		n!
		r!(n−r)!
		,where r ≤ n, n! = n×(n−1)×...×3×2×1, and 0! = 1.
		It is not until n = 23, that a value exceeds one-million: 23C10 = 1144066.

		How many, not necessarily distinct, values of  nCr, for 1 ≤ n ≤ 100, are greater than one-million?
	*/
	//Solution: 4075.  Interestingly, doubles work! even though the precision isn't the same as always dealing with ints.  One way to work is solve Pascal's triangle, looking for entries above 1 million
// #include <iostream>
// #include <cmath>
// 
// double log_factorial(double X);
// 
// int main()
// {
// 	double numerator = 0.,d_r = 0.,d_nmr = 0.;
// 	int limit = 100,counter = 0;
// 	double max = log(1000000);
// 	for(int n = 1;n<=limit;n++)
// 	for(int r = 1;r<=n;r++)
// 	{
// 		if(log_factorial(1.*n)-log_factorial(1.*r)-log_factorial(1.*(n-r)) >max)counter++;
// 		
// 	}
// std::cout<<counter<<std::endl;
// 	return 0;
// }
// 
// double log_factorial(double X)
// {
// 	double newX = 0.;
// 	while(X>0.)
// 	{
// 		newX+= log(X);
// 		X-=1.;
// 	}
// 	
// 	return newX;
// 
// }


// --------- Project Euler Number 54 -----------
		//Poker Hands
		
		/* Problem Statement-

In the card game poker, a hand consists of five cards and are ranked, from lowest to highest, in the following way:

High Card: Highest value card.
One Pair: Two cards of the same value.
Two Pairs: Two different pairs.
Three of a Kind: Three cards of the same value.
Straight: All cards are consecutive values.
Flush: All cards of the same suit.
Full House: Three of a kind and a pair.
Four of a Kind: Four cards of the same value.
Straight Flush: All cards are consecutive values of same suit.
Royal Flush: Ten, Jack, Queen, King, Ace, in same suit.
The cards are valued in the order:
2, 3, 4, 5, 6, 7, 8, 9, 10, Jack, Queen, King, Ace.

If two players have the same ranked hands then the rank made up of the highest value wins; for example, a pair of eights beats a pair of fives (see example 1 below). But if two ranks tie, for example, both players have a pair of queens, then highest cards in each hand are compared (see example 4 below); if the highest cards tie then the next highest cards are compared, and so on.

Consider the following five hands dealt to two players:

Hand	 	Player 1	 	Player 2	 	Winner
1	 	5H 5C 6S 7S KD
Pair of Fives
 	2C 3S 8S 8D TD
Pair of Eights
 	Player 2
2	 	5D 8C 9S JS AC
Highest card Ace
 	2C 5C 7D 8S QH
Highest card Queen
 	Player 1
3	 	2D 9C AS AH AC
Three Aces
 	3D 6D 7D TD QD
Flush with Diamonds
 	Player 2
4	 	4D 6S 9H QH QC
Pair of Queens
Highest card Nine
 	3D 6D 7H QD QS
Pair of Queens
Highest card Seven
 	Player 1
5	 	2H 2D 4C 4D 4S
Full House
With Three Fours
 	3C 3D 3S 9S 9D
Full House
with Three Threes
 	Player 1
The file, poker.txt, contains one-thousand random hands dealt to two players. Each line of the file contains ten cards (separated by a single space): the first five are Player 1's cards and the last five are Player 2's cards. You can assume that all hands are valid (no invalid characters or repeated cards), each player's hand is in no specific order, and in each hand there is a clear winner.

How many hands does Player 1 win?

//SOlution: 376 hands.

	*/
	
	
// #include <iostream>
// #include <fstream>
// #include <sstream>
// #include <string>
// #include <vector>
// #include <algorithm>
// #include "project_euler_functions.h"
// 
// std::string	find_hand(std::string &hand);
// 
// const char file_name[] = "poker.txt";
// int main()
// {
// 
// 	std::ifstream fin;
// 	fin.open(file_name);
// 	std::string temp = "",hand1="",hand2="";
// 	std::vector<std::string> player1_hands,player2_hands ;
// 	int counter = 0;
// 		std::stringstream ss;
// 
// while(getline(fin,temp))
// 	{
// 		temp.erase(std::remove_if(temp.begin(),temp.end(),isspace),temp.end());
// 		for(int i = 0;i<10;i++)ss<<temp[i];
// 		hand1 = ss.str();
// 		ss.str(std::string());
// 		for(int i = 10;i<20;i++)ss<<temp[i];
// 		hand2 = ss.str();
// 		ss.str(std::string());
// 		player1_hands.push_back(hand1);
// 		player2_hands.push_back(hand2);
// 		hand1.clear();
// 		hand2.clear();
// 	}
// // 	//now that hands are stored, etc, we can compare! cards are number,suit
// 	int num_hands = player1_hands.size();
// // 	//Hands will be assigned 1-10 based on hand type.  As hands are narrowed down, we subtract from 55.
// 	int player1_won = 0;
// 	for(int i = 0;i<num_hands;i++)
// 	{
// 		if( find_hand(player1_hands[i]) >find_hand(player2_hands[i]))player1_won++;
// 	}
// 	std::cout<<"Player 1 won " <<player1_won<< " hands out of the 1000 played"<<std::endl;
// 	return 0;
// }
// 
// std::string	find_hand(std::string &hand)
// {
// //3x,2p,1p need highest,l
// // 2 3 4 5 6 7 8 9 10 J Q K A
// // 0 1 2 3 4 5 6 7 8  9 10 11 12
// // A B C D E F G H I  J K  L  M
// std::stringstream ss;
// 
// 		int c[13]={0};
// 		char hand_type;
// 		bool flush = false;
// 		int suit_same = 0;
// 		for(int i = 3;i<=9;i+=2)suit_same+=(hand[1]==hand[i]);
// 		if(suit_same ==4)flush=true;
// 		
// 		for(int i = 0;i<10;i+=2)
// 		{
// 			if(hand[i]=='T')c[8]++;
// 			else if (hand[i]=='J')c[9]++;
// 			else if (hand[i]=='Q')c[10]++;
// 			else if (hand[i]=='K')c[11]++;
// 			else if (hand[i]=='A')c[12]++;
// 			else
// 			c[hand[i]-'0'-2]++;
// 		}
// 		//now c holds card distribution
// 	
// 	int pair_counter = 0;
// 	int card_sum = 0;
// 	bool three_of_a_kind = false;
// 		for(int i = 0;i<13;i++)//0th entry always filled
// 		{
// 			if(c[i]==4){hand_type='H';break;}//four of a kind;
// 			if(c[i]==3)three_of_a_kind=true;
// 			if(c[i]==2)pair_counter++;
// 			if(c[i]==1)card_sum++;
// 		}
// 		if(three_of_a_kind==true)hand_type='D';
// 		if(pair_counter==1)hand_type='B';
// 
// 		if(three_of_a_kind==true && pair_counter==1)hand_type = 'G';
// 		if(pair_counter==2)hand_type='C';
// 		if(card_sum==5)hand_type = 'A';
// 		
// 		bool straight = false;
// 		int high_card = 0;
// 		int counter=0 ;
// 		for(int i = 0;i<12;i++)
// 		{
// 			if(c[i]==1 && c[i+1]==1)counter++;
// 			if(counter==4){high_card = i+1;straight=true;break;}
// 		}
// 		
// 		if(straight==false && flush==true)hand_type='F';
// 		if(straight==true && flush==true)hand_type ='I';
// 		if(straight==true && flush==false)hand_type = 'E';
// 		if(hand_type=='I' && high_card==12)hand_type ='J';
// 		ss<<hand_type;
// 		
// 		int max_repeat = 4;
// 
// 		int cards_outputted = 0;
// 		while(max_repeat>1)
// 		{
// 			for(int i = 12;i>=0;i--)
// 			{
// 				if(c[i]==max_repeat)
// 				{
// 					for(int j = 0;j<max_repeat;j++){ss<<(char)(i+'A');cards_outputted++;}
// 					c[i]=0;
// 				}
// 			}
// 			max_repeat--;
// 		}
// 		
// 
// 			for(int i = 12;i>=0;i--)
// 			{
// 				if(c[i]==1)
// 				{
// 					ss<<(char)(i+'A');
// 					cards_outputted++;
// 					c[i]=0;
// 				}
// 			}
// 
// 		return ss.str();
// 
// }
// --------- Project Euler Number 55 -----------
		//Lychrel numbers
		
		/* Problem Statement-
		
		If we take 47, reverse and add, 47 + 74 = 121, which is palindromic.

Not all numbers produce palindromes so quickly. For example,

349 + 943 = 1292,
1292 + 2921 = 4213
4213 + 3124 = 7337

That is, 349 took three iterations to arrive at a palindrome.

Although no one has proved it yet, it is thought that some numbers, like 196, never produce a palindrome. A number that never forms a palindrome through the reverse and add process is called a Lychrel number. Due to the theoretical nature of these numbers, and for the purpose of this problem, we shall assume that a number is Lychrel until proven otherwise. In addition you are given that for every number below ten-thousand, it will either (i) become a palindrome in less than fifty iterations, or, (ii) no one, with all the computing power that exists, has managed so far to map it to a palindrome. In fact, 10677 is the first number to be shown to require over fifty iterations before producing a palindrome: 4668731596684224866951378664 (53 iterations, 28-digits).

Surprisingly, there are palindromic numbers that are themselves Lychrel numbers; the first example is 4994.

How many Lychrel numbers are there below ten-thousand?
//Solution: 249

		*/

// #include <iostream>
// #include "project_euler_functions.h"
// 
// int main()
// {
// 	unsigned long max = 10000,i = 1,test;
// 	int iterations = 0,limit = 50,lychrel_count=0;
// 	
// 	//Search through all i integers less than 10000, limiting to 50 iterations.  Each iteration, add palindrome, and test if it hit.  If iterations ran fully to the limit, we "found" a lychrel number, and increment the counter.
// 	while(i<max)
// 	{
// 		test = i;
// 		iterations = 0;
// 		while(iterations<limit)
// 		{
// 			test+=mirror_num2(test);
// 			if(test== mirror_num2(test) )break;
// 			iterations++;
// 		}
// 		if(iterations==limit)lychrel_count++;
// 		i++;
// 	}
// std::cout<<lychrel_count<<std::endl;
// 	return 0;	
// }

// --------- Project Euler Number 56 -----------
		//Powerful digit sum
		
		/* Problem Statement-
		
		A googol (10100) is a massive number: one followed by one-hundred zeros; 100100 is almost unimaginably large: one followed by two-hundred zeros. Despite their size, the sum of the digits in each number is only 1.

Considering natural numbers of the form, ab, where a, b < 100, what is the maximum digital sum?
//Solution : 972 Not happy that had to use big_int class, but I guess that's what its for!
		*/
		
// #include <iostream>
// #include <string>
// #include <sstream>
// #include "big_int.h"
// 
// 
// int main()
// {
// 	
// 	std::string ss_a="",holder="1",helper = "";
// 	big_int ba(ss_a),bholder(holder);
// 	int max_digit_sum = 0,digit_sum;
// 
//     int limit = 100;
//     std::stringstream to_convert;
//     for(int a = 1;a<limit;a++)
//     {
//     
//     	to_convert<<a;
//         ba.set_value(to_convert.str() );
//     	for(int b = 2;b<limit;b++)
//     	{
//     	        digit_sum = 0;
//     		bholder*=ba;//find next power
//     		helper= bholder.get_value();
//     		for(int i=0;i<helper.size();i++)digit_sum+=helper[i]-'0';
//     		if(digit_sum>max_digit_sum)max_digit_sum=digit_sum;
//     	
//     	}
//     	
//     	to_convert.str(std::string());
//         ba.clear_value();//erase bigint
//         holder.clear();
//         holder = "1";
//         bholder = holder;
//         
//         
//     }
//                
//         std::cout<<max_digit_sum<<std::endl;
//     
// }

// --------- Project Euler Number 57 -----------
		//Squre root convergents
		
		/* Problem Statement-
		
		It is possible to show that the square root of two can be expressed as an infinite continued fraction.

√ 2 = 1 + 1/(2 + 1/(2 + 1/(2 + ... ))) = 1.414213...

By expanding this for the first four iterations, we get:

1 + 1/2 = 3/2 = 1.5
1 + 1/(2 + 1/2) = 7/5 = 1.4
1 + 1/(2 + 1/(2 + 1/2)) = 17/12 = 1.41666...
1 + 1/(2 + 1/(2 + 1/(2 + 1/2))) = 41/29 = 1.41379...

The next three expansions are 99/70, 239/169, and 577/408, but the eighth expansion, 1393/985, is the first example where the number of digits in the numerator exceeds the number of digits in the denominator.

In the first one-thousand expansions, how many fractions contain a numerator with more digits than denominator?
//Solution: 153

		*/
		
		
// #include <iostream>
// #include <sstream>
// #include <string>
// #include "big_int.h"
// //NEEDS BIG INTEGERS WAHHHHHH
// int main()
// {
// 	int limit = 1000,count=0;	
// 	int num_dig, denom_dig,new_n;
// 	std::string a, b,c="2";
// 	big_int new_num(a),new_denom(b),intermed(a),multiplier(c);
// 			
// for(int n = 1;n<=limit;n++)
// {
// 	a="1";b="2";
// 	new_n = n;
// 	new_num.set_value(a),new_denom.set_value(b);
// 	while(new_n>0)
// 	{
// 		if(new_n ==1)new_num = new_denom+new_num;
// 
// 		else
// 		{
// 	
// 			new_num =new_denom*multiplier +new_num;
// 			intermed = new_num;
// 			new_num=new_denom;
// 			new_denom = intermed;
// 		}
// 		new_n--;
// 	}
// 	if(new_num.get_size()>new_denom.get_size() )count++;
// }
// 	std::cout<<count<<std::endl;
// 
// 
// 
// 	return 0;
// }



	
// --------- Project Euler Number 58 -----------
		//Spiral Primes
		
		/* Problem Statement-
Starting with 1 and spiralling anticlockwise in the following way, a square spiral with side length 7 is formed.

37 36 35 34 33 32 31
38 17 16 15 14 13 30
39 18  5  4  3 12 29
40 19  6  1  2 11 28
41 20  7  8  9 10 27
42 21 22 23 24 25 26
43 44 45 46 47 48 49

It is interesting to note that the odd squares lie along the bottom right diagonal, but what is more interesting is that 8 out of the 13 numbers lying along both diagonals are prime; that is, a ratio of 8/13 ≈ 62%.

If one complete new layer is wrapped around the spiral above, a square spiral with side length 9 will be formed. If this process is continued, what is the side length of the square spiral for which the ratio of primes along both diagonals first falls below 10%?
//Solution 26241
		*/
		
// #include <iostream>
// #include "project_euler_functions.h"
// 
// int main()
// {
// 	//reused from problem 29.  Start in ring number two to apply proper condition.  Remember2*ring_num-1 is side lentgh!
// 		int ring_num = 2,jump_counter,position=9,diag_terms = 4 ;
// 	long sum = 3;
// 	
// 	while(10.*sum > diag_terms)
// 	{
// 		jump_counter =0;
// 		while(jump_counter<4)
// 		{
// 			position +=2*ring_num;
// 			if(isPrime(position))sum +=1;
// 			diag_terms++;
// 			jump_counter++;
// 		}
// 		ring_num++;
// 	
// 	}
// 	std::cout<<"At ring number "<<2*ring_num-1<<" the ratio of primes along both diagonals falls below 10%"<<std::endl;
// 	return 0;
// }	

// --------- Project Euler Number 59 -----------
		//XOR decryption
		
	/*	Problem Statement-

	Each character on a computer is assigned a unique code and the preferred standard is ASCII (American Standard Code for Information Interchange). For example, uppercase A = 65, asterisk (*) = 42, and lowercase k = 107.

A modern encryption method is to take a text file, convert the bytes to ASCII, then XOR each byte with a given value, taken from a secret key. The advantage with the XOR function is that using the same encryption key on the cipher text, restores the plain text; for example, 65 XOR 42 = 107, then 107 XOR 42 = 65.

For unbreakable encryption, the key is the same length as the plain text message, and the key is made up of random bytes. The user would keep the encrypted message and the encryption key in different locations, and without both "halves", it is impossible to decrypt the message.

Unfortunately, this method is impractical for most users, so the modified method is to use a password as a key. If the password is shorter than the message, which is likely, the key is repeated cyclically throughout the message. The balance for this method is using a sufficiently long password key for security, but short enough to be memorable.

Your task has been made easy, as the encryption key consists of three lower case characters. Using cipher1.txt (right click and 'Save Link/Target As...'), a file containing the encrypted ASCII codes, and the knowledge that the plain text must contain common English words, decrypt the message and find the sum of the ASCII values in the original text.
//solution 107359: The first chapter of the new testatment/gospel of john
	*/
	
#include<fstream>
#include <string>
#include <vector>
#include <sstream>
#include<iostream>
#include <stdlib.h>
//range of values after operation 65-90,97-122, 32
//First key is 111, 79^111 = 32;

const char code[] = "cipher1.txt";
int main()
{
int a = 79, b =9,c = 75,d =79;

std::ifstream fin;
	fin.open(code);
	std::string temp = "";
	std::vector<int> coded_message ;
	int holder;
	while(getline(fin,temp,','))//while the read succeeds,store what's left
	{
		holder = atoi(temp.c_str() );//needed for ?
		coded_message.push_back(holder);//Reads each name into an entry.  Adds the name to the end of the vector
		
	}
	fin.close();//self_explanatory- close the input file.

// 	1 2 3 4 5;
// "know" that 111 is the first, so find (i+1)%3	
	int coded_length = coded_message.size();
	int kl = coded_length,intermed;
	int key[3]={0};
	std::vector<char> decoded(kl);

 	int lower_lim = 97,upper_lim = 122,print = 0;
 	bool found_key=false;//Stops search when we've decoded the message 
for(int m =lower_lim;m<=upper_lim;m++)
{
	key[0]=m;
		for(int j =lower_lim;j<=upper_lim;j++)
		{
		key[1]=j;
		for(int k = lower_lim;k<=upper_lim;k++)
		{
			key[2]=k;
			
		print = 0;
		for(int i = 0;i<kl;i++)
		{
			intermed = (coded_message[i]^key[i%3]);
			decoded[i]=(char)intermed;
			if(intermed>=123 ||(intermed>=35&&intermed<=38))break;
			print++;
		}
		if(print ==kl)for(int i = 0;i<kl;i++)std::cout<<decoded[i];
		if(print ==kl)
		{
			std::cout<<std::endl;
			std::cout<<( (char) m)<<" "<<( (char)j )<<" "<<( (char)k )<<std::endl;	
			int sum = 0;
			for(int i = 0;i<kl;i++)sum+=(int)decoded[i];
			std::cout<<sum<<std::endl;
			found_key = true;
		}
		}
		if(found_key==true)break;
		}
		if(found_key ==true)break;
		}

	return 0;
}

// --------- Project Euler Number 76 -----------
		//Counting Summations
		
	/*	Problem Statement-
	
	It is possible to write five as a sum in exactly six different ways:

4 + 1
3 + 2
3 + 1 + 1
2 + 2 + 1
2 + 1 + 1 + 1
1 + 1 + 1 + 1 + 1

How many different ways can one hundred be written as a sum of at least two positive integers?

*/
//use dynamic programming, with summations not including 100, because that would be 0 and 100, need to add at least 1.
// #include <cmath>
// #include <iostream>
// int main()
// {
// 
// 	long newways[101]={0};
// 	newways[0]=1;
// 	goal = 100;
// 	for(int i = 1;i<100;i++)for(int j = i;j<=goal;j++)newways[j]+=newways[ j-i];
// 	std::cout<<newways[100]<<std::endl;
// 
// }