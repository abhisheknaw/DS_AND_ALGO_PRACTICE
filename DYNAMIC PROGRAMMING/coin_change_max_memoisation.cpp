#include<bits/stdc++.h>
using namespace std;
int coin_change(vector<int>&coins,int n,int S,vector<vector<int>>&t)
{
	if(S==0)
	{
		t[n][S]=1;
		return t[n][S];
	}
	if(S!=0 && n==0)
	{
		t[n][S]=0;
		return t[n][S];
	}
	if(t[n][S] != -1)
	{
		return t[n][S];
	}
	if(coins[n-1] <= S)
	{
		int x = coin_change(coins,n,S-coins[n-1],t);
		int y = coin_change(coins,n-1,S,t);
		t[n][S] = x+y;
		return t[n][S];
	}
	else
	{
		t[n][S] = coin_change(coins,n-1,S,t);
		return t[n][S];
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
    int i,n,S,sol;
    cout<<"enter the no. of coins:\n";
    cin>>n;
    cout<<"enter the sum:\n";
    cin>>S;
    vector<int>coins(n);
    vector<vector<int>>t(n+1,vector<int>(S+1,-1));
    for(i=0;i<n;i++)
    {
    	cin>>coins[i];
    }
    sol=coin_change(coins,n,S,t);
    cout<<"number of ways we can do change:"<<sol;
    return 0;

}