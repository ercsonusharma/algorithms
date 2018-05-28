#include <stdio.h>
int main ()
{
	char a[2] = {0x00, 0x01};
	short int b = *(short int *)a;
	/*
		short int = 2 bytes
	*/
	printf ("%d\n", b);
	/*
		Big Endian = 0x 00 01 = 1(value)
		Little Endian = 0x 01 00 = 256(value)
	*/
	return 0;
}
/*
	There are 2 types of systems:
	Little Endian - LS byte at lower address
	Big Endian    - LS byte at higher address
	Homework: Write code to check if a system is little endian or big endian.
*/
/* a = 0xab cd dc ba
	    (MSB)	 (LSB)
Can either store as: ab cd dc ba  (Big Endian)
						OR,
					 ba dc cd ab (Little Endian) (intel)
*/
