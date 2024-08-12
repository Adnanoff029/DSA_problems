#include <bits/stdc++.h>
using namespace std;

// Memoization Code
int f(int i, int j, vector<vector<int>> grid, vector<vector<int>> &dp)
{
    if (i == 0 && j == 0)
        return grid[0][0];
    if (i < 0 || j < 0)
        return 1e5;
    if (dp[i][j] != -1)
        return dp[i][j];
    int up = grid[i][j] + f(i - 1, j, grid, dp);
    int left = grid[i][j] + f(i, j - 1, grid, dp);
    return dp[i][j] = min(up, left);
}

int main()
{
    int m, n;
    cin >> m >> n;
    vector<vector<int>> grid(m, vector<int>(n, 0));
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> grid[i][j];
        }
    }

    // For Memoization
    // vector<vector<int>> dp(m, vector<int>(n, -1));
    // cout << f(m - 1, n - 1, grid, dp) << endl;

    // For Tabulation
    // vector<vector<int>> dp(m, vector<int>(n, 0));
    // dp[0][0] = grid[0][0];
    // for (int i = 0; i < m; i++)
    // {
    //     for (int j = 0; j < n; j++)
    //     {
    //         if (i == 0 && j == 0)
    //             continue;
    //         int down = INT_MAX;
    //         int right = INT_MAX;
    //         if (i > 0)
    //         {
    //             down = grid[i][j] + dp[i - 1][j];
    //         }
    //         if (j > 0)
    //         {
    //             right = grid[i][j] + dp[i][j - 1];
    //         }
    //         dp[i][j] = min(down, right);
    //     }
    // }
    // cout << dp[m - 1][n - 1] << endl;

    // For Space Optimization
    vector<int> prev(n, 0), curr(n, 0);
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (i == 0 && j == 0)
            {
                curr[j] = grid[i][j];
                continue;
            }
            int down = INT_MAX;
            int right = INT_MAX;
            if (i > 0)
            {
                down = grid[i][j] + prev[j];
            }
            if (j > 0)
            {
                right = grid[i][j] + curr[j - 1];
            }
            curr[j] = min(down, right);
        }
        prev = curr;
    }
    cout << curr[n - 1] << endl;
    return 0;
}