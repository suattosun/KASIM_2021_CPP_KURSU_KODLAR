#include <iostream>
#include<string>

using namespace std;
/*
templates:
	class templates:
		a class template's speicialization is just like a class but there are two differences:
			1. compiler writes the code for the class template specialization
			2.	when you create a class, compiler compiles all member functions, but if it is a class template compiler only
				compiles the codes for the used functions
				this shrinks the object size, so with templates it has a smaller object size

*/

class Sample {

};

template<typename T>
class Nec {
public:
	///
	void foo() {
		T x;
		++x;		// this would be compile error if compiler writes this function's code
	}

};

int main() {

	// for instance here compiler only writes ctor with const char* parameter and dtor
	string name{ "ismail ucar" };

	auto len = name.length();		// now compiler writes lenght() function's code


	Nec < Sample > mynec;	// this is not syntax error (note that compiler only writes Nec<Sample> ctor and dtor)
	// mynec.foo();			// once we call the foo() it will be syntax error
}