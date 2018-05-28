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
	int x,y,n;
//call
	buildtree(1,1,n);
query(1,1,n,x,y);

	return 0;
}
