#include <iostream>

using namespace std;

/*
templates:
	partial specialization:
		is only for class templates, and variable templates, not for function templates
		it is a specialization for a group of arguments, not only one argument type (which is explicit specialization)
			like specialization for pointers, but all type of pointers
			array types, or some types which fullfills some rules
		you can have more than one partial specialization as long as there is no ambiguity
*/

// note that explicit specialization does not have to be done only for one template argument, but many
template <typename T, typename U, int x>
class Nec{

};

template <>
class Nec<int, double, 5> {

};

// template partial specialization syntax is different:
template <typename T>
class Myclass {
public:
	Myclass()
	{
		cout << "primary template \n";
	}
};

template <typename T>
class Myclass<T*>{		// this partial template will be used for all pointer types
public:
	Myclass()
	{
		cout << "partial specialization Myclass<T *> \n";
	}
};

template <typename T>
class Myclass<T&> {		// this partial template will be used for all pointer types
public:
	Myclass()
	{
		cout << "partial specialization Myclass<T &> \n";
	}
};

template <typename T>
class Myclass<T[]> {		// this partial template will be used for all pointer types
public:
	Myclass()
	{
		cout << "partial specialization Myclass<T []> \n";
	}
};

template <typename T>
class Myclass<T[10]> {		// this partial template will be used for all pointer types
public:
	Myclass()
	{
		cout << "partial specialization Myclass<T [10]> \n";
	}
};

int main() {
	Myclass<int> x;
	Myclass<int*> y;
	Myclass<int&> z;
	Myclass<double[]> t;
	Myclass < float [10] > k;
}