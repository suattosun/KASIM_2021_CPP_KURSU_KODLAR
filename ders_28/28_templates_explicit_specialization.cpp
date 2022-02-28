#include <iostream>

using namespace std;
/*
templates:
	explicit specialization (full specialization) used for both class and function templates, mostly for class templates
		(the other is partial specialization and it is only used for class templates)
	explicit specialization:
		apart from primary tempalate code, when you provide an explicit specialization code
			explicit specialization code will be used whenever it is needed
		it is used when primary template's code is not suitable for some types, or if we need to end a recursive call during
			compile time
		you can have multiple explicit specializations
		explicit specialization code does not need to have the same interface with primary template code
			note that vector<bool> is a specialization too, holds values by bits
*/

template <typename T>
class Myclass {
public:
	Myclass() {
		cout << "primary (master) template \n";
	}

	void f1();
};

// explicit specialization uses diamond
template<>
class Myclass<int> {
public:
	Myclass() {
		cout << "Myclass<int> explicit specialization \n";
	}

	void f2();	// interface can be different than primary template
};

template<>
class Myclass<char> {
public:
	Myclass() {
		cout << "Myclass<char> explicit specialization \n";
	}

};

int main() {
	Myclass<int> m1;
	Myclass<char> m2;
	Myclass<double> m3;
	Myclass<long> m4;

}