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
    		return t[n][SUM];
    	}
    	else
    	{
    		t[n][SUM]=0;
    		return t[n][SUM];

    	}
    
    }
    else
    {
    	if(subset(arr,n-1,SUM))
    	{
    		t[n][SUM]=1;
    		return t[n][SUM];
    	}
    	else
    	{
    		t[n][SUM]=0;
    		return t[n][SUM];
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
	cout<<"enter no.of elements:\n";
	cin>>n;
	cout<<"enter the sum:\n";
	cin>>SUM;
	int arr[n];
	for(i=0;i<n;i++)
	{
		cin>>arr[i];
	}

	bool sol= subset(arr,n,SUM);

	if(sol)
	{
		cout<<"true";
	}
	else
	{
		cout<<"false";
	}

	/*if(subset(arr,n,SUM))
	{
		t[n][SUM]=1;
       
	}
	else
	{
		t[n][SUM]=0;
	}
	if(t[n][SUM])
	{
		cout<<"true";
	}
	else
	{
		cout<<"false";
	}*/
	return 0;


}