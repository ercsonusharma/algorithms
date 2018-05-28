#include <stdio.h>
int main()
{
	char as[] = "\\0\0";
	
	int i = 0;
	do
	{
		switch(as[i++])
		{
			
			printf("%d\n",sizeof(++i)); /
			/* 
				This statement will never get executed because cases are actually jump labels like go to labels. 
				So this line is skipped and we go directly to the appropriate case label.
			*/
			
			case '\\' : printf("A\n");
						break;
			case 0   :  printf("B\n");
						break;
			default : 	printf("C\n");
						break;
		}
	 } while(i<3);
	 return 0;
}
