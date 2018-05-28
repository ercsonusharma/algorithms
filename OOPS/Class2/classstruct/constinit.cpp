//use of initializer list
#include <iostream>

using namespace std;

class cinit
{
	public:
		const int a;  // Can't initialize here
		cinit() : a(10)    //obj. created here only
		{
			// during construction a will be given memory and a value too from the initializer list
			// will have to initialize const when giving it memory
			a = 10;
			cout << a << endl;
		}
};

int main()
{
	cinit obj;
	return 0;
}
