#include<bits/stdc++.h>
using namespace std;
int rod_cutting(vector<int>&len,vector<int>&price,int n,int L,vector<vector<int>>&t)
{
	if(n==0 || L==0)
	{
		t[n][L]=0;
		return t[n][L];
	}
	if(t[n][L] != -1)
	{
		return t[n][L];
	}
	if(len[n-1] <= L)
	{
		int x = rod_cutting(len,price,n,L-len[n-1],t)+price[n-1];
		int y = rod_cutting(len,price,n-1,L,t);
		t[n][L] = max(x,y);
		return t[n][L];
	}
	else
	{
		t[n][L] = rod_cutting(len,price,n-1,L,t);
		return t[n][L];
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
    int i,n,L,sol;
    cout<<"enter the no. of elments:\n";
    cin>>n;
    cout<<"enter the length of rod:\n";
    cin>>L;
    vector<int>len(n);
    vector<int>price(n);
    vector<vector<int>>t(n+1,vector<int>(L+1,-1));
    for(i=0;i<n;i++)
    {
    	cin>>len[i];
    }
    for(i=0;i<n;i++)
    {
    	cin>>price[i];
    }
    sol=rod_cutting(len,price,n,L,t);
    cout<<sol;
    return 0;

}