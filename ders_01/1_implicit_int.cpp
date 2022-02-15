#include <iostream>

// no-return type is handled as int (implicit) in c, syntax error in c
func() {

}

// in c following means parameters are not given, in c it means no parameter
int foo1();
// in c following foo takes no parameters, in c it means no parameter
int foo2(void);

// old-style function definition is legal in c, syntax error in c
int foo3(a, b, c) double b, c; { return a; }

int main() {
	foo1(1, 3, 4);	// valid in c, syntax error in c
	func2(3, 5);	// if function is called before declared, in c it is implicit function declaration
					// and compiler only gives a warning, but in c it is syntax error because it could not be found during name lookup
}

void func2(int, int) {
}
