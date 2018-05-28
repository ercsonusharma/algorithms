/*
	Concept: Shallow copy vs Deep copy
*/
#include <iostream>
using namespace std;
class Shallow {
	private:
		int i;
	public:
		int *pi;
		Shallow() {
			pi = new int;
		}
		Shallow(const Shallow& copy) {
			i = copy.i;
			pi = copy.pi; //Pointer copied as it is
		}
};

class Deep
{
	private:
		int i;
	public:
		int *pi;
		Deep()
		{
			pi = new int;
		}
		Deep(const Deep& copy)
		{
			i = copy.i;
			pi = new int(*copy.pi); //Value copied into a new location
		}
};

int main()
{
	Shallow s;
	Shallow s1 = s;
	cout << s.pi << " " << s1.pi << endl;
	Deep d;
	Deep d1 = d;
	cout << d.pi << " " << d1.pi << endl;
	return 0;
}
