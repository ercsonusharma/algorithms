#include<bits/stdc++.h>
using namespace std;

typedef struct node{
	 int data;
	 struct node* lchild,*rchild;

}Node;


bool isBst(Node* ptr,int min,int max)
{

	if(!ptr)return false;

	if(ptr->data<min||ptr->data>max)
		return false;

	return isBst(ptr->lchild,min,ptr->data-1)&(isBst(ptr->rchild,ptr->data+1,max));


}


void inorder(Node* ptr)
{
stack<Node*> st;

while(true)
	{

		while(ptr->lchild)
		{
			st.push(ptr);
			ptr=ptr->lchild;
		}

		while(!ptr->rchild)
		{
			cout<<ptr->data<<"\n";
			if(st.empty()) return ;
			ptr=st.top(),st.pop();
		}

			ptr=ptr->rchild;

	}

}

int func(Node* ptr)
{
	if(!ptr)
		return 0;

	func(ptr->lchild);
	return ptr->data+func(ptr->rchild);


}
