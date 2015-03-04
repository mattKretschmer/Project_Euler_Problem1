#include "project_euler_functions.h"

bool isPrime(long long int value)
{
    bool primeIndicator = true;

	long long int divisor = 2; //A starting point
	while(divisor <= sqrt(value))
	{
	//Searches up to sqrt(value).  Value can be factored into a*b.  Max a and b can be is sqrt(value).  So we only need one leg of the "search", up to a's maximum value.

        if(value%divisor==0){primeIndicator = false; break;}
        divisor++;

	}
	return primeIndicator ;
}


void string_swap( std::string &string, int location_1,int location_2)
{
	//Swaps two characters of a string, at the locations given by location_1 and location_2
	char temp = string[location_1];
	string[location_1]=string[location_2];
	string[location_2]=temp;
}

long long mod_power(int base, int power,long long modulo)
{
	//Raises the base to a power, but returns the result modulo "modulo".  Helps to avoid HUGE numbers in calculations.
	long long c = 1;
	for(int e = 1;e<=power;e++)
	{
		c =(base*c )%modulo;
	}
	return c;
}

void find_amicable_numbers( int limit, int (*list)[2] )
{
		//An amicable number is one whose of divisors equals a number. The sum of divisors of that number equals the original.  This records the numbers if amicable in an array.
		int sum = 1;
		long MAX = 1000000;
		//First, if we haven't done so, find the sum of divisors of a number
		if(list[limit][1]==0)for( int i = 2;i<= limit/2;i++)if(limit%i==0)sum+=i;
	
		int sum_2 = 1;
		//Find the sum of divisors of that number
		if(sum<MAX && list[sum][1]==0)for(int i = 2;i<=sum/2;i++)if(sum%i==0)sum_2+=i;

		//if the two numbers are less than 10k, not equal to one another, and amicable, record them.
		if((sum_2==limit && sum<MAX) && (limit!=sum))//Need to not be equal to the same number! otherwise we double count.
		{
			list[limit][1]=sum;
			list[sum][1]=sum_2;
		}	
}

bool is_Abundant(int num_to_check)
{
	//A number is abundant if the sum of its proper divisors is greater than that number.
	long sum = 1;//1 always is a "proper divisor".
	for(int i = 2;i*i <= num_to_check;i++)
	{
		if(num_to_check%i==0)
		{
			sum+=i;
			sum+=num_to_check/i;
		}
		if(i == num_to_check/i && num_to_check%i==0)sum-=i;//to make sure we don't double count perfect squares;
	}
	bool abundant_or_not = false;
	if(sum>num_to_check)abundant_or_not = true;
	return abundant_or_not;
}

int find_sequence_length(int d)
{
	//Finds length of repeating decimal part of 1/d.
	std::vector<int> modulo_list,denominator_list;
	modulo_list.push_back(0);
	denominator_list.push_back(0);
	
	int denominator = 10; //1 * 10//this would be what I change in the future.
	int modulo = 0,remain,start;
	bool repeat =false,non_repeat = false;
	while(!(repeat))//while repeat is not true (or hasn't been found
	{
		modulo = denominator/d;
		remain = denominator %d;

		if(remain==0)
			{
				non_repeat=true;
				break;//No more repeats!
			}
		for(int i =0;i<modulo_list.size();i++)
			{
				if( modulo_list[i]==modulo && denominator_list[i]==denominator)
				{
					repeat=true;
					start = i;
				}
			}
		//if a repeat hasn't been found, add what we have and continue.
		modulo_list.push_back(modulo);
		denominator_list.push_back(denominator);
		denominator = 10*remain;
		if(repeat==true)break;

	}
	if(non_repeat==true)return 0;
	else return modulo_list.size()-(1+start);// start is 0-based, so add 1.  Size is position of last element, in 1-based index.
}

int simple_test(int test_int,int max_divisor)
{
	//tests if a number, test_int is divisible by max_divisor or integers less than it.
	int result = 0;
	for(int i = max_divisor-1;i>=2;i--)
	{
		if(test_int%i ==0){result=i;break;}
	}
	return result;
}

int pow_factors(int tb_fact)
{
	//Finds if the number tb_fact is the power of a smaller integer. If it is, it returns the exponent of that smaller number.
	int base = 2,pow = 1,other=base;
	while(base*base<=tb_fact)
	{
	if(other<tb_fact)
	{
		other*=base;
		pow++;
	}
	if(other==tb_fact)
	{
		break;
	}
	if(other>tb_fact)
	{
		base++;
		other = base;
		pow = 1;
		//reset, essentially
	}
	}
	if(pow==1)pow=0;
	return pow;
}

int find_combinations(int amount ,int denoms[],int index)
{	
	//Recursive function, that returns the number of ways of making an amount out of an ordered list of denominations.  A call is typically started with index =end.
	int total_combs = 0;
	if(index==0)return 1;
	if(amount<0)return 0;
	int k = amount/denoms[index];
	int cur_denom = denoms[index];
	for(int i = 0;i<=k;i++)
	{
		total_combs +=find_combinations(amount-i*cur_denom,denoms,index-1);
	}

return total_combs;
}

long int_pow(long base,long exponent)
{
	//Finds the integer power of base^{exponent}
	long result = base;
	if(exponent==0)return 1;
	if(exponent==1)return base;
	for(int i = 2;i<=exponent;i++)
	{
		result *=base;
	}
return result;
}

long factorial(int n)
{
	//returns n!;
	if( n==0)return 1;
	else return n*factorial(n-1);
}

int num_of_digits(unsigned long long holder)
{
		//returns the number of digits in holder;
		int digit_sum=0;
		while(holder>0)
		{
			holder/=10;
			digit_sum++;
		}
		return digit_sum;
}

long circ_shift_num(long test, int size)
	{
		//Circularly shifts long test, putting first digit at last, and shifting everything else;
		int* new_num = new int[size];
		int remainder = 0;
		long new_new_num = 0;

		for(int i = 0;i<size;i++)
		{
			new_num[i] = test%10;
			test/=10;
		}
		long pow = 1;
		
		for(int i = 1;i<size;i++)
		{
			new_new_num += new_num[i]*pow;
			pow*=10;
		}
	
		new_new_num +=new_num[0]*pow;
		
		delete [] new_num;
	return new_new_num ;
	}
	
std::string	dec_to_bin(int to_convert)
{
	//returns a string holding the zeros and ones of (dec) int to_convert.  A base switcher.
	int holder = to_convert,counter = 0;
	
	while(to_convert>=1)
	{
		to_convert/=2;
		counter++;
	}
	
	int* bin_array = new int[counter];
	int index = counter-1;
	while(holder>=1)
	{
		bin_array[index--]= holder%2;
		holder/=2;
	}
std::stringstream ss;
for(int i = 0;i<counter;i++)ss<< bin_array[i];

	delete [] bin_array;
	return ss.str();
}

int	mirror_num(int test, int size)
{
		//takes in a test number, returns the mirror of it, with the order of its digits flipped.
		int* new_num = new int[size];
		int remainder = 0;
		int new_new_num = 0;

		for(int i = 0;i<size;i++)
		{
			new_num[i] = test%10;
			test/=10;
		}
		long pow = 1;
		
		for(int i = size-1;i>=0;i--)
		{
			new_new_num += new_num[i]*pow;
			pow*=10;
		}
	
		
		delete [] new_num;
	return new_new_num ;
}

long	mirror_num2(long test)
{
	long pow = 1,a = test,return_val = 0;
	while(a>0)
	{
		a/=10;
		pow*=10;
	}
	pow/=10;//for n digits, want n-1 powers of 10;
	while(test>0)
	{
		return_val +=pow*(test%10);
		pow/=10;
		test/=10;
	}
	return return_val;
}

bool palindromic2( int tester,int base)
{
	//Checks if tester is palindromic in the base given, without resorting to string conversion ,etc.  A brilliant idea! very much faster than palindromic;
	long reversed = 0;
	int k = tester;
	//finds last digit of tester, multiplies it by base, effectively making it first, etc. Does this process in an arbitrary base.  
		while(k>0)
	{
		reversed = base* reversed + k%base;
		k/=base;
	}
	return tester==reversed;

}	
bool palindromic( std::string &array1, int start,int end)
{
	//Checks if the num held in string array1 is palindromic.  Recursively called.
	bool indicator = false;
	if(start>=end) indicator = true;
	
	else if(array1[start]==array1[end])
	{
		return palindromic(array1, start+1,end-1);
	}
	else indicator =false;
	
	return indicator;

}

long int_concat(long a, long b)
{
	//concatentates a and b, without string manipulation.  Probably pretty fast, taken from internets.
	long c = b;
	
	while(c>0)
	{
		a*=10;
		c/=10;
	}
	return a+b;
}

int	nth_dig(int num,int dig_diff)
{	
	//Returns the nth digit of num, indexed from the right.  So 1st would be ones, etc.
	for(int i = 1;i<dig_diff;i++)
	{
		num/=10;
	}
	
	return num%10;
}

void next_descending_string_perm( std::string &permuted_string)
{
		//Given a string of integers, finds the next smallest permutation of those integers.  If the string is already the smallest, makes no changes
		int size = permuted_string.size();
		int biggest_k = 0,biggest_l = 0,counter=0,index_i,index_j;
	
	
			//find largest k, such that permuted_string[k]>permuted_string[k+1];
			 biggest_k = 0;
			for(int i = 0;i<size-1;i++)if(permuted_string[i]>permuted_string[i+1] && i>biggest_k)biggest_k = i;
		
			//Stops loop if we've found lowest permutation,which occurs when numbers are all increasing
			counter =0 ;
			for(int i = 0;i<size-1;i++)if(permuted_string[i]<permuted_string[i+1])counter+=1;
			if(counter==size-1)goto end; //can't use break, not in a loop!

			//Find largest index l such that a[k]>a[l];
			 biggest_l = biggest_k;
			for(int i = biggest_k+1;i<size;i++)if(permuted_string[i]<permuted_string[biggest_k] && i >biggest_l)biggest_l = i;

			//swap these k,l values;
			string_swap(permuted_string,biggest_k,biggest_l);
	
			//Reverse values from biggest_k + 1 to final element.  
			 index_i = biggest_k + 1,index_j = size-1;
			while(index_i !=index_j)
			{
				string_swap(permuted_string,index_i,index_j);
				index_i++;
				index_j--;
				if(index_i>index_j)break;//If this happens we've "walked" by each other
			}
		end: ;

}

void next_ascending_string_perm( std::string &permuted_string)
{
		//Given a string of integers, finds the next smallest permutation of those integers.  If the string is already the smallest, makes no changes
		int size = permuted_string.size();
		int biggest_k = 0,biggest_l = 0,counter=0,index_i,index_j;
	
	
			//find largest k, such that permuted_string[k]<permuted_string[k+1];
			 biggest_k = 0;
			for(int i = 0;i<size-1;i++)if(permuted_string[i]<permuted_string[i+1] && i>biggest_k)biggest_k = i;
		
			//Stops loop if we've found lowest permutation,which occurs when numbers are all decreasing
			counter =0 ;
			for(int i = 0;i<size-1;i++)if(permuted_string[i]>permuted_string[i+1])counter+=1;
			if(counter==size-1)goto end; //can't use break, not in a loop!

			//Find largest index l such that a[k]<a[l];
			 biggest_l = biggest_k;
			for(int i = biggest_k+1;i<size;i++)if(permuted_string[i]>permuted_string[biggest_k] && i >biggest_l)biggest_l = i;

			//swap these k,l values;
			string_swap(permuted_string,biggest_k,biggest_l);
	
			//Reverse values from biggest_k + 1 to final element.  
			 index_i = biggest_k + 1,index_j = size-1;
			while(index_i !=index_j)
			{
				string_swap(permuted_string,index_i,index_j);
				index_i++;
				index_j--;
				if(index_i>index_j)break;//If this happens we've "walked" by each other
			}
		end: ;

}	

std::string convertFromInt( int number)
{	
	//Uses string streams.  Throws the int onto the stream, then extracts it as a string.  Very convenient formulation!.  Very useful in the future too.
    std::stringstream ss;//create a stringstream
    ss << number;//add number to the stream
    return ss.str();//return a string with the contents of the stream
}

long long int BiggestPrime(long long int value)
{
	//Returns the biggest prime factor of value; Should maybe be divisor*divisor<value?
	
	int divisor = 2; //A starting point
	long long int biggestfactor = 2;//Same thing, an initial place to store the biggest factor;
	while(divisor < (value/2))
	{
	
		if(value%divisor==0)
		{
			//Recursively calls itself.  If the divisor goes in evenly, it calls itself
		//for smaller value.
				if((value/divisor) > biggestfactor)biggestfactor = value/divisor;
				return BiggestPrime(value/divisor);
		}
		else
			divisor++;	
		
		}
	return value ;//Returns the final most prime value.

}

long long int make_triangle_num(int seed)
{
	//Makes a triangle number. Triangle numbers are found by adding up the consecutive natural numbers;  Finds the seedth number
       return (1/2)*seed*(seed+1);
}

int num_of_divisors(long long int test_case)
{
	//finds the number of divisors, excluding 1 and itself, of test_case;
   int divise_num = 2;
   
   for(int i =2;i<sqrt(test_case);i++)if(test_case%i==0)divise_num+=2;
   return divise_num;   
}

long find_collatz_sequence_length(long int n)
{
    long sequence_length = 1.;
    while(n!=1)
    {
        if(n%2 == 0){n /=2;sequence_length+=1;}
        else{ n=3*n+1;sequence_length+=1;}
    }
    return sequence_length;
}

long find_collatz_sequence_length_with_memoization(long int n,long *list_of_lengths)
{
    long sequence_length = 1.,moveable_index = n;
    int LIMIT = 50;
    
    while(n!=1)
    {

        if(n%2 == 0)
        {
                n /=2;
            sequence_length++;

            if(n<moveable_index && n < LIMIT)
            {
                    sequence_length+=list_of_lengths[n-1];
                    break;
            }
        }
        else{ n=3*n+1;sequence_length+=1;}
        
    }
    list_of_lengths[moveable_index-1]=sequence_length;
    std::cout<<list_of_lengths[moveable_index-1]<<'\t'<<moveable_index<<std::endl;
    return sequence_length;
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

long make_num(std::string &permuted_string,int start,int dist)
{
	long pow = 1;
	long  num = 0;
	
	for(int i = 0;i<dist;i++)
	{
		num+=pow*(permuted_string[start-i]-'0');
		pow*=10;
	}
	return num;
}

bool is_pentagon(long to_test)
{
	double maybe = (1+sqrt(1+24.*to_test) )/6.;
return (maybe ==(int)maybe);
}

int prime_divisors(long long int test_case)
{
	//finds the number of distinct prime factors of a number, excluding 1 and itself;
	int prime_divisors = 0;
	//First check if its even, and divide it by two till its not even.
	int divisor = 2;
	if(test_case%2==0)
	{
		do
			{
				test_case/=divisor;
			}
			while(test_case%divisor ==0);
			prime_divisors+=1;
	}
	
	divisor++;//Start checking if divisible by 3, etc;
	
	while(test_case>1)
	{
		if(divisor*divisor>test_case){prime_divisors++;break;}//Search till divisor>sqr(test_case).  If we get this big, the last divisor is test_case itself.
		//Divide by prime factors till we reach 1.
	   if(test_case%divisor==0 && isPrime(divisor)==true)
	   {
			do
			{
				test_case/=divisor;
			}
			while(test_case%divisor ==0);
		
			prime_divisors+=1;
		}
		else divisor+=1;
		
	}
	
      return prime_divisors;   
}

std::vector<int> sieve_of_Erasthenes( int limit,int lower_limit)
{
	//calculates all primes below limit, returns them in a std::vector.
	
	std::vector<int> primes_list;
	int start = 2;
	bool* check_list = new bool[limit+1];
	bool switcher=true;
	for(int i = 1;i<=limit;i++)check_list[i]=false;

	while(start<limit)
	{
		for(int i = 2*start;i<=limit;i+=start)check_list[i]=true;
		if(start>=lower_limit)primes_list.push_back(start);
		
		//find new start
		switcher = false;
		for(int i = start+1;i<=limit;i++)
		{
			if(check_list[i]==false){start = i;break;}
			if(i ==limit)switcher=true;
		}
		if(switcher==true)break;
	}
	delete [] check_list;
	return primes_list;
}

bool permutation_finder(int a, int b)
{
	int c[10]={0};
	bool equal_or_not = true;//true if they're equal
	while(a>0)
	{c[a%10]++;a/=10;}
	while(b>0)
	{c[b%10]--;b/=10;}
	for(int i = 0;i<10;i++)if(c[i]!=0){equal_or_not = false;break;}
	
	return equal_or_not;
}

int repeating_except_last(int a,int times)
{
	int c[10]={0};
	int result = -1;
	a/=10;//NOT concerned with the last digit.
	while(a>0)
	{c[a%10]++;a/=10;}
	
	for(int i = 0;i<10;i++)if(c[i]==times){result=i;break;}
	return result;
}

void find_locations( int a, int *indices, int search)
{
	a/=10;
	int i = 1,index = 0;
	while(a>0)
	{
		if(a%10==search)
		{
			indices[index]=i;
			i++;
			index++;
		}
		else i++;
		a/=10;
	}
}

int switch_at_locations( int a,int*indices,int search,int replace)
{
	int pow = 1;
	for(int i = 0;i<3;i++)
	{
		pow = 1;
		for(int j = 0;j<indices[i];j++)
		{
			pow*=10;
		}
		a+= pow*(replace-search);
	}
	return a;
}


