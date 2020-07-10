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
    int i,j,s=0,n,mindiff = INT_MAX;
    cout<<"enter the no of elements:\n";
    cin>>n;
    vector<int>vec(n);
    for(i=0;i<n;i++)
    {
    	cin>>vec[i];
    	s=s+vec[i];
    }	
    vector <vector<int>>t(n+1,vector<int>(s+1,-1));
    for(i=0;i<n+1;i++)
    {
    	t[i][0]=true;
    }
    for(j=1;j<s+1;j++)
    {
    	t[0][j]=false;
    }
    for(i=1;i<n+1;i++)
    {
    	for(j=1;j<s+1;j++)
    	{
    		if(vec[i-1]<=j)
    		{
    			t[i][j]=t[i-1][j-vec[i-1]] || t[i-1][j];
    		}
    		else
    		{
    			t[i][j]=t[i-1][j];
    		}
    	}
    }
    vector <int>v;
    for(j=0;j<(s/2);j++)
    {
    	if(t[n][j])
    	{
    		v.push_back(j);
    		
    	}
    }
    for(i=0;i<v.size();i++)
    {
    	int temp= s-2*(v[i]);
    	mindiff=min(mindiff, temp);
    }
    cout<<mindiff;
    
    return 0;

}