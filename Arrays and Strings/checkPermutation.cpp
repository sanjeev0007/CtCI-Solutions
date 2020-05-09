/*
Problem Statement!!!
Check Permuatation

Given 2 strings, devise a method to tell whether the 2 strings are permuations of each other or not

*/

#include<bits/stdc++.h>
using namespace std;

// Approach 1
// Just sorting the strings and comparing them character by character
bool checkPermuation1(string a, string b)
{
	if(a.size() != b.size())	return false;
	sort(a.begin(), a.end());
	sort(b.begin(), b.end());
	for(int i=0; i<a.size(); i++)
	{
		if(a[i] != b[i])	return false;
	}
	return true;
}

// Approach 2
// We will use 2 integers to save the details of all the alphabets. One of the ints will hold details of all the lowercase alphabets
// and the other integer will handle the uppercase alphabets.
bool checkPermuation2(string a, string b)
{
	if(a.size() != b.size())	return false;
	int l = 0;	// For lowercase handling
	int u = 0;	// For uppercase handling
	
	for(auto character:a)
	{
//		What we will be doing in the following few lines is that if we read 'a' we will add 2^0, on seeing 'b' we will add 2^0 and similarly
//		for all the uppercase alphabets also. 
		int ascii = character-'A';
		if(ascii>25)
		{
			ascii = ascii - 32;
			l += 1<<ascii;
		}
		else if(ascii<=25)
		{
			u += 1<<ascii;
		}
	}
	
//	Now we will do the exact opposite of what we did initially 
// if we read 'a' we will subtract 2^0, on seeing 'b' we will subtract 2^0 and similarly for all the uppercase alphabets also.
	for(auto character:b)
	{
		int ascii = character-'A';
		if(ascii>25)
		{
			ascii = ascii - 32;
			l -= (1<<ascii);
		}
		else if(ascii<=25)
		{
			u -= (1<<ascii);
		}
	}
	return (l==0 and u==0);
}
int main()
{
    string a, b;
    cin>>a>>b;
    cout<<checkPermuation2(a, b)<<"\n";
}
