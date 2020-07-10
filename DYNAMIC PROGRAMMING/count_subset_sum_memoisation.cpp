#include <bits/stdc++.h>
using namespace std;
int t[100][100];

int subset_count(int arr[], int n, int sum)
{
	if(sum==0)
	{
		return 1;
	}
	if(sum!=0 && n==0)
	{
		return 0;
	}
	if(t[n][sum]!=-1)
	{
		return t[n][sum];
	}
	if(arr[n-1]<=sum)
	{
		t[n][sum]=subset_count(arr,n-1,sum-arr[n-1])+subset_count(arr,n-1,sum);
		return t[n][sum];
	}
	else
	{
		t[n][sum]=subset_count(arr,n-1,sum);
		return t[n][sum];
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
	int i,n,sum,sol;
	memset(t,-1,sizeof(t));
	cout<<"enter no. of elements:\n";
	cin>>n;
	cout<<"enter the sum:\n";
	cin>>sum;
	int arr[n];
    for(i=0;i<n;i++)
    {
    	cin>>arr[i];
    }
    sol=subset_count(arr,n,sum);
    cout<<"count of subset:"<<sol;

}