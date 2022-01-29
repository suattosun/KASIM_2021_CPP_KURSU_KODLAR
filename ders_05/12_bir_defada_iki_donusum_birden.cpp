/* 
* C++'da bir defada iki dönüşüm birden yapılamaz! 
* Bunun için ayrı ayrı dönüşüm yapmak gerekir.
*/

#include <iostream>
int main()
{
    const int x = 10;

    char* p = reinterpret_cast<char*>(&x); //hem const bir adresten const olmayan bir adrese, hem de int* türünden char* 
    //türüne bir dönüşüm aynı anda yapılmaya çalışılıyor. Bu durum syntax error.

    //fakat
    char* p1 = const_cast<char*>(reinterpret_cast<const char*>(&x)); //legal bir dönüşüm
    //veya
    char* p2 = reinterpret_cast<char*>(const_cast<int*>(&x)); //legal bir dönüşüm
}