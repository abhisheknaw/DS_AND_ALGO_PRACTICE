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
	string x,y;
	cin>>x;
	cin>>y;
	int m=x.length();
	int n=y.length();
	vector<vector<int>>t(m+1,vector<int>(n+1,-1));
	int i,j;
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
			if(x[i-1]==y[j-1])
			{
				t[i][j]=1+t[i-1][j-1];
			}
			else
			{
				int first=t[i][j-1];
				int second=t[i-1][j];
				t[i][j]=max(first,second);
			}
		}
	}
	if(t[m][n]==m)
	{
		cout<<"true";
	}
	else
	{
		cout<<"false";
	}
	return 0;
}