#include <bits/stdc++.h>
using namespace std;
void count_sort(int a[],int n,int b[],int k)
{
	int i,j,c[k];
	for(i=0;i<k;i++)
	{
		c[i]=0;
	}
	for(j=0;j<n;j++)
	{
		c[a[j]]=c[a[j]]+1;
	}
	for(i=1;i<k;i++)
	{
		c[i]=c[i]+c[i-1];
	}
	for(j=n-1;j>=0;j--)
	{
		b[c[a[j]]-1]=a[j];
		c[a[j]]=c[a[j]]-1;
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
	int n,i;
	cin>>n;
	int a[n],b[n];
	int k=10;
	for(i=0;i<n;i++)
	{
		cin>>a[i];
	}
	count_sort(a,n,b,k);
	for(i=0;i<n;i++)
	{
		cout<<b[i]<<" ";
	}
	return 0;
}	