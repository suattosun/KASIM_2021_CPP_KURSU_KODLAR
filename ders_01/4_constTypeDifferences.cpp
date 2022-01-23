
// global const objects have internal linkage in cpp, but external linkage in c
// external linkage means you can use it in any source files
int x = 10;			// x has external linkage both in c and cpp
const int y = 20;	// y has external linkage in c but internal linkage in cpp !!!

// static globals have internal linkage both in c and cpp
static void func(int);

int main() {

	// in cpp const objects must be initialized
	// in c you do not have to initialize const objects but they hold a garbage value which you can't change (useless)
	const int a;

	// top level const: const pointer to int or rigt const:
	int x = 10;
	int y = 15;
	int* const ptr = &x;
	ptr = &y;			// syntax error in both c and cpp
	*ptr = 345;			// completely fine

	// low - level const: pointer to const int or left const:
	const int* ptr2 = &x;	// note same with int const* ptr = &x;
	ptr2 = &y;				// is ok
	*ptr2 = 15;				// syntax error in both c and cpp

	// in cpp const object must be inited 
	int* const ptr3;		// syntax error 
	const int* ptr4;		// this is fine

	// in cpp const variables can be used wherever a const is needed, in c it is not valid:
	const int size = 10;
	int a[size] = { 0 };

}
