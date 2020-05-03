#include<iostream>
#include<bits/stdc++.h> 
#include "Tree.h"

using namespace std;

bool containsX(TreeNode<int>*root,int x)
{
	if(root->data==x)
		return true;
	
	for(int i=0;i<root->children.size();i++)
	{
		bool status=containsX(root->children[i],x);
		if(status==true)
			return true;
	}
	return false;
}

int countGreaterthanX(TreeNode<int>*root,int x)
{
	if(root==NULL)
		return 0;
	
	int count=0;	
	if(root->data>x)
		count=1;
	for(int i=0;i<root->children.size();i++)
	{
		int childCount=countGreaterthanX(root->children[i],x);
		count=count+childCount;
	}
	return count;
}

pair<int,int> maxSumNode(TreeNode<int>*root)
{
	if(root==NULL)
	{
		pair<int,int> ans;
		ans.first=INT_MIN;
		ans.second=INT_MIN;
		return ans;
	}
	
	int sum=root->data;
	for(int i=0;i<root->children.size();i++)
	{
		sum=sum+root->children[i]->data;
	}
	pair<int,int> max;
	max.first=root->data;
	max.second=sum;
	
	for(int i=0;i<root->children.size();i++)
	{
		pair<int,int> p=maxSumNode(root->children[i]);
		if(p.second>max.second)
		{
			max.second=p.second;
			max.first=p.first;
		}
	}
	return max;
}

bool checkIdentical(TreeNode<int>*root1,TreeNode<int>*root2)
{
	if(root1==NULL && root2==NULL)
		return true;
	
	if(root1->data==root2->data)
	{
		if(root1->children.size()==root2->children.size())
		{
			for(int i=0;i<root1->children.size();i++)
			{
				bool status=checkIdentical(root1->children[i],root2->children[i]);
				if(status==false)
					return false;
			}
		}
		else
			return false;
	}
	else
		return false;
	return true;
}

int nextLargerElement(TreeNode<int>*root,int x)
{
	if(root==NULL)
		return INT_MIN;
	
	int minGreater=INT_MAX;
	if(root->data>x)
	{
		minGreater=root->data;
	}
	
	for(int i=0;i<root->children.size();i++)
	{
		int temp=nextLargerElement(root->children[i],x);
		if(temp<minGreater)
		{
			minGreater=temp;
		}
	}
	return minGreater;
}

TreeNode<int>* secondLargest(TreeNode<int>*root)
{
	if(root==NULL)
		return NULL;
		
	int secondMaxValue=INT_MIN;
	TreeNode<int>* secondMax=NULL;
	
	int MaxValue=INT_MIN;
	TreeNode<int>* Max=NULL;
	
	if(root->children.size()==0)
	{
		secondMax=root;
		Max=root;
	}
	
	for(int i=0;i<root->children.size();i++)
	{
		TreeNode<int>* temp=secondLargest(root->children[i]);
		if(temp->data>MaxValue && temp->data>secondMaxValue)
		{
			secondMaxValue=MaxValue;
			secondMax=Max;
			Max=temp;
			MaxValue=temp->data;
		}
		else
		{
			if(temp->data<MaxValue && temp->data>secondMaxValue)
			{
				secondMaxValue=temp->data;
				secondMax=temp;
			}
		}
	}
	if(root->data>secondMaxValue && root->data<MaxValue)
	{
		secondMax=root;
	}
	return secondMax;
}

TreeNode<int>* replaceWithDepth(TreeNode<int>*root,int depth)
{
	if(root==NULL)
		return NULL;
		
	root->data=depth;
	for(int i=0;i<root->children.size();i++)
	{
		root->children[i]=replaceWithDepth(root->children[i],depth+1);
	}
	return root;
}

TreeNode<int>* replaceWithDepth(TreeNode<int>*root)
{
	TreeNode<int>*newRoot=replaceWithDepth(root,0);
	return newRoot;
}

int main()
{
	//1 3 2 3 4 2 5 6 2 7 8 0 0 0 0 0
	//5 3 1 6 2 2 8 9 2 3 4 1 7 0 0 0 0 0 
	//10 3 2 3 4 2 100 200 1 5 1 8 0 0 0 0 
	//10 3 20 30 40 2 40 50 0 0 0 0  check for 18 5th,6th
	TreeNode<int>* root=takeInput_levelOrder();
	cout<<endl;
	printTree_levelOrder(root);
	
	//Contains X
	cout<<"Enter an element : ";
	int x;
	cin>>x;
	if(containsX(root,x))
		cout<<x<<" is present.";
	else
		cout<<x<<" is not present.";
	cout<<endl;
	
	//Count nodes greater than x
	cout<<"Number of nodes greater than "<<x<<" = "<<countGreaterthanX(root,x)<<endl;
	
	//Node with maximum sum
	cout<<"Node with maximum sum -> ";
	pair<int,int> p=maxSumNode(root);
	cout<<p.first<<endl;
	
	//Check if two trees are identical (Structurally and Value wise)
	TreeNode<int>* root2=takeInput_levelOrder();
	cout<<endl;
	printTree_levelOrder(root2);
	if(checkIdentical(root,root2))
		cout<<"Trees are identical."<<endl;
	else
		cout<<"Trees are not identical."<<endl;
		
	//Find element just greater than x
	cout<<"Element just greater than "<<x<<" = "<<nextLargerElement(root,x)<<endl;
	
	//Find second largest element
	TreeNode<int>* node=secondLargest(root);
	cout<<"Second largest element = "<<node->data<<endl;
	
	//Replace each node with depth value
	TreeNode<int>* updatedRoot=replaceWithDepth(root);
	printTree_levelOrder(updatedRoot);
	
}
