#include <stdio.h>

int main()
{
	char *p="abc";
	char *q="abc123";
	//p[0] = 'b'; this will give segmentation fault because:
	/*
		p will store address of "abc"
		"abc"(or any other hard coded string) will be stored in the read only memory space - text segment(kal btaya tha na k ye segment read only hota h)
		So, you are not allowed to modify that memory.
	*/
	
	//printf("%u\n", sizeof(*p));
	/*
		p will not get dereferenced...sizeof will know that *p is of char type therefore, size = 1.
	*/
	while(*p==*q)
	{
			printf("%c %c\n",*p,*q);
			p++;
			q++;
	}
	return 0;
}
