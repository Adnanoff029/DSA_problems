#include <bits/stdc++.h>
using namespace std;

int f(int i, int j, vector<int> nums, vector<vector<int>> &dp)
{
    if (i == 0)
    {
        if (j == 0 && nums[0] == 0)
            return 2;
        else if (j == 0 || nums[0] == j)
            return 1;
        else
            return 0;
    }
    if (dp[i][j] != -1)
    {
        return dp[i][j];
    }
    int take = 0;
    int not_take = f(i - 1, j, nums, dp);
    if (j >= nums[i])
    {
        take = f(i - 1, j - nums[i], nums, dp);
    }
    return dp[i][j] = (take + not_take);
}

int main()
{
    int n, target;
    cin >> n >> target;
    vector<int> nums(n);
    for (int i = 0; i < n; i++)
    {
        cin >> nums[i];
    }

    int sum = 0;
    for (int x : nums)
        sum += x;
    if ((sum - target) < 0 || (sum - target) % 2 == 1)
        return 0;
    sum -= target;
    sum /= 2;

    // For Memoization
    // vector<vector<int>> dp(n, vector<int>(sum + 1, -1));
    // cout << f(n - 1, sum, nums, dp) << endl;

    // For Tabulation
    vector<vector<int>> dp(n, vector<int>(sum + 1, 0));
    if (nums[0] == 0)
        dp[0][0] = 2;
    else
        dp[0][0] = 1;

    if (nums[0] <= sum && nums[0] != 0)
        dp[0][nums[0]] = 1;

    for (int i = 1; i < n; i++)
    {
        for (int j = 0; j <= sum; j++)
        {
            int take = 0;
            int not_take = dp[i - 1][j];
            if (j >= nums[i])
            {
                take = dp[i - 1][j - nums[i]];
            }
            dp[i][j] = take + not_take;
        }
    }
    cout << dp[n - 1][sum] << endl;

    
    return 0;
}