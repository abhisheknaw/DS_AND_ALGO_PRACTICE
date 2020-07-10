#include <bits/stdc++.h>
using namespace std;
int lcs(string a,string b,int m,int n,vector<vector<int>>&t)
{
	if(m==0||n==0)
	{
		t[m][n]=0;
		return t[m][n];
	}
	if(t[m][n]!=0)
	{
		return t[m][n];
	}
	if(a[m-1]==b[n-1])
	{
		t[m][n]=lcs(a,b,m-1,n-1,t)+1;
		return t[m][n];
	}
	else
	{
		int first=lcs(a,b,m,n-1,t);
		int second=lcs(a,b,m-1,n,t);
		t[m][n]=max(first,second);
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
	string a,b;
	cin>>a>>b;
	int m=a.length();
	int n=b.length();
	vector<vector<int>>t(m+1,vector<int>(n+1));
	string s=" ";
	lcs(a,b,m,n,t);
	int i=m;
	int j=n;
	while(i>0 && j>0)
	{
		if(a[i-1]==b[j-1])
		{
			s.insert(s.begin(),a[i-1]);
			i--;
			j--;
		}
		else
		{
			if(t[i][j-1]>t[i-1][j])
			{
				s.insert(s.begin(),b[j-1]);
				j--;
			}
			else
			{
				s.insert(s.begin(),a[i-1]);
				i--;
			}
		}
	}
	while(i>0)
	{
		s.insert(s.begin(),a[i-1]);
		i--;
	}
	while(j>0)
	{
		s.insert(s.begin(),b[j-1]);
		j--;
	}
	cout<<s;
	return 0;
}	