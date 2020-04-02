#include<iostream>
#include "Tree.h"

using namespace std;

int numNodes(TreeNode<int>* root)
{
	if(root == NULL)
		return 0;
		
	int s=0;
	for(int i=0;i<root->children.size();i++)
	{
		s=s+numNodes(root->children[i]);
	}
	return 1+s;
}

int sumNodes(TreeNode<int>* root)
{
	if(root == NULL)
		return 0;
		
	int sum=0;
	for(int i=0;i<root->children.size();i++)
	{
		sum=sum+sumNodes(root->children[i]);
	}
	return root->data+sum;
}

TreeNode<int>* maxDataNode(TreeNode<int>* root)
{
	if(root==NULL)
		return root;
		
	TreeNode<int>* maxNode=root;
	for(int i=0;i<root->children.size();i++)
	{
		TreeNode<int>* temp=maxDataNode(root->children[i]);
		if((maxNode->data)<(temp->data))
			maxNode=temp;
	}
	return maxNode;
}

int heightTree(TreeNode<int>* root)
{
	if(root==NULL)
		return 0;
	
	int maxHeight=0;
	for(int i=0;i<root->children.size();i++)
	{
		int branchHeight=heightTree(root->children[i]);
		if (branchHeight>maxHeight)
		{
			maxHeight=branchHeight;
		}
	}
	return 1+maxHeight;
}

void printAtLevelK(TreeNode<int>*root,int k)
{
	if(root==NULL)
		return;
		
	if(k==0)
		cout<<root->data<<" ";
		return;
	
	for(int i=0;i<root->children.size();i++)
	{
		printAtLevelK(root->children[i],k-1);
	}
}

int countLeafNodes(TreeNode<int>*root)
{
	if(root==NULL)
		return 0;
		
	if(root->children.size()==0)
		return 1;
	
	int sum=0;
	for(int i=0;i<root->children.size();i++)
	{
		sum=sum+countLeafNodes(root->children[i]);
	}
	return sum;
}

void preOrder(TreeNode<int>*root)
{
	if(root==NULL)
		return;
	
	cout<<root->data<<" ";
	for(int i=0;i<root->children.size();i++)
	{
		preOrder(root->children[i]);
	}
}

void postOrder(TreeNode<int>*root)
{
	if(root==NULL)
		return;
	
	if(root->children.size()==0)
	{
		cout<<root->data<<" ";
		return;
	}
	for(int i=0;i<root->children.size();i++)
	{
		postOrder(root->children[i]);
	}
	cout<<root->data<<" ";
}

int main()
{
	//Functions
	TreeNode<int>* root=NULL;
	root=takeInput_levelOrder();
	printTree_levelOrder(root);
	
	cout<<"Number of Nodes = "<<numNodes(root)<<endl;
	cout<<"Sum of Nodes = "<<sumNodes(root)<<endl;
	
	TreeNode<int>* temp=maxDataNode(root);
	cout<<"Maximum Node : "<<temp->data<<endl;
	
	int height=heightTree(root);
	cout<<"Height of Tree = "<<height<<endl;
	
	int k;
	cout<<"Enter level of tree to be printed (Level should be less than height of tree) : ";
	cin>>k;
	cout<<"Level "<<k<<" of tree : ";
	printAtLevelK(root,k);
	cout<<endl;
	
	cout<<"Number of Leaf Nodes = "<<countLeafNodes(root)<<endl;
	
	cout<<"PreOrder : ";
	preOrder(root);
	cout<<endl;
	
	cout<<"PostOrder : ";
	postOrder(root);
	cout<<endl;
	
	delete root;
}
