#include <stdio.h>
int main()
{
	const int a = 5;	// a has garbage value which can't be changed
	//In C++ uninitialised const int a; is not permissive
	printf("%d\n", a);
	//a = 10; //gives error
	return 0;
}
