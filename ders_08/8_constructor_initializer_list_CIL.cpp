#include <iostream>
#include <string>
/*
constructor initializer list CIL:
	is called member initializer list (MIL)
	once an object is created, its members are created too
		and object's data members should have a valid value so that that object can be used, who is doing this? ctor()
			ctor's main job is to initialize data members so that client codes can use objects
		ctor can sometimes do simple things like initializing primitive types, but sometimex complex things like to use that
			object there must be a connection to a database, so ctor must do database connection,
			or when the object is created logging must start, so ctor creates a log file etc

	cil is used to initialize class's non-static data members
		syntax is same for inline ctor definition, or in cpp file
		if you use cil syntax you have to provide ctor's main block {} even if you do not have anything else to do
		with modern cpp you can use value initialization {}

*/

class Myclass {
public:
	Myclass() : mx(0), my(0) {
	}
	Myclass(int x);
	Myclass(int x, int y);

private:
	// classes data members will be created once an object of this class is created
	int mx, my;
	std::string std;

};

// cil in cpp can be like this:
Myclass::Myclass(int x, int y) : mx(x), my(y) {
}
Myclass::Myclass(int x) : mx{x}, my{ 0 } {
}
