#include <bits/stdc++.h>
using namespace std;

int lastOccurence(vector<int> v, int i, int key)
{
    if (i == -1)
        return -1;
    if (v[i] == key)
        return i;
    return lastOccurence(v, i - 1, key);
}

int main()
{
    int n, key;
    cin >> n >> key;
    vector<int> v(n);
    for (int i = 0; i < n; i++)
    {
        cin >> v[i];
    }
    int idx = lastOccurence(v, n - 1, key);
    if (idx == -1)
    {
        cout << "Element not found." << endl;
    }
    else
    {
        cout << "Element was last found at index " << idx << endl;
    }
    return 0;
}