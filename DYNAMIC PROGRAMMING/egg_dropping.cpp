#include <bits/stdc++.h>
using namespace std;
int drop(int e,int f,vector<vector<int>>&t)
{
	int i;
	if(f==0 || f==1)
	{
		return f;
	}
	if(e==1)
	{
		return f;
	}
	if(t[e][f]!=-1)
	{
		return t[e][f];
	}
	int answer=INT_MAX;
	for(i=1;i<=f;i++)
	{
		int temp=1+max(drop(e-1,i-1,t),drop(e,f-i,t));
		answer=min(temp,answer);
	}
	t[e][f]=answer;
	return answer;
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
	int e,f;
	cout<<"enter no of floor"<<"\n";
	cin>>f;
	cout<<"enter no of egg"<<"\n";
	cin>>e;
	vector<vector<int>>t(e+1,vector<int>(f+1,-1));
	int result=drop(e,f,t);
	cout<<result;
	return 0;
}