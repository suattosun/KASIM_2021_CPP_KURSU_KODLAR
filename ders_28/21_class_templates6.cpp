#include <iostream>

using namespace std;
/*
templates:
	class templates:

*/


template<typename T>
class Sample {

};

template<typename T>
class Myclass {
public:
	foo(Myclass);
};

int main() {
	Sample<int> x;
	Sample<double> y;
	x = y; // is syntax error as they do not have type conversion between them


	Myclass<int> m1;
	Myclass<double> m2;
	m1.foo(m2);		// syntax error as each foo() function has different parameters: Myclass<int> and Myclass<double>

}