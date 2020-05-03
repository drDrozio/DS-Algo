#include<iostream>
#include<vector>
#include<queue>
using namespace std;

template<typename T>
class TreeNode
{
	public:
		T data;
		vector<TreeNode<T>*> children;
		
		TreeNode(T d)
		{
			this->data=d;
		}	
		
		~TreeNode()
		{
			for(int i=0;i<children.size();i++)
				delete children[i];
		}
};

TreeNode<int>* takeInput_Rec()
{
	int rootData;
	cout<<"Enter data : ";
	cin>>rootData;
	TreeNode<int>* root=new TreeNode<int>(rootData);
	
	int n;
	cout<<"Enter number of children of "<<root->data<<" : ";
	cin>>n;
	for(int i=0;i<n;i++)
	{
		TreeNode<int>* child=takeInput_Rec();
		root->children.push_back(child);
	}
	return root;
}

void printTree_Rec(TreeNode<int>* root) 
{
	if (root == NULL) {
		return;
	}

	cout << root->data << ":";
	for (int i = 0; i < root->children.size(); i++) {
		cout << root->children[i]->data << ",";
	}
	cout << endl;
	for (int i = 0; i < root->children.size() ; i++) {
		printTree_Rec(root->children[i]);
	}
}

TreeNode<int>* takeInput_levelOrder()
{
	int rootData;
	cout<<"Enter root data : ";
	cin>>rootData;
	TreeNode<int>* root=new TreeNode<int>(rootData);
	
	queue <TreeNode<int>*> pendingNodes;
	pendingNodes.push(root);
	while(pendingNodes.size()!=0)
	{
		TreeNode<int>* front=pendingNodes.front();
		pendingNodes.pop();
		int numChildren;
		cout<<"Enter number of children of "<<front->data<<" : ";
		cin>>numChildren;
		for(int i=0;i<numChildren;i++)
		{
			int childData;
			cout<<"Enter "<<i+1<<"th child of "<<front->data<<" : ";
			cin>>childData;
			TreeNode<int>* child=new TreeNode<int>(childData);
			front->children.push_back(child);
			pendingNodes.push(child);
		}
	}
	return root;
}

void printTree_levelOrder(TreeNode<int>* root)
{
	queue <TreeNode<int>*> pendingNodes;
	cout<<root->data<<endl;
	pendingNodes.push(root);
	int sib=0;
	while(pendingNodes.size()!=0)
	{
		TreeNode<int>* front=pendingNodes.front();
		pendingNodes.pop();
		int i=0;
		while(i<front->children.size())
		{
			pendingNodes.push(front->children[i]);
			cout<<front->children[i]->data<<" ";
			i++;
			sib++;
		}
		if(sib==pendingNodes.size())
		{
			cout<<endl;
			sib=0;
		}
		front=NULL;
	}
}


