#include <bits/stdc++.h>
using namespace std;

// Memoization
int f(int i, int j, vector<vector<int>> &dp, int n, int m)
{
    if (i < 0 || j < 0)
    {
        return 0;
    }
    if (i == 0 && j == 0)
    {
        return 1;
    }
    if (dp[i][j] != -1)
        return dp[i][j];
    int up = f(i - 1, j, dp, n, m);
    int left = f(i, j - 1, dp, n, m);
    return dp[i][j] = up + left;
}

int main()
{
    int n, m;
    cin >> m >> n;

    // For Memoization
    // vector<vector<int>> dp(n, vector<int>(m, -1));
    // int ans = f(m - 1, n - 1, dp, n, m);
    // cout << ans << endl;

    // For Tabulation
    vector<vector<int>> dp(m, vector<int>(n, 0));
    dp[0][0] = 1;
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (i == 0 && j == 0)
                continue;
            int up = 0;
            int left = 0;
            if (i > 0)
                up = dp[i - 1][j];
            if (j > 0)
                left = dp[i][j - 1];
            dp[i][j] = up + left;
        }
    }
    cout << dp[m - 1][n - 1] << endl;

    
    return 0;
}