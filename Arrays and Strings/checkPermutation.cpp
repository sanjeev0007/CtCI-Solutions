/*

Problem Statement!!!

Check Permutation: Given two strings, write a method to decide if one is a permutation of the
other.


*/

#include<bits/stdc++.h>
using namespace std;

//Approach 1

bool checkPermutation(string s1,string s2)
{
    int l1=s1.length();
    int l2=s2.length();
    if(l1!=l2)
        return false;
    sort(s1.begin(),s1.end());
    sort(s2.begin(),s2.end());
    if(s1==s2)
        return true;
    return false;    
}


int main()
{
    string s1,s2;
    cin>>s1>>s2;
    cout<<checkPermutation(s1,s2)<<"\n";
}