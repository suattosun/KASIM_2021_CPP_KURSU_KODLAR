#include <iostream>
#include <string>
#include<cstring>

using namespace std;

/*
templates:
	explicit specialization: or full specialization
*/

template <typename T>
T get_max(T x, T y)
{
	return x > y ? x : y;
}

// explicit specialization
// uncomment and see const char* calls will produce correct result
//template <>
//const char* get_max(const char* p1, const char* p2)
//{
//	return std::strcmp(p1, p2) > 0 ? p1 : p2;
//}

int main() {

	cout << get_max(12, 45) << '\n';
	cout << get_max(45, 12) << '\n';
	cout << get_max(2.3, 1.2) << '\n';
	std::string s1{ "ayla" }, s2{ "su" };	// lexicographical compare, like in dictionary order compare
	cout << get_max(s1, s2) << '\n';

	// here, if we do not have above explicit specialization we will have problem as it will compare p1 and p2's memory locations
	const char* p1 = "zeynep";
	const char* p2 = "ayse";
	cout << get_max(p1, p2) << '\n';
	cout << get_max(p2, p1) << '\n';
}