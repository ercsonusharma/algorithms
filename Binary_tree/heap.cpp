
#include<bits/stdc++.h>
using namespace std;
#define ll long long

#define mod 1000000007

int arr[155],ar[155];
void max_heapify(int x,int hs)
{
	int l = x << 1;
	int r = (x << 1) + 1;
	int smallest = x;

		if (l<=hs&&ar[l]>ar[x])
			smallest = l;
		if (r<=hs&&ar[r]>ar[smallest])
			smallest = r;
		if (smallest != x)
		{
			swap(ar[x], ar[smallest]);
			max_heapify(smallest, hs);
		}

}
int extract_max(int* hs)
{
	int ret = ar[1];
	ar[1] = ar[*hs];
	(*hs)--;
	max_heapify(1, *hs);
	return ret;
}
void heap_sort(int hs)
{
	int i;
	for (i = hs; i > 1; i--)
	{
		int tp = ar[1];
		ar[1] = ar[hs];
		ar[hs] = tp;
		hs--;
		max_heapify(1,hs);
	}
	return;
}

void insert(int x,int hs)
{

}

void buildheap(int hs)
{
	for (int i = 1; i <= hs; i++)
		ar[i] = arr[i - 1];

	for (int i = hs / 2; i > 0; i--)
		max_heapify(i, hs);
}
int main()
{
	int i;
	cout << "Array Elements:\n";
	for (i = 0; i < 14; i++)
	{
		arr[i] = rand() % 1000;
		cout << arr[i] << " ";
	}
	cout << "\n";
	buildheap(14);

	heap_sort(14);
	cout << "after heap sort:";
	for (i = 1; i <= 14; i++)
		cout << ar[i] << " ";

	return 0;

}
