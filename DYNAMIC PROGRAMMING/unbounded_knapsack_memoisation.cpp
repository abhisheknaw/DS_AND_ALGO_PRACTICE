#include<bits/stdc++.h>
using namespace std;
int unbounded(vector<int>&wt,vector<int>&val,int n,int W,vector<vector<int>>&t)
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
	if(wt[n-1] <= W)
	{
		int x = unbounded(wt,val,n,W-wt[n-1],t)+val[n-1];
		int y = unbounded(wt,val,n-1,W,t);
		t[n][W] = max(x,y);
		return t[n][W];
	}
	else
	{
		t[n][W] = unbounded(wt,val,n-1,W,t);
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
    int i,n,W,sol;
    cout<<"enter the no. of elments:\n";
    cin>>n;
    cout<<"enter the wt of knapsack:\n";
    cin>>W;
    vector<int>wt(n);
    vector<int>val(n);
    vector<vector<int>>t(n+1,vector<int>(W+1,-1));
    for(i=0;i<n;i++)
    {
    	cin>>wt[i];
    }
    for(i=0;i<n;i++)
    {
    	cin>>val[i];
    }
    sol=unbounded(wt,val,n,W,t);
    cout<<sol;
    return 0;

}