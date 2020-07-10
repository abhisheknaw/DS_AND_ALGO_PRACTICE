#include <bits/stdc++.h>
using namespace std;
bool mini(vector<int>&vec,int n, int s, vector<vector<int>>&t)
{
	if(s==0)
	{
		return true;
	}
	else if(s!=0 && n==0)
	{
		return false;
	}
	if(t[n][s]!=-1)
	{
		if(t[n][s])
		{
			
			return true;
		}
		else
		{
			
			return false;
		}
	}
	if(vec[n-1]<=s)
	{
		bool x =mini(vec,n-1,s-vec[n-1],t);
		bool y =mini(vec,n-1,s,t);
		if(x||y)
		{
			t[n][s]=1;
			return true;
		}
		else
		{
			t[n][s]=0;
			return false;
		}
	}
	else
	{
		if(mini(vec,n-1,s,t))
		{
			t[n][s]=1;
			return true;
		}
		else
		{
			t[n][s]=0;
			return false;
		}
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
    int n,s=0,i,mindiff= INT_MAX;
    cout<<"enter no of elements:\n";
    cin>>n;
    vector <int> vec(n);
        
    for(i=0;i<n;i++)
    {
    	cin>>vec[i];
    	s=s+vec[i];
    }	
    vector <vector<int>> t(n+1,vector<int>(s+1,-1));
    vector <int> v;
    for(i=0;i<(s/2);i++)
    {
    	if(mini(vec,n,i,t))
    	{
    		v.push_back(i);

    	}
    	
    }
    for(i=0;i<v.size();i++)
    {
    	mindiff=min(mindiff, s-2*v[i]);
    }
    cout<<mindiff;
    return 0;
}