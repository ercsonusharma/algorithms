//Sonu Kumar Sharma
//CSE 2nd Year MNNIT Allahabad
//Objective: Build the segment tree and then Range Minimum Query or Range Maximum Query

#include<bits/stdc++.h>
#define max 1000000
typedef long long int ll;
typedef unsigned long long int ull;
typedef long int li;
#define fl(var,start,end) for(var=start;var<end;var++)
#define mod 1000000007
using namespace std;
int T[max],arr[max];
int val;//the value the tree to be updated with
int lazy[max]; //array for marking lazy


void propagate(int idx,int l,int r)
{
	if(lazy[idx])  //if index is lazy
 	{
		T[idx]+=lazy[idx];
	}
	if(l!=r)		//if the node is not the leaf node then transfer lazy characteristic to children
	{
		lazy[2*idx]=lazy[idx];
		lazy[2*idx+1]=lazy[idx];
	}
	lazy[idx]=0; //unmark current node as lazy
	return ;
}
void updatelazy(int idx,int l,int r,int i,int j)
{
	if(lazy[idx])
		propagate(idx,l,r);
	if(l>j || r<i)
				return ;  //out of range will not be updated
			if(l>=i && r<=j)
			{
				//T[idx]+=val;  //will not be updated right now but updated when needed by lazy prop.
				lazy[idx]+=val;	//marking lazy
				propagate(idx,l,r);
			return ;
			}
		int mid=(l+r)/2;
		updatelazy(2*idx,l,mid,i,j);
		updatelazy(2*idx+1,mid+1,r,i,j);
		T[idx]=max(T[2*idx],T[2*idx+1]);   //any operation to be performed for
														//querying e.g. min , sum etc..
					return  ;

}

//Update the tree without lazy propagation
void update(int idx,int l,int r,int i,int j)
{
	if(l>j || r<i)
			return ;  //out of range will not be updated
		if(l==r)
		{
			T[idx]+=val;
			return ;
		}
		int mid=(l+r)/2;
			update(2*idx,l,mid,i,j);
			update(2*idx+1,mid+1,r,i,j);
			T[idx]=max(T[2*idx],T[2*idx+1]);   //any operation to be performed for
												//querying e.g. min , sum etc..
			return  ;

}

//Query e.g. RMQ OR RSQ etc.
int query(int idx,int l,int r,int i,int j)
{
	if(l>j || r<i)
		return -1;  //out of range invalid query
	if(l>=i && r<=j)
		return T[idx];
	else
	{
		int mid=(l+r)/2;
		return max(query(2*idx,l,mid,i,j),query(2*idx+1,mid+1,r,i,j));
					//max can be replace with the required operation as done in buildtree
	}

}

//Build Tree
void buildtree(int idx,int l,int r)
{
	if(l==r)
	{
		T[idx]=arr[l];
		return ;
	}
	int mid=(l+r)/2;
	buildtree(2*idx,l,mid);
	buildtree(2*idx+1,mid+1,r);
	T[idx]=max(T[2*idx],T[2*idx+1]);   //any operation to be performed for
										//querying e.g. min , sum etc..
	return  ;
}
int main()
{
	int n,i;
	cin>>(n);
	for(i=1;i<n+1;i++)
	cin>>arr[i];
	buildtree(1,1,n,1,n);
	update(1,1,n,1,n);
	cout<<query(1,1,2,1,n);

	return 0;
}
