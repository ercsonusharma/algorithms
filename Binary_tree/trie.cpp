//Sonu Kumar Sharma
//CSE 2nd Year MNNIT Allahabad
//Objective:Trie


		#include<bits/stdc++.h>
        #define max 100005
        typedef long long int ll;
        typedef unsigned long long int ull;
        typedef long int li;
        #define inc(var,start,end) for(var=start;var<end;++var)
		#define dec(var,start,end) for(var=start;var>end;--var)
		#define in(a) scanf("%d",&a);
		#define in2(a,b) scanf("%d%d",&a,&b);
		#define f(a) scanf("%f",&a);
		#define f2(a) scanf("%f%f",&a,&b);
		#define instr(a) scanf("%s",a);
		#define inll(a) scanf("%lld",&a);
		#define in2ll(a,b) scanf("%lld%lld",&a,&b);
		#define fl(a) scanf("%lf",&a);
		#define f2l(a) scanf("%lf%lf",&a,&b);
		#define instr(a) scanf("%s",a);
        #define mod 1000000007
        using namespace std;

        //Structure of trie
        typedef struct node
        {
        	int flag;
        	struct node* child[26];
        }Trie;
        Trie * root=NULL;

        Trie* allocate(Trie* ptr)
        {
        	ptr=(Trie*)malloc(sizeof(Trie));
        	for(int i=0;i<26;i++)
        		ptr->child[i]=NULL;
        	ptr->flag=0;
        	return ptr;
        }
        void insert(char* str)
        {
        	if(!root)
        	root=allocate(root);
        	Trie* ptr=root;
        	for(int i=0;str[i];++i)
        	{
        		if(!ptr->child[str[i]-'a'])
        			{
        				ptr->child[str[i]-'a']=allocate(ptr->child[str[i]-'a']);

        			}
        		ptr=ptr->child[str[i]-'a'];
        	}
        	ptr->flag=1;
        	return ;
        }

        bool search(char* str)
        {
        	Trie* ptr=root;
        		bool fraud=false;
        	        	for(int i=0;str[i]&&ptr;++i)
        	        	{
        	        		if(ptr->child[str[i]-'a'])
        	        		ptr=ptr->child[str[i]-'a'];
        	        		else
        	        		{
        	        			fraud=true;
        	        			break;
        	        		}
        	        	}
        	        	if(!fraud)
        	        	{
        	        		if(ptr->flag)
        	        			return true;
        	        	}
        	        	return false;

        }
        void deallocate(Trie* ptr)
        {
        	if(!ptr)
        		return ;
        	for(int i=0;i<26;i++)
        	{
        		ptr->flag=0;
        		free(ptr->child[i]);
        	}
        	return ;
        }

        void delete_key(char* str,Trie* ptr)
        {
        	if(!ptr)
        		return ;
        	else if(ptr->child[*str-'a'])
        		delete_key(str++,ptr->child[*str-'a']);
        	deallocate(ptr);
        }


int main()
{

	char str[10][1000],st[1000];
	int n;
	cin>>n;
	for(int i=0;i<n;i++)
	{
	cin>>str[i];

	insert(str[i]);
	}
	delete_key(str[1],root);
	cin>>st;
	if(search(st))
		cout<<"found";
	else
		cout<<"not found";


return 0;
}
