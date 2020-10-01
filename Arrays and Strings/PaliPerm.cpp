/*

Problem Statement!!!

Palindrome Permutation: Given a string, write a function to check if it is a permutation of a palin­
drome. A palindrome is a word or phrase that is the same forwards and backwards. A permutation
is a rearrangement of letters. The palindrome does not need to be limited to just dictionary words.


*/

#include <bits/stdc++.h>
using namespace std;

//Approach 1

bool isPermutationOfPalindrom(string s)
{
    int n = s.size();
    map<int, int> mp;
    for (int i = 0; i < n; ++i)
    {
        mp[s[i]]++;
    }
    int ct = 0;
    for (auto &cc : mp)
    {
        if (cc.second % 2)
            ct++;
    }
    return ct >= 1;
}

int main()
{
    string s1;
    cin >> s1;
    cout << isPermutationOfPalindrom(s1) << "\n";
}