//Sonu Kumar Sharma
//CSE 2nd Year MNNIT Allahabad
//Objective:	DSU

#include<bits/stdc++.h>
#define max 1000000
typedef long long int ll;
typedef unsigned long long int ull;
typedef long int li;
#define fl(var,start,end) for(var=start;var<end;var++)
#define mod 1000000007
using namespace std;
int parent[max],rank[max]={0};
vector<pair<int,pair<int,int> > > vec;
//Finding parent
//Iterative approach
int findparent(int x)
{
	while(parent[x]!=x)
		x=parent[x];
	return x;
}
//Recursive approach
int recfindparent(int x)
{
	if(parent[x]==x)
		return x;
	return parent[x]=recfindparent(parent[x]);
}

//Ackerman rank-compression
//To do

//Union Naive approach
bool unionsetnaive(int x,int y)
		{
			int px=findparent(x);
			int py=findparent(y);
			if(px!=py){
				parent[px]=py;
			return true;
			}
			else
			return false;
		}

//union optimised
bool unionset(int x,int y)
		{
			int px=findparent(x);
			int py=findparent(y);
			if(px!=py){
				if(rank[px]==rank[py])
				{
					parent[px]=py;
					rank[py]++;
				}
				else if(rank[px]>rank[py])
					parent[py]=px;
				else
					parent[px]=py;
			return true;
			}
			else
			return false;
		}
int main()
{
	//freopen("in.txt","r",stdin);

		printf("Enter no. of vertices and edges respectively:\n");
		int n,i,e,r,u,v,w;
		fl(i,0,max)
					parent[i]=i;
		scanf("%d%d",&n,&e);
		fl(i,0,e)
		{
			scanf("%d%d%d",&u,&v,&w);
			vec.push_back(make_pair(w,make_pair(u,v)));

		}
		int sum=0;
		sort(vec.begin(),vec.end());
		fl(i,0,e)
		{
		if(unionset(vec[i].second.first,vec[i].second.second))
		{
			sum+=vec[i].first;
			printf("Edge:%d %d \n",vec[i].second.first,vec[i].second.second);
		}
		}
		printf("Minimum weight:%d\n",sum);
	return 0;
}
