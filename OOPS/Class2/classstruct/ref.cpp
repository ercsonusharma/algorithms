#include <iostream>
using namespace std;
int main()
{
	int x;
	int &ref = x;
	/*
		ref is an alias of x
		change x -- both ref and x will change
		change ref -- both ref and x will change
		reference must be initialized
		ref and x will have same address
	*/
	x = 10;
	cout << x << " " << ref << endl;
	int b = 100;
	ref = b;	// ref's add. same as x
	// it's like writing x = b only
	cout << x << " " << b << " " << ref << endl;
	ref--;	// ref will always refer to x in this prog.
	cout << x << " " << b << " " << ref << endl;
	return 0;
}
