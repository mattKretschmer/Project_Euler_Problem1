/*----------Project Euler #13 --------------

Find the sum of the first 10 digits of 100 50-digit numbers. Just load them into an array, then perform addition like a person would. SUm up a column, then if over 10, add modulo extra bit to next column and continue. Contune for 50 places.. At place 50, sum then put ino remainding spaces.*/
#include <iostream>
#include <sstream>
#include <string>
#include <fstream>
#include <cmath>
#define ROWS 100
#define COLUMNS 50
#define DIG_TO_PRINT 10
char file_in[] = "p_euler-13.txt";
 
 int main()
 {
	std::ifstream fin;
	fin.open(file_in);
	char c;// = fin.get();
	int num_block[ROWS][COLUMNS]={0};
	for(int i = 0;i<ROWS;i++)for(int j = 0;j<COLUMNS;j++)
		{
			fin>>c;
			num_block[i][j]=c-'0';
			// c=fin.get();
		}
	fin.close();
	//  for(int i = 0;i<ROWS;i++)for(int j = 0;j<COLUMNS;j++)fin>>num_block[i][j];
	//   for(int i = 0;i<ROWS;i++){for(int j = 0;j<COLUMNS;j++)std::cout<<num_block[i][j];std::cout<<std::endl;}
	// 
	 int sum_list[COLUMNS] = {0};
	 int sum = 0,pre_sum = 0;
	 for(int i = (COLUMNS-1);i>=0;i--)
	 {
		sum = 0;
		sum+=pre_sum;
		for(int j = 0;j<ROWS;j++)
		{
			sum+=num_block[j][i];
		}
		sum_list[i] = sum%10;
		pre_sum = (sum-(sum%10))/10;
	 }
  	//Need to add pre_sum digits to the front!

	//how many digits are there?
		int psdc = 0,test=pre_sum;
		while(test>0)
		{
			test/=10;
			psdc+=1;
		}
		std::cout<<pre_sum;
 		for(int i = 0;i<(DIG_TO_PRINT-psdc);i++)std::cout<<sum_list[i];
 		std::cout<<std::endl;
 }
