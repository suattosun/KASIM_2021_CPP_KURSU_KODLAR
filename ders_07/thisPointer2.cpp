
//this pointer ve operator overloading ornegi

#include <iostream>

int main()
{
	using namespace std;
	int a = 10;
	double b = 2.3;
	unsigned long c = 45u;

	//cout << a << b << c;
	cout.operator<<(a).operator<<(b).operator<<(c);

}