#include <bits/stdc++.h>
using namespace std;

// Memoization Code
bool f(int i, vector<int> arr, int target, int k, vector<vector<int>> &dp)
{
    if (target == 0)
        return true;
    if (i == 0)
    {
        if (arr[0] == target)
            return true;
        else
            return false;
    }
    if (dp[i][target] != -1)
        return dp[i][target];
    bool take = false;
    if (target >= arr[i])
        take = f(i - 1, arr, target - arr[i], k, dp);
    bool not_take = f(i - 1, arr, target, k, dp);
    return dp[i][target] = take | not_take;
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
    // cout << f(n - 1, arr, k, k, dp) << endl;

    // For tabulation
    vector<vector<bool>> dp(n, vector<bool>((k + 1), 0));
    for (int i = 0; i < n; i++)
    {
        dp[i][0] = 1;
    }
    dp[0][arr[0]] = 1;
    for (int i = 1; i < n; i++)
    {
        for (int j = 1; j <= k; j++)
        {
            bool take = false;
            if (arr[i] <= j)
                take = dp[i - 1][j - arr[i]];
            bool not_take = dp[i - 1][j];
            dp[i][j] = take | not_take;
        }
    }
    cout << dp[n - 1][k] << endl;

    // For Space Optimization
    vector<bool> prev(k + 1, 0), curr(k + 1, 0);
    prev[0] = 1;
    curr[0] = 1;
    prev[arr[0]] = 1;
    for (int i = 1; i < n; i++)
    {
        for (int j = 1; j <= k; j++)
        {
            bool take = false;
            if (arr[i] <= j)
                take = prev[j - arr[i]];
            bool not_take = prev[j];
            curr[j] = take | not_take;
        }
        prev = curr;
    }
    cout << curr[k] << endl;
    return 0;
}