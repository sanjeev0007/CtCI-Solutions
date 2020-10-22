/*

Problem Statement!!!

Given an image represented by an NxN matrix, where each pixel in the image is 4
bytes, write a method to rotate the image by 90 degrees. Can you do this in place?

*/

#include <bits/stdc++.h>
using namespace std;

//Approach 1
//I guess there is only one approach for this

const int N = 1000;
int mat[N][N];
int ans[N][N];

void rotateMat(int n)
{
    //if row length and column length are not equal
    // not taking this condition
    for (int layer = 0; layer < n / 2; ++layer)
    {
        int first = layer;
        int last = n - 1 - first;
        for (int i = first; i < last; ++i)
        {
            int offset = i - first;
            int top = mat[first][i];
            //left->top
            mat[first][i] = mat[last - offset][first];
            //top->right
            mat[last - offset][first] = mat[last][last - offset];
            //right->bottom
            mat[last][last - offset] = mat[i][first];
            //bottom ->right
            mat[i][first] = top;
        }
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
    rotateMat(n);

    return 0;
}
