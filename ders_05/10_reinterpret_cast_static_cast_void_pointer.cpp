/* 
* C++'da bir pointer türünden farklı bir pointer türüne dönüşüm için reinterpret_cast operatörü kullanılır.
* Fakat bu durumun bir istisnası void* kullanımındadır.
*/
#include <iostream>
#include <cstdlib>

int main()
{
    std::size_t n = 100;
	
    int* p1 = reinterpret_cast<int*>(std::malloc(n * sizeof(int)));
    int* p2 = static_cast<int*>(std::malloc(n * sizeof(int))); //static_cast ile de dönüşüm gerçekleştirilebilir.
}