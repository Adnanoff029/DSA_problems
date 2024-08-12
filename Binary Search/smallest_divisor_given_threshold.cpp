#include <bits/stdc++.h>
using namespace std;
int find_max(vector<int> nums)
{
    int ans = 0;
    for (auto it : nums)
    {
        ans = max(ans, it);
    }
    return ans;
}
int smallestDivisor(vector<int> &nums, int threshold)
{
    int n = nums.size();
    int low = 1;
    int high = find_max(nums);
    int ans = INT_MAX;
    while (low <= high)
    {
        int mid = low + (high - low) / 2;
        int sum = 0;
        for (int i = 0; i < n; i++)
        {
            sum += ceil(double(nums[i]) / double(mid));
        }
        if (sum <= threshold)
        {
            ans = min(ans, mid);
            high = mid - 1;
        }
        else
        {
            low = mid + 1;
        }
    }
    return ans;
}
int main()
{
    int n, threshold;
    cin >> n;
    vector<int> nums(n, 0);
    for (int i = 0; i < n; i++)
    {
        cin >> nums[i];
    }
    cin >> threshold;
    cout << smallestDivisor(nums, threshold) << endl;
    return 0;
}