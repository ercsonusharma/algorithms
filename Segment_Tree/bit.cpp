//Sonu Kumar Sharma
//CSE 2nd Year MNNIT Allahabad
//Objective:


		#include<bits/stdc++.h>
        #define maxx 100005
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
		#ifdef ONLINE_JUDGE
		#define gc getchar_unlocked
		#else
		#define gc  getchar
		#endif
        using namespace std;
        template<class T>

		T readint()
        {
        	T n;
        	char ch=gc();
        	while(!(ch>47&&ch<58))
        		ch=gc();
        	while(ch>47&&ch<58)
        	{
        		n=n*10+ch-'0';
        		ch=gc();
        	}
        	return n;
        }

        int dx[]={1,1,1,0,0,-1,-1,-1};
        int dy[]={0,1,-1,1,-1,1,0,-1};



#define maxx 200005
int T[maxx+1],arr[maxx];

int getNext(int x)
{
	return x + (x&(-x));
}
int getParent(int x)
{
	return x - (x&(-x));
}

//update from x to the end of the array of BIT

//for range updation
//update(x,1,n);
//update(y+1,-1,n);
//this wiil update from x....n with the value of 1 and y+1...n with the value of -1
//hence the middle intersection of both ranges with get an increment of 1
//and in this way we can update x.....y with the value=1(let)

void update(int x, int val,int n)
{
	while (x <= n)
	{
		T[x] += val;
		x = getNext(x);
	}
}
//not correct
void create(int size)
{
	int i;
	for (i = 1; i <= size; i++)
		update(i, arr[i],size);
	return;
}

//return the sum of value of BIT from 1...x
//for range do the same thing as updation but difference is that it return the cummulative sum
//from start
//so,, for sum b/w x to y =>query(y)-query(x-1); return sum b/w x.....y
int query(int x)
{
	int sum = 0;
	while (x >0)
	{
		sum += T[x];
		x = getParent(x);
	}
	return sum;
}
int main()
{
	return 0;
}
