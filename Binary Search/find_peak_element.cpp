#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;
    vector<int> nums(n, 0);
    for (int i = 0; i < n; i++)
    {
        cin >> nums[i];
    }
    if (nums.size() == 1)
    {
        cout << "Peak Element is at index: "
             << "0" << endl;
        return 0;
    }
    if (nums[0] > nums[1])
    {
        cout << "Peak Element is at index: "
             << "0" << endl;
        return 0;
    }
    if (nums[n - 1] > nums[n - 2])
    {
        cout << "Peak Element is at index: " << n - 1 << endl;
        return 0;
    }
    int low = 1;
    int high = n - 2;
    while (low <= high)
    {
        int mid = low + (high - low) / 2;
        if (nums[mid] > nums[mid + 1] && nums[mid] > nums[mid - 1])
        {
            cout << "Peak Element is at index: " << mid << endl;
            return 0;
        }
        else if (nums[mid] > nums[mid - 1])
            low = mid + 1;
        else if (nums[mid] < nums[mid + 1])
            high = mid - 1;
        else
            high = mid - 1;
    }
    cout << "No Peak Element" << endl;
    return 0;
}