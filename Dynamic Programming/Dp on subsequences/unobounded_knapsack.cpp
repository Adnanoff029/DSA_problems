#include <bits/stdc++.h>
using namespace std;

// Memoization
int f(int i, int j, vector<int> profit, vector<int> weight,
      vector<vector<int>> dp)
{
    if (i == 0)
    {
        if (j % weight[0] == 0)
            return (j / weight[0]) * profit[0];
        else
            return 0;
    }
    if (dp[i][j] != -1)
        return dp[i][j];
    int take = 0;
    int not_take = f(i - 1, j, profit, weight, dp);
    if (j >= weight[i])
    {
        take = profit[i] + f(i, j - weight[i], profit, weight, dp);
    }
    return dp[i][j] = max(take, not_take);
}

int main()
{
    int n, w;
    cin >> n >> w;
    vector<int> profit(n), weight(n);
    for (int i = 0; i < n; i++)
        cin >> profit[i];
    for (int i = 0; i < n; i++)
        cin >> weight[i];

    // For Memoization
    // vector<vector<int>> dp(n, vector<int>(w + 1, -1));
    // cout << f(n - 1, w, profit, weight, dp) << endl;

    // For Tabulation
    vector<vector<int>> dp(n, vector<int>(w + 1, 0));
    for (int i = weight[0]; i <= w; i++)
    {
        if (i % weight[0] == 0)
            dp[0][i] = profit[0] * (i / weight[0]);
    }

    for (int i = 1; i < n; i++)
    {
        for (int j = 0; j <= w; j++)
        {
            int take = 0;
            int not_take = dp[i - 1][j];
            if (j >= weight[i])
            {
                take = profit[i] + dp[i][j - weight[i]];
            }
            dp[i][j] = max(take, not_take);
        }
    }
    cout << dp[n - 1][w] << endl;
    return 0;
}