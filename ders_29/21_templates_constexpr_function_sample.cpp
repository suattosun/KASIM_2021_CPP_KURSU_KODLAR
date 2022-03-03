#include <iostream>

// comment out std as less will be ambiguous
// using namespace std;

/*
templates:
	a constexpr function to compare two arrays lexicographical during compile time

*/

template <typename T, int N, int M>
constexpr bool less(const T(&x)[N], const T(&y)[M]){
	for (int i = 0; i < N && i < M; ++i) {
		if (x[i] < y[i])
			return true;
		if (y[i] < x[i])
			return false;
	}
	return N < M;
}

int main() {

	// normally these do not need to be constexpr
	constexpr int a[] = { 1, 2, 4, 7, 9 };
	constexpr int b[] = { 1, 2, 3, 7, 9 };

	constexpr auto result = less(a, b);

	std::cout << result;
}