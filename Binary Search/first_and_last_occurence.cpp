#include <bits/stdc++.h>
using namespace std;

int ceil(vector<int> arr, int n, int target)
{
    int ans = -1;
    int low = 0, high = n - 1;
    while (low <= high)
    {
        int mid = low + (high - low) / 2;
        if (arr[mid] == target)
        {
            ans = mid;
            low = mid + 1;
        }
        if (arr[mid] < target)
        {
            low = mid + 1;
        }
        else
        {
            high = mid - 1;
        }
    }
    return ans;
}
int floor(vector<int> arr, int n, int target)
{
    int ans = -1;
    int s = 0;
    int e = n - 1;
    int m = s + (e - s) / 2;
    while (s <= e)
    {
        if (arr[m] == target)
        {
            ans = m;
            e = m - 1;
        }
        else if (arr[m] < target)
        {
            s = m + 1;
        }
        else
        {
            e = m - 1;
        }
        m = s + (e - s) / 2;
    }
    return ans;
}

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
    cout << floor(arr, n, target) << " " << ceil(arr, n, target) << endl;
    return 0;
}