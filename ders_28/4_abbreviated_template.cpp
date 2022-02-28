#include <iostream>

/*
templates:
	function templates:
					
*/

// cpp20 abbreviated template syntax:
void func(auto x)
{
}
void func(auto &x)
{
}

// cpp20 abbreviated template syntax is same with followings:
template <typename T>
void func(T x)
{
}
template <typename T>
void foo(T &x)
{
}
