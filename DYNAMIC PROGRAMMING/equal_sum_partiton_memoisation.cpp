#include <bits/stdc++.h>
using namespace std;
int t[100][100];

bool equal_partition(int arr[], int n, int s)
{
	if(s==0)
	{
		return true;
	}
	if(n==0 && s!=0)
	{
		return false;
	}
	if(t[n][s]!=-1)
	{
		if(t[n][s])
		{
			return true;
		}
		else
		{
			return false;
		}
	}
	if(arr[n-1]<=s)
	{
		bool x=equal_partition(arr,n,s-arr[n-1]);
		bool y=equal_partition(arr,n-1,s);
		if(x||y)
		{
			t[n][s]=1;
			return t[n][s];
		}
		else
		{
			t[n][s]=0;
			return t[n][s];
		}
	}
	else
	{
		if(equal_partition(arr,n-1,s))
		{
			t[n][s]=1;
			return t[n][s];
		}
		else
		{
			t[n][s]=0;
			return t[n][s];
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
        int n,i,sum=0,s;
        memset(t,-1,sizeof(t));
        cout<<"enter no. of elements:\n";
        cin>>n;
        int arr[n];
        for(i=0;i<n;i++)
        {
        	cin>>arr[i];
        	sum=sum+arr[i];
        }
        s=sum/2;
        if(sum%2 !=0)
        {
        	cout<<"false";
        }
        else
        {
        	bool sol=equal_partition(arr,n,s);
        	if(sol)
        	{
        		cout<<"true";
        	}
        	else
        	{
        		cout<<"false";
        	}

        }
        return 0;

	}
