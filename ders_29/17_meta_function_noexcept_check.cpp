#include <iostream>
#include <type_traits>

using namespace std;

/*
templates:
	partial specialization:
		meta function:
			some samples
				
*/

template <typename T>
void func(T) {
	/*
		why we need to learn whether a class's move ctor is noexcept or not?
		if we use that class as a template argument, and if we need to produce template code according to class's move ctor is
		noexcept or not, we need to learn it in temaplte

	*/
	// we can check it like this:
	std::is_nothrow_move_constructible<T>::value;

}

/*
during compile time can we check is this class's move ctor is no-except or not?
(no-except guarantee is not throwing any exceptions at all)
*/
class Myclass {
public:
	Myclass() = default;
	Myclass(Myclass&&);				// comment out and check ::value again
	Myclass(Myclass&&)noexcept;		// comment out and check ::value again

};

int main() {

	std::is_nothrow_move_constructible<Myclass>::value;		// see whether value is true or not
}