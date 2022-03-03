#include <iostream>
#include <type_traits>

using namespace std;

/*
templates:
	partial specialization:
		meta function:
			a sample to check whether a type is pointer during compile time
*/

template <typename T>
void func(T x) {
	cout << std::boolalpha << std::is_pointer<T>::value << '\n';
}

int main() {

	// bring mouse on value and see whether it is false or true
	auto x = std::is_pointer<int>::value;
	auto y = std::is_pointer<int*>::value;

	// by using is_pointer() we can check whether the parameter sent to func is pointer or not during compile time !!!
	func(12);
	int* p{};
	func(p);

}