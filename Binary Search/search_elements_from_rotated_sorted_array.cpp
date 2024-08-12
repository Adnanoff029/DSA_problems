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
    bool f = 1;
    while (low <= high)
    {
        int mid = low + (high - low) / 2;
        if (arr[mid] == target)
        {
            f = 0;
            cout << "Target is at: " << mid << endl;
            break;
        }
        // If the list contains Duplicates
        if (arr[mid] == arr[low] && arr[mid] == arr[high])
        {
            low++;
            high--;
            continue;
        }
        // Left Sorted
        if (arr[mid] >= arr[low])
        {
            if (arr[low] <= target && arr[mid] >= target)
            {
                // Target exists in the left sorted array
                high = mid - 1;
            }
            else
            {
                low = mid + 1;
            }
        }
        // Right Sorted
        else
        {
            if (arr[mid] <= target && arr[high] >= target)
            {
                // Target exists in the right sorted array
                low = mid + 1;
            }
            else
            {
                high = mid - 1;
            }
        }
    }
    if (f)
    {
        cout << "Target not found.";
    }
    return 0;
}