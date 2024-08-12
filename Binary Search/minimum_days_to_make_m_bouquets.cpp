#include <bits/stdc++.h>
using namespace std;
int find_max(vector<int> bloomDay)
{
    int ans = 0;
    for (int i = 0; i < bloomDay.size(); i++)
    {
        ans = max(ans, bloomDay[i]);
    }
    return ans;
}
int minDays(vector<int> &bloomDay, int m, int k)
{
    int n = bloomDay.size();
    // if(m*k > n)return -1;
    int low = 1;
    int high = find_max(bloomDay);
    int ans = INT_MAX;
    while (low <= high)
    {
        int mid = low + (high - low) / 2;
        int i = 0, x = 0, l = 0;
        while (i < n)
        {
            if (bloomDay[i] > mid)
            {
                x = 0;
            }
            else
            {
                x++;
                if (x == k)
                {
                    x = 0;
                    l++;
                }
            }
            i++;
        }
        if (l >= m)
        {
            ans = min(ans, mid);
            high = mid - 1;
        }
        else
        {
            low = mid + 1;
        }
    }
    if (ans == INT_MAX)
        return -1;
    return ans;
}
int main()
{
    int n, m, k;
    cin >> n;
    vector<int> nums(n, 0);
    for (int i = 0; i < n; i++)
    {
        cin >> nums[i];
    }
    cin >> m >> k;
    cout << minDays(nums, m, k) << endl;
    return 0;
}