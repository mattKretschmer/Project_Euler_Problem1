/*  --------- Project Euler Number 42 -----------
		//Coded triangle numbers
		
		Problem Statement-

	The nth term of the sequence of triangle numbers is given by, tn = ½n(n+1); so the first ten triangle numbers are:

1, 3, 6, 10, 15, 21, 28, 36, 45, 55, ...

By converting each letter in a word to a number corresponding to its alphabetical position and adding these values we form a word value. For example, the word value for SKY is 19 + 11 + 25 = 55 = t10. If the word value is a triangle number then we shall call the word a triangle word.

Using words.txt (right click and 'Save Link/Target As...'), a 16K text file containing nearly two-thousand common English words, how many are triangle words?

	*/

 /*std::remove- takes a range, and removes all values equal to third input argument. Doesn't change the size of the array/string.Returns an iterator/pointer to end of new array.  I then use a.erase to delete extra space when I store the name.
 
 	std::getline(fin,a,',');//std::getline(input stream, "destination string, (optional) termination character);  Need to use this, else fin<< just gets all 5k names.
	*/
	
//Can check quickly if its a triangle number, by inverse of tn = (1/2)n(n+1): think about arithmetic, if (sqrt(8*score+1)-1 )/2 is integer, its a triangle num! 	
 //Solution:162 triangle words in list;

 #include <iostream>
 #include <string>
 #include <fstream>
 #include <cmath>
 #include <vector>
 #include <algorithm> //presumably for erase method, remove, etc
 const char names_list[] = "words.txt";
 
 int main()
 {
 	std::ifstream fin;
 	fin.open(names_list);
 	std::string temp = "";
 	std::vector<std::string> name_list ;
 	int counter = 0;
 	while(getline(fin,temp,','))//while the read succeeds,store what's left
 	{
 		temp.erase(std::remove(temp.begin(),temp.end(),'\"'),temp.end() );//Take the string we have, and looking between beginning and end, remove the double parenthesis instances.
 		name_list.push_back(temp);//Reads each name into an entry.  Adds the name to the end of the vector
 			
 	}
 	fin.close();//self_explanatory- close the input file.
 	int name_num = name_list.size(); //how many names are we dealing with?
 	//create triangle numbers (like 50 lets say)
 	
 	 int triangle_num_list[75] = {0};
  	for(int i = 1;i<=75;i++)triangle_num_list[i-1]=i*(i+1)/2;
 	
 	for(int i = 0;i<name_num;i++)
 	{
 		//Now that names are sorted, calculate their "scores"
 		//Strings are holding ascii capitals.  To convert to position in the alphabet subtract 64.
 		int score=0;
 
 			//Calculate multiplier for each position in the list
  			for(int j = 0;j<name_list[i].size();j++)score+=(int)name_list[i][j]-64;
 	
 		//Now that we have the score, is it a triangle number? if so
 		 for(int i = 0;i<75;i++)
  		{
  			if(triangle_num_list[i]==score)
  			{
  				counter++;
  				break;
  			}
  		}
 		double word_score = (sqrt(8*score+1)-1) /2;
 		if( word_score==(int)word_score)counter++;
 		
 	}	
 	
 	std::cout<<"The total number of triangle words is " <<counter<<std::endl;
 
 
 	return 0;
 }