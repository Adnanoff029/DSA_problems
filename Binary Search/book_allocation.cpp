#include <bits/stdc++.h>
using namespace std;

int canSplit(vector<int> arr, long long int mid)
{
    long long int sum = 0;
    int l = 1;
    for (int i = 0; i < arr.size(); i++)
    {
        if (arr[i] + sum <= mid)
        {
            sum += arr[i];
        }
        else
        {
            l++;
            sum = arr[i];
        }
    }
    return l;
}
int findPages(vector<int> &arr, int n, int m)
{
    if (m > n)
        return -1;
    int low = *max_element(arr.begin(), arr.end());
    int high = accumulate(arr.begin(), arr.end(), 0);
    // long long int ans = INT_MAX;
    while (low <= high)
    {
        int mid = low + (high - low) / 2;
        int studs = canSplit(arr, mid);
        if (studs > m)
        {
            low = mid + 1;
        }
        else
        {
            high = mid - 1;
        }
    }
    return low;
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
    int m;
    cin >> m;
    cout << findPages(arr, n, m) << endl;
    return 0;
}