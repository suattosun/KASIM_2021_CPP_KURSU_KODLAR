#include <iostream>

using namespace std;

/*
templates:
	partial specialization:
		a question: do not use cpp11, modern cpp, write a meta function that calculates a power b during compile time
		meta function:
			it is a class template which can evaluate value or argument type during compile time
				normal functions does the calculations etc during runtime
			there are two types of meta functions
				1. value calculating meta functions (we have already done one, factorial)
					class has a constexpr static data member named "value"
						Power<5,7>::value is 5 to power 7
				2. type calculating meta functions
			note: meta function is not a function template, it is a class template, it is called "meta function" as
				a calculation is done, and calculation is done during compile time
*/

// a sample for value calculating meta function:
template <size_t base, size_t exp>		// those are template non-type parameters
struct Power {
	constexpr static size_t value = base * Power<base, exp - 1>::value;
};
// now we need to create a partial specialization to stop this recursivity (not explicit specialization)
template<size_t base>
struct Power<base, 0u> {
	constexpr static size_t value = 1;
};

int main() {

	constexpr auto val = Power<2, 5>::value;
}