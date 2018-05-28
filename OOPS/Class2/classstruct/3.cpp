#include <iostream>
using namespace std;

struct notnode
{// Default access specifier = public
// Can contain functions too
	int a;
	notnode()
	{
		a = 5;
		cout << "Constructor" << endl;
	}
	~notnode()
	{
		cout << "Destructor" << endl;
	}
};

int main ()
{
	notnode nn; //No need for struct keyword here
	cout<<nn.a<<endl;
	return 0;
}
