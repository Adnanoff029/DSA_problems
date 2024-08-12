#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;
    vector<int> arr(n, 0);
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    int low = 0;
    int high = n - 1;
    int ans = 1e9;
    int idx = 0;
    while (low <= high)
    {
        int mid = low + (high - low) / 2;
        if (arr[low] <= arr[high])
        {
            if (ans >= arr[low])
            {
                ans = arr[low];
                idx = low;
            }
            break;
        }
        if (arr[mid] >= arr[low])
        {
            if (ans >= arr[low])
            {
                ans = arr[low];
                idx = low;
            }
            low = mid + 1;
        }
        else
        {
            if (ans >= arr[mid])
            {
                ans = arr[mid];
                idx = mid;
            }
            high = mid - 1;
        }
    }
    cout << ans << " " << idx;
    return 0;
}