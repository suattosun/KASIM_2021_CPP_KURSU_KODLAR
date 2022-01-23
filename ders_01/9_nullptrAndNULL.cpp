#include <iostream>

//NULL is a macro in c, and is(void*)0;
// in c, int* p; p = 0; is done by NULL pointer conversion

// nullptr is a keyword in cpp its type is nullptr_t
// do not use nor NULL neither 0, use: int* ptr = nullptr;

using namespace std;
int main() {
	int* p = nullptr;
	cout << "p:" << p << "\n";

	// nullptr does not have conversion to any other types. 
	int ptr = nullptr; // is syntax error.
}
