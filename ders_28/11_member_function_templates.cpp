#include <iostream>
#include <string>
#include <vector>
#include <list>

/*
templates:
	function templates:
	member function templates:
		a class's member functions and ctors can be template function too (this is different than class templates)
*/

class Myclass {
public:
	
	// instead of using several member function we can write a member function template
	//void func(int) {
	//	std::cout << "Myclass::func(int)\n";
	//}
	//void func(double) {
	//	std::cout << "Myclass::func(double)\n";
	//}
	//void func(long) {
	//	std::cout << "Myclass::func(long)\n";
	//}

	template <typename T>
	void func(T) {
		std::cout << "Myclass.func(T) type: "<< typeid(T).name()<< '\n';
	}

};

class Nec {
public:
	template <typename T>
	Nec(T) {
		std::cout << "Nec::Nec() T is : " << typeid(T).name() <<'\n';
	}
};

int main() {
	Myclass m;

	m.func(12);
	m.func(1.2);
	m.func(5L);
	m.func('A');

	Nec mynec1{ 12 };
	Nec mynec2{ 1.2 };
	Nec mynec3{ "ahmet" };
}