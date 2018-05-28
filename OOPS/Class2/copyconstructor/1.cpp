#include <iostream>
using namespace std;
class A
{
	public:
		int a;
		A(int i)
		{
			a = i;
			cout << "Constructor\n";
		}
		A(const A &c)
		{/*
			const so that b can't be changed even mistakenly
		*/
			this->a = c.a;
			cout << "Copy Constructor\n";
		}
		~A()
		{
			cout << "Destructor\n";
		}
};
int main()
{
	A a(1);		// Simple constructor called
	A b = a;	// Copy constructor called (Initialization)
	A c(b);		// Copy constructor called (Argument passing)
	/*A d(1);	
	d = a;		// Assignment (Not Initialization)
	*/
	cout << a.a<<endl;
	cout << b.a<<endl;
	cout << c.a<<endl;
	return 0;
}




