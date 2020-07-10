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

    int i,j,n,W;
    cout<<"Enter the no. of elements: \n";
    cin>>n;
    cout<<"Enter the weight of knapsack: \n";
    cin>>W;

    int wt[n],val[n];

    for(i=0;i<n;i++)
    {
    	cin>>wt[i];
    }

    for(i=0;i<n;i++)
    {
    	cin>>val[i];
    }

    int t[n+1][W+1];

    for(i=0;i<n+1;i++)
    {
    	for(j=0;j<W+1;j++)
    	{
    		if(i==0 || j==0)
    		{
    			t[i][j]=0;
    		}
    	}
    }
    for(i=1;i<n+1;i++)
    {
    	for(j=1;j<W+1;j++)
    	{
    		if(wt[i-1]<=j)
    		{
    			t[i][j]=max(val[i-1]+t[i-1][j-wt[i-1]], t[i-1][j]);
    		}
    		else
    		{
    			t[i][j]=t[i-1][j];
    		}
    	}
    }
    cout<<t[n][W]<<"\n";

    return 0;
}