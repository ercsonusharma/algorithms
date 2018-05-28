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
//Update the tree without lazy propagation
void update(int idx,int l,int r,int i,int j)
{
	if(l>j || r<i)
			return ;  //out of range invalid query
		if(l==r)
			arr[idx]+=val;
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


	return 0;
}
