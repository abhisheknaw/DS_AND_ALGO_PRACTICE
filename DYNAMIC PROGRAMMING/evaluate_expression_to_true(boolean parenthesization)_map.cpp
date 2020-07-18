#include <bits/stdc++.h>
using namespace std;
unordered_map<string,int>mp;
int solve(string s,int i,int j,bool istrue)
{
	int k;
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
	string temp=to_string(i);
	temp.append(to_string(j));
	temp.append(to_string(istrue));
	if(mp.find(temp)!=mp.end())
	{
		return mp[temp];
	}
	int ans=0;
	for(k=i+1;k<=j-1;k++)
	{
		int lt,lf,rt,rf;
		lt=solve(s,i,k-1,true);
		lf=solve(s,i,k-1,false);
		rt=solve(s,k+1,j,true);
		rf=solve(s,k+1,j,false);
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
	mp[temp]=ans;
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
	mp.clear();
	int answer=solve(s,0,n-1,true);
	cout<<answer;
	return 0;
}	