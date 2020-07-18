#include <bits/stdc++.h>
using namespace std;
int t[101][101][2];
int solve(string &s,int i,int j,bool istrue)
{
	if(i>j)
	{
		return 0;
	}
	if(i==j)
	{
		if(istrue==true)
		{
			return (s[i]=='T');
		}
		else
		{
			return (s[i]=='F');
		}
	}
	if(t[i][j][istrue]!=-1)
	{
		return t[i][j][istrue];
	}
	int ans=0;
	
	for(int k=i+1;k<=j-1;k=k+2)
	{
		int lt,lf,rt,rf;
		if(t[i][k-1][1]!=-1)
		{
			lt=t[i][k-1][1];
		}
		else
		{
			lt=solve(s,i,k-1,true);
			t[i][k-1][1]=lt;			
		}
		if(t[i][k-1][0]!=-1)
		{
			lf=t[i][k-1][0];
		}
		else
		{
			lf=solve(s,i,k-1,false);
			t[i][k-1][0]=lf;			
		}
		if(t[k+1][j][1]!=-1)
		{
			rt=t[k+1][j][1];
		}
		else
		{
			rt=solve(s,k+1,j,true);
			t[k+1][j][1]=rt;			
		}
		if(t[k+1][j][0]!=-1)
		{
			rf=t[k+1][j][0];
		}
		else
		{
			rf=solve(s,k+1,j,false);
			t[k+1][j][0]=rf;			
		}
		if(s[k]=='&')
		{
			if(istrue==true)
			{
				ans=ans+lt*rt;
			}
			else
			{
				ans=ans+lt*rf+lf*rt+rf*lf;
			}
		}	
		else if(s[k]=='|')
		{
			if(istrue==true)
			{
				ans=ans+lt*rt+lt*rf+lf*rt;
			}
			else
			{
				ans=ans+lf*rf;
			}
		}
		else if(s[k]=='^')
		{
			if(istrue==true)
			{
				ans=ans+lt*rf+lf*rt;
			}
			else
			{
				ans=ans+lt*rt+rf*lf;
			}
		}												
	}
	t[i][j][istrue]=ans;
	return ans;
	
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
	string s;
	cin>>s;
	int n=s.length();
	memset(t,-1,sizeof(t));
	int result=solve(s,0,n-1,true);
	cout<<result;
	return 0;
}	
