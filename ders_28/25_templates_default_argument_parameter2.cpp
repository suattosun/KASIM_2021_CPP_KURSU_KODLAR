#include <iostream>

using namespace std;
/*
templates:
	templates' default argument:
		a prior argument parameter can be the next parameter's default argument
		a template parameter can be another template as well
*/

template<typename T, typename U = T>
class Myclass {
};


// a template parameter can be another template
template<typename T>
class Nec {

};

template<typename T, typename U = Nec<T>>
class Myclass2 {
};

int main() {

	Myclass<int, double> m1;
	Myclass<int> m2;
	Myclass<long> m3;
	
	cout << "typeid name: " << typeid(m1).name() << '\n';
	cout << "typeid name: " << typeid(m2).name() << '\n';
	cout << "typeid name: " << typeid(m3).name() << "\n\n\n";


	Myclass2<int> m4;
	Myclass2<double> m5;
	cout << "typeid name: " << typeid(m4).name() << '\n';
	cout << "typeid name: " << typeid(m5).name() << '\n';

}