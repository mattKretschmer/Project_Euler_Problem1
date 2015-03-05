/*  --------- Project Euler Number 31 -----------
		//Coin Sums		
		Problem Statement-
		In England the currency is made up of pound, £, and pence, p, and there are eight coins in general circulation:

		1p, 2p, 5p, 10p, 20p, 50p, £1 (100p) and £2 (200p).
		It is possible to make £2 in the following way:

		1×£1 + 1×50p + 2×20p + 1×5p + 1×2p + 3×1p
		How many different ways can £2 be made using any number of coins?  

	*/
 #include <iostream>
 #include <cmath>
 	
 int find_combinations(int amount, int denoms[],int index);
 int main()
 {
 	int p1 = 1,p2 = 2,p5 = 5, p10 = 10, p20 = 20, p50 = 50,L1 = 100,L2 = 200;
 	
 	int counter = 0,num_coins = 8,goal = 200;
 	//use dynamic programming here
 	int *coin_options = new int[num_coins];
 	long ways[201]={0};//Will hold the ways to make 1, 2,3, etc with any number of coins.
 	ways[0]=1;
 	coin_options[0]=p1;
 	coin_options[1]=p2;
 	coin_options[2]=p5;
 	coin_options[3]=p10;
 	coin_options[4]=p20;
 	coin_options[5]=p50;
 	coin_options[6]=L1;
 	coin_options[7]=L2;
 //For each coin, calculate the ways to make i change using that coin.  Much simpler than the recursive solution, i think
 for(int coin_in = 0;coin_in<num_coins; coin_in++)
 for(int i = coin_options[coin_in];i<=goal;i++)ways[i] +=ways[ i-coin_options[coin_in]];
 
 std::cout<<ways[200]<<std::endl;
  std::cout<<find_combinations(goal,coin_options,7)<<std::endl;
 //The power of recursion!
 
 delete [] coin_options;
 return 0;
 }
 
 int find_combinations(int amount ,int denoms[],int index)
 {	
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