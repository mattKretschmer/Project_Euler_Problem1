#include <cmath>
#include <iostream>
#include <string>
#include <sstream>
#include <vector>

bool isPrime(long long int value);

void string_swap( std::string &string, int location_1,int location_2);

long long mod_power(int base, int power,long long modulo);

void find_amicable_numbers( int limit, int (*list)[2] );

bool is_Abundant(int num_to_check);

int find_sequence_length(int d);

int simple_test(int test_int,int max_divisor);

int pow_factors(int tb_fact);

int find_combinations(int amount ,int denoms[],int index);

long int_pow(long base,long exponent);

long factorial(int n);

int num_of_digits(unsigned long long holder);

long circ_shift_num(long test, int size);

std::string	dec_to_bin(int to_convert);

int	mirror_num(int test, int size);
long	mirror_num2(long test);

bool palindromic2( int tester,int base);

bool palindromic( std::string &array1, int start,int end);

long int_concat(long a, long b);

int	nth_dig(int num,int dig_diff);

void next_descending_string_perm( std::string &permuted_string);

void next_ascending_string_perm( std::string &permuted_string);

std::string convertFromInt( int number);

long long int BiggestPrime(long long int value);

long long int make_triangle_num(int seed);

int num_of_divisors(long long int test_case);

long find_collatz_sequence_length(long int n);

long find_collatz_sequence_length_with_memoization(long int n,long *list_of_lengths);

int get_days(const int month);

inline int mod( const int &n, const int &N ) { return n%N < 0 ? n%N + N : n%N; }

long make_num(std::string &permuted_string,int start,int dist);

bool is_pentagon(long to_test);

inline long make_pentagonal(long n){return n*(3*n-1)/2;}

int prime_divisors(long long int test_case);

std::vector<int> sieve_of_Erasthenes( int limit,int lower_limit);
bool permutation_finder(int a, int b);
int repeating_except_last(int a,int times);
void find_locations( int a, int *indices, int search);
int switch_at_locations( int a,int *indices,int search,int replace);






















