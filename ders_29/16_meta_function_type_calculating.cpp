#include <iostream>
#include <type_traits>

using namespace std;

/*
templates:
	partial specialization:
		meta function:
				2. type calculating meta functions

*/

// type alias
template <typename T>
struct Nec {
	using type = int;		// type alias, you can do it with typedef too
};

// partial specialization
template <typename T>
struct Nec<T*> {
	using type = double;		// type alias, you can do it with typedef too
};
int main() {

	Nec<double>::type x;		// hover on x, and see it is int type !!!

	Nec<int>::type y;
	Nec<int*>::type z;

}