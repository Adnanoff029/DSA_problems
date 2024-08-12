#include <bits/stdc++.h>
using namespace std;
// Memoization
int f(int i, vector<int> height, int k, vector<int> &dp)
{
    if (i == 0 || i < 0)
    {
        return 0;
    }
    if (dp[i] != -1)
    {
        return dp[i];
    }
    int min_cost = INT_MAX;
    for (int j = 1; j <= k; j++)
    {
        int distance = INT_MAX;
        if (i - j >= 0)
        {
            distance = abs(height[i] - height[i - j]) + f(i - j, height, k, dp);
        }
        min_cost = min(min_cost, distance);
    }
    return dp[i] = min_cost;
}

int main()
{
    // Taking Inputs
    int n, k;
    cin >> n >> k;
    vector<int> heights(n);
    for (int i = 0; i < n; i++)
    {
        cin >> heights[i];
    }

    // For Memoization
    // vector<int> dp(n, -1);
    // cout << f(n - 1, heights, k, dp) << endl;

    // For Tabulation
    vector<int> dp(n, INT_MAX);
    dp[0] = 0;
    for (int i = 1; i < n; i++)
    {
        int minCost = INT_MAX;
        for (int j = 1; j <= k; j++)
        {
            int distance = INT_MAX;
            if (i - j >= 0)
            {
                distance = abs(heights[i] - heights[i - j]) + dp[i - j];
            }
            minCost = min(distance, minCost);
        }
        dp[i] = minCost;
    }
    cout << dp[n - 1] << endl;
    return 0;
}