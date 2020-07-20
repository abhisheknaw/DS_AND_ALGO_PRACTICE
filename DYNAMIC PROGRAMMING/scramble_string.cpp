#include <bits/stdc++.h>
using namespace std;
unordered_map<string,bool>mp;
bool scram(string a,string b)
{
	int i;
	int n=a.length();
	if(a.compare(b)==0)
	{
		return true;
	}
	if(n<=1)
	{
		return false;
	}
	string key=a+" "+b;
	if(mp.find(key)!=mp.end())
	{
		return mp[key];
	}
	bool result=false;
	for(i=1;i<=n-1;i++)
	{
		bool isswap=false; 
		bool noswap=false;
		if(scram(a.substr(0,i),b.substr(n-i,i)) && scram(a.substr(i,n-i),b.substr(0,n-i)))
		{
			isswap=true;

		}
		else if(scram(a.substr(0,i),b.substr(0,i)) && scram(a.substr(i,n-i),b.substr(i,n-i)))
		{
			noswap=true;
		}
		if(isswap || noswap)
		{
			result=true;
			break;
		}
	}
	mp[key]=result;
	return result;

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
	int x=a.length();
	int y=b.length();
	mp.clear();
	if(x!=y)
	{
		cout<<"false";
	}
	else if(a.empty() && b.empty())
	{
		cout<<"true";
	}
	else if(scram(a,b))
	{
		cout<<"true";
	}
	else
	{
		cout<<"false";
	}
	return 0;
}	