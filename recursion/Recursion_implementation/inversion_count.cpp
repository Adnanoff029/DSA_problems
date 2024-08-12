#include <bits/stdc++.h>
using namespace std;

int merge(vector<int> &array, int low, int high)
{
    int ans = 0;
    int mid = low + ((high - low) / 2);
    int i = low;
    int j = mid + 1;
    vector<int> v;
    while (i <= mid && j <= high)
    {
        if (array[i] > array[j])
        {
            v.push_back(array[j]);
            j++;
            ans += mid - i + 1;
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
    return ans;
}

int mergeSort(vector<int> &array, int low, int high)
{
    if (low >= high)
        return 0;
    int mid = low + ((high - low) / 2);
    int a = mergeSort(array, low, mid);
    int b = mergeSort(array, mid + 1, high);
    int c = merge(array, low, high);
    return a + b + c;
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
    int ans = mergeSort(array, 0, n - 1);
    cout << ans << endl;
    for (auto it : array)
    {
        cout << it << " ";
    }
    return 0;
}