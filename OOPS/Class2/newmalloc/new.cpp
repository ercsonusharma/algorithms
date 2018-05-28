#include <iostream>
#include <cstdlib>
using namespace std;
class Obj{
	public:
		Obj(){
			cout << "Constructing Obj" << endl;
		}
		~Obj(){
			cout << "Destroying Obj" << endl;
		}
};
/*
	Compiler inserts code in destructor too(before our hand written code)
*/
int main(){
	Obj* obj = new Obj;	// ctor called
	delete obj;	// new throws exception if no memory is allocated. It never returns NULL
	//free(obj);	// returns deallocated memory to heap (always)
	
	//Delete knows whether freed memory should go to heap or freestore - free always  returns memory to heap => above line is undefined bahaviour
	return 0;
}
