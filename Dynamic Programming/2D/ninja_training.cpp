#include <bits/stdc++.h>
using namespace std;
// Memoization
int f(int i, int j, vector<vector<int>> &dp, vector<vector<int>> points, int n)
{
    if (i == 0)
    {
        int maxi = 0;
        for (int k = 0; k <= 2; k++)
        {
            if (k != j)
            {
                maxi = max(maxi, points[i][k]);
            }
        }
        return maxi;
    }
    if (dp[i][j] != -1)
    {
        return dp[i][j];
    }

    int maxi = 0;
    for (int k = 0; k <= 2; k++)
    {
        if (k != j)
        {
            int l = points[i][k] + f(i - 1, k, dp, points, n);
            maxi = max(maxi, l);
        }
    }
    return dp[i][j] = maxi;
}

int main()
{

    int n;
    cin >> n;
    vector<vector<int>> points(n, vector<int>(3));
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            cin >> points[i][j];
        }
    }

    // For Memoization
    // vector<vector<int>> dp(n, vector<int>(4, -1));
    // int ans = f(n - 1, 3, dp, points, n);
    // cout << ans << endl;

    // For Tabulation
    // vector<vector<int>> dp(n, vector<int>(4, 0));
    // dp[0][0] = max(points[0][1], points[0][2]);
    // dp[0][1] = max(points[0][0], points[0][2]);
    // dp[0][2] = max(points[0][0], points[0][1]);
    // dp[0][3] = max(points[0][0], max(points[0][1], points[0][2]));
    // for (int i = 1; i < n; i++)
    // {
    //     for (int j = 0; j <= 3; j++)
    //     {
    //         int maxi = 0;
    //         for (int k = 0; k <= 2; k++)
    //         {
    //             if (k != j)
    //             {
    //                 int l = points[i][k] + dp[i - 1][k];
    //                 maxi = max(maxi, l);
    //             }
    //         }
    //         dp[i][j] = maxi;
    //     }
    // }
    // cout << dp[n - 1][3] << endl;

    // For Space Optimization
    vector<int> last(4, 0);
    vector<int> curr(4, 0);
    last[0] = max(points[0][1], points[0][2]);
    last[1] = max(points[0][0], points[0][2]);
    last[2] = max(points[0][0], points[0][1]);
    last[3] = max(points[0][0], max(points[0][1], points[0][2]));

    for (int i = 1; i < n; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            int maxi = 0;
            for (int k = 0; k <= 2; k++)
            {
                if (k != j)
                {
                    int l = points[i][k] + last[k];
                    maxi = max(maxi, l);
                }
            }
            curr[j] = maxi;
        }
        last = curr;
    }
    cout << last[3] << endl;
    return 0;
}