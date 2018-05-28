#include <iostream>
#include <cstdlib>
using namespace std;
class Obj
{
	public:
		Obj()
		{
			cout << "Constructing Obj" << endl;
		}
		~Obj()
		{
			cout << "Destroying Obj" << endl;
		}
};

int main()
{
	Obj* obj = (Obj*)malloc(sizeof(Obj));
	if (obj)//malloc may return NULL on failure
		free(obj);
	return 0;
}
