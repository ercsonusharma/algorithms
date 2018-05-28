#include <stdio.h>

#define m(var) ((char*)(&var + 1)) - ((char*)(&var))

/*
	var is a variable, not a datatype
	&var is a pointer to var
	&var + 1 = increase according to var's datatype
	if var was of int type, &var + 1 will take it 4 bytes ahead
	so let var's address was 1000 and var was of type int
	&var + 1 is 1004
	&var is 1000
	on typecasting it to char* and then subtracting(remember we are subtracting two pointers here)
	divide the subtracted value by 1
	(1004 - 1000) / 1 = 4(correct size of int)
*/

//See it in action below...
struct node
{
	int i;
	struct node* next;
};

int main ()
{
	char c;
	int i;
	float f;
	double d;
	int* p;
	struct node s;
	printf ("sizeof(char) = %d\n", m(c));
	printf ("sizeof(int) = %d\n", m(i));
	printf ("sizeof(float) = %d\n", m(f));
	printf ("sizeof(double) = %d\n", m(d));
	printf ("sizeof(int pointer) = %d\n", m(p));
	printf ("sizeof(struct node) = %d\n", m(s));
	return 0;
}
