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