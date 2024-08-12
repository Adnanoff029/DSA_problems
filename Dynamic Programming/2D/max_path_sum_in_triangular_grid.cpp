#include <bits/stdc++.h>
using namespace std;

int f(int i, int j, vector<vector<int>> triangle, vector<vector<int>> &dp)
{
    if (i == triangle.size() || j == triangle.size())
        return 0;
    if (dp[i][j] != -1)
        return dp[i][j];
    int down = triangle[i][j] + f(i + 1, j, triangle, dp);
    int right = triangle[i][j] + f(i + 1, j + 1, triangle, dp);
    return dp[i][j] = min(down, right);
}

int main()
{
    int n;
    cin >> n;
    vector<vector<int>> triangle;
    int l = 0;
    for (int i = 0; i < n; i++)
    {
        vector<int> v(l, 0);
        for (int j = 0; j <= l; j++)
        {
            cin >> v[j];
        }
        l++;
        triangle.push_back(v);
    }

    // For Memoization
    // vector<vector<int>> dp(n, vector<int>(n, -1));
    // cout << f(0, 0, triangle, dp) << endl;

    // For Tabulation
    // vector<vector<int>> dp(n, vector<int>(n, 0));
    // for (int i = n - 1; i >= 0; i--)
    // {
    //     for (int j = i; j >= 0; j--)
    //     {
    //         if (i == n - 1)
    //         {
    //             dp[i][j] = triangle[i][j];
    //             continue;
    //         }
    //         int up = triangle[i][j] + dp[i + 1][j];
    //         int left = triangle[i][j] + dp[i + 1][j + 1];
    //         dp[i][j] = min(up, left);
    //     }
    // }
    // cout << dp[0][0] << endl;

    // For Memory Optimization
    vector<int> prev(n, 0), curr(n, 0);
    for (int i = n - 1; i >= 0; i--)
    {
        for (int j = i; j >= 0; j--)
        {
            if (i == n - 1)
            {
                curr[j] = triangle[i][j];
                continue;
            }
            int up = triangle[i][j] + prev[j];
            int left = triangle[i][j] + prev[j + 1];
            curr[j] = min(up, left);
        }
        prev = curr;
    }
    cout << curr[0] << endl;
    return 0;
}