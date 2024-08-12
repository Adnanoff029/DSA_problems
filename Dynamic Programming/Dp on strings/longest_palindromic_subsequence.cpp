#include <bits/stdc++.h>
using namespace std;

// Makes use of tabulation, as any other approach like memoization would cause the time limit to exceed.

int longestPalindromeSubseq(string s)
{
    int n = s.size();
    int m = n;
    string s1 = s;
    reverse(s1.begin(), s1.end());
    int ans = 0;
    vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            int take = 0, not_take = 0;
            if (s[i - 1] == s1[j - 1])
            {
                take = 1 + dp[i - 1][j - 1];
            }
            else
            {
                not_take = 0 + max(dp[i - 1][j], dp[i][j - 1]);
            }
            dp[i][j] = max(take, not_take);
        }
    }
    return dp[n][m];
}

int main()
{
    string s;
    cin >> s;
    int ans = longestPalindromeSubseq(s);
    cout << ans << endl;
    return 0;
}