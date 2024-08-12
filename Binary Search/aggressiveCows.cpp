#include <bits/stdc++.h>
using namespace std;

bool canWePlace(vector<int>stalls, int k, int dis)
{
    int cnt = 1, last = stalls[0];
    for(int i = 1; i < stalls.size(); i++)
    {
        if(stalls[i] - last >= dis)
        {
            cnt++;
            last = stalls[i];
        } 
        if(cnt >= k) return true;
    }
    return false;
}
int aggressiveCows(vector<int> &stalls, int k)
{
    //    Write your code here.
    int n = stalls.size();
    sort(stalls.begin(), stalls.end());
    int low = 1;
    int high = stalls[n-1] - stalls[0];
    int ans;
    while(low <= high)
    {
        int mid = low + (high - low)/2;
        if(canWePlace(stalls, k, mid))
        {
            ans = mid;
            low = mid + 1;
        }
        else
        {
            high = mid - 1;
        }
    }
    return ans;
}

int main()
{
    int n;
    cin >> n;
    vector<int>stalls(n, 0);
    for(int i = 0; i < n; i++)
    {
        cin >> stalls[i];
    }
    int k;
    cin >> k;
    cout<< aggressiveCows(stalls, k) <<endl;
    return 0;
}