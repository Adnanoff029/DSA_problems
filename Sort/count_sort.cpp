// #include <iostream>
// #include <vector>
// #include<climits>
// using namespace std;
// int maxele(vector <int> &v, int n)
// {
//     int m=INT_MIN;
//     for(auto ele: v)
//     {
//         if(ele>m)
//         {
//             m=ele;
//         }
//     }
//     return m;
// }

// void merge_sort(vector<int> &v, vector<int> &c, int n)
// {
//     int v1[n];
//     for(int i=0; i<n; i++)
//     {
//         int key=v[n-1-i];
//         if(c[key]-1>=0)
//         {
//             v1[c[key]-1]=key;
//             c[key]-=1;
//         }
//     }
//     cout<<"Sorted Array: ";
//     for(int i=0; i<n; i++)
//     {
//         cout<<v1[i]<<" ";
//     }
// }

// void news(vector <int> &c, int m)
// {
//     for(int i=1; i<=m; i++)
//     {
//         c[i]+=c[i-1];
//     }
// }

// void count(vector<int> &v, int n)
// {
//     vector<int> c;
//     int m = maxele(v,n);
//     for(int i=0; i<=m; i++)
//     {
//         int f=0;
//         for(int j=0; j<n; j++)
//         {
//             if(v[j]==i)
//             {
//                 f++;
//             }
//         }
//         c.push_back(f);
//     }
//     cout<<"Count Array Before: ";
//     for(auto ele:c)
//     {
//         cout<<ele<<" ";
//     }
//     cout<<endl;
//     news(c,m);
//     cout<<"Count Array After: ";
//     for(auto ele:c)
//     {
//         cout<<ele<<" ";
//     }
//     cout<<endl;
//     merge_sort(v,c,n);
// }

// int main()
// {
//     int n;
//     cout<<"Enter the no. of elements to be entered: ";
//     cin >> n;
//     vector<int> v;
//     int input;
//     cout<<"Enter the elements: ";
//     for (int i = 0; i < n; i++)
//     {
//         cin >> input;
//         v.push_back(input);
//     }
//     count(v, n);
//     return 0;
// }

#include <iostream>
using namespace std;

void count_sort(int a[], int n)
{
    int k = a[0];
    for (int i = 0; i < n; i++)
    {
        k = max(k, a[i]);
    }
    int count[k] = {0};
    for (int i = 0; i < n; i++)
    {
        count[a[i]]++;
    }
    for (int i = 1; i <= k; i++)
    {
        count[i] += count[i - 1];
    }
    int output[n];
    for (int i = n - 1; i >= 0; i--)
    {
        output[--count[a[i]]] = a[i];
    }
    for (int i = 0; i < n; i++)
    {
        a[i] = output[i];
    }
}
int main()
{
    int n;
    cout << "Enter the no. of elements: ";
    cin >> n;
    int a[n];
    cout << "Enter array elements: ";
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    count_sort(a, n);
    cout<<"Sorted Array: ";
    for(int i=0; i<n; i++)
    {
        cout<<a[i]<<" ";
    }
    return 0;
}