#include<bits/stdc++.h>
using namespace std;
#define MAX 100005

int arr[MAX];

typedef struct trie {
	struct trie* child[2];
	trie()
	{
		for (int i = 0; i < 2; i++)
			this->child[i] = NULL;
	}

}Trie;
Trie* root = NULL,*tmp;

void insert(int x,int d)
{
	int st,i=d-1;		//d is the level or depth of max number
	if (!root)
		root = new Trie();
	Trie* ptr = root;

	while (i>=0)
	{
		st = (x&(1 << i))?1:0;				//(x&(1<<i)=>check if bit from msb is set or not
										//st stores 1 if it is set else 0

			if (!ptr->child[st])
				ptr->child[st] = new Trie();
			ptr = ptr->child[st];
			//cout << st<<" ";
		i--;
	}
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
	delete(ptr);
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

int main()
	{
		int i, n, x,d=64,t;
		scanf("%d", &t);
		while (t--)
		{
			scanf("%d", &n);

			for (i = 0; i < n; i++)
			{
				scanf("%d",arr+i); //insert(arr[i], d);
			}
			//cout<<find_pair_max_xor(n,d);
			printf("%d\n", find_subarray_max_xor(n, d));
			disallocate(root);
			root = NULL;
			delete(root);
		}
		return 0;
	}
