#include <iostream>

using namespace std;
/*
templates:
	templates' default argument:
		template <typename T = int>
	if parameter is not given for template, then default template parameter will be chosen by compiler
	just like in functions:
		all the parameters coming after a default argument parameter, must have a default arguemnt as well
*/

template<typename T = int>
class Myclass {
public:
	Myclass() {
		cout << "type T is: " << typeid(T).name() << '\n';
	}

};

int main() {

	Myclass<double> m1;
	Myclass<> m2;

	// note that following can be done only with cpp20, CTAD, abbreviated template arguments:
	Myclass x;	// if it is not cpp20, you need to write <>
}