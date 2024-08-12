#include <bits/stdc++.h>
using namespace std;

bool check_sorted(vector<int> v, int i)
{
    if (i == v.size())
        return true;
    return (v[i] >= v[i - 1]) && check_sorted(v, i + 1);
}

int main()
{
    int n;
    cin >> n;
    vector<int> v(n);
    for (int i = 0; i < n; i++)
    {
        cin >> v[i];
    }
    if (check_sorted(v, 1))
    {
        cout << "The array is sorted." << endl;
    }
    else
    {
        cout << "The array is not sorted." << endl;
    }
    return 0;
}