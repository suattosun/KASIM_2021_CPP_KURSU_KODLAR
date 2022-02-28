#include <iostream>
#include<bitset>
#include <memory>
#include<vector>
#include<random>

/*
templates:
	class templates:
		just like function templates, they have template head: template <typename T>
		and we can use T type anywhere in class, and other than that, rest is same with a normal class definition
		you can define functions inline or out of class (but not in *.cpp file), they must be in same file
			if you are defining out of class, then you need the template head
				note template argument T is a name, has a scope, so:
					insead of T you can use something else while defining a function out of class
		for each different template argument T, a new specialization will be done, meanly a new different class will be created
		
		before cpp17, there was no class template argument deduction, you had to write template arguments explicitly,
			but with cpp17 it can be deduced
		CTAD: Class Template Argument Deduction
			deducing template argument using class's ctor
		
*/

template <typename T>
class Myclass {
public:
	T foo();
	T& func(T x);
	int f(int);

private:
	T mx;
};

template <typename U>
U Myclass<U>::foo() {
	///
}

template <int x>
class Nec {
public:
};

int main() {

	// Myclass m; // syntax error as Myclass is not a class, it is a class template

	Myclass<int> m1;		// a Myclass<int> class will be created
	Myclass<double> m2;		// a Myclass<double> class will be created
	m1 = m2;				// syntax error as they are different classes

	Nec<10> n1;
	Nec<20> n2;
	n1 = n2;				// still they are different classes, syntax error


	// there are similar classes in STL:
	std::bitset<16> bs16;
	std::bitset<32> bs32;
	bs16 = bs32;			// still they are different classes, syntax error

	std::unique_ptr<int> up1;
	std::unique_ptr<double> up2;

	// cpp17
	std::vector ivec{ 1,2,3,4 };					// ctad
	std::uniform_int_distribution dist{ 10,20 };	// ctad

}