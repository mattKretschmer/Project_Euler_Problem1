/* --------- Project Euler Number 54 -----------
		//Poker Hands
		
		 Problem Statement-

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
	
	
 #include <iostream>
 #include <fstream>
 #include <sstream>
 #include <string>
 #include <vector>
 #include <algorithm>
 #include "project_euler_functions.h"
 
 std::string	find_hand(std::string &hand);
 
 const char file_name[] = "poker.txt";
 int main()
 {
 
 	std::ifstream fin;
 	fin.open(file_name);
 	std::string temp = "",hand1="",hand2="";
 	std::vector<std::string> player1_hands,player2_hands ;
 	int counter = 0;
 		std::stringstream ss;
 
 while(getline(fin,temp))
 	{
 		temp.erase(std::remove_if(temp.begin(),temp.end(),isspace),temp.end());
 		for(int i = 0;i<10;i++)ss<<temp[i];
 		hand1 = ss.str();
 		ss.str(std::string());
 		for(int i = 10;i<20;i++)ss<<temp[i];
 		hand2 = ss.str();
 		ss.str(std::string());
 		player1_hands.push_back(hand1);
 		player2_hands.push_back(hand2);
 		hand1.clear();
 		hand2.clear();
 	}
  	//now that hands are stored, etc, we can compare! cards are number,suit
 	int num_hands = player1_hands.size();
  	//Hands will be assigned 1-10 based on hand type.  As hands are narrowed down, we subtract from 55.
 	int player1_won = 0;
 	for(int i = 0;i<num_hands;i++)
 	{
 		if( find_hand(player1_hands[i]) >find_hand(player2_hands[i]))player1_won++;
 	}
 	std::cout<<"Player 1 won " <<player1_won<< " hands out of the 1000 played"<<std::endl;
 	return 0;
 }
 
 std::string	find_hand(std::string &hand)
 { //Converts a given hand into a code, then returns what the code is.
 /*3x,2p,1p need highest,l
  2 3 4 5 6 7 8 9 10 J Q K A
  0 1 2 3 4 5 6 7 8  9 10 11 12
  A B C D E F G H I  J K  L  M */
 std::stringstream ss;
 
 		int c[13]={0};
 		char hand_type;
 		bool flush = false;
 		int suit_same = 0;
 		for(int i = 3;i<=9;i+=2)suit_same+=(hand[1]==hand[i]);
 		if(suit_same ==4)flush=true;
 		
 		for(int i = 0;i<10;i+=2)
 		{
 			if(hand[i]=='T')c[8]++;
 			else if (hand[i]=='J')c[9]++;
 			else if (hand[i]=='Q')c[10]++;
 			else if (hand[i]=='K')c[11]++;
 			else if (hand[i]=='A')c[12]++;
 			else
 			c[hand[i]-'0'-2]++;
 		}
 		//now c holds card distribution
 	
 	int pair_counter = 0;
 	int card_sum = 0;
 	bool three_of_a_kind = false;
 		for(int i = 0;i<13;i++)//0th entry always filled
 		{
 			if(c[i]==4){hand_type='H';break;}//four of a kind;
 			if(c[i]==3)three_of_a_kind=true;
 			if(c[i]==2)pair_counter++;
 			if(c[i]==1)card_sum++;
 		}
 		if(three_of_a_kind==true)hand_type='D';
 		if(pair_counter==1)hand_type='B';
 
 		if(three_of_a_kind==true && pair_counter==1)hand_type = 'G';
 		if(pair_counter==2)hand_type='C';
 		if(card_sum==5)hand_type = 'A';
 		
 		bool straight = false;
 		int high_card = 0;
 		int counter=0 ;
 		for(int i = 0;i<12;i++)
 		{
 			if(c[i]==1 && c[i+1]==1)counter++;
 			if(counter==4){high_card = i+1;straight=true;break;}
 		}
 		
 		if(straight==false && flush==true)hand_type='F';
 		if(straight==true && flush==true)hand_type ='I';
 		if(straight==true && flush==false)hand_type = 'E';
 		if(hand_type=='I' && high_card==12)hand_type ='J';
 		ss<<hand_type;
 		
 		int max_repeat = 4;
 
 		int cards_outputted = 0;
 		while(max_repeat>1)
 		{
 			for(int i = 12;i>=0;i--)
 			{
 				if(c[i]==max_repeat)
 				{
 					for(int j = 0;j<max_repeat;j++){ss<<(char)(i+'A');cards_outputted++;}
 					c[i]=0;
 				}
 			}
 			max_repeat--;
 		}
 		
 
 			for(int i = 12;i>=0;i--)
 			{
 				if(c[i]==1)
 				{
 					ss<<(char)(i+'A');
 					cards_outputted++;
 					c[i]=0;
 				}
 			}
 
 		return ss.str();
 
 }