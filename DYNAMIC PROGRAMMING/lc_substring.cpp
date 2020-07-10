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
	int i,j;
	string x,y;
	cin>>x>>y;
	int m= x.length();
	int n= y.length();
	vector<vector<int>>t(m+1,vector<int>(n+1,-1));
	for(i=0;i<m+1;i++)
	{
		for(j=0;j<n+1;j++)
		{
			if(i==0 || j==0)
			{
				t[i][j]=0;
			}
		}
	}
    for(i=1;i<m+1;i++)
    {
    	for(j=1;j<n+1;j++)
    	{
    		if(x[i-1] == y[j-1])
    		{
    			t[i][j] = 1+t[i-1][j-1];
    		}
    		else
    		{
    			t[i][j]=0;

    		}
    	}
    }
    int result =0;
    for(i=1;i<m+1;i++)
    {
    	for(j=1;j<n+1;j++)
    	{
    		result=max(result,t[i][j]);
    	}
    }
  
    cout<<result;
    return 0;
}