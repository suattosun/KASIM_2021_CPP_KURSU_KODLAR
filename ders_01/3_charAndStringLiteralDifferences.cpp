#include <iostream>


int main() {
	
	// chars are int type in c 4Bytes, char type in cpp 1Byte
	printf("size of char: %zu \n", sizeof('A'));

	// changing string literals is undefined in c, syntax error in cpp:
	// "elem"'s type is const char[5] in cpp, char[5] in c
	char* p = "elem"; // you cannot even define this in cpp as it is const char[5]
	p = 'A';
}
