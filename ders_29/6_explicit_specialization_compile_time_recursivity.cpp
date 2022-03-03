#include <iostream>

using namespace std;

/*
templates:
	explicit specialization: or full specialization
		meta programming sample using compile time recursivity

		compile time recursivity:
			compiler is creating more than one specialization from the same template
				compiler is creating different specializations for different template arguments
*/

template <int n>
constexpr int factorial() // as this function has no parameters, the only way to call it is using explicit template argument
{
	return n * factorial<n - 1>();
}

// this explicit specialization is to stop compile time recursivity
template <>
constexpr int factorial<0>()
{
	return 1;
}

int main()
{
	constexpr auto val = factorial<5>(); // if there is no explicit specialization: fatal error C1202: recursive type or function dependency context too complex

	cout << val << '\n';
}
// as it is constexpr functions done during compile time, your program's exe size is not effected by this
