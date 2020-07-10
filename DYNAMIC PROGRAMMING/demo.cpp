#include <bits/stdc++.h>
using namespace std;
int t[100][100];
bool subset(int arr[], int n, int SUM)
{
	if(SUM!=0 && n==0)
	{
		return false;  
	}
	if(SUM==0)
	{
		return true;
	}
	if (t[n][SUM]!=-1)
	{
		if(t[n][SUM])
		{
			return true;

		}
		else
		{
			return false;
		}

    }
    if (arr[n-1]<=SUM)
    {
    	bool x=subset(arr,n-1,SUM-arr[n-1]);
    	bool y=subset(arr,n-1,SUM);
    	if(x||y)
    	{
    		t[n][SUM]=1;
    	}
    	else
    	{
    		t[n][SUM]=0;

    	}
    	if(t[n][SUM]=1)
    	{
    		return true;
    	}
    	else
    	{
    		return false;
    	}
    }
    else
    {
    	if(subset(arr,n-1,SUM))
    	{
    		t[n][SUM]=1;
    	}
    	else
    	{
    		t[n][SUM]=0;
    	}
    	if(t[n][SUM]=1)
    	{
    		return true;
    	}
    	else
    	{
    		return false;
    	}
    }
		
}

int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

#ifndef ONLINE_JUDGE
	// for getting input from input.txt
	freopen("input.txt", "r", stdin);
	// for writing output to output.txt
	freopen("output.txt", "w", stdout);
#endif
	int n,SUM,i;
	memset(t,-1,sizeof(t));
	cout<<"enter no.of elements:";
	cin>>n;
	cout<<"enter the sum:";
	cin>>SUM;
	int arr[n];
	for(i=0;i<n;i++)
	{
		cin>>arr[i];
	}

	if(subset(arr,n,SUM)!=0)
	{
		cout<<true;
       
	}
	else
	{
		cout<<false;
	}
	return 0;


}