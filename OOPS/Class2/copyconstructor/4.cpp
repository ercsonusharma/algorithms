#include <iostream>
using namespace std;
class Shallow{
	char* str;
	public:
		Shallow(){
			str = new char;
		}
		~Shallow(){
			cout << "Dtor\n";
			delete str;
		}
};
void f(Shallow X){} // Desturctor for X called - deletes str => seg fault
int main(){
	Shallow obj;
	f(obj); 
	return 0;
}
