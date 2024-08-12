#include <bits/stdc++.h>
using namespace std;

void stoi(string s, int i, int &ans, int n)
{
    if (n == -1)
        return;
    int a = s[n] - '0';
    ans += (a)*pow(10, i);
    stoi(s, i + 1, ans, n - 1);
}
int main()
{
    string s;
    cin >> s;
    int ans = 0;
    int n = s.size();
    stoi(s, 0, ans, n - 1);
    cout << ans << endl;
    return 0;
}