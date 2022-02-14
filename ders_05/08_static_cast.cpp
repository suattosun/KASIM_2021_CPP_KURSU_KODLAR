/* C++'da static_cast operatörüne bir örnek. */
#include <iostream>

int main()
{
    int x = 10;
    int y = 56;

    if(y){
        double dval = static_cast<double>(x) / y;
    }
}
