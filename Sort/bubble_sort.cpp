#include<iostream>
using namespace std;

void bubble_sort(int a[], int n)
{
    for(int i=0; i<n-1;i++)
    {    
        for(int j=0; j<n-i-1; j++)
        {
            if(a[j]>a[j+1])
            {
                int temp=a[j];
                a[j]=a[j+1];
                a[j+1]=temp;
            }
            else continue;  
        }
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
    bubble_sort(a,n);
     cout<<"Sorted Array: ";
    for(int i=0; i<n; i++)
    {
        cout<<a[i]<<" ";
    }
    return 0;
}