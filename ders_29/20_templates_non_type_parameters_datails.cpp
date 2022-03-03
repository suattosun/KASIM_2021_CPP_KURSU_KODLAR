#include <iostream>
#include <cstddef>

using namespace std;

/*
templates:
	non-type parameter:
		if template's non-type parameter is a pointer, then template argument must be a static lifetime object address
			template's non-type parameter can be integral, pointer, reference, or function pointer, real numbers (cpp20),
				literal type (cpp20)


*/

template <int val>
class Nec {

};

template <int *p>
class Myclass {

};
int x{};

template <const char* p>
class Myclass2 {

};
char str[] = "mustafa";


// cpp20 revolution non-type parameters can be real numbers:
template <double dx>
class Myclass3 {

};

// cpp20 revolution non-type parameters can be literal types:
struct A {

};
template <A ax>
class Myclass4 {

};


int main() {

	Nec<10> mynec;


	// int x{};				// when you define x here, following will be syntax error
	// static int x{};		// this one is ok
	Myclass<&x> m;

	Myclass2<"alican"> m2;		// before cpp20 you cannot use string literals, syntax error
	Myclass2<str> m3;			// now it is ok

}