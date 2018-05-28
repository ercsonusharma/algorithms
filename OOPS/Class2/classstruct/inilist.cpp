#include<iostream>

using namespace std;

class IList
{
	int a;
	char b;
	public:
		IList(int c, char d): a(c), b(d) //initializer list
		{
			/*a = c;
			b = d;*/
		}
		void print()
		{
			cout << a << " " << b << endl;
		}
};

int main()
{
	IList obj(4, 'c');
	obj.print();
	return 0;
}
