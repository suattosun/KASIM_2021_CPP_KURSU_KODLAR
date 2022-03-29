#include <iostream>
#include <string>
#include <vector>
#include "nutility.h"

using namespace std;

/*
lambda expressions:
	it is a closure type
	it is an expression that compiler creates a class againts it and a temporary object
		and you can use () and call its operator()(){} function in place [](){...}()
			it is called immediately invoked function expression IIFE
	they are like nested functions, we do not have nested functions in cpp but we can use lambdas instead
	we can name and use lambda expression several times in code
	and many STL alghoritms are taking a callable parameter (predicate), lambdas are mostly used as predicates
		predicates can be unary or binary: Unpred pred, Bipred pred
	till cpp20 lambda's default ctor and copy assignment function (operator=()) were deleted
		as we need to use these, in cpp20 it is fixed
			to use this there is a condition: lambda's should be stateless, which means it must have no data members
	even if you write completely same lambda code in several places in code, they are all of different types !!!
		so you cannot assign them to one another, syntax error
		you can check types by is_same_v() which gives you a compile type constant
	there is implicit conversion from stateless lambdas to function pointers
	positive lambda idiom:
		when you put a "+" before lambda expression, such lambda expression must be either pointer type or integer type
		so if lambda is stateless, and if you want to make a type deduction not like closure type but function pointer,
			use + before lambda
		it is used when calling function templates with lambdas as well, so parameter will be a function pointer
	rest of the lambdas will be handled later

*/

template <typename T>
void func(T) {

}

int main() {

	auto f = [](int x) {return x * x; };
	
	decltype(f) f1;		// syntax error prior to cpp10 as default ctor was deleted
	decltype(f) f2(f);	// this is fine as copy ctor is used
	f2 = f;				// syntax error prior to cpp10 as copy assignment was deleted

	// in cpp20 to use default and copy ctors, lambda must be stateless:
	int ival{ 10 };
	auto ff = [ival](int x) {return x * ival; };
	// decltype(ff) ff1;		// syntax error as lambda is not stateless
	decltype(ff) ff2(ff);
	// ff2 = ff;				// syntax error as lambda is not stateless

	// even if you write completely same lambda code in several places in code, they are all of different types
	auto f3 = [](int x) {return x + 5; };
	auto f4 = [](int x) {return x + 5; };
	is_same_v<decltype(f3), decltype(f4)>;	// hover over and see this const is false
	cout << typeid(f3).name() << '\n';		// you can even print and see their names are different
	cout << typeid(f4).name() << '\n';

	// there is implicit conversion from stateless lambdas to function pointers
	int(*fptr)(int) = [](int x) {return x + 5; };
	cout << fptr(5) << '\n';

	// positive lambda idiom:
	auto f5 = +[](int x) {return x + 5; };		// try with + and its type will be function pointer type not closure type
	cout << typeid(f5).name() << '\n';			// and this is important when using with templates
	func(+[](int x) {return x + 5; });			// T will be function pointer
	func([](int x) {return x + 5; });			// T will be closure type

}