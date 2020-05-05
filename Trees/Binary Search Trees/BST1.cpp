#include<iostream>
#include<queue>
#include<algorithm>
#include<bits/stdc++.h> 
#include "BinaryTreeNode.h"

class isBST
{
	public:
		bool check;
		int minimum;
		int maximum;
};

class NodeLL
{
	public:
		int data;
		NodeLL*next;
		
		NodeLL(int x)
		{
			this->data=x;
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

BinaryTreeNode<int>* searchBST(BinaryTreeNode<int>*root,int x)
{
	if(root==NULL)
		return NULL;
		
	if(root->data==x)
		return root;
	else
	{
		if(x<root->data)
		{
			return searchBST(root->left,x);
		}
		else
		{
			return searchBST(root->right,x);
		}
	}
}

void printInRange(BinaryTreeNode<int>*root,int k1,int k2)
{
	if(root==NULL)
		return;
		
	if(root->data>=k1 && root->data<=k2)
	{
		printInRange(root->left,k1,root->data);
		cout<<root->data<<" ";
		printInRange(root->right,root->data,k2);
	}	
	
	//Left side of root
	if(root->data>k2)
		printInRange(root->left,k1,k2);
		
	//Right side of root
	if(root->data<k1)
		printInRange(root->right,k1,k2);
}

int maximum(BinaryTreeNode<int>*root)
{
	if(root==NULL)
		return INT_MIN;
	int maxL=maximum(root->left);
	int maxR=maximum(root->right);
	
	int maxValue=max(maxL,maxR);
	return max(root->data,maxValue);
}

int minimum(BinaryTreeNode<int>*root)
{
	if(root==NULL)
		return INT_MAX;
	int minL=minimum(root->left);
	int minR=minimum(root->right);
	
	int minValue=min(minL,minR);
	return min(root->data,minValue);
}

bool checkBST1(BinaryTreeNode<int>*root)
{
	if(root==NULL)
		return true;
		
	int maxLeft=maximum(root->left);
	int minRight=minimum(root->right);
	 
	if(root->data>maxLeft && root->data<=minRight)
	{
		checkBST1(root->left);
		checkBST1(root->right);
	}
	else
		return false;
}

isBST checkBST2(BinaryTreeNode<int>*root)
{
	if(root==NULL)
	{
		isBST ans;
		ans.minimum=INT_MAX;
		ans.maximum=INT_MIN;
		ans.check=true;
		return ans;
	}
	
	isBST leftAns=checkBST2(root->left);
	isBST rightAns=checkBST2(root->right);
	
	isBST op;
	op.minimum=min(root->data,min(leftAns.minimum,rightAns.minimum));
	op.maximum=max(root->data,max(leftAns.maximum,rightAns.maximum));
	
	if(root->data>leftAns.maximum && root->data<=rightAns.minimum && leftAns.check && rightAns.check)
		op.check=true;
	else
		op.check=false;
	return op;
}

bool checkBST3(BinaryTreeNode<int>*root,int minimum=INT_MIN,int maximum=INT_MAX)
{
	if(root==NULL)
		return true;
	if(root->data<minimum || root->data>maximum)
		return false;
		
	bool leftCheck=checkBST3(root->left,minimum,root->data-1);
	bool rightCheck=checkBST3(root->right,root->data+1,maximum);
	
	return leftCheck && rightCheck;
}

BinaryTreeNode<int>* BSTfromArrayHelper(int a[],int start,int end)
{
	if(end<start)
		return NULL;
		
	int mid=(start+end)/2;
	
	BinaryTreeNode<int>* root=new BinaryTreeNode<int>(a[mid]);	
	root->left= BSTfromArrayHelper(a,start,mid-1);
	root->right= BSTfromArrayHelper(a,mid+1,end);
	return root;
}

BinaryTreeNode<int>* BSTfromArray(int a[],int size)
{
	int start=0;
	int end=size-1;
	BinaryTreeNode<int>* root=BSTfromArrayHelper(a,start,end);
	return root;
}

pair<NodeLL*,NodeLL*> LLfromBSTHelper(BinaryTreeNode<int>*root)
{
	if(root==NULL)
	{
		pair<NodeLL*,NodeLL*>p;
		p.first=NULL;
		p.second=NULL;
		return p;
	}
	
	pair<NodeLL*,NodeLL*>leftList=LLfromBSTHelper(root->left);
	pair<NodeLL*,NodeLL*>rightList=LLfromBSTHelper(root->left);
	
	NodeLL*newNode=new NodeLL(root->data);
	
	if(leftList.first==NULL && rightList.first==NULL)
	{
		leftList.first=newNode;
		leftList.second=newNode;
		rightList.first=newNode;
		rightList.second=newNode;
	}
	else
	{
		if(leftList.first==NULL && rightList.first!=NULL)
		{
			leftList.first=newNode;
			leftList.second=newNode;
			newNode->next=rightList.first;
		}
		else
		{
			leftList.second->next=newNode;
			newNode->next=rightList.first;
		}
	}
	pair<NodeLL*,NodeLL*>ans;
	ans.first=leftList.first;
	ans.second=rightList.second;
	
	return ans;
}

NodeLL* LLfromBST(BinaryTreeNode<int>*root)
{
	pair<NodeLL*,NodeLL*>p;
	p=LLfromBSTHelper(root);
	return p.first;
}

vector<int>* getPath(BinaryTreeNode<int>*root,int data)
{
	if(root==NULL)
		return NULL;
		
	if(root->data==data)
	{
		vector<int>*output=new vector<int>();
		output->push_back(root->data);
		return output;
	}
	
	if(data<root->data)
	{
		vector<int>*output=getPath(root->left,data);
		if(output!=NULL)
		{
			output->push_back(root->data);
		}
		return output;
	}
	else
	{
		vector<int>*output=getPath(root->right,data);
		if(output!=NULL)
		{
			output->push_back(root->data);
		}
		return output;
	}
	
}

int main()
{
	//40 20 60 10 30 50 70 -1 -1 -1 -1  -1 -1 -1 80 -1 -1
	BinaryTreeNode<int>*root=takeInput_LevelWise();
	printLevelWise(root);
	cout<<endl;
	
	//Search BST
	int x;
	cout<<"Enter element to be searched : ";
	cin>>x;
	BinaryTreeNode<int>*temp=searchBST(root,x);
	if(temp!=NULL)
	{
		cout<<temp->data<<" is present.";
	}
	else
	{
		cout<<x<<" not present";
	}
	cout<<endl;
	
	//Print in range k1,k2
	int k1,k2;
	cout<<"Enter lower limit of Search : ";
	cin>>k1;
	cout<<"Enter upper limit of Search : ";
	cin>>k2;
	printInRange(root,k1,k2);
	cout<<endl;
	
	//Check BST1
	if(checkBST1(root))
		cout<<"Binary Tree is BST.";
	else
		cout<<"Binary Tree is not BST.";
	cout<<endl;
	//Check BST2
	isBST output=checkBST2(root);
	if(output.check)
		cout<<"Binary Tree is BST.";
	else
		cout<<"Binary Tree is not BST.";
	cout<<endl;
	//Check BST3
	if(checkBST3(root))
		cout<<"Binary Tree is BST.";
	else
		cout<<"Binary Tree is not BST.";
	cout<<endl;
	
	//Construct BST from array
	int size;
	cout<<"Enter size of array : ";
	cin>>size;
	int a[size];
	cout<<"Enter sorted array : ";
	for(int i=0;i<size;i++)
	{
		cin>>a[i];
	}
	BinaryTreeNode<int>*newRoot=BSTfromArray(a,size);
	printLevelWise(newRoot);
	cout<<endl;
	
	//Construct sorted list from BST 4 2 6 1 3 5 7 -1 -1 -1 -1 -1 -1 -1 -1
	BinaryTreeNode<int>*newRoot2=takeInput_LevelWise();
	cout<<endl;
	NodeLL* head=LLfromBST(newRoot2);
	NodeLL* temp=head;
	while(temp!=NULL)
	{
		cout<<temp->data<<" ";
		temp=temp->next;
	}
	
	//Get path from node to root or root to node
	int xx;
	cout<<"Enter node data for path : ";
	cin>>xx;
	vector<int>* path=getPath(root,xx);
	for(int i=0;i<path->size();i++)
	{
		cout<<path->at(i)<<" ";
	}
	
	delete newRoot;
	delete newRoot2;
	delete root;
}
