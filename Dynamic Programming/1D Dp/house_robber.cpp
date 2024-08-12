#include <bits/stdc++.h>
using namespace std;

// Memoization
int f(int i, vector<int> nums, vector<int> &dp)
{
    if (i < 0)
    {
        return 0;
    }
    if (dp[i] != -1)
    {
        return dp[i];
    }
    int take = nums[i] + f(i - 2, nums, dp);
    int not_take = f(i - 1, nums, dp);
    return dp[i] = max(take, not_take);
}

int main()
{
    // Taking inputs
    int n;
    cin >> n;
    vector<int> nums(n);
    for (int i = 0; i < n; i++)
    {
        cin >> nums[i];
    }

    // For Memoization
    // vector<int> dp(n, -1);
    // cout << f(n - 1, nums, dp) << endl;

    // For Tabulation
    // vector<int> dp(n, 0);
    // dp[0] = nums[0];
    // for (int i = 1; i < n; i++)
    // {
    //     int take = INT_MIN;
    //     int not_take = dp[i - 1];
    //     if (i >= 2)
    //     {
    //         take = nums[i] + dp[i - 2];
    //     }
    //     dp[i] = max(take, not_take);
    // }
    // cout << dp[n - 1] << endl;

    // For Sapce Optimization
    int last = nums[0], second_last = 0;
    for (int i = 1; i < nums.size(); i++)
    {
        int take = nums[i];
        int not_take = last;
        if (i >= 2)
        {
            take = nums[i] + second_last;
        }
        second_last = last;
        last = max(take, not_take);
    }
    cout << last << endl;
    return 0;
}