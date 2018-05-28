//Sonu Kumar Sharma
//CSE 2nd Year MNNIT Allahabad
//Objective:


		#include<bits/stdc++.h>
        #define maxx 500010
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

        ull T[maxx];
        ull arr[maxx],n;

        void buildtree(int idx,int i,int j,int l,int r)
        {
        	if(l>j||r<i)
        		return ;

        	if(l==r)
        	{
        		T[idx]=arr[l];
        	return ;
        	}
        	int mid=(l+r)>>1;
        	buildtree(idx<<1,i,j,l,mid);
        	buildtree((idx<<1)+1,i,j,mid+1,r);
        	T[idx]=T[idx<<1]+T[(idx<<1)+1];

        	return ;
        }

        ull query(int idx,int i,int j,int l,int r)
        {
        	if(l>j||r<i)
        		return 0;
        	if(l>=i&&r<=j)
        	{
        		return T[idx];
        	}
        	int mid=(l+r)>>1;
        	return (query(idx<<1,i,j,l,mid)+query((idx<<1)+1,i,j,mid+1,r));
        }



      /*  void propagate(int idx,int l,int r)
        {
        	if(lazy[idx])
        	{
        		T[idx]=lazy[idx];
        	}
        	if(l!=r)
        	{
        		lazy[idx<<1]=queryroot(1,l,l);
        		lazy[(idx<<1)+1]=queryroot(1,r,r);
        	}
        	cout<<"l,r="<<lazy[idx<<1]<<","<<lazy[(idx<<1)+1]<<endl;
        		lazy[idx]=0;

        }
*/
        void update(int idx,int i,int j,int l,int r)
        {

        	if(l>j||r<i)
        		return ;
        	//if(lazy[idx])
        	//propagate(idx,l,r);
//cout<<"idx= "<<idx<<endl;
        	if(T[idx]==(r-l+1))
        	{
        		//cout<<"q";
        		return ;
        	}

        	if(l==r)
        	{
        		 T[idx]=sqrt(T[idx]);


        		// cout<<"laz"<<lazy[idx]<<"for i,j,l,r="<<i<<","<<j<<","<<l<<","<<r<<endl;
        		// propagate(idx,l,r);

        		 return ;
        	}
        	int mid=(l+r)>>1;
        	//cout<<mid<<" ";
        	update(idx<<1,i,j,l,mid);
        	update((idx<<1)+1,i,j,mid+1,r);
        	T[idx]=T[idx<<1]+T[(idx<<1)+1];
        }

int main()
{
int i,m,x,l,r,t=0;
while(scanf("%d",&n)!=EOF)
{
t++;

inc(i,1,n+1)
inll(arr[i]);
memset(T,0,sizeof(T));
buildtree(1,1,n,1,n);
//inc(i,1,2*n)
//cout<<T[i]<<" ";
//cout<<endl;
in(m);
printf("Case #%d:\n",t);
while(m--)
{
	in(x);
in2(l,r);
if(l>r)
{
	i=l;
	l=r;
	r=i;
}
if(x==1)
{
	//cout<<"l,r="<<l<<","<<r<<endl;

printf("%lld\n",query(1,l,r,1,n));
}
else
{
	update(1,l,r,1,n);
}
}
printf("\n");
}
return 0;
}
