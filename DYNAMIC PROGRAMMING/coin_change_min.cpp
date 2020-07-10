#include<bits/stdc++.h>
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
	int i,j,n,S;
	cin>>n>>S;
	vector<int>coins(n);
	vector<vector<int>>t(n+1,vector<int>(S+1));
	for(i=0;i<n;i++)
	{
		cin>>coins[i];
	}
	for(i=1;i<n+1;i++)
	{
		t[i][0]=0;
	}
	for(j=0;j<S+1;j++)
	{
		t[0][j]=INT_MAX-1;
	}
	for(i=1;i<n+1;i++)
	{
		for(j=1;j<S+1;j++)
			if(coins[i-1]<=j)
			{
				t[i][j]=min(t[i][j-coins[i-1]]+1,t[i-1][j]);
			}
			else
			{
				t[i][j]=t[i-1][j];
			}
	}
	cout<<"minimum number of coins required are:"<<t[n][S];
	return 0;
}	