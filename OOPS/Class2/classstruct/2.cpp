#include <iostream>
using namespace std;
class Imed
{
	int a;
	public:
		Imed()
		{
			//int a;
			this->a = 5;
			/*
				this = refers to current object
			*/
			//a = 5;
		}
		/*Imed(int i)//parametrized ctor
		{
			this->a = i;
			//a = i;
		}*/
		~Imed()
		{
			cout<<"Destructor of "<<a<<endl;
		}
};

int main ()
{
	Imed arr[3];	
	//Imed arr[3] = {Imed(1), Imed(2), Imed(3)}; //Require parametrized ctor for this
	return 0;
}
