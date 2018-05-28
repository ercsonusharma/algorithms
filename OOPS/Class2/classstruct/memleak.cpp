//Need of destructor

#include <iostream>
#include <cstdlib>
using namespace std;
class Basic{
	int *ptr;
	public:
		Basic(){
			ptr = (int *)malloc(sizeof (int));
		}
		~Basic(int a){
			free(ptr);
		}
};
int main()
{	
	Basic obj;
	return 0;
}






