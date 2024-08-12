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
    if (n == 1)
    {
        cout << arr[0] << endl;
        return 0;
    }
    if (arr[0] != arr[1])
    {
        cout << arr[0] << endl;
        return 0;
    }
    if (arr[n - 1] != arr[n - 2])
    {
        cout << arr[n - 1] << endl;
        return 0;
    }
    int low = 0, high = n - 1;
    while (low <= high)
    {
        int mid = low + (high - low) / 2;
        if (arr[mid] != arr[mid - 1] && arr[mid] != arr[mid + 1])
        {
            cout << arr[mid] << endl;
            return 0;
        }
        if ((mid % 2 == 1 && arr[mid] == arr[mid - 1]) || (mid % 2 == 1 && arr[mid] == arr[mid + 1]))
        {
            low = mid + 1;
        }
        else
        {
            high = mid - 1;
        }
    }
    cout << -1 << endl;
    return 0;
}