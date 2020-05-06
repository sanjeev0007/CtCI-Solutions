/*

Problem Statement!!!

Is Unique: Implement an algorithm to determine if a string has all unique characters. What if you
cannot use additional data structures?

*/

// First doubt should come if string is in ASCII string or UNICODE string.

#include<bits/stdc++.h>
using namespace std;

//
bool isUnique(string s)
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

int main()
{
    string s;
    cin>>s;
    cout<<isUnique(s)<<"\n";
}