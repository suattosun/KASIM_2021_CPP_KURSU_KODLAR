/* C++'da const_cast operatörüne bir örnek. */
#include <iostream>

int main()
{
    int x = 2354;
	
    const int* p = &x;
    int* ptr = const_cast<int *>(p);
}