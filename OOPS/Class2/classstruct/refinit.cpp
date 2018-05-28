#include <iostream>

using namespace std;

class rinit
{
	private:
		int b;
		int &c; //= b;  // Can't initialize here
		public:
			rinit() : c(b) 
			{
				cout << b << endl;
			}
};

int main()
{
	rinit obj;
	return 0;
}
