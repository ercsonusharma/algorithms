#include<stdio.h>
int a = 5, b = 10;
void change1(int *p)
/*
	Let the address of p be 3000
	value of p = 1000
*/
{ 	
	p=&a; 
	/*
		Let the address of a be 4000
		Let the address of b be 5000
		value of p = 4000
	*/
	printf("%d\n",*p);
	/*
		Value at add. stored in p
	*/
}
void change2(int **pp)//add of pp = 6000
{
	*pp=&b;
	//Value at the address stored in pp -- change to &b
	**pp = 5;
	// pp pe jao...usme jo address likha h wahan pe jao...us location pe jo address likha h wahan pe jao..
}
int main(void)
{
	int x=20,*ptr=&x;
	/*
		int *ptr = &x is equivalent to
		int *ptr;
		ptr = &x;
	*/
	/*
		Let the address of x be 1000
		Let add. of ptr be 2000
	*/
	printf("%d ",*ptr);
	/*
		Value at address stored in ptr
	*/
	change1(ptr);
	/*
		passed 1000
	*/
	printf("%d ",*ptr);
	/*
		ptr unchanged
		prints 20 again
	*/	
	change2(&ptr);	//2000 passed
	printf("%d\n",*ptr);
	return 0;
}
