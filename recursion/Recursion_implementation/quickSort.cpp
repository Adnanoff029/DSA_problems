#include <bits/stdc++.h>
using namespace std;

int pivot(vector<int> &arr, int start, int end)
{
    int p = arr[end];
    int j = start - 1;
    for (int i = start; i < end; i++)
    {
        if (arr[i] <= p)
        {
            j++;
            swap(arr[j], arr[i]);
        }
    }
    swap(arr[j + 1], arr[end]);
    
    return j + 1;
}

void quickSort(vector<int> &arr, int start, int end)
{
    if (start >= end)
        return;
    int pi = pivot(arr, start, end);
    quickSort(arr, start, pi - 1);
    quickSort(arr, pi + 1, end);
}

int main()
{
    int n;
    cin >> n;
    vector<int> array(n);

    for (int i = 0; i < n; i++)
    {
        cin >> array[i];
    }

    quickSort(array, 0, n - 1);

    for (auto it : array)
    {
        cout << it << " ";
    }
    return 0;
}