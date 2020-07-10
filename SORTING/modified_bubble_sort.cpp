#include <bits/stdc++.h>

using namespace std;

void bubble_sort(int arr[],int n)
{
    int r ,temp=0,flag;
    for(r=1;r<=n-1;r++)
    {
        flag=0;
        for(int i=0;i<=n-1-r;i++)
        {
            if(arr[i]>arr[i+1])
            {
                flag=1;
                temp=arr[i];
                arr[i]=arr[i+1];
                arr[i+1]=temp;
            }
        }
        if(flag==0)
        {
            cout<<r<<"\n";
            break;
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

#ifndef ONLINE_JUDGE
    // for getting input from input.txt
    freopen("input.txt", "r", stdin);
    // for writing output to output.txt
    freopen("output.txt", "w", stdout);
#endif
    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
    }
    bubble_sort(arr,n);
    for(int i=0;i<n;i++)
    {
        cout<<arr[i]<<" ";
    }
    return 0;
}