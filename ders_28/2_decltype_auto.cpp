#include <iostream>

/*
templates:
	function templates:
		decltype(auto):
			with decltype(auto) compiler deduce a type from initializing expression using decltype rules:
			recall decltype rules:
				if operand is a name, result is that name's type
				if operand is a reference, result is a reference
				and keeping const
				if operand is an expression, then value category of expression is checked:
					PR -> T
					L -> T&
					X -> T&&

			decltype(auto) generally will be used for return type of templates
					
*/


int&& foo();

int main() {
	
	// auto x = 10;				// deduction is done according to auto rules
	// decltype(auto) y = 10;	// deduction is done according to decltype rules

// if operand is a name, result is that name's type

	int x{};
	int& r{ x };
	decltype(x) y = 10;		// int
	decltype(r) z = y;		// int&

	const int a = 5;
	decltype(a) a1 = 10;	// const int

	int ar[] = {2, 4, 6};
	decltype(ar)br;			// int[3]

// if operand is an expression:

	int b = 10;
	decltype(b + 5) c;		// PR - int
	decltype((b)) d;		// L - int& and syntax error as it has to be inited
	decltype(foo()) e = 30;	// X - int&& e = 30;

	int* ptr{ &b };
	decltype(*ptr) f = c;		// L - int&
	
	//
	decltype(auto) g = 10;		// expr 10 is PR so int
	decltype(auto) g1 = b;		// PR - int
	decltype(auto) g2 = (b);	// L - int&
	decltype(auto) g3 = foo();	// X - int&&
}

