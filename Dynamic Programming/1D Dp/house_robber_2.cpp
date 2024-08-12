#include <bits/stdc++.h>
using namespace std;

// Memoization
// For houses from index 1 to n-1;
int f1(int i, vector<int> nums, vector<int> &dp)
{
    if (i <= 0)
    {
        return 0;
    }
    if (dp[i] != -1)
        return dp[i];
    int not_take = f1(i - 1, nums, dp);
    int take = nums[i] + f1(i - 2, nums, dp);
    return dp[i] = max(take, not_take);
}
// For houses from index 0 to n-2;
int f2(int i, vector<int> nums, vector<int> &dp)
{
    if (i < 0)
    {
        return 0;
    }
    if (dp[i] != -1)
        return dp[i];
    int not_take = f2(i - 1, nums, dp);
    int take = nums[i] + f2(i - 2, nums, dp);

    return dp[i] = max(take, not_take);
}

int main()
{
    // Taking inputs
    int n;
    cin >> n;
    vector<int> nums(n);
    for (int i = 0; i < nums.size(); i++)
    {
        cin >> nums[i];
    }

    // Memoization
    // vector<int> dp(n, -1);
    // int a = f1(n - 1, nums, dp);
    // fill(dp.begin(), dp.end(), -1);
    // int b = f2(n - 2, nums, dp);
    // cout << max(a, b) << endl;

    // Tabulation
    // For houses from index 1 to n-1;
    // vector<int> dp(n, 0);
    // dp[0] = nums[0];
    // for (int i = 1; i < n - 1; i++)
    // {
    //     int take = INT_MIN;
    //     int not_take = dp[i - 1];
    //     if (i >= 2)
    //     {
    //         take = nums[i] + dp[i - 2];
    //     }
    //     dp[i] = max(take, not_take);
    // }
    // int a = dp[n - 2];
    // For houses from index 0 to n-2;
    // fill(dp.begin(), dp.end(), 0);
    // dp[1] = nums[1];
    // for (int i = 2; i < n; i++)
    // {
    //     int take = INT_MIN;
    //     int not_take = dp[i - 1];
    //     if (i >= 2)
    //     {
    //         take = nums[i] + dp[i - 2];
    //     }
    //     dp[i] = max(take, not_take);
    // }
    // int b = dp[n - 1];
    // cout << max(a, b) << endl;

    // Space Optimization
    // For houses from index 1 to n-1;
    int last = nums[0];
    int second_last = 0;
    for (int i = 1; i < n - 1; i++)
    {
        int take = INT_MIN;
        int not_take = last;
        if (i >= 2)
        {
            take = nums[i] + second_last;
        }
        second_last = last;
        last = max(take, not_take);
    }
    int a = last;
    // For houses from index 0 to n-2;
    last = nums[1];
    second_last = 0;
    for (int i = 2; i < n; i++)
    {
        int take = INT_MIN;
        int not_take = last;
        if (i >= 2)
        {
            take = nums[i] + second_last;
        }
        second_last = last;
        last = max(take, not_take);
    }
    int b = last;
    cout << max(a, b) << endl;
    return 0;
}