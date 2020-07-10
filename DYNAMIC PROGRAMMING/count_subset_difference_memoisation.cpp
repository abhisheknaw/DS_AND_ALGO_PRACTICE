#include <bits/stdc++.h>
using namespace std;

int sub_count(vector<int>&vec,int so,int n,vector<vector<int>>&t)
{
	if(so==0)
	{

		return 1;
	}
	if(so!=0 && n==0)
	{
	
		return 0;
	}
	if(t[n][so]!=-1)
	{
		return t[n][so];
	}
	if(vec[n-1]<=so)
	{
		t[n][so]=sub_count(vec,so-vec[n-1],n-1,t)+sub_count(vec,so,n-1,t);
		return t[n][so];
	}
	else
	{
		t[n][so]=sub_count(vec,so,n-1,t);
		return t[n][so];
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
    int i,n,so,sum=0,diff,count;
    cout<<"enter no. of elememnts:\n";
    cin>>n;
    cout<<"enter the given diff:\n";
    cin>>diff;
    vector<int>vec(n);
    for(i=0;i<n;i++)
    {
    	cin>>vec[i];
    	sum=sum+vec[i];
    }
    
    if((sum+diff)%2==1)
    {
    	cout<<0;
    }
    else
    {
    	so=(sum+diff)/2;
    	vector<vector<int>> t(n+1,vector<int>(so+1,-1));
        count=sub_count(vec,so,n,t);
        cout<<count;
    } 
    
    return 0;


}