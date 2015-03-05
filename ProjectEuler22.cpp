/* --------- Project Euler Number 22 -----------
Problem Statement:

  Using names.txt (right click and 'Save Link/Target As...'), a 46K text file containing over five-thousand first names, begin by sorting it into alphabetical order. Then working out the alphabetical value for each name, multiply this value by its alphabetical position in the list to obtain a name score.
  
  For example, when the list is sorted into alphabetical order, COLIN, which is worth 3 + 15 + 12 + 9 + 14 = 53, is the 938th name in the list. So, COLIN would obtain a score of 938 × 53 = 49714.
  
  What is the total of all the name scores in the file?.
*/
	/* names.txt has names separated by commas.*/
/*Notes:
	std::remove- takes a range, and removes all values equal to third input argument. Doesn't change the size of the array/string.Returns an iterator/pointer to end of new array.  I then use a.erase to delete extra space when I store the name.

	std::getline(fin,a,','); std::getline(input stream, "destination string, (optional) termination character);  Need to use this, else fin<< just gets all 5k names.
	
	
	Outline of main() function:
	
	  	First, read in from names list and store the names ina vector of strings. Then, go through and sort all the names (using bubble sort), to get them in alphabetical order. Once sorted, calculate the scores of each one and store. Then run through the score storage vector to find end sum.
	*/
	 /*Answeris 871198282*/
  #include <iostream>
  #include <sstream>
  #include <string>
  #include <fstream>
  #include <cmath>
  #include <vector>
  #include <algorithm>  for erase method, remove, etc
 
const char names_list[] = "names.txt";
  int main()
  {
  	std::ifstream fin;
  	fin.open(names_list);
  	std::string temp = "";
  	std::vector<std::string> name_list ;
  	while(getline(fin,temp,','))
  	{
  		temp.erase(std::remove(temp.begin(),temp.end(),'\"'),temp.end() ); //Take the string we have, and looking between beginning and end, remove the double parenthesis instances.
  		name_list.push_back(temp); //Reads each name into an entry.  Adds the name to the end of the vector
  			
  	}
  	fin.close(); //close the input file.
  	int name_num = name_list.size();//  how many names are we dealing with? 
  	temp.clear(); //clears the contents of temp, so I can use it later in the sorting process;
  	
  	

  	 /*Next--- Sort the list into alphabetical order.  Use relational operators.  A bubble sort implementation- Not complex or fast, but simple to implement.  Swap adjacent elements till no elements are swapped*/
  	
/*  	  
		/////////// A simple (but slow) sorting implementation, the std::algorithm sort is much better.
		int sort_counter ;  //repeat sorting till I pass through the array with no changes.
    	do
    	{
    		sort_counter = 0;
    		for(int i = 0;i<name_num-1;i++)
    		if(name_list[i]>name_list[i+1])
    		{
    			temp = name_list[i+1];
    			name_list[i+1]=name_list[i];
    			name_list[i]=temp;
    			sort_counter++;
    		}
    	}
    	while(sort_counter!=0);
*/
  
  	std::sort(name_list.begin(),name_list.end());
  	
  	/* //As a debug-- Print out the contents of the now sorted list:
  	for( std::vector<std::string>::const_iterator i = name_list.begin();i !=name_list.end();i++)std::cout<<*i<<std::endl;*/
  	
  	// Now that names are sorted, calculate their "scores"
  		// Strings are holding ascii capitals.  To convert to position in the alphabet subtract 64.
  	long *name_score = new long[name_num]; //stores scores.  Use longs, because 5k * a score of easily 50 > int limit
  for(int i = 0;i<name_num;i++)name_score[i]=0; //initialize
  
  	for(int i = 0;i<name_num;i++)
  	{
  		long multiplier = 0;
  		 //Calculate multiplier for each position in the list
   		for(int j = 0;j<name_list[i].size();j++)
   		{
   			multiplier+=(int)name_list[i][j]-64;
   		}
  		name_score[i] =(i+1)*multiplier;
  	
  	}
  	 //now, name_score has all the scores, scan through and sum them all up.
  	
  	long score_sum=0;
  	
  	for(int i = 0;i<name_num;i++)score_sum+=name_score[i];
  	std::cout<<"The total score of all the names is equal to " <<score_sum<<std::endl;
  
  	delete[] name_score;
  	return 0;
  }