#include <bits/stdc++.h>
using namespace std;

int find_max(vector<int> piles)
{
    int ans = 0;
    for (int i = 0; i < piles.size(); i++)
    {
        ans = max(piles[i], ans);
    }
    return ans;
}
int minEatingSpeed(vector<int> &piles, int h)
{
    int n = piles.size();
    int low = 1;
    int high = find_max(piles);
    int ans = 1e9;
    while (low <= high)
    {
        long long sum = 0;
        int mid = low + (high - low) / 2;
        for (int i = 0; i < n; i++)
        {
            sum += ceil(double(piles[i]) / double(mid));
        }
        if (sum <= h)
        {
            ans = min(ans, mid);
            high = mid - 1;
        }
        else if (sum > h)
        {
            low = mid + 1;
        }
    }
    return ans;
}
int main()
{
    int n;
    cin >> n;
    vector<int> nums(n, 0);
    for (int i = 0; i < n; i++)
    {
        cin >> nums[i];
    }
    int h;
    cin >> h;
    cout << minEatingSpeed(nums, h) << endl;
    return 0;
}