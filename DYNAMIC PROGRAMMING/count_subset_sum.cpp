#include <bits\stdc++.h>
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
    int i,j,sum,n;
    cout<<"enter no. of elements:\n";
    cin>>n;
    cout<<"enter the sum:\n";
    cin>>sum;
    int arr[n];
    for(i=0;i<n;i++)
    {
    	cin>>arr[i];
    }

    int t[n+1][sum+1];
    for(i=0;i<n+1;i++)
    {
    	t[i][0]=1;
    }
    for(j=1;j<sum+1;j++)
    {
    	t[0][j]=0;
    }    
    for(i=1;i<n+1;i++)
    {
    	for(j=1;j<sum+1;j++)
    	{
    		if(arr[i-1]<=j)
    		{
    			t[i][j]=t[i-1][j-arr[i-1]]+t[i-1][j];
    		}
    		else
    		{
    			t[i][j]=t[i-1][j];
    		}
    	}
    }
    cout<<"count of subset is:\n"<<t[n][sum];
    return 0;
}