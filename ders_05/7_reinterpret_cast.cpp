/* 
* C++'da reinterpret_cast operatörüne bir örnek.
* Farklı adres türleri arasındaki dönüşüm reinterpret_cast ile yapılır.
* Kullanımı reinterpret_cast<hedef adres türü>(kaynak adres) şeklindedir.
*/
#include <iostream>

struct Data{
    int a, b, c;
};

int main()
{
    struct Data mydata = {1, 54, 6};
    char* p = reinterpret_cast<char *>(&mydata); //farklı bir tür dönüştürme opratörü kullansaydık syntax hatası alırdık.
}