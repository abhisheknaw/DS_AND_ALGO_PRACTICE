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
    int i,j,S,n;
    cout<<"enter no of items:\n";
    cin>>n;	
    cout<<"enter the sum:\n";
    cin>>S;
    vector<int>coins(n);
    vector<vector <int>>t(n+1,vector<int>(S+1));
    for(i=0;i<n;i++)
    {
    	cin>>coins[i];
    }    
    for (i=0;i<n+1;i++)
    {
        t[i][0]=1;
    }
    for(j=1;j<S+1;j++)
    {
        t[0][j]=0;
    }
    for(i=1;i<n+1;i++)
    {
    	for(j=1;j<S+1;j++)
    	{
    		if(coins[i-1]<=j)
    		{
    			t[i][j]=t[i][j-coins[i-1]]+t[i-1][j];
    		}
    		else
    		{
    			t[i][j]=t[i-1][j];
    		}
    	}
    }
    cout<<"number of ways we can do change:"<<t[n][S];
    return 0;
}