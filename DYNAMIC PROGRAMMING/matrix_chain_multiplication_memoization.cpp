#include <bits/stdc++.h>
using namespace std;
int solve(vector<int>&arr,int i,int j,vector<vector<int>>&t)
{
	if(i>=j)
	{
		t[i][j]=0;
		return t[i][j];
	}
	if(t[i][j]!=-1)
	{
		return t[i][j];
	}
	int mn=INT_MAX;
	for(int k=i;k<=j-1;k++)
	{
		int temp_ans=solve(arr,i,k,t)+solve(arr,k+1,j,t)+arr[i-1]*arr[k]*arr[j];
        if(temp_ans<mn)
        {
        	mn=temp_ans;
        }
        t[i][j]=mn; 
	}
	return t[i][j];

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
	int n,i;
	cin>>n;
	vector<int>arr(n);
	for(i=0;i<n;i++)
	{
		cin>>arr[i];
	}
	vector<vector<int>>t(n+1,vector<int>(n+1,-1));
	int answer=solve(arr,1,n-1,t);
	cout<<answer;
	return 0;
}	
