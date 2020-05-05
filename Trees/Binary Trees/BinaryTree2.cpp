#include<iostream>
#include "BinaryTreeNode.h"
#include<queue>
#include<stack>
#include<vector>

using namespace std;

template<typename T>
class node
{
	public:
		T data;
		node<T>*next;
		
		node(T d)
		{
			this->data=d;
			this->next=NULL;
		}
};

BinaryTreeNode<int>* takeInput_LevelWise()
{
	int rootData;
	cout<<"Enter root Data : ";
	cin>>rootData;
	if(rootData==-1)
		return NULL;

	BinaryTreeNode<int>* root=new BinaryTreeNode<int>(rootData);
	queue<BinaryTreeNode<int>*> pendingNodes;
	pendingNodes.push(root);
	while(pendingNodes.size()!=0)
	{
		BinaryTreeNode<int>* front=pendingNodes.front();
		pendingNodes.pop();
		
		int leftChildData;
		cout<<"Enter left child of "<<front->data<<" : ";
		cin>>leftChildData;
		if(leftChildData!=-1)
		{
			BinaryTreeNode<int>* leftChild=new BinaryTreeNode<int>(leftChildData);
			front->left=leftChild;
			pendingNodes.push(leftChild);
		}
		
		int rightChildData;
		cout<<"Enter right child of "<<front->data<<" : ";
		cin>>rightChildData;
		if(rightChildData!=-1)
		{
			BinaryTreeNode<int>* rightChild=new BinaryTreeNode<int>(rightChildData);
			front->right=rightChild;
			pendingNodes.push(rightChild);
		}
	}
	return root;
}

void printLevelWise(BinaryTreeNode<int>*root)
{
	queue<BinaryTreeNode<int>*> pendingNodes;
	pendingNodes.push(root);
	
	while(pendingNodes.size()!=0)
	{
		BinaryTreeNode<int>*front=pendingNodes.front();
		pendingNodes.pop();
		cout<<front->data<<" : ";
		
		if(front->left!=NULL)
		{
			BinaryTreeNode<int>*leftChild=front->left;
			pendingNodes.push(leftChild);
			cout<<"L:"<<leftChild->data<<",";
		}
		
		if(front->right!=NULL)
		{
			BinaryTreeNode<int>*rightChild=front->right;
			pendingNodes.push(rightChild);
			cout<<"R:"<<rightChild->data;
		}
		cout<<endl;
	}
}

int sumNodes(BinaryTreeNode<int>*root)
{
	if(root==NULL)
		return 0;
	return root->data+sumNodes(root->left)+sumNodes(root->right);
}

pair<bool,int> isBalancedHelper(BinaryTreeNode<int>*root)
{
	if(root==NULL)
	{
		pair<bool,int> base;
		base.first=true;
		base.second=0;
		return base;
	}
	
	pair<bool,int> leftAns=isBalancedHelper(root->left);
	pair<bool,int> rightAns=isBalancedHelper(root->right);
	pair<bool,int> ans;
	
	if(leftAns.first==true && rightAns.first==true)
	{
		if(leftAns.second-rightAns.second<=1 || rightAns.second-leftAns.second<=1)
			ans.first=true;
		else
			ans.first=false;
	}
	else
		ans.first=false;
	
	ans.second=1+max(leftAns.second,rightAns.second);
	return ans;
}

bool isBalanced(BinaryTreeNode<int>*root)
{
	pair<bool,int> output=isBalancedHelper(root);
	return output.first;
}

void printLevelOrder(BinaryTreeNode<int>*root)
{
	queue<BinaryTreeNode<int>*> pendingNodes;
	pendingNodes.push(root);
	pendingNodes.push(NULL);
	
	while(pendingNodes.size()!=0)
	{
		BinaryTreeNode<int>* front=pendingNodes.front();
		pendingNodes.pop();
		
		if(front!=NULL)
		{
			cout<<front->data<<" ";
			if(front->left!=NULL)
				pendingNodes.push(front->left);
			if(front->right!=NULL)
				pendingNodes.push(front->right);
		}
		else
		{
			if(pendingNodes.size()>0)
			{
				cout<<endl;
				pendingNodes.push(NULL);
			}
			else
			{
				break;
			}
		}
	}
}

BinaryTreeNode<int>* removeLeaves(BinaryTreeNode<int>*root)
{
	if(root==NULL)
		return NULL;
		
	if(root->left==NULL && root->right==NULL)
	{
		delete root;
		return NULL;
	}
	
	root->left=removeLeaves(root->left);
	root->right=removeLeaves(root->right);
	return root;
}

vector<node<int>*>* levelWiseLinkedList(BinaryTreeNode<int>*root)
{
	vector<node<int>*>* output;
	queue<BinaryTreeNode<int>*> pendingNodes;
	pendingNodes.push(root);
	pendingNodes.push(NULL);
	node<int>* head=NULL;
	node<int>* tail=NULL;
	
	while(pendingNodes.size()!=0)
	{
		BinaryTreeNode<int>*front=pendingNodes.front();
		pendingNodes.pop();
		if(front!=NULL)
		{
			node<int>* newNode=new node<int>(front->data);
			if(head==NULL)
			{
				head=newNode;
				tail=newNode;
			}
			else
			{
				tail->next=newNode;
				tail=newNode;
			}
			if(front->left!=NULL)
                pendingNodes.push(front->left);
            if(front->right!=NULL)
                pendingNodes.push(front->right);
		}
		else
		{
			if(pendingNodes.size()>0)
			{
				output->push_back(head);
				pendingNodes.push(NULL);
			}
			else
				break;
		}
	}
	return output;
}

void printZigZag(BinaryTreeNode<int>*root)
{
	stack<BinaryTreeNode<int>*> s1;
	stack<BinaryTreeNode<int>*> s2;
	
	s1.push(root);
	
	while(s1.size()!=0 ||s2.size()!=0)
	{
		BinaryTreeNode<int>*topNode=NULL;
		if(s1.size()!=0 && s2.size()==0)
		{
			while(s1.size()!=0)
			{
				topNode=s1.top();
				s1.pop();
				cout<<topNode->data<<" ";
				if(topNode->left!=NULL)
					s2.push(topNode->left);
				if(topNode->right!=NULL)
					s2.push(topNode->right);
			}
			cout<<endl;
		}
		if(s1.size()==0 && s2.size()!=0)
		{
			while(s2.size()!=0)
			{
				topNode=s2.top();
				s2.pop();
				cout<<topNode->data<<" ";
				if(topNode->right!=NULL)
					s1.push(topNode->right);
				if(topNode->left!=NULL)
					s1.push(topNode->left);
			}
			cout<<endl;
		}
	}
}


int main()
{
	//5 6 10 2 3 -1 -1 -1 -1 -1 9 -1 -1
	//1 2 3 -1 -1 -1 -1
	//8 3 10 1 6 -1 14 -1 -1 4 7 13 -1 -1 -1 -1 -1 -1 -1
	//1 2 3 4 5 6 7 -1 -1 8 -1 -1 9 -1 -1 -1 -1 10 -1 -1 -1
	BinaryTreeNode<int>*root=takeInput_LevelWise();
	cout<<endl;
	printLevelWise(root);
	cout<<endl;
	
	//Sum of all Nodes
	cout<<"Sum of all nodes = "<<sumNodes(root)<<endl;
	
	//Balanced BT?
	cout<<"Check if tree is balanced or not:-"<<endl;
	if(isBalanced(root)==true)
		cout<<"Binary Tree is balanced."<<endl;
	else
		cout<<"Binary Tree is not balanced."<<endl;
		
	//Print level order with each level at new line
	printLevelOrder(root);
	cout<<endl<<endl;
		
	//Remove all Leaf Nodes
	cout<<"Binary Tree after removal of leaf nodes->"<<endl;
	BinaryTreeNode<int>* newRoot=root;
	newRoot=removeLeaves(newRoot);
	printLevelOrder(newRoot);
	cout<<endl<<endl;
	
	cout<<"Level Order Print :"<<endl;
	printLevelOrder(root);
	cout<<endl<<endl;
	
	//Print ZigZag
	cout<<"ZigZag ordered level wise tree -> "<<endl;
	printZigZag(root);
	cout<<endl<<endl;
}
