/*
* Fonksiyonlar aynı skopta bulundukarından birbirlerine overload durumdalar.
* Sonuçları derleme zamanında görmek maksadıyla fonksiyonların geri dönüş tiplerine constexpr eklenmiştir.
*/
#include <iostream>

constexpr int foo(bool){return 1;} //int* türünden bool türüne otomatik dönüşüm olduğundan tek başına kullanılsa dahi çağrılır.
constexpr int foo(void *){return 2;}//int* türünden void* türüne otomatik dönüşüm olduğundan tek başına kullanılsa dahi çağrılır.

int x{}; 

int main()
{
	constexpr int n = foo(&x); //Viable olan her iki fonksiyondan ikincisi seçilir ve n 2 olur.
}