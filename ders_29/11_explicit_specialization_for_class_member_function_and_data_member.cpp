#include <iostream>

using namespace std;

/*
templates:
	explicit specialization:
		explicit specialization can be done for class's member function or static data member
*/

template <typename T>
class Nec {
public:
	static int x;
};

template <>
int Nec<int>::x = 66;

template <>
int Nec<double>::x = 22;


template <typename T>
class Myclass {
public:
	void func(T)
	{
		cout << "primary template \n";
	}

};

template <>
void Myclass<int>::func(int)
{
	cout << "explicit specialization Myclass<int>::func(int) \n";
}

int main() {

	std::cout << Nec<int>::x << '\n';
	std::cout << Nec<double>::x << '\n';


	Myclass<double> dm;
	dm.func(10);
	Myclass<int> im;
	im.func(10);
}