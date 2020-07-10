#include <bits/stdc++.h>
using namespace std;
void insertion_sort(int arr[],int n)
{
	int j;
	for(int i=1;i<n;i++)
	{
		int temp=arr[i];
		for(j=i-1;j>=0 && temp<arr[j];j--)
		{
			arr[j+1]=arr[j];
		}
		arr[j+1]=temp;
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
	int n;
	cin>>n;
	int arr[n];
	for(int i=0;i<n;i++)
	{
		cin>>arr[i];
	}
	insertion_sort(arr,n);
	for(int i=0;i<n;i++)
	{
		cout<<arr[i]<<" ";
	}
	return 0;
}	