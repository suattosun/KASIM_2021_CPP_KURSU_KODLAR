#include <iostream>

// implicit conversion between address types and integral types:
int main() {
	
	// implicit conversion from int ==> int* in c is legal compiler gives a warning, in cpp syntax error
	int x = 10;
	int* p = x;
	
	// implicit conversion from int* ==> int in c is legal compiler gives a warning, in cpp syntax error
	int* p2 = &x;
	int y = p2;

	// implicit conversion between different address types is legal in c, syntax error in cpp
	char* charptr = p;

	// implicit conversion from void * to any address type is legal in c, syntax error in cpp
	int z = 10;
	void* p3 = &z;
	int* iptr = p3;
}
