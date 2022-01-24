#include <iostream>

// no-return type is handled as int (implicit) in C, syntax error in CPP
func() 
{

}

// in C following means parameters are not given, in CPP it means no parameter
int foo1();
// in C following foo takes no parameters, in CPP it means no parameter
int foo2(void);

// old-style function definition is legal in C, syntax error in CPP
int foo3(a, b, c) double b, c; 
{
	return a; 
}

int main() 
{
	foo1(1, 3, 4);	// valid in C, syntax error in CPP
	func2(3, 5);	// if function is called before declared, in C it is implicit function declaration
					// and compiler only gives a warning, but in CPP it is syntax error because it could not be found during name lookup
}
