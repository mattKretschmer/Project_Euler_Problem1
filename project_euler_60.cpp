#include <iostream>
#include <vector>
#include "project_euler_functions.cpp"

#define LIMIT 30000
#define PSIZE 5

int	permute_primes( int *prime_list, int size_p_list);


int main()
{
	int prime_list[5] = {0};
	std::vector<int> prime_vector = sieve_of_Erasthenes( LIMIT,0); //Guessing that we'll find our solution before 100k.  Might not be true though.
	int max_p_ind = prime_vector.size(),sum = 0,max_sum = 0;

					
				}
	std::cout<< "The sum of these primes is equal to "<<sum<<std::endl;
	return 0;
}

bool	permute_primes( int p_1, int p_2)
{
	bool yes_or_no = false;
			if( (isPrime(int_concat(p_1,p_2) ) && isPrime( int_concat(p_2,p_1) ) ) )
			{
				yes_or_no = true;
			}
	return yes_or_no;

}

int	permute_primes( int *prime_list, int size_p_list)
{
		//Goes through prime_list, and checks if combinations are prime.  If all prmutations are concatenation-prime, sum up and return. 
		bool sum_or_not = true;
		int sum = 0;
		int z = 0;
		for(int i = 0;i<size_p_list;i++)
		{
			if(sum_or_not ==false)break;
			for(int j = i+1;j<size_p_list;j++)
			{
				if( !(isPrime(int_concat(prime_list[i],prime_list[j]) ) && isPrime( int_concat(prime_list[j],prime_list[i]) ) ) ){sum_or_not = false;break;}
			}
		}
		if(sum_or_not == true)
		{
			for(int i = 0;i<size_p_list;i++)
			{
				sum+=prime_list[i];
			}
		}
	return sum;
}
	
	//adapt this to recursively search for 5 concatenating primes
bool find_group(int start, int length ) //(5,1)
{
	int sol_size = sol.size();
    for (int i = 0; i < sol_size; i++) 
    {
        if (sol[i] != 0) continue;
        for (int j = 0; j < nums[i].size(); j++) 
        {
 
            bool unique = true;
            for(int k = 0; k < sol_size; k++)
            {
                if (nums[i][j] == sol[k]) 
                {
                    unique = false;
                    break;
                }
            }
 
            if ( unique && nums[i][j] / 100 == sol[ start] % 100) 
            {
                sol[i] = nums[i][j];
                if ( length == 5) 
                {
                    if (sol[0] / 100 == sol[i] % 100)
                        return true;
                }
                if (find_chain(i,length+1)) return true;
            }
        }
        sol[i] = 0;
    }
    return false;
}

