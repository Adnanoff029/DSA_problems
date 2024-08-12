#include <bits/stdc++.h>
using namespace std;

int minDistance(string word1, string word2)
{
    int n = word1.size();
    int m = word2.size();
    vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            int eq = 0;
            if (word1[i - 1] == word2[j - 1])
                eq = 1 + dp[i - 1][j - 1];
            else
                eq = 0 + max(dp[i - 1][j], dp[i][j - 1]);
            dp[i][j] = eq;
        }
    }
    int a = n - dp[n][m];
    int b = m - dp[n][m];
    if (a < 0)
        a = 0;
    if (b < 0)
        b = 0;
    return a + b;
}

int main()
{
    string s1, s2;
    cin >> s1 >> s2;
    int ans = minDistance(s1, s2);
    cout << ans << endl;
    return 0;
}
