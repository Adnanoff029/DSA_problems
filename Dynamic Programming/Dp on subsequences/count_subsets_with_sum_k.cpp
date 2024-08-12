#include <bits/stdc++.h>
using namespace std;

int mod = 1e9 + 7;
int f(int i, int j, vector<int> arr, vector<vector<int>> &dp)
{
    if (j == 0)
        return 1;
    if (i == 0)
    {
        if (arr[i] == j)
            return 1;
        else
            return 0;
    }
    if (dp[i][j] != -1)
        return dp[i][j];
    int take = 0;
    if (j >= arr[i])
    {
        take = f(i - 1, j - arr[i], arr, dp);
    }
    int not_take = f(i - 1, j, arr, dp);
    return dp[i][j] = ((take + not_take) % mod);
}

int main()
{
    int n, k;
    cin >> n >> k;
    vector<int> arr(n);
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    // For Memoization
    // vector<vector<int>> dp(n, vector<int>(k + 1, -1));
    // cout << f(n - 1, k, arr, dp) << endl;

    // For Tabulation
    vector<vector<int>> dp(n + 1, vector<int>(k + 1, 0));
    for (int i = 0; i < n; i++)
    {
        dp[i][0] = 1;
    }
    for (int i = 1; i <= n; i++)
    {
        for (int j = 0; j <= k; j++)
        {
            int take = 0;
            if (j >= arr[i - 1])
            {
                take = dp[i - 1][j - arr[i - 1]] % mod;
            }
            int not_take = dp[i - 1][j] % mod;
            dp[i][j] = ((take + not_take) % mod);
        }
    }
    return dp[n][k];

    // For Memory Optimization
    vector<int> prev(k + 1, 0), curr(k + 1, 0);
    prev[0] = 1;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 0; j <= k; j++)
        {
            int take = 0;
            if (j >= arr[i - 1])
            {
                take = prev[j - arr[i - 1]] % mod;
            }
            int not_take = prev[j] % mod;
            curr[j] = ((take + not_take) % mod);
        }
        prev = curr;
    }
    cout << curr[k] << endl;
    return 0;
}