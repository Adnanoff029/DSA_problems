#include <bits/stdc++.h>
using namespace std;

// Memoization Code
int f(int i, int j, vector<int> coins, vector<vector<int>> &dp)
{
    if (i == 0)
    {
        if (j % coins[i] == 0)
            return j / coins[i];
        else
            return 1e8;
    }
    if (dp[i][j] != -1)
    {
        return dp[i][j];
    }
    int take = INT_MAX;
    if (j >= coins[i])
    {
        take = 1 + f(i, j - coins[i], coins, dp);
    }
    int not_take = f(i - 1, j, coins, dp);
    return dp[i][j] = min(take, not_take);
}
int main()
{
    int n, amount;
    cin >> n >> amount;
    vector<int> coins(n);
    for (int i = 0; i < n; i++)
    {
        cin >> coins[i];
    }

    if (amount == 0)
    {
        cout << 0 << endl;
        return 0;
    }

    // For Memoization
    // vector<vector<int>> dp(n, vector<int>(amount + 1, -1));
    // int ans = f(n - 1, amount, coins, dp);
    // if (ans == 1e8)
    //     cout << -1 << endl;
    // cout << ans << endl;

    // For Tabulation
    // vector<vector<int>> dp(n, vector<int>(amount + 1, 0));
    // for (int i = 0; i <= amount; i++)
    // {
    //     if (i % coins[0] == 0)
    //         dp[0][i] = (i / coins[0]);
    //     else
    //         dp[0][i] = 1e9;
    // }

    // for (int i = 1; i < n; i++)
    // {
    //     for (int j = 0; j <= amount; j++)
    //     {
    //         int take = INT_MAX;
    //         if (j >= coins[i])
    //         {
    //             take = 1 + dp[i][j - coins[i]];
    //         }
    //         int not_take = dp[i - 1][j];
    //         dp[i][j] = min(take, not_take);
    //     }
    // }
    // int ans = dp[n - 1][amount];
    // if (ans >= 1e9)
    //     cout << -1 << endl;
    // else
    //     cout << ans << endl;

    // For Space Optimization
    int n = coins.size();
    vector<int> prev(amount + 1, 0), curr(amount + 1, 0);
    for (int i = 0; i <= amount; i++)
    {
        if (i % coins[0] == 0)
            prev[i] = (i / coins[0]);
        else
            prev[i] = 1e9;
    }

    for (int i = 1; i < n; i++)
    {
        for (int j = 0; j <= amount; j++)
        {
            int take = INT_MAX;
            if (j >= coins[i])
            {
                take = 1 + curr[j - coins[i]];
            }
            int not_take = prev[j];
            curr[j] = min(take, not_take);
        }
        prev = curr;
    }
    int ans = prev[amount];
    if (ans >= 1e9)
        cout << -1 << endl;
    else
        cout << ans << endl;
    return 0;
}