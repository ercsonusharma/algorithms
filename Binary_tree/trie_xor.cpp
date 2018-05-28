
#include<bits/stdc++.h>
using namespace std;
#define MAX 100005

long long arr[MAX];

typedef struct trie {
	struct trie* child[2];
	int ncount[2];
}Trie;
Trie* root = NULL,*tmp;


Trie* allocate(Trie* ptr)
{
	ptr = (Trie*)malloc(sizeof(Trie));
	for (int i = 0; i<2; i++)
		ptr->child[i] = NULL,ptr->ncount[i]=0;


	return ptr;
}
void insert(int x,int d)
{
	int st,i=d-1;		//d is the level or depth of max number
	if (!root)
		root = allocate(root);
	Trie* ptr = root;

	while (i>=0)
	{
		st = (x&(1 << i))?1:0;				//(x&(1<<i)=>check if bit from msb is set or not
										//st stores 1 if it is set else 0

			if (!ptr->child[st])
				ptr->child[st] = allocate(ptr->child[st]);
			ptr->ncount[st]++;
			ptr = ptr->child[st];

			//cout << st<<" ";
		i--;
	}
	ptr->ncount[st]++;
}

int find_pair_max_xor(int n,int d)
{
	//n is the no of elements in the array

	int i,st,j,num=0,max_xor=0;
	Trie* ptr = root;
	for (i = 0; i < n; i++)		//O(n)
	{
		num = 0;
		ptr = root;
		for (j = d - 1; j >= 0; j--)		//O(d) or O(log2(MAX))
		{
			st = (arr[i] & (1 << j)) ? 1 : 0;				//(x&(1<<i)=>check if bit from msb is set or not
													//st stores 1 if it is set else 0

			if (ptr->child[!st])			//!st go to opposite direction
				ptr = ptr->child[!st],num+=1;
			else
				ptr = ptr->child[st];
			if(j)
			num <<= 1;
		}
		//cout << num << " ";
		max_xor = max(max_xor, num);
	}
	return max_xor;
}

int query(int p, int d)
{
	int st, i ,num=0;		//d is the level or depth of max number

	Trie* ptr = root;

	for (i = d - 1; i >= 0;i--)
	{
		st = (p&(1 << i)) ? 1 : 0;				//(x&(1<<i)=>check if bit from msb is set or not
												//st stores 1 if it is set else 0

		if (ptr->child[!st])
		ptr = ptr->child[!st],num+=1;
		else
			ptr = ptr->child[st];

	//	cout << num<<" ";
		if (i)num <<= 1;
	}
	return num;
}

void disallocate(Trie* ptr)
{
	if (!ptr)
		return;

	for (int i = 0; i < 2; i++)
	{
		if (ptr->child[i])
		{
			disallocate(ptr->child[i]);
			ptr->child[i] = NULL;
		}
	}
	free(ptr);
}

int find_subarray_max_xor(int n, int d)
{
	insert(0, d);
	int ans = 0, p = 0, i;
	for (i = 0; i < n; i++)
	{
		p ^= arr[i];
		insert(p,d);
		ans = max(ans, query(p, d));
	}
	return ans;
}

long long query_range(int q, int k,int d)
{
	//q is the current left current xor and k is the given number (less than k)
	int i, x, num = 0, st_k, st_q;long long ans = 0;
	Trie* ptr = root;
	for (i = d - 1; i >= 0; i--)
	{
		st_q = (q&(1 << i)) ? 1 : 0;
		st_k = (k&(1 << i)) ? 1 : 0;
		if (st_q == 1 && st_k == 1)
		{
			if (ptr->child[1])
				ans +=(long long) ptr->ncount[1];
			if (ptr->child[0])
				ptr = ptr->child[0];
			else
				return ans;

		}
		else if (st_q == 0 && st_k == 1)
		{
			if (ptr->child[0])
				ans += (long long)ptr->ncount[0];
			if (ptr->child[1])
				ptr = ptr->child[1];
			else
				return ans;

		}
		else if (st_q == 1 && st_k == 0)
		{

			if (ptr->child[1])
				ptr = ptr->child[1];
			else
				return ans;

		}
		else
		{
			if (ptr->child[0])
				ptr = ptr->child[0];
			else
				return ans;
		}

	}
	return ans;



}
long long find_subarray_xor_less_than_k(int n, int d,int k)
{
	insert(0, d);
	long long ans = 0, p = 0;int i;
	for (i = 0; i < n; i++)
	{
		p ^= arr[i];
		//cout << "ans=" << ans << "\n";
		ans += query_range(p, k, d);
		insert(p, d);
	}
	return ans;

}


int main()
	{
		int i, n, x,d=18,t,k;
		scanf("%d", &t);
		while (t--)
		{
			scanf("%d%d", &n,&k);

			for (i = 0; i < n; i++)
			{
				scanf("%lld",arr+i);
			}
			//cout<<find_pair_max_xor(n,d);
			printf("%lld\n", find_subarray_xor_less_than_k(n, d,k));
			disallocate(root);
			root = NULL;
			free(root);
		}
		return 0;
	}
