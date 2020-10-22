/*

Problem Statement!!!

Implement a method to perform basic string compression using the counts
of repeated characters. For example, the string aabcccccaaa would become a2blc5a3. If the
"compressed" string would not become smaller than the original string, your method should return
the original string. You can assume the string has only uppercase and lowercase letters (a - z).

*/

#include <bits/stdc++.h>
using namespace std;



//Approach 1
//may be this approach is lengthy :(

void strigComp(string s)
{
    int n = s.size();
    int ct = 0;
    string ans = "";
    vector<int> v;
    set<char> st;
    for (int i = 0; i < n; ++i)
    {
        st.insert(s[i]);
        if (i + 1 < n && s[i] == s[i + 1])
        {
            ct++;
        }
        else
        {
            v.push_back(ct + 1);
            ct = 0;
        }
    }
    for (auto &c : st)
        ans += c;
    for (int i = 0; i < v.size(); ++i)
    {
        cout << ans[i];
        cout << v[i];
    }
}

//Approach 2

//Idea we can also make it in O(N) by iterating from 0 to n and counting simmultaneously maybe?



int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    string s1;
    cin >> s1;
    strigComp(s1);
    return 0;
}
