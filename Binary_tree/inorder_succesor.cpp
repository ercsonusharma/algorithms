//Sonu Kumar Sharma
//CSE 2nd Year MNNIT Allahabad
//Objective: Iterative approach/Recursive approach for Inorder Traversal

#include<bits/stdc++.h>
#define maxx 1000000
typedef long long int ll;
typedef unsigned long long int ull;
typedef long int li;
#define fl(var,start,end) for(var=start;var<end;var++)
#define mod 1000000007
using namespace std;

typedef struct node
{
	int data;
	struct node* lchild,*rchild,*next;
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

Node* inorder_succesor(Node* ptr,Node* x)
{

	Node* succ=NULL;

	while(ptr)
	{
		if(x->data < ptr->data)
		{
			succ=x;
			ptr=ptr->lchild;
		}
		else if(x->data>ptr->data)
			ptr=ptr->rchild;
		else
			break;
	}
return succ;

}

void predecessor(Node* ptr,Node** nextt)
{
	if(!ptr)
		return ;

	predecessor(ptr->rchild,nextt);

	ptr->next=*nextt;

	*nextt=ptr;

	predecessor(ptr->lchild,nextt);
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
	Node* nextt=NULL;
	predecessor(root,&nextt);

	Node* ptr=root;

	while(ptr->lchild)
		ptr=ptr->lchild;
	while(ptr)
	{
		printf("Next of %d is %d \n",ptr->data,(ptr->next?ptr->next->data:-1));
	ptr=ptr->next;
	}

	//dist(root,1);
	//recinorder(root);
	//printf("f-%d",root->lchild->data);
	return 0;
}
