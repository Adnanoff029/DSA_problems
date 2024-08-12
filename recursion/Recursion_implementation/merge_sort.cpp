#include <bits/stdc++.h>
using namespace std;

void merge(vector<int> &array, int low, int high)
{
    int mid = low + ((high - low) / 2);
    int i = low;
    int j = mid + 1;
    vector<int>v;
    while (i <= mid && j <= high)
    {
        if (array[i] > array[j])
        {
            v.push_back(array[j]);
            j++;
        }
        else
        {
            v.push_back(array[i]);
            i++;
        }
    }

    while (i <= mid)
    {
        v.push_back(array[i]);
        i++;
    }

    while (j <= high)
    {
        v.push_back(array[j]);
        j++;
    }

    for (int k = 0; k < v.size(); k++)
    {
        array[low + k] = v[k];
    }
}

void mergeSort(vector<int> &array, int low, int high)
{
    if (low >= high)
        return;
    int mid = low + ((high - low) / 2);
    mergeSort(array, low, mid);
    mergeSort(array, mid + 1, high);
    merge(array, low, high);
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
    mergeSort(array, 0, n - 1);
    for (auto it : array)
    {
        cout << it << " ";
    }
    return 0;
}