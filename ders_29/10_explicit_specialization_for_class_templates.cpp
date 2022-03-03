#include <iostream>

using namespace std;

/*
templates:
	explicit specialization:
		explicit specialization can have a completely different interface, different functions etc
*/

template <typename T>
class Myclass {
public:
	void f1();
	void f2();
	void f3();
};

template <>
class Myclass<int> {
public:
	void g1();
	void g2();
	void g3();
};

int main() {
	Myclass<double> dm;
	dm.f1();
	dm.f2();
	dm.f3();

	Myclass<int> im;
	im.g1();
	im.g2();
	im.g3();

}