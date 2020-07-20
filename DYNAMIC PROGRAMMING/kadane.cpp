#include<bits/stdc++.h>
using namespace std;
int kadane(int arr[],int n)
{
    int count=0,i;
    int res=INT_MIN;
    for(i=0;i<n;i++)
    {
        count=count+arr[i];
        if(count<0)
        {
            count=0;
        }
        if(count> res)
        {
            res=count;
        }
    }
    return res;
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
    int i,n;
    cin>>n;
    int arr[n];
    for(i=0;i<n;i++)
    {
        cin>>arr[i];
    }
    int result=kadane(arr,n);
    cout<<result;
    return 0;
}