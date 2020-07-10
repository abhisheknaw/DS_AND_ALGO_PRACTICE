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
	
	cin>>x>>y;
	int m=x.length();
	int n=y.length();
	vector<vector<int>>t(m+1,vector<int>(n+1,-1));
	for(int i=0;i<=m;i++)
	{
		for(int j=0;j<=n;j++)
		{
			if(i==0 || j==0)
			{
				t[i][j]=0;
			}
		}
	}
	for(int i=1;i<=m;i++)
	{
		for(int j=1;j<=n;j++)
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
	string s= "";
	int i=m,j=n;
	while(i>0 && j>0)
	{
		if(x[i-1] == y[j-1])
		{
			s.insert(s.begin(),x[i-1]);
			i--;
			j--;
		}
		else
		{
			if(t[i][j-1]>t[i-1][j])
			{
				j--;
			}
			else
			{
				i--;
			}
		}
	}
	cout<<s;
	return 0;
}	

