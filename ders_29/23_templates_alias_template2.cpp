#include <iostream>
#include <set>

using namespace std;

/*
templates:
	alias template: cpp11

*/

// lets pretend we are client of this class and are using 2nd argument as int mostly, you can do it by an alias template
template <typename T, typename U>
class Myclass {

};

template <typename T>
using Nec = Myclass<T, int>;

template <typename T>
using gset = std::set<T, std::greater<T>>;

int main() {

	// now followings are same:
	Myclass<double, int> m1;
	Nec<double>  m2;

	// for instance set template is easy use
	set<int> myset;
		// is actually same with following, as rest is default you do not need to indicate those
		set<int, less<int>, allocator<int>> myset2;
	// but if you need something like greater to smaller then:
	set<int, greater<int>> myset3;
		// this is not intuitive, so you can make it better with an alias template:
		gset<int> myset4;

}
