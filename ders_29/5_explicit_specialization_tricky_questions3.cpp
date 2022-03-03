#include <iostream>
#include <string>
#include<cstring>

using namespace std;

/*
templates:
	explicit specialization: or full specialization
*/

template <typename T>
void foo(T)
{
	cout << "1\n";
}


template <>
void foo(int*)
{
	cout << "2\n";
}

template <typename T>
void foo(T*)
{
	cout << "3\n";
}

template <>
void foo(int*)
{
	cout << "4\n";
}


int main() {

	int* p{ nullptr };
	/*
		again 1 and 3 are added to function overload resolution and 3 wins
		and afterwards as explicit specialization 4 is suitable, 4 is called
	*/
	foo(p);
}