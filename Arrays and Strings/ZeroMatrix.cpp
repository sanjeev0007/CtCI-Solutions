/*

Problem Statement!!!

Write an algorithm such that if an element in an MxN matrix is 0, its entire row and
column are set to 0.

*/

#include <bits/stdc++.h>
using namespace std;

//Approach 1
//I guess there is only one approach for this

const int N = 1000;
int mat[N][N];
int ans[N][N];

void ZeroMat(int n)
{
    vector<pair<int, int>> zeroCord;

    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < n; ++j)
        {
            if (mat[i][j] == 0)
            {
                zeroCord.push_back({i, j});
            }
        }
    }

    for (int k = 0; k < zeroCord.size(); ++k)
    {
        int x = zeroCord[k].first;
        int y = zeroCord[k].second;
        for (int j = 0; j < n; ++j)
            mat[x][j] = 0;
        for (int j = 0; j < n; ++j)
            mat[j][y] = 0;
    }

    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < n; ++j)
        {
            cout << mat[i][j] << " ";
        }
        cout << "\n";
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    
    int n;
    cin >> n;
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < n; ++j)
        {
            cin >> mat[i][j];
        }
    }
    ZeroMat(n);

    return 0;
}
