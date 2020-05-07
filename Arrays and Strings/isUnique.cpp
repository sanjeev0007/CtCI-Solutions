/*
Problem Statement!!!
Is Unique: Implement an algorithm to determine if a string has all unique characters. What if you
cannot use additional data structures?
*/

// First doubt should come if string is in ASCII string or UNICODE string.

#include<bits/stdc++.h>
using namespace std;

// Approach 1
bool isUnique1(string s)
{
    int l=s.length();
    //if length of string is greater than total no. of unique character present in ASCII
    if(l>128)
        return false;

    bool check[128]={0};
    for(int i=0;i<l;++i)
    {
        int value=(int)s[i];
        //cout<<value<<"\n";
        if(check[value])
            return false;
        check[value]=true;
    }
    return true;
}
// Approach 2 
// An approach without the use of extra space ie without using any data structures.
// The approach mentioned below assumes that only small alphbets from a-z are available in the string.
bool isUnique2(string s)
{
	int l = s.size();
	if(l>128) return false;
	
	int bits = 0;
	for(auto character:s)
	{
		int bitShift = character-'a';
		if((bits & (1<<bitShift)) > 0)	return false;
		bits += 1<<bitShift;
	}
	return true;
}

//Approach 3
//This approach will work for both unicode and ascii
bool isUnique3(string s)
{
//	Unicode has 137,374 characters at the time of writing this.
	bitset<137374> bits(0);
//	The above basically declares 137374 bits and assigns them the value of 0
// Eg :- The bit 56 will be set when the unicode character which is the integer equivalent of 56 is read. If the character with integer value 56
// is ever read again, we'll know that by observing if the bit in bitset is set or not.
	for(auto character:s)
	{
		int bit = int(character);
		// The unicode value of the said character is stored inside of the variable bit.
		
		// The if statement below checks if the character that is read now has ever been read before, if it has then return false and if not
		// then make sure to set the corresponding bit so that you can know that this particular character appeared before or not. 
		if(bits.test(bit) > 0)	return false;
		bits.set(bit);
	}
	return true;
}

//Approach 4
bool isUnique4(string s)
{
	sort(s.begin(), s.end());
	for(int i=0; i<s.size()-1; i++)
	{
		if(s[i] == s[i+1])	return false;
	}
	return true;
}

int main()
{
    string s;
    cin>>s;
    cout<<isUnique3(s)<<"\n";
}
