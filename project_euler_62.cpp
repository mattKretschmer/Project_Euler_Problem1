// ---------- Cubic Permutations

/* 		-- Problem Statement --

The cube, 41063625 (3453), can be permuted to produce two other cubes: 56623104 (3843) and 66430125 (4053). In fact, 41063625 is the smallest cube which has exactly three permutations of its digits which are also cube.

Find the smallest cube for which exactly five permutations of its digits are cube.

*/
#include <iostream>
#include <vector>
#include <algorithm>


int perfect_cube(unsigned long long a);
unsigned long long find_biggest_perm( unsigned long long a);
long find_smallest_perm( long a);
void swap( int* list, int location_1,int location_2);
void next_descending_perm( unsigned long long &a);


int main()
{	
	unsigned long long cube_to_test,permutation_b;
	unsigned long long n = 11;
	int counter = 0;// counter tests how many permutations are cubic
	bool found_smallestcube = false;
	std::vector<unsigned long long> permutation;
	std::vector<int> repeats;
	repeats.push_back(0);
	permutation.push_back(0);
		std::vector<unsigned long long>::iterator a;
		int dist ;
while(found_smallestcube==false)
	{
			n++;
		cube_to_test = n*n*n;
		//find and test each permutation
		permutation_b = find_biggest_perm(cube_to_test);
		
		a = std::find(permutation.begin(),permutation.end(),permutation_b);
		if( a !=permutation.end())
		{
			dist = std::distance(permutation.begin(),a);
			if(dist<permutation.size())
			{
				repeats[dist]++;
				if(repeats[dist]==5 ){found_smallestcube==true;break;}
			}
		}
		else
		{
			permutation.push_back(permutation_b);
			repeats.push_back(1);
		}

	}	
	
//Now, need to work up, testing which is cube! (Much faster than testing every permutation moving down too)
	n = 11;
	bool found_smallest = false;
	
	while(found_smallest == false)
	{
		if( find_biggest_perm(n*n*n)==permutation_b){ found_smallest =true;break;}
		n++;		
	}

std::cout<<"Smallest such cube is "<<n*n*n<<" produced by " <<n<<std::endl;
	return 0;
}


void next_descending_perm( unsigned long long &a)
{
		unsigned long long b = a;
		int size = 0;
		while(b)
		{
			b/=10;
			size++;
		}
		b = a;
		int* list = new int[size];
		for(int i = size-1;i>=0;i--)
		{
			list[i] = b%10;
			b/=10;
		}	
		
		int biggest_k = 0,biggest_l = 0,counter=0,index_i,index_j;
	
			//find largest k, such that permuted_string[k]>permuted_string[k+1];
			 biggest_k = 0;
			for(int i = 0;i<size-1;i++)if(list[i]>list[i+1] && i>biggest_k)biggest_k = i;
		
			//Stops loop if we've found lowest permutation,which occurs when numbers are all increasing
			counter =0 ;
			for(int i = 0;i<size-1;i++)if(list[i]<list[i+1])counter+=1;
			if(counter==size-1)goto end; //can't use break, not in a loop!

			//Find largest index l such that a[k]>a[l];
			 biggest_l = biggest_k;
			for(int i = biggest_k+1;i<size;i++)if(list[i]<list[biggest_k] && i >biggest_l)biggest_l = i;

			//swap these k,l values;
			swap(list,biggest_k,biggest_l);
	
			//Reverse values from biggest_k + 1 to final element.  
			 index_i = biggest_k + 1,index_j = size-1;
			while(index_i !=index_j)
			{
				swap(list,index_i,index_j);
				index_i++;
				index_j--;
				if(index_i>index_j)break;//If this happens we've "walked" by each other
			}
		end: ;
		
		unsigned long long r_value = 0;
		unsigned long long place_holder = 1;
		
		for(int i = size-1;i>=0;i--)
		{
				r_value+=list[i]*place_holder;
				place_holder*=10;
		}
		delete [] list;

	a= r_value;

}

void swap( int* list, int location_1,int location_2)
{
	//Swaps two characters of a string, at the locations given by location_1 and location_2
	int temp = list[location_1];
	list[location_1]=list[location_2];
	list[location_2]=temp;
}

long find_smallest_perm( long a)
	//Has a bug, won't give right permutation for "smallest" when there is a zero somewhere.
{
	long b = a;
	int list[10] = {0};
	while(b)
	{
		list[b%10]++;b/=10;
	}
	long return_val = 0,place_holder = 1;
 
 	for(int i = 9;i>=0;i--)
	{
		while(list[i])
		{
			return_val+=i*place_holder;
			list[i]--;
			place_holder*=10;
		}
	
	}
	return return_val;
}

unsigned long long find_biggest_perm( unsigned long long a)
{
	unsigned long long b = a;
	int list[10] = {0};
	while(b)
	{
		list[b%10]++;b/=10;
	}
	unsigned long long return_val = 0,place_holder = 1;
 
 	for(int i = 0;i<10;i++)
	{
		while(list[i])
		{
			return_val+=i*place_holder;
			list[i]--;
			place_holder*=10;
		}
	
	}
	return return_val;
}

int perfect_cube(unsigned long long a)
{
	//returns 0 if its not a perfect cube
	unsigned long long start = a/2,root=0;
	unsigned long long low = 0, high = a+1, mid,test;
//An integer root find.  So we want our search region to be >1! makes senseee.
	while(high-low >1)
	{	
		mid = (low+high)/2;
		test = mid*mid*mid;
	
		if(test>a)high =mid;
		if(test<a)low = mid;
		if(test==a){root= mid;break;}
	}
		return root;
}