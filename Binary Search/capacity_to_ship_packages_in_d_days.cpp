#include <bits/stdc++.h>
using namespace std;

int shipWithinDays(vector<int> &weights, int days)
{
    int n = weights.size();
    int low = *max_element(weights.begin(), weights.end());
    int high = accumulate(weights.begin(), weights.end(), 0);
    // int ans = INT_MAX;
    while (low <= high)
    {
        int mid = low + (high - low) / 2;
        int x = 1;
        int sum = 0;
        for (int i = 0; i < n; i++)
        {
            if (sum + weights[i] > mid)
            {
                x++;
                sum = weights[i];
            }
            else
            {
                sum += weights[i];
            }
        }

        if (x <= days)
        {
            // ans = min(ans, mid);
            high = mid - 1;
        }
        else
        {
            low = mid + 1;
        }
    }
    return low;
}

int main()
{
    int n;
    cin >> n;
    vector<int> weights(n, 0);
    for (int i = 0; i < n; i++)
    {
        cin >> weights[i];
    }
    int days;
    cin >> days;
    cout << shipWithinDays(weights, days) << endl;
    return 0;
}