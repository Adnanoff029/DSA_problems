#include <bits/stdc++.h>
using namespace std;

// Memoization
int f(int i, int j, string s, string t, vector<vector<int>> &dp)
{
    if (i < 0 || j < 0)
        return 0;

    if (i == 0 && j == 0)
    {
        return s[0] == t[0];
    }

    if (dp[i][j] != -1)
        return dp[i][j];
    int eq = 0;
    if (s[i] == t[j])
    {
        eq = 1 + f(i - 1, j - 1, s, t, dp);
    }
    else
        eq = 0 + max(f(i - 1, j, s, t, dp), f(i, j - 1, s, t, dp));
    return dp[i][j] = eq;
}
int main()
{
    int n, m;
    cin >> n >> m;
    string s, t;
    cin >> s >> t;

    // For Memoization
    // vector<vector<int>> dp(n, vector<int>(m, -1));
    // cout << f(n - 1, m - 1, s, t, dp) << endl;

    // For Tabulation
    vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            int eq = 0;
            if (s[i - 1] == t[j - 1])
                eq = 1 + dp[i - 1][j - 1];
            else
                eq = 0 + max(dp[i - 1][j], dp[i][j - 1]);
            dp[i][j] = eq;
        }
    }
    // Length of LCS
    cout << dp[n][m] << endl;
    // Print LCS
    int len = dp[n][m];
    //   cout << len << endl;
    string ans = "";
    for (int i = 0; i < len; i++)
    {
        ans += '#';
    }
    int i = n, j = m;
    int idx = len - 1;
    while (i > 0 && j > 0)
    {
        if (s[i - 1] == t[j - 1])
        {
            ans[idx] = s[i - 1];
            i--;
            j--;
            idx--;
        }
        else if (dp[i - 1][j] > dp[i][j - 1])
        {
            i--;
        }
        else
        {
            j--;
        }
    }
    cout << ans << endl;
    return 0;
}