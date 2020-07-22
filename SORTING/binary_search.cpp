#include<bits/stdc++.h>
using namespace std;
int search(int a[],int s,int e,int x)
{
    if(s<=e)
    {
        int mid=s+(e-s)/2;
        if(a[mid]==x)
        {
            return mid;
        }
        if(a[mid]>x)
        {
            return search(a,s,mid-1,x);
        }
        if(a[mid]<x)
        {
            return search(a,mid+1,e,x);
        }
    }
    return -1;
    
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
    int n,x;
    cin>>n;
    int a[n];
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
    }
    cin>>x;
    int res=search(a,0,n-1,x);
    if(res==-1)
    {
        cout<<"not found";
    }
    else
    {
        cout<<res;
    }
    return 0;
}