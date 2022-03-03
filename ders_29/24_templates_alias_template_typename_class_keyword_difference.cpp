#include <iostream>
#include <set>
#include <vector>

using namespace std;

/*
templates:
	alias template: cpp11
		typename and clas difference which are used in template definition: template <class T> template <typename T>
		in function templates T::value_type is handled as class's static data member
			so to use T as a type name you need to use like this:
				typename T::value_type x;
				and instead of this typename usage you cannot use class keyword
			template's biggest issue: error messages can be very long like 300-500 lines !!! cpp20 makes it better
		alias templates are used to alias a function template and easy use of it
*/

//template <typename T>
//void func(T x) {
//	
//	T::value_type x;		// will be syntax error if value_type is not T's static data member
//
//	// if you want to use typename T's nested type and you want it to depended to T then:
//	typename T::value_type x;	// here T::value_type will be handled as a typename, and class keyword cannot be used here
//}

template <typename Container>
void func(Container c) {
	
	// iterators are a nested type of containers
	// Container::iterator iter = c.begin();	// 'iterator': use of dependent type name must be prefixed with 'typename'
	typename Container::iterator iter = c.begin();

}

int main() {

	vector<int> ivec;
	func(ivec);

}

// what is the relationship with alias templates? you can use an alias template to get rid of using "typename" over and over
template <typename T>
using veciter = typename vector<T>::iterator;
