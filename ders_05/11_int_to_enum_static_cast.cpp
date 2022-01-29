/* 
* C++'da int türden enum türüne doğrudan bir dönüşüm yoktur.
* Onun için static_cast kullanabiliriz.
*/
#include <iostream>

enum Color {blue, red, magenta};

int main()
{
    Color mycolor {red};
    int ival = 1;
	
    mycolor = static_cast<Color>(ival);	
}