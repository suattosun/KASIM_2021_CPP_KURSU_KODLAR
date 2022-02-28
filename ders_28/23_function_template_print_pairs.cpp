#include <iostream>
#include <utility>
#include <string>

using namespace std;
/*
templates:
	as a sample to print pair objects with cout
	to do that we will use a function template
*/

// there is no standart function, but we can write one:
template<typename T, typename U>
std::ostream& operator<<(std::ostream& os, const std::pair<T, U>& p) 
{
	return os << "[" << p.first << ", " << p.second << "]";
}

int main() {

	pair<int, double> p1{ 2, 3.4 };
	pair<const char*, int> p2{ "alican", 987 };

	cout << p1 << '\n' << p2 << '\n';

	// now try something crazy and see how it is printed, and see how mighty templates!
	auto x = make_pair(make_pair(make_pair(12, 4.5), make_pair("ali", 3.4)), make_pair('A', 'Z'));
	cout << "x's type: " << typeid(x).name() << '\n';
	// to print following, compiler will write 5 different operator<< functions for each different paramatered make_pair() !!!
	cout << x;

}