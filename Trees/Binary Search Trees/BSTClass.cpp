#include<iostream>
#include "BST.h"
using namespace std;

int main()
{
	BST b;
	b.insert(8);
	b.insert(5);
	b.insert(10);
	b.insert(2);
	b.insert(6);
	b.insert(9);
	b.insert(13);
	b.prtintTree();
	cout<<endl;
	b.del(2);
	b.del(8);
	b.prtintTree();
}
