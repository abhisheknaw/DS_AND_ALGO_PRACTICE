#include <bits/stdc++.h>
using namespace std;
struct bstnode
{
	int data;
	bstnode *left;
	bstnode *right;
};
bstnode* getnewnode(int data)
{
	bstnode *newnode = new bstnode();
	newnode->data=data;
	newnode->left=NULL;
	newnode->right=NULL;
	return newnode;
}
bstnode *insert(bstnode *root,int data)
{
	if(root==NULL)
	{
		root=getnewnode(data);
		return root;
	}
	else if(root->data >= data)
	{
		root->left=insert(root->left,data);
		return root;
	}
	else
	{
		root->right=insert(root->right,data);
		return root;
	}
}
int diaTREE(bstnode *root,int &res)
{
	if(root==NULL)
	{
		return 0;
	}
	int left=diaTREE(root->left,res);
	int right=diaTREE(root->right,res);

	int temp = max(max(left,right)+root->data,root->data);
	int sol=left+right+root->data;
	int ans = max(temp,sol);
	res = max(res,ans);
	return temp;
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
	int res=INT_MIN;
	int n,x;
	bstnode *root=NULL;
	cout<<"enter the number of elements:\n";
	cin>>n;
	cout<<"enter elements:\n";
	for(int i=0;i<n;i++)
	{
		cin>>x;
		root=insert(root,x);
	}
	diaTREE(root,res);
	cout<<res;
	return 0;
}				