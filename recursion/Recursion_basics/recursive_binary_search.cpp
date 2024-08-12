#include <bits/stdc++.h>
using namespace std;

int binary_search1(vector<int> v, int start, int end, int num)
{
    if (start <= end)
    {
        int mid = start + ((end - start) >> 1);
        if (v[mid] == num)
        {
            return mid;
        }
        if (v[mid] < num)
        {
            return binary_search1(v, mid, end, num);
        }

        return binary_search1(v, start, mid, num);
    }
    return -1;
}

int main()
{
    int n, num;
    cin >> n >> num;
    vector<int> v(n);
    for (int i = 0; i < n; i++)
    {
        cin >> v[i];
    }
    int idx = binary_search1(v, 0, n - 1, num);
    if (idx == -1)
    {
        cout << "Element not found" << endl;
    }
    else
    {
        cout << "Element found at index " << idx << endl;
    }
    return 0;
}