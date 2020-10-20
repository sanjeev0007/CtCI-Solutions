/*

Problem Statement!!!

There are three types of edits that can be performed on strings: insert a character,
remove a character, or replace a character. Given two strings, write a function to check if they are
one edit (or zero edits) away

*/

#include <bits/stdc++.h>
using namespace std;

//Approach 1

bool oneAway(string s1, string s2)
{
    map<int, int> mp1;
    for (int i = 0; i < s1.size(); ++i)
    {
        mp1[s1[i]]++;
    }
    int ct = 0;
    for (int i = 0; i < s2.size(); ++i)
    {
        mp1[s2[i]]--;
        if (mp1[s2[i]] < 0)
            ct++;
    }
    return ct <= 1;
}

int main()
{
    string s1, s2;
    cin >> s1 >> s2;
    int n1 = s1.size();
    int n2 = s2.size();
    if (abs(n1 - n2) <= 1)
        cout << oneAway(s1, s2) << "\n";
    else
        cout << "false"
             << "\n";
}
