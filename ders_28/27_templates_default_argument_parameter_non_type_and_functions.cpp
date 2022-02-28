#include <iostream>

using namespace std;
/*
templates:
	templates' default argument:
		non-type parameters can have default argument too

	note that before modern cpp, cpp11, default template parameter could be used only for class templates
		there was no facility for function templates
*/
 
template <int x = 10, int y = 20, int z = 30>
class Nec {
};


class Myclass {

};

template<typename T, typename U = Myclass>
void func(T x, U y = U{})
{

}

int main() {
	Nec<> mynec1;
	Nec<2> mynec2;
	Nec<2, 5> mynec3;

	cout << typeid(mynec1).name() << '\n';
	cout << typeid(mynec2).name() << '\n';
	cout << typeid(mynec3).name() << '\n';

	func(12);		// this call is like func(12, Myclass{})
	func(2.3, Nec{});
}