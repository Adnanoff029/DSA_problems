#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, d;
    cin >> n >> d;
    vector<int> arr(n);
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    int mod = 1e9 + 7;
    int sum = 0;
    for (int x : arr)
        sum += x;
    if (sum < d || (sum - d) % 2 == 1)
        return 0;
    int l = (sum - d) / 2;

    // For Tabulation
    vector<vector<int>> dp(n, vector<int>(l + 1));
    if (arr[0] == 0)
        dp[0][0] = 2; // Pick and not-pick
    else
        dp[0][0] = 1; // Not pick only
    if (arr[0] != 0 && arr[0] <= l)
    {
        dp[0][arr[0]] = 1;
    }
    for (int i = 1; i < n; i++)
    {
        for (int j = 0; j <= (l); j++)
        {
            int take = 0;
            if (j >= arr[i])
            {
                take = dp[i - 1][j - arr[i]];
            }
            int not_take = dp[i - 1][j];
            dp[i][j] = (take + not_take) % mod;
        }
    }
    cout << dp[n - 1][l] << endl;

    // For Space Optimization
    vector<int> prev(l + 1, 0), curr(l + 1, 0);
    if (arr[0] == 0)
        prev[0] = 2;
    else
        prev[0] = 1;
    if (arr[0] != 0 && arr[0] <= l)
    {
        prev[arr[0]] = 1;
    }
    for (int i = 1; i < n; i++)
    {
        for (int j = 0; j <= (l); j++)
        {
            int take = 0;
            if (j >= arr[i])
            {
                take = prev[j - arr[i]];
            }
            int not_take = prev[j];
            curr[j] = (take + not_take) % mod;
        }
        prev = curr;
    }
    cout << curr[l] << endl;
    return 0;
}