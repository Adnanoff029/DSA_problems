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
    int target = 0;
    cin >> target;
    int low = 0;
    int high = n - 1;
    int ans = 1e9;
    while (low <= high)
    {
        int mid = low + (high - low) / 2;
        if (arr[mid] >= arr[low])
        {
            ans = min(ans, arr[low]);
            low = mid + 1;
        }
        else
        {
            ans = min(ans, arr[mid]);
            high = mid - 1;
        }
    }
    cout<<ans;
    return 0;
}