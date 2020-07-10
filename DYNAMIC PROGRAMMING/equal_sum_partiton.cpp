#include <bits/stdc++.h>
using namespace std;

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

    int sum=0,s,n,i,j;
    cout<<"enter no. of elements:\n";
    cin>>n;
    int arr[n];
    s=sum/2;
    int t[n+1][s+1];
    for(i=0;i<n;i++)
    {
    	cin>>arr[i];
    	sum=sum+arr[i];
    }
    if(sum%2 != 0)
    {
    	cout<<"given set cannot be divided into equal sum subset\n";
    }
    else
    {
 
    	for(i=0;i<n+1;i++)
    	{
    		t[i][0]=true;
    	}
    	for(j=1;j<s+1;j++)
    	{
    		t[0][j]=false;
    	}
    	for(i=1;i<n+1;i++)
    	{
    		for(j=1;j<s+1;j++)
    		{
    			if(arr[i-1]<=j)
    			{
    				bool x = t[i-1][j-arr[i-1]];
    			    bool y = t[i-1][j];
    			    t[i][j]= x||y;
    		    }
    		    else
    		    {
    		    	t[i][j]=t[i-1][j];
    		    }
    		}    
    	}
    	if(t[n][s])
    	{
    		cout<<"given set can be divided into equal sum subset";
    	}
    	else
    	{
    		cout<<"given set cannot be divided into equal sum subset";
    	}
    }
    return 0;
}