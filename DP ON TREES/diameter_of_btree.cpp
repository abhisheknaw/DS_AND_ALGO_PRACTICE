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

	int temp = max(left,right)+1;
	int sol=left+right+1;
	//int ans = max(temp,sol);
	res = max(res,sol);
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
	bstnode *root=NULL;
	root=insert(root,15);
	root=insert(root,25);
	root=insert(root,10);
	root=insert(root,13);
	root=insert(root,7);
	root=insert(root,20);
	root=insert(root,27);
	diaTREE(root,res);
	cout<<res;
	return 0;
}		