#include <bits/stdc++.h>
using namespace std;

// Decreaseing recursion
void print_nos_decreasing(int n)
{
    if (n == 1)
    {
        cout << 1 << " ";
        return;
    }
    cout << n << " ";
    print_nos_decreasing(n - 1);
}

void print_nos_increasing(int n)
{
    if (n == 0)
        return;
    print_nos_increasing(n - 1);
    cout << n << " ";
    return;
}

int main()
{
    int n;
    cin >> n;
    print_nos_decreasing(n);
    cout << endl;
    print_nos_increasing(n);
    return 0;
}