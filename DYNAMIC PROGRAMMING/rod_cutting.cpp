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
    int i,j,L,n,sol;
    cout<<"enter no of items:\n";
    cin>>n;	
    cout<<"enter the length of rod:\n";
    cin>>L;
    vector<int>len(n);
    vector<int>price(n);
    vector<vector <int>>t(n+1,vector<int>(L+1,-1));
    for(i=0;i<n;i++)
    {
    	cin>>len[i];
    }
    for(i=0;i<n;i++)
    {
    	cin>>price[i];
    }    
    for (i=0;i<n+1;i++)
    {
    	for(j=0;j<L+1;j++)
    	{
    		if(i==0 || j==0)
    		{
    			t[i][j]=0;
    		}
        }
    
    }
    for(i=1;i<n+1;i++)
    {
    	for(j=1;j<L+1;j++)
    	{
    		if(len[i-1]<=j)
    		{
    			int x=t[i][j-len[i-1]]+price[i-1];
    			int y=t[i-1][j];
    			t[i][j]=max(x,y);
    		}
    		else
    		{
    			t[i][j]=t[i-1][j];
    		}
    	}
    }
    sol=t[n][L];
    cout<<sol;
    return 0;
}