#include <bits\stdc++.h>
using namespace std;
int lcs(string x, string y, int m, int n, vector<vector <int>>&t)
{
	if(m==0 || n==0)
	{
		t[m][n]=0;
		return t[m][n];
	}
	if(t[m][n]!=-1)
	{
		return t[m][n];
	}
	if(x[m-1] == y[n-1])
	{
		t[m][n]=1+lcs(x,y,m-1,n-1,t);
		return t[m][n];
	}
	else
	{
		int a= lcs(x,y,m-1,n,t);
		int b= lcs(x,y,m,n-1,t);
		t[m][n]= max(a,b);
		return t[m][n];
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
	string x,y;
	cin>>x>>y;

	int m= x.length();
	int n= y.length();

	vector<vector<int>>t(m+1,vector<int>(n+1,-1));

	int answer;
	lcs(x,y,m,n,t);
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