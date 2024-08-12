#include <bits/stdc++.h>
using namespace std;

bool f(int i, int j, vector<int> nums, vector<vector<int>> &dp)
{
    if (j == 0)
        return true;
    if (i == 0)
    {
        if (j == nums[i])
            return true;
        else
            return false;
    }
    if (dp[i][j] != -1)
        return dp[i][j];
    int take = false;
    int not_take = f(i - 1, j, nums, dp);
    if (nums[i] <= j)
        take = f(i - 1, j - nums[i], nums, dp);
    return dp[i][j] = take | not_take;
}
int main()
{
    int n;
    cin >> n;
    vector<int> nums(n);
    for (int i = 0; i < n; i++)
    {
        cin >> nums[i];
    }

    int sum = 0;
    for (int x : nums)
    {
        sum += x;
    }
    if (sum % 2 == 1)
        return false;
    sum /= 2;

    // For Memoization
    // vector<vector<int>> dp(n, vector<int>(sum + 1, -1));
    // cout << f(n - 1, sum, nums, dp) << endl;

    // For Tabulation
    vector<vector<bool>> dp(n, vector<bool>(sum + 1, 0));
    for(int i = 0; i < n; i++)
    {
        dp[i][0] = 1;
    }
    dp[0][nums[0]] = 1;
    for(int i = 1; i < n; i++)
    {
        for(int j = 1; j <= sum; j++)
        {
            int take = false;
            if(j >= nums[i])
            {
                take = dp[i-1][j-nums[i]];
            }
            int not_take = dp[i-1][j];
            dp[i][j] = take | not_take;
        }
    }
    cout << dp[n-1][sum] << endl;
    return 0;
}