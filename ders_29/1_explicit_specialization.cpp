#include <iostream>

using namespace std;
/*
templates:
	explicit specialization: or full specialization
		you tell compiler: for some special template arguments, if they are used, do not use main template, use this given one
		explicit specialization is used for both function and class templates
		why we need it?
			1. the template we use won't be suitable for some template arguments, so we are providing another template
				to compiler to use
			2. it is used techically in TMP (template meta programming)
			3. to stop recursive function templates

		so we will have two templates: primary template (or master template), and explicit specialization
*/

// primary (master) template
template<typename T>
void func(T)
{
	cout << "primary template's argument T is: " << typeid(T).name() << '\n';
}

template<>
void func(int x)
{
	cout << "explicit specialization for func(int) \n";
}

int main()
{
	func(2.4);
	func('A');
	func(4>2);
	func(4);

}