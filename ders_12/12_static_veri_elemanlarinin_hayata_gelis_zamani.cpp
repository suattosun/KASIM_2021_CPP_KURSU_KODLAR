/*
* Global değişkenler ve sınıfların statik veri elemanları 
* daha main() fonksiyonu çağrılmadan hayata gelirler
*/

#include <iostream>

int foo()
{
    std::cout << "foo cagrildi\n";
    return 5;
}

class Myclass {
    inline static int x = foo();
};

int main()
{
    std::cout << "main basladi\n";
}

/*
    ÇIKTI AŞAĞIDAKİ GİBİ OLUR :
    foo cagrildi
    main basladi
*/
