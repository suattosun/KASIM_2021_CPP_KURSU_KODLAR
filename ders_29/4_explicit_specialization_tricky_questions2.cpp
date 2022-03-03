#include <iostream>
#include <string>
#include<cstring>

using namespace std;

/*
templates:
	explicit specialization: or full specialization
		explicit specialization is used widely in class templates
			it is not used frequently for function templates as there can be some problems,
				instead there is a better way: overloading function templates, or writing a function overload
		note explicit specialization is not added to function overload resolution
			explicit specialization wherever it is located it specialize the template before itself
		if there is overloading then, first, the template will be selected from function overload resolution
			after template is selected, then if there is a suitable specialization of selected template,
				specialization will be chosen
*/

template <typename T>
void foo(T)
{
	cout << "1\n";
}

template <typename T>
void foo(T*)
{
	cout << "2\n";
}

template <>
void foo(int*)
{
	cout << "3\n";
}

int main() {

	int* p{ nullptr };
	foo(p);	
	/*
	3 will be selected because as explained above:
		1 and 2 are added to the function overload resolution and 2 is selected, and then because there is an explicit
			specialization of 2, and it is suitable, that is why 3 is called
		if there is overloading then, first, the template will be selected from function overload resolution
			after template is selected, then if there is a suitable specialization of selected template,
				specialization will be chosen

	*/
}