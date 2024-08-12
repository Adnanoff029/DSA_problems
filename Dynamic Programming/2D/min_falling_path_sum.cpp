#include <bits/stdc++.h>
using namespace std;
// Memoization Code
int f(int i, int j, vector<vector<int>> grid, vector<vector<int>> dp)
{
    if (i < 0 || j < 0)
    {
        return 1e8;
    }
    if (i == 0)
    {
        return grid[i][j];
    }
    if (dp[i][j] != -1)
    {
        return dp[i][j];
    }
    int down = 1e8;
    int left = 1e8;
    int right = 1e8;
    if (i > 0)
    {
        down = grid[i][j] + f(i - 1, j, grid, dp);
    }
    if (i > 0 && j > 0)
    {
        left = grid[i][j] + f(i - 1, j - 1, grid, dp);
    }
    if (i > 0 && j < grid.size() - 1)
    {
        right = grid[i][j] + f(i - 1, j + 1, grid, dp);
    }
    return dp[i][j] = min(down, min(left, right));
}

int main()
{
    int n;
    cin >> n;
    vector<vector<int>> grid(n, vector<int>(n, 0));
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> grid[i][j];
        }
    }

    // For Memoization
    // vector<vector<int>> dp(n, vector<int>(n, -1));
    // int ans = INT_MAX;
    // for (int i = 0; i < n; i++)
    // {
    //     ans = min(ans, f(n - 1, i, grid, dp));
    // }
    // cout << ans << endl;

    // For Tabulation
    // vector<vector<int>> dp(n, vector<int>(n, 0));
    // for (int i = 0; i < n; i++)
    // {
    //     for (int j = 0; j < n; j++)
    //     {
    //         if (i == 0)
    //         {
    //             dp[i][j] = grid[i][j];
    //             continue;
    //         }
    //         int down = 1e8;
    //         int left = 1e8;
    //         int right = 1e8;
    //         if (i > 0)
    //         {
    //             down = grid[i][j] + dp[i - 1][j];
    //         }
    //         if (i > 0 && j > 0)
    //         {
    //             left = grid[i][j] + dp[i - 1][j - 1];
    //         }
    //         if (i > 0 && j < n - 1)
    //         {
    //             right = grid[i][j] + dp[i - 1][j + 1];
    //         }
    //         dp[i][j] = min(down, min(left, right));
    //     }
    // }
    // int ans = 1e8;
    // for (int i = 0; i < n; i++)
    // {
    //     ans = min(ans, dp[n - 1][i]);
    // }
    // cout << ans << endl;

    // For Space Optimization
    vector<int> curr(n, 0), prev(n, 0);
    prev = grid[0];
    for (int i = 1; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            int down = 1e8;
            int left = 1e8;
            int right = 1e8;
            if (i > 0)
            {
                down = grid[i][j] + prev[j];
            }
            if (i > 0 && j > 0)
            {
                left = grid[i][j] + prev[j - 1];
            }
            if (i > 0 && j < n - 1)
            {
                right = grid[i][j] + prev[j + 1];
            }
            curr[j] = min(down, min(left, right));
        }
        prev = curr;
    }
    int ans = INT_MAX;
    for (int x : prev)
    {
        ans = min(ans, x);
    }
    return ans;

    return 0;
}