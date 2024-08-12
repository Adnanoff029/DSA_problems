#include<iostream>
using namespace std;
void insertion_sort(int a[], int n)
{
    int key, i,j;
    for(i=1; i<n; i++)
    {
        key=a[i];
        j=i-1;
        while(j>=0 && a[j]>key)
        {
            a[j+1]=a[j];
            j--;
        }
        a[j+1]=key;
    }
}
int main()
{
    int n;
    cout<<"Enter the no. of elements you want to enter: ";
    cin>>n;
    int a[n];
    cout<<"Enter elements: ";
    for(int i=0; i<n; i++)
    {
        cin>>a[i];
    }
    cout<<"Unsorted Array: ";
    for(int i=0; i<n; i++)
    {
        cout<<a[i]<<" ";
    }
    cout<<endl;
    insertion_sort(a,n);
    cout<<"Sorted Array: ";
    for(int i=0; i<n; i++)
    {
        cout<<a[i]<<" ";
    }
    return 0;
}