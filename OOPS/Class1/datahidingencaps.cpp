#include<iostream>
using namespace std;
class A
{
	private:
		int a;
	public:
		void fun()
		{
			cout << a << endl;
		}

		void gun()
		{
			cout << a + 5 << endl;
		}
};

int main()
{
	A b;
	b.fun();
	b.gun();
	//cout << b.a << endl; // a is private
	return 0;	
}
