#include <bits/stdc++.h>
using namespace std;

// Memoization Code
int f(int i, int j1, int j2, vector<vector<int>> grid,
      vector<vector<vector<int>>> &dp, int r, int c)
{
    if (j1 < 0 || j2 < 0 || j1 >= c || j2 >= c)
        return -1e7;
    if (i == r - 1)
    {
        if (j1 == j2)
            return grid[i][j1];
        else
            return grid[i][j1] + grid[i][j2];
    }
    if (dp[i][j1][j2] != -1)
        return dp[i][j1][j2];
    int maxi = -1e7;
    int posCol[] = {1, 0, -1};
    for (int k = 0; k < 3; k++)
    {
        for (int z = 0; z < 3; z++)
        {
            if (j1 == j2)
            {
                maxi = max(maxi, grid[i][j1] + f(i + 1, j1 + posCol[k], j2 + posCol[z],
                                                 grid, dp, r, c));
            }
            else
            {
                maxi = max(
                    maxi, grid[i][j1] + grid[i][j2] +
                              f(i + 1, j1 + posCol[k], j2 + posCol[z], grid, dp, r, c));
            }
        }
    }
    return dp[i][j1][j2] = maxi;
}

int main()
{
    int r, c;
    cin >> r >> c;
    vector<vector<int>> grid(r, vector<int>(c, 0));
    for (int i = 0; i < r; i++)
    {
        for (int j = 0; j < c; j++)
        {
            cin >> grid[i][j];
        }
    }

    // For Memoization
    // vector<vector<vector<int>>> dp(r, vector<vector<int>>(c, vector<int>(c, -1)));
    // cout << f(0, 0, c - 1, grid, dp, r, c) << endl;

    // For Tabulation
    vector<vector<vector<int>>> dp(r, vector<vector<int>>(c, vector<int>(c, 0)));
    int posCol[] = {-1, 0, 1};

    for (int i = 0; i < c; i++)
    {
        for (int j = 0; j < c; j++)
        {
            if (i == j)
                dp[r - 1][i][j] = grid[r - 1][j];
            else
                dp[r - 1][i][j] = grid[r - 1][i] + grid[r - 1][j];
        }
    }

    for (int i = r - 2; i >= 0; i--)
    {
        for (int j = 0; j < c; j++)
        {
            for (int k = 0; k < c; k++)
            {
                int maxi = -1e7;
                for (int b = 0; b < 3; b++)
                {
                    for (int a = 0; a < 3; a++)
                    {
                        int val = 0;
                        if (j == k)
                        {
                            val = grid[i][j];
                        }
                        else
                        {
                            val = grid[i][j] + grid[i][k];
                        }
                        if (j + posCol[b] >= 0 && j + posCol[b] < c && k + posCol[a] >= 0 &&
                            k + posCol[a] < c)
                        {
                            val += dp[i + 1][j + posCol[b]][k + posCol[a]];
                        }
                        else
                        {
                            val += -1e7;
                        }
                        maxi = max(maxi, val);
                    }
                }
                dp[i][j][k] = maxi;
            }
        }
    }
    cout << dp[0][0][c - 1] << endl;
    return 0;
}