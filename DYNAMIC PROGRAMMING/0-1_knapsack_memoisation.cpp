#include <bits/stdc++.h>
using namespace std;

    int t[100][100];
	

int knapsack(int wt[], int val[], int W, int n)
{
    
	if(n==0 || W==0)
	{
		t[n][W]=0;
		return t[n][W];
	}

	if(t[n][W] != -1)
	{
		return t[n][W];
	}

	if(wt[n-1]>W)
	{
		t[n][W] = knapsack(wt, val, W, n-1);
		return t[n][W];
	}

	else
	{
		t[n][W] = max(val[n-1]+knapsack(wt, val, W-wt[n-1], n-1),
			   knapsack(wt, val, W, n-1));
		return t[n][W];
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
	int n, W, i, sol;
	

    cout<<"Enter no of input.\n";
    cin>>n;
    cout<<"Enter weight of Knapsack.\n";
    cin>>W;
    
    memset(t,-1,sizeof(t));
    int wt[n], val[n];

    for(i=0;i<n;i++)
    {
    	cin>>wt[i];
    }
    for(i=0;i<n;i++)
    {
    	cin>>val[i];
    }
    sol=knapsack(wt, val, W, n);

    cout<<sol<<"\n";
    return 0;


}