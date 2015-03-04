#include "big_int.h"
#include <sstream>

big_int::big_int(std::string val_string):value(val_string){}//constructor
big_int::~big_int(){}

int big_int::operator[] (const int &index) const
{
	int return_value = value[index]-'0';
	return return_value;
}


std::ostream& operator <<(std::ostream& os, const big_int &value_1)
{
	os << value_1.get_value();

	return os;

}


void big_int::clear_value(){value.clear();}

void big_int::set_value(std::string string)
{
	value = string;
}


std::string  big_int::get_value() const
{
	return value;
}
int big_int::get_size() const {return value.size();}


big_int operator *(const big_int &value_1 , const big_int &value_2)
{
    //First, we find out which of the strings is longer (if any).  If they're congruent, set one to "top" and the other to "bottom"
    int size_1 = value_1.get_size(),size_2 = value_2.get_size();
    string top="",bottom="";
    if(size_1<=size_2)
    {
        bottom = value_1.get_value();
        top = value_2.get_value();
    }
    else
    {
        top = value_1.get_value();
        bottom = value_2.get_value();
    }
    int top_size = top.size(),bottom_size = bottom.size();
    //Once we have top and bottom strings, we get their size and store them in top_size and bottom_size;
    //Going to initialize an array to hold what we need during multiplication.  Maximum we'll need is top_size+bottom_size, with bottom_size;
    
    int total_size = (top_size+bottom_size)*bottom_size,row_size = top_size+bottom_size;
    int *mult_holder=new int[total_size];
    for(int i = 0;i<total_size;i++)mult_holder[i]=0;
    
        //mult_holder[i][j]=mult_holder[i*row_size +j]
    
    int holder = 0,carry = 0,row_index=0,col_index;
    for(int i = bottom.size();i>0;i--)
    {
        holder = 0; carry = 0,col_index = row_size-1;
        for(int j = top.size();j>0;j--)
        {
            
            holder = (top[j-1]-48)*(bottom[i-1]-48);
            if(holder>9)
            {
                carry = holder/10;
                mult_holder[row_index*row_size+col_index-row_index]+=holder%10;
                mult_holder[row_index*row_size+col_index-1-row_index]+=carry;

            }
            else
            {
                carry = 0;
                mult_holder[row_index*row_size+col_index-row_index]+=holder;

            }
            col_index--;
        }
        row_index++;
    }
 
    //the final array, we will store our product in:
    int *final_array = new int[row_size];
    for(int i = 0;i<row_size;i++)final_array[i]=0;
    
    carry = 0;holder = 0;
    
    for(int j =(row_size-1);j>=0;j--)
        for(int i = bottom.size()-1;i>=0;i--)
        {
            final_array[j]+=mult_holder[row_size*i +j];
            
        }

    //Haven't taken care of instances where numbers are greater than 9, here we do that.
    for(int i = row_size-1;i>0;i--)if(final_array[i]>9)
    {
        final_array[i-1]+= final_array[i]/10;
        final_array[i] = final_array[i] % 10;
        
    }


    stringstream ss;
    //trim the extra zeros in front
    int start = 0;
    for(int i = 0;i<row_size;i++)if(final_array[i]>0){start = i;break;}
    for(int i = start;i<row_size;i++)ss<<final_array[i];

    
    //free up memory we allocated for operations
    delete[] final_array;
    delete[] mult_holder;
    
    big_int return_int(ss.str());
    return return_int;  
}

big_int operator +(const big_int &value_1 , const big_int &value_2)
{
    
    //First, we find out which of the strings is longer (if any).  If they're congruent, set one to "top" and the other to "bottom"
    int size_1 = value_1.get_size(),size_2 = value_2.get_size();
	int total_size = std::max(size_1,size_2)+1;

    int *top = new int[total_size];
    int *bottom = new int[total_size];
  
  for(int i = 0;i<total_size;i++)
  {
	  top[i]=0;
	  bottom[i]=0;
  }
	for(int i = size_1-1,col_index1=total_size-1;i>=0;i--)top[col_index1--]=(int)value_1[i];
	for(int i = size_2-1,col_index2=total_size-1;i>=0;i--)bottom[col_index2--]=(int)value_2[i];

    int *add_holder=new int[total_size];
    for(int i = 0;i<total_size;i++)add_holder[i]=0;
    
    for(int i = total_size-1,holder = 0,carry = 0;i>=0;i--)
    {
    	holder = top[i]+bottom[i]+carry;
    	if(holder>9)
    	{
    		carry = holder/10;
    		add_holder[i]+= holder%10;
    	}
    	else
    	{
    		add_holder[i]+=holder;
    		carry = 0;
    	}
    }
    
    stringstream ss;
    //trim the extra zeros in front
    int start = 0;
    for(int i = 0;i<total_size;i++)if(add_holder[i]>0){start = i;break;}
    for(int i = start;i<total_size;i++)ss<<add_holder[i];

    //free up memory we allocated for operations
    delete[] add_holder;
    
    big_int return_int(ss.str());
    return return_int;  
}

big_int operator -(const big_int &value_1 , const big_int &value_2)
{

    int size_1 = value_1.get_size(),size_2 = value_2.get_size();
	int total_size = std::max(size_1,size_2)+1;

    int *top = new int[total_size];
    int *bottom = new int[total_size];
    
  //inialize the new arrays;
  for(int i = 0;i<total_size;i++)
  {
	  top[i]=0;
	  bottom[i]=0;
  }

	bool is_Negative = false;//will keep track of result will be negative or not
	if(size_1<size_2)is_Negative = true;
	if(size_1==size_2)for(int i = 0;i<size_1;i++)
	{
		if(value_1[i]<value_2[i])
		{
			is_Negative=true;
			break;
		}
	}
	
	if(is_Negative)
	{
		size_1 = value_2.get_size();
		size_2 = value_1.get_size();
	}

  //put values of "top" and "bottom" into the new arrays, keeping track of size for negative cases.;
  if(!(is_Negative))//if not negative
  {
	for(int i = size_1-1,col_index1=total_size-1;i>=0;i--)top[col_index1--]=(int)value_1[i];
	for(int i = size_2-1,col_index2=total_size-1;i>=0;i--)bottom[col_index2--]=(int)value_2[i];
   }
   else
   {
    for(int i = size_2-1,col_index1=total_size-1;i>=0;i--)bottom[col_index1--]=(int)value_1[i];
	for(int i = size_1-1,col_index2=total_size-1;i>=0;i--)top[col_index2--]=(int)value_2[i];
   }
	//turn 0s into appropriate 9s and 10s 
   for(int i = total_size-1;i>total_size-size_1;i--)if(top[i]<=0){top[i]+=10;top[i-1]-=1;}

	int *sub_holder=new int[total_size];
    for(int i = 0;i<total_size;i++)sub_holder[i]=0;

	 for(int i = total_size-1,holder = 0;i>=0;i--)sub_holder[i] = top[i]-bottom[i];
    	
    stringstream ss;
    //trim the extra zeros in front
    int start = 0;
    for(int i = 0;i<total_size;i++)if(sub_holder[i]!=0){start = i;break;}
    if(is_Negative)ss<<-1*sub_holder[start];
    else ss<<sub_holder[start];
    for(int i = start+1;i<total_size;i++)ss<<std::abs(sub_holder[i]);

    //free up memory we allocated for operations
    delete[] sub_holder;
    delete[] top;
    delete[] bottom;
    
    big_int return_int(ss.str());
    return return_int;  


}

big_int &big_int::operator = (const big_int &rhs)
{
	if(this != &rhs)
	{
		value = rhs.value;
	}
	return *this;
}

big_int &operator *= (big_int &a,const big_int &b)
{
	big_int c = a*b;
	a = c;
	return a;
}

big_int &operator += (big_int &a, const big_int &b)
{
	big_int c = a+b;
	a = c;
	return a;
}



