#include<iostream>
#include "BinaryTreeNode.h"

class BST
{
	BinaryTreeNode<int>*root;
	
	bool hasData(BinaryTreeNode<int>*node,int data)
	{
		if(node==NULL)
			return false;
		if(node->data==data)
			return true;
		else
		{
			if(node->data>data)
				return hasData(node->left,data);
			else
				return hasData(node->right,data);
		}
	}
	
	public:
		BST()
		{
			root=NULL;
		}
		
		~BST()
		{
			delete root;
		}
		
		bool hasData(int data)
		{
			return hasData(root,data);
		}
	
	private:
		BinaryTreeNode<int>* insert(BinaryTreeNode<int>*node,int data)
		{
			if(node==NULL)
			{
				BinaryTreeNode<int>*newNode=new BinaryTreeNode<int>(data);
				return newNode;
			}
			
			if(data<node->data)
			{
				node->left=insert(node->left,data);
			}
			else
			{
				node->right=insert(node->right,data);
			}
			return node;
		}
		
		BinaryTreeNode<int>* del(BinaryTreeNode<int>*node,int data)
		{
			if(node==NULL)
				return NULL;
				
			if(data<node->data)
			{
				node->left=del(node->left,data);
			}
			else
			{
				if(data>node->data)
				{
					node->right=del(node->right,data);
				}
				else
				{
					if(node->left==NULL && node->right!=NULL)
					{
						BinaryTreeNode<int>*temp=node->right;
						node->right=NULL;
						delete node;
						return temp;
					}
					else
					{
						if(node->left!=NULL && node->right==NULL)
						{
							BinaryTreeNode<int>*temp=node->left;
							node->left=NULL;
							delete node;
							return temp;
						}
						else
						{
							if(node->left!=NULL && node->right!=NULL)
							{
								BinaryTreeNode<int>*minNode=node->right;
								while(minNode->left!=NULL)
								{
									minNode=minNode->left;
								}
								int rightMin=minNode->data;
								node->data=rightMin;
								node->right=del(node->right,rightMin);
								return node;
							}
							else
							{
								delete node;
								return NULL;
							}
						}
					}
				}
			}
		}
		
		void printTree(BinaryTreeNode<int>*root)
		{
			if(root==NULL)
				return;
				
			cout<<root->data<<":";
			if(root->left!=NULL)
				cout<<"L"<<root->left->data;
			if(root->right!=NULL)
				cout<<"R"<<root->right->data;
			cout<<endl;	
			printTree(root->left);
			printTree(root->right);
		}
	public:
		void insert(int data)
		{
			this->root=insert(root,data);
		}
		
		void del(int data)
		{
			this->root=del(root,data);
		}
		void prtintTree()
		{
			printTree(root);
		}
		
};
