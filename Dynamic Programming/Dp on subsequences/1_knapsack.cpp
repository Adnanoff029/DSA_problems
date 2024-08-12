#include <bits/stdc++.h>
using namespace std;

int f(int i, int j, vector<int> weight, vector<int> value,
      vector<vector<int>> &dp)
{
    if (i == 0)
    {
        if (weight[0] <= j)
            return value[0];
        else
            return 0;
    }
    if (dp[i][j] != -1)
        return dp[i][j];
    int not_take = f(i - 1, j, weight, value, dp);
    int take = 0;
    if (j >= weight[i])
        take = value[i] + f(i - 1, j - weight[i], weight, value, dp);
    return dp[i][j] = max(take, not_take);
}

int main()
{
    int n, maxWeight;
    cin >> n >> maxWeight;
    vector<int> value(n), weight(n);
    for (int i = 0; i < n; i++)
    {
        cin >> value[i];
    }
    for (int i = 0; i < n; i++)
    {
        cin >> weight[i];
    }

    // For Memoization
    // vector<vector<int>> dp(n, vector<int>(maxWeight + 1, -1));
    // cout << f(n - 1, maxWeight, weight, value, dp) << endl;

    // For Tabulation
    // vector<vector<int>> dp(n, vector<int>(maxWeight + 1, 0));
    // for (int i = weight[0]; i <= maxWeight; i++)
    //     dp[0][i] = value[0];

    // for (int i = 1; i < n; i++)
    // {
    //     for (int j = 0; j <= maxWeight; j++)
    //     {
    //         int not_take = dp[i - 1][j];
    //         int take = INT_MIN;
    //         if (j >= weight[i])
    //             take = value[i] + dp[i - 1][j - weight[i]];
    //         dp[i][j] = max(take, not_take);
    //     }
    // }
    // cout << dp[n - 1][maxWeight] << endl;

    // For Space Optimization
    vector<int> prev(maxWeight + 1, 0), curr(maxWeight + 1, 0);
    for (int i = weight[0]; i <= maxWeight; i++)
        prev[i] = value[0];

    for (int i = 1; i < n; i++)
    {
        for (int j = 0; j <= maxWeight; j++)
        {
            int not_take = prev[j];
            int take = INT_MIN;
            if (j >= weight[i])
                take = value[i] + prev[j - weight[i]];
            curr[j] = max(take, not_take);
        }
        prev = curr;
    }
    cout << prev[maxWeight] << endl;
    return 0;
}