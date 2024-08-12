#include <bits/stdc++.h>
using namespace std;

void spell(int n, unordered_map<int, string> mp)
{
    if (n == 0)
        return;
    int digit = n % 10;
    n /= 10;
    spell(n, mp);
    cout << mp[digit] << " ";
}

int main()
{
    int n;
    cin >> n;
    if (n == 0)
    {
        cout << "zero" << endl;
        return 0;
    }
    unordered_map<int, string> mp;
    mp[0] = "zero";
    mp[1] = "one";
    mp[2] = "two";
    mp[3] = "three";
    mp[4] = "four";
    mp[5] = "five";
    mp[6] = "six";
    mp[7] = "seven";
    mp[8] = "eight";
    mp[9] = "nine";
    spell(n, mp);

    return 0;
}