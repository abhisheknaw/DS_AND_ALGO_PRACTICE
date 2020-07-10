#include <bits/stdc++.h>
using namespace std;
void selection_sort(int arr[],int n)
{
	for(int k=0;k<n-1;k++)
	{
		int min=arr[k];
		int loc=k;
		for(int j=k+1;j<n;j++)
		{
			if(min>arr[j])
			{
				min=arr[j];
				loc=j;
			}
		}	
		int temp=arr[k];
		arr[k]=arr[loc];
		arr[loc]=temp;		
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
	int arr[n];
	for(i=0;i<n;i++)
	{
		cin>>arr[i];
	}
	selection_sort(arr,n);
	for(i=0;i<n;i++)
	{
		cout<<arr[i]<<" ";
	}
	return 0;
}	