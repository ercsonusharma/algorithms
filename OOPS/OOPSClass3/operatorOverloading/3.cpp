#include <iostream>
using namespace std;
class loc 
{
    int longitude, latitude;
	public:
	    loc() {}
		loc(int lg, int lt) 
		{
			longitude = lg;
			latitude = lt;
		}
		loc operator = (const loc& op2)
		{
			longitude = op2.longitude;
			latitude = op2.latitude;
			return *this; // this = loc*
		}
		void show() 
		{
			cout << longitude << " ";
			cout << latitude << "\n";
		}
};

int main()
{
	loc ob1(10, 20), ob2(30, 40), ob3(50, 60);
	ob1 = ob2;// ob1.operator=(ob2);
	ob1.show();
	ob1 = ob2 = ob3;
	/*ob1.show();
	ob2.show();
	*/
	return 0;
}
