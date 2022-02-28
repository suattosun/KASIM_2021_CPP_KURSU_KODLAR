#include <iostream>
#include <vector>
#include <set>
#include <unordered_map>

using namespace std;
/*
templates:
	templates' default argument:
		all of the containers in STL, except one, has a template argument which is responsible from dynamic memory management
			it is allocator
		so dynamic memory management's codes are isolated from container's codes

		for instance:
			you are doing embedded programming and as there is no heap there, and you can use a static memory location for
				the dynamic array's memory. you can do this with an allocator template

*/
 
// a sample Vector:
template<typename T>
class Allocator {

};

template<typename T, typename A = Allocator<T>>
class Vector {

};

// and another sample Set
template<typename T>
struct Less {

};

template<typename K, typename C = Less<K>, typename A = Allocator<K>>
class Set {

};

int main() {

	Vector<int> ivec;
	cout << typeid(ivec).name() << '\n';
	// now see STL's vector is same:
	std:vector<int> ivec2;
	cout << typeid(ivec2).name() << '\n' << '\n';

	Set<int> myset;
	cout << typeid(myset).name() << '\n';
	set<int> myset2;
	cout << typeid(myset2).name() << '\n' << '\n';


	unordered_map<int, double> mymap;
	cout << typeid(mymap).name() << '\n';

}