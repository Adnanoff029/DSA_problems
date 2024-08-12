#include <bits/stdc++.h>
using namespace std;

int find_power(int n, int a)
{
    if (a == 0)
    {
        return 1;
    }
    return n * find_power(n, a - 1);
}

int main()
{
    int n, a;
    cin >> n >> a;
    cout << find_power(n, a) << endl;
    return 0;
}