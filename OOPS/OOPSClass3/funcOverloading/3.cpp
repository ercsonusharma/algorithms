#include <iostream>
using namespace std;
class A
{
	public:	
		int a;
		A(int b = 0)
		{
			a = b;
			cout << "C1" << endl;
		}
		A(){
			cout << "C2" << endl;
		}
};

int main()
{
	A a;	// Can call A() or A(0)
	A b(5);
	cout << a.a << " " << b.a << endl;
	return 0;
}
