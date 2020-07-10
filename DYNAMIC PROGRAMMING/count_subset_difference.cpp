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
    int i,j,n,sum=0,diff,so,sol;
    cout<<"enter no. of elements:\n";
    cin>>n;	
    cout<<"enter the diff:\n";
    cin>>diff;
    vector<int>vec(n);
    for(i=0;i<n;i++)
    {
    	cin>>vec[i];
    	sum=sum+vec[i];
    }

    if((sum+diff)%2 == 1)
    {
    	sol=0;

    }
    else
    {
    	so=(sum+diff)/2;
        vector<vector<int>>t(n+1,vector<int>(so+1));
    	for(i=0;i<n+1;i++)
    	{
    		t[i][0]=1;
    	}
    	for(j=1;j<so+1;j++)
    	{
    		t[0][j]=0;
    	}
    	for(i=1;i<n+1;i++)
    	{
    		for(j=1;j<so+1;j++)
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
    	sol=t[n][so];
    }
    cout<<sol;
    
    return 0;
}