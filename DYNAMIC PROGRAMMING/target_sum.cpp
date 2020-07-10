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
	int ts,n,i,j,s=0,sol,range;
	cin>>n;
	cout<<"enter the target sum:\n";
	cin>>ts;
	vector<int>vec(n);
	for(i=0;i<n;i++)
	{
		cin>>vec[i];
		s=s+vec[i];

	}
	if((ts+s)%2 == 1)
	{
		sol=0;
	}
	else
	{
		range=(s+ts)/2;
		vector<vector<int>>t(n+1,vector<int>(range+1,-1));
		for(i=0;i<n+1;i++)
		{
			t[i][0]=1;
		}
		for(j=1;j<range+1;j++)
		{
			t[0][j]=0;		
		}
		for(i=1;i<n+1;i++)
		{
			for(j=1;j<range+1;j++)
			{
				if(vec[i-1]<=j)
				{
					t[i][j]=t[i-1][j-vec[i-1]]+t[i-1][j];
				}
				else
				{
					t[i][j]=t[i-1][j];
				}
			} 
	    }
	    sol=t[n][range];

	}
	cout<<sol;
	return 0;

}