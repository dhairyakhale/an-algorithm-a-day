#include<iostream>
using namespace std;

int merge(int arr[], int f, int m, int l)
{
    int n1 = m-f+1;
    int n2 = l-m;

    int a1[n1],a2[n2];
    for(int i=0;i<=n1;i++)
    {
        a1[i]=arr[f+i];
    }
    for(int i=0;i<=n2;i++)
    {
        a2[i]=arr[m+1+i];
    }

    int i=0,j=0,k=f;
    while(i<n1 || j<n2)
    {
        if(i>=n1)
        {
            arr[k]=a2[j];
            j++;
        }
        else if(j>=n2)
        {
            arr[k]=a1[i];
            i++;
        }
        else if(a1[i]<a2[j])
        {
            arr[k]=a1[i];
            i++;
        }
        else if(a1[i]>=a2[j])
        {
            arr[k]=a2[j];
            j++;
        }
        k++;
    }
}

void mergesort(int arr[], int f, int l)
{
    int m;
    if(f<l)
    {
        m = (f+l)/2;
        mergesort(arr, f, m);
        mergesort(arr, m+1, l);
        merge(arr,f,m,l);
    }
}

int main()
{
    int n;
    cout<<"Enter n: "; cin>>n;

    int a[n];
    for(int i=0;i<n;i++)
    {
        cout<<"Enter element: "; cin>>a[i];
    }

    mergesort(a, 0, n-1);

    for(int i=0;i<n;i++)
    {
        cout<<a[i]<<" ";
    }
}