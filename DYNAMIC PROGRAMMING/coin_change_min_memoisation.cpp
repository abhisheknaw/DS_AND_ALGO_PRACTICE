#include<bits/stdc++.h>
using namespace std;
int coin_change_min(vector<int>&coins,int n,int S,vector<vector<int>>&t)
{
	if(n==0)
	{
		t[n][S]=INT_MAX-1;
		return t[n][S];
	}
	if(n!=0 && S==0)
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
		int x = coin_change_min(coins,n,S-coins[n-1],t);
		int y = coin_change_min(coins,n-1,S,t);
		t[n][S] = min(x+1,y);
		return t[n][S];
	}
	else
	{
		t[n][S] = coin_change_min(coins,n-1,S,t);
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
    sol=coin_change_min(coins,n,S,t);
    cout<<"minimum number of coins required are:"<<sol;
    return 0;

}