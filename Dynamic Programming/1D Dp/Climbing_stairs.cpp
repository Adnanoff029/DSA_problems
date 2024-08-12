#include <bits/stdc++.h>
using namespace std;
// Memoization
int f(int i, vector<int> &dp)
{
    if (i < 0)
    {
        return 0;
    }
    if (i == 0)
    {
        return dp[i] = 1;
    }
    if (dp[i] != -1)
        return dp[i];
    int one = f(i - 1, dp);
    int two = f(i - 2, dp);

    return dp[i] = one + two;
}

int main()
{
    int n;
    cin >> n;
    vector<int> dp(n + 1, 0);
    dp[0] = 0;
    dp[1] = 1;
    for (int i = 2; i <= n; i++)
    {
        if (i < n)
        {
            dp[i] = 2 + dp[i - 1];
        }
        else
        {
            dp[i] = 1 + dp[i - 1];
        }
    }
    cout << dp[n] << endl;
    return 0;
}