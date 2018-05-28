#include <iostream>
using namespace std;
class C2;	// Forward declaration
class C1 {
	int a; 
	public:
		C1()
		{
			a = 4;
		}
		void idle(C2 b); 
};

class C2 {
	int b;
	public:
		C2()
		{
			b = 5;
		}
		friend void C1::idle(C2 b);
};

void C1::idle(C2 d)
{
	cout << "IDLE" << endl;
	cout << d.b << endl;
}

int main()
{
	C1 x;
	C2 y;
	x.idle(y);
	return 0;
}
