#include <bits/stdc++.h>
using namespace std;
// Memoization
int f(int i, vector<int> heights, vector<int> &dp)
{
    if (i < 0 || i == 0)
    {
        return 0;
    }
    if (dp[i] != -1)
        return dp[i];
    int one_step = abs(heights[i] - heights[i - 1]) + f(i - 1, heights, dp);
    int two_step = INT_MAX;
    if (i >= 2)
        two_step = abs(heights[i] - heights[i - 2]) + f(i - 2, heights, dp);
    return dp[i] = min(one_step, two_step);
}

int main()
{
    // Taking Input
    int n;
    cin >> n;
    vector<int> heights(n);
    for (int i = 0; i < n; i++)
    {
        cin >> heights[i];
    }

    // For Memoization
    // vector<int> dp(n, -1);
    // cout << f(n - 1, heights, dp) << endl;

    // For tabulation
    // vector<int> dp(n, 0);
    // dp[0] = 0;
    // for (int i = 1; i < n; i++)
    // {
    //     int one_step = dp[i - 1] + abs(heights[i] - heights[i - 1]);
    //     int two_step = INT_MAX;
    //     if (i >= 2)
    //     {
    //         two_step = dp[i - 2] + abs(heights[i] - heights[i - 2]);
    //     }
    //     dp[i] = min(one_step, two_step);
    // }
    // cout << dp[n - 1] << endl;

    // For Memory optimization
    int last = 0;
    int secondLast = 0;
    for (int i = 1; i < n; i++)
    {
        int one_step = last + abs(heights[i - 1] - heights[i]);
        int two_step = INT_MAX;
        if (i >= 2)
        {
            two_step = secondLast + abs(heights[i] - heights[i - 2]);
        }
        secondLast = last;
        last = min(one_step, two_step);
    }
    cout << last << endl;
    return 0;
}