#include<stdio.h>
int arr[100000]={0};
void SeiveOfEratosthenes(int n)
{
	arr[1]=1;
	arr[0]=1;
	int i,j;
	for(i=2;i*i<n;i++)
	{
		if(arr[i]==0)
		{
			for(j=i+1;j<n;j++)
			{
				if(j%i==0)
				arr[j]=1;
			}
		}
	}
	for(i=2;i<n;i++)
	if(arr[i]==0)
	printf("%d\t",i);
}

int main()
{
	SeiveOfEratosthenes(1000);
}
