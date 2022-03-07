/*************** trailing return types **********************/

/* 
- Template function in return type i 2 türlu olabilir:
    -auto return type
    -trailing return type

## trailing return type:

tmplate <typename T>
auto func(T x) -> decltype(exp);

- func geri donus degerie auto yaziliyor. "->" ile devam ediyor.
- auto da Compiler return type a bakip kendi karar verecek.
 */

tmplate <typename T>
auto func(T x)
{
    return x + .5;
}

/******************************************************************/
// Ornek:

template <typename T>
T sum(T x, T y)
{
    return x + y;
}

int main()
{
    auto x = sum(1.2, 3.4);
    std::cout << "x=" << x << "\n";
}

/******************************************************************/
// Asagida yine hata olmaz

#include <iostream>

template <typename T>
T sum(T x, T y)
{
    return x + y;
}

int main()
{
    using namespace std;

    string s1="saban";
    string s2 = "kocal";
    auto x = sum(s1, s2);
    std::cout << "x=" << x << "\n";
}

/******************************************************************/
// veri kaybi olacak!

#include <iostream>

template <typename T, typename U>
T sum(T t, U u)
{
    return t + u;
}

int main()
{
    auto x = sum(12, 3.4);
    std::cout << "x=" << x << "\n";
}

/******************************************************************/
// parametrelerin yerini degisince yine sorun:

#include <iostream>

template <typename T, typename U>
U sum(T t, U u)
{
    return t + u;
}

int main()
{
    auto x = sum(1.32, 5);
    std::cout << "x=" << x << "\n";
}


/******************************************************************/
// trailing return type : C++11 ile dile eklendi.
// auto return type bu anda yoktu. C++14 standartlariyla dile eklendi.

/******************************************************************/

// Asagidaki kullanim hata verir!!!

#include <iostream>

template <typename T, typename U>
decltype(t*u) sum(T t, U u)
{
    return t * t;
}

int main()
{
    
}

/******************************************************************/

// Bunu asmak icin oktan sonra gecis degeri yazilinca syntax hatasi olmuyor!!!
// Trailing return type: Genel manada fonksiyonlar icin

#include <iostream>

template <typename T, typename U>
auto sum(T t, U u) -> decltype(t*u)
{
    return t * t;
}

int main()
{
    
}
