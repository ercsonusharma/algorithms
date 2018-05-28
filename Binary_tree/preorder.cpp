//Sonu Kumar Sharma
//CSE 2nd Year MNNIT Allahabad
//Objective: Iterative approach/Recursive approach for Inorder Traversal

#include<bits/stdc++.h>
#define max 1000000
typedef long long int ll;
typedef unsigned long long int ull;
typedef long int li;
#define fl(var,start,end) for(var=start;var<end;var++)
#define mod 1000000007
using namespace std;

typedef struct node
{
	int data;
	struct node* lchild,*rchild;
}Node;
Node* root=NULL;

//allocating a new node

Node* getnode(Node* ptr,int x)
{
	ptr=(Node*)malloc(sizeof(Node));
	ptr->lchild=NULL;
	ptr->rchild=NULL;
	ptr->data=x;
	return ptr;
}
//insertion as bst
void insert(int x)
{
	Node* tmp=root,*par;

	if(!tmp)
		return ;
	while(tmp)
	{
		par=tmp;
	if(x>tmp->data)
		tmp=tmp->rchild;
	else
		tmp=tmp->lchild;
	}
	if(par->data>x)
		par->lchild=getnode(par->lchild,x);
	else
		par->rchild=getnode(par->rchild,x);
	return ;
}
//insertion in recursive way
void insertrec(Node* tmp,int x)
{
	Node* par=tmp;
	if(tmp)
	{
		par=tmp;
		if(x>tmp->data)
			 insertrec(tmp->rchild,x);
		else
			insertrec(tmp->lchild,x);
	}
	else
		return;

		if(par->data>x)
		par->lchild=getnode(par->lchild,x);
	else
		par->rchild=getnode(par->rchild,x);

	return ;

}
//Preorder Traversal
//Recursive

void recpreorder(Node* ptr)
{
	if(!ptr)
		return ;
	printf("%d ",ptr->data);
	recpreorder(ptr->lchild);
	recpreorder(ptr->rchild);
	return ;
}

void iterpreorder(Node* ptr)
{

	stack<Node*> st;
	st.push(ptr);
	while(!st.empty())
	{

		ptr=st.top();
		st.pop();
		printf("%d ",ptr->data);
		if(ptr->rchild)
			st.push(ptr->rchild);
		if(ptr->lchild)
			st.push(ptr->lchild);

	}
	return ;
}

int main()
{
	freopen("in.txt","r",stdin);
	printf("Enter no. of nodes\n");
	int n,i;
	scanf("%d",&n);
	while(n--)
	{
		scanf("%d",&i);
		if(root)
			insert(i);
		else
		root=getnode(root,i);
	}
	iterpreorder(root);
	//printf("f-%d",root->lchild->data);
	return 0;
}
