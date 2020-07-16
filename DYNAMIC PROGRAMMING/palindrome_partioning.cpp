#include <bits/stdc++.h>
using namespace std;
bool ispalindrome(string a,int i,int j)
{
	while(i<j)
	{
		if(a[i]!=a[j])
		{
			return false;
		}
		i++;
		j--;
	}
	return true;
}
int palindrome_partion(string a,int i,int j,vector<vector<int>>&t)
{
	if(i>=j)
	{
		t[i][j]=0;
		return t[i][j];
	}
	if(ispalindrome(a,i,j))
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
		int ans=palindrome_partion(a,i,k,t)+palindrome_partion(a,k+1,j,t)+1;
        if(ans<mn)
        {
        	mn=ans;
        }
	}
	t[i][j]=mn;
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
	string a;
	cin>>a;
	int n=a.length();
	vector<vector<int>>t(n+1,vector<int>(n+1,-1));
	int answer= palindrome_partion(a,0,n-1,t);
	cout<<answer;
	return 0;
}	