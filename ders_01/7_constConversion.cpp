
// T * and const T* are different types
// in c conversion from const T* to T* is not correct but legal, it is syntax error in cpp
int main() {

	const int x = 10;
	int* p = &x;		// valid in c, syntax error in cpp

	// now it is more clear why following is syntax error in cpp
	char* ptr = "mustafa";		// "mustafa" has the type of const char[8] which is converted to const char*
}
