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

	int n,SUM,i,j;
	cout<<"Enter the number of elements in array:\n";
	cin>>n;

	cout<<"Enter the sum:\n";
	cin>>SUM;

	int arr[n];
	int t[n+1][SUM+1];

	for(i=0;i<n+1;i++)
	{
		cin>>arr[i];
	}

	for(i=0;i<n+1;i++)
	{
		for(j=0;j<SUM+1;j++)
		{
			if(i==0)
			{
				t[i][j] = false;
			}
			if(j==0)
			{
				t[i][j] = true;
			}
		}
	}

	for(i=1;i<n+1;i++)
	{
		for(j=1;j<SUM+1;j++)
		{
			if(arr[i-1]<=j)
			{
				t[i][j]=(t[i-1][j-arr[i-1]] || t[i-1][j]);
			}
			else
			{
				t[i][j]=t[i-1][j];
			}
		}
	}
	if(t[n][SUM]==1)
	{
		cout<<"True";
	}
	else
	{
		cout<<"False";
	}

}





