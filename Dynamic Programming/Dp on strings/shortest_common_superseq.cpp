#include <bits/stdc++.h>
using namespace std;

int main()
{
    string a, b;
    cin >> a >> b;
    int n = a.size();
    int m = b.size();
    vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            int take = 0;
            if (a[i - 1] == b[j - 1])
            {
                take = 1 + dp[i - 1][j - 1];
            }
            else
            {
                take = 0 + max(dp[i - 1][j], dp[i][j - 1]);
            }
            dp[i][j] = take;
        }
    }

    int i = n, j = m;
    string ans = "";
    int len = dp[n][m];
    for (int i = 0; i < (n + m - len); i++)
    {
        ans += '$';
    }
    int idx = (m + n - len) - 1;
    while (i > 0 && j > 0)
    {
        if (a[i - 1] == b[j - 1])
        {
            ans[idx] = a[i - 1];
            i--;
            j--;
            idx--;
        }
        else if (dp[i - 1][j] > dp[i][j - 1])
        {
            ans[idx] = a[i - 1];
            idx--;
            i--;
        }
        else
        {
            ans[idx] = b[j - 1];
            idx--;
            j--;
        }
    }
    while (i > 0)
    {
        ans[idx] = a[i - 1];
        idx--;
        i--;
    }
    while (j > 0)
    {
        ans[idx] = b[j - 1];
        idx--;
        j--;
    }

    cout << ans << endl;
    return 0;
}