#include <bits/stdc++.h>
using namespace std;

// Memoization
int f(int i, int j, vector<vector<int>> &dp, vector<vector<int>> grid)
{
    if (i >= 0 && j >= 0 && grid[i][j] == 1)
        return 0;
    if (i == 0 && j == 0)
        return 1;
    if (i < 0 || j < 0)
        return 0;
    if (dp[i][j] != -1)
        return dp[i][j];
    int up = 0;
    int left = 0;
    up = f(i - 1, j, dp, grid);
    left = f(i, j - 1, dp, grid);
    return dp[i][j] = left + up;
}

int main()
{
    int m, n;
    cin >> m >> n;
    vector<vector<int>> grid(m, vector<int>(n));
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> grid[i][j];
        }
    }

    // For Memoization
    // vector<vector<int>> dp(m, vector<int>(n, -1));
    // cout << f(m - 1, n - 1, dp, grid) << endl;

    // For Tabulation
    // if (grid[0][0] == 1 || grid[m - 1][n - 1] == 1)
    // {
    //     cout << 0 << endl;
    //     return 0;
    // }
    // vector<vector<int>> dp(m, vector<int>(n, 0));
    // dp[0][0] = 1;
    // for (int i = 0; i < m; i++)
    // {
    //     for (int j = 0; j < n; j++)
    //     {
    //         if (i == 0 && j == 0)
    //             continue;
    //         if (grid[i][j] == 1)
    //         {
    //             continue;
    //         }
    //         int down = 0;
    //         int right = 0;
    //         if (i - 1 >= 0)
    //         {
    //             down = dp[i - 1][j];
    //         }
    //         if (j - 1 >= 0)
    //         {
    //             right = dp[i][j - 1];
    //         }
    //         dp[i][j] = down + right;
    //     }
    // }
    // cout << dp[m - 1][n - 1] << endl;

    // For Space Optimization
    if (grid[0][0] == 1 || grid[m - 1][n - 1] == 1)
    {
        cout << 0 << endl;
        return 0;
    }
    vector<int> prev(n, 0), curr(n, 0);
    curr[0] = 1;
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (i == 0 && j == 0)
            {
                curr[j] = 1;
                continue;
            }
            if (grid[i][j] == 1)
            {
                curr[j] = 0;
                continue;
            }
            int down = 0;
            int right = 0;
            if (i - 1 >= 0)
            {
                down = prev[j];
            }
            if (j - 1 >= 0)
            {
                right = curr[j - 1];
            }
            curr[j] = down + right;
        }
        prev = curr;
    }
    cout << curr[n - 1] << endl;
    return 0;
}