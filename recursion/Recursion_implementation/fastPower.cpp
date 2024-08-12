#include <bits/stdc++.h>
using namespace std;

int fastPower(int n, int a)
{
    if (a == 0)
        return 1;

    int smaller_problem = fastPower(n, a / 2);
    smaller_problem *= smaller_problem;

    if (a % 2 == 1)
    {
        return smaller_problem * n;
    }
    return smaller_problem;
}

int main()
{
    int n, a;
    cin >> n >> a;
    cout << fastPower(n, a) << endl;
    return 0;
}