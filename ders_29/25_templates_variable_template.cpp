#include <iostream>
#include <set>
#include <vector>
#include <type_traits>

using namespace std;

/*
templates:
	variable template: cpp11
		compiler is instantiating a function template and creating a function
			similarly compiler is instantiating a class template and creating a class
			so class template's specialization is a class
		if it is done from a variable template, then a variable is created
		variable template is significantly used in meta functions
	
*/

// first usage:
// does not have to be constexpr, but generally used that way
template <typename T>
constexpr T pi = T(3.14159433434211424344);
// and you can have a generic template to calculate circle area and use it in any type you want:
template <typename T>
T circlearea(T& r){
	return pi<T> *r * r;
}

// second usage: meta functions
template <typename T>
struct Nec {
	constexpr static bool value{}; 
	// while using it you keep writing like Nec<int>::value, so why not use it like Nec<int> ? how can we do that?
};
template <typename T>
constexpr static bool Nec_v = Nec<T>::value;



int main() {

	// hover about pi and see difference
	pi<double>;
	pi<float>;

	// so now both of the followings are same:
	constexpr auto val1 = Nec<int>::value;
	constexpr auto val2 = Nec_v<int>;

	// and is_pointer_v is done similarly and followings both are same:
	std::is_pointer<int*>::value;
	std::is_pointer_v<int*>;
}