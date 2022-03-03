#include <iostream>

using namespace std;

/*
templates:
	explicit specialization: or full specialization for classes
		a template can have multiple specialization as long as specializations are done for different types
		explicit specialization can have a completely different interface, different functions etc
*/

template <typename T>
class Myclass {
public:
	Myclass()
	{
		cout << "primary template\n";
	}

};

template <>
class Myclass<int>
{
public:
	Myclass()
	{
		cout << "explicit specialization for Myclass<int> \n";
	}
};

template <>
class Myclass<float>
{
public:
	Myclass()
	{
		cout << "explicit specialization for Myclass<float> \n";
	}
};


int main()
{
	Myclass<double> m1;
	Myclass<int> m2;
	Myclass<float> m3;
	Myclass<char> m4;

}