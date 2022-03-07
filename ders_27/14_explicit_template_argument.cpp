/****************************	explicit template argument  ****************************/
// !!! Dersin cok detayli özeti icin notlar.md dosyasina bakmanizi tavsiye ederim !!! 

// explicit template argument(derleyiciye acik acik soyleme)
// yeni bir typename daha ekleniyor.

#include <iostream>

template <typename R, typename T, typename U>
R sum(T t, U u)
{
    return t + u;
}

int main()
{
    auto x = sum<double>(12, 4.5);
    std::cout << "x=" << x << "\n";
}

//ilkini ben soyledim, kalan ikisini deduction. T ve U comp. belirledi.


/******************************************************************/
#include <iostream>

template <typename T, typename U, typename W>
void f(T t, U u, W w);

int main()
{
    f(1, 2.3, 5L);
}

// Compiler türleri deduction ile tespit ediyor.

/******************************************************************/

// asagidaki ornekte derleyiciye data türlerini biz soyluyoruz.

#include <iostream>

template <typename T, typename U, typename W>
void f(T t, U u, W w);

int main()
{
    //f<int, int, int>(1, 2.3, 5L);
    // kac parametreyi explicit belirtmek istiyorsam onlari belirtiyorum, kalani compiler a ait.
    f<int>(1, 2.3, 5L); 
}


/******************************************************************/

/* 
    ### Soru: 
    Neden explicit argument kullanilir?
    - Derleyicinin cikarim yapma sansi yok.
    - Ör: make_unique ve make_shared gibi functionlar. Cunku burda geri donus türünde kullaniliyor. Burada cikarim yapma sansi yok.
    - Diger bir ihtimal:
        - Asagidaki kodda derleyici her biri icin ayri fonksiyon yazmak zorunda!

 */

#include <iostream>
#include <string>
#include <memory>

template <typename T>
T foo(T t)
{
    //
    return t * t;
}

int main()
{
    foo(1.2); 
    foo(12.f); 
    foo(234); 
    foo('S'); 
}

/******************************************************************/

// Her bir arguman icin derleyici yeni func. uretiyor

#include <iostream>
#include <string>
#include <memory>

template <typename T>
void foo(T t)
{
    std::cout << typeid(T).name() << "\n";
}

int main()
{
    foo(1.2); 
    foo(12.f); 
    foo(234); 
    foo('S'); 
}

//Ekran ciktisi:
// d
// f
// i
// c

/******************************************************************/

// Istersem her degisken türü icin ayri func. üretmenin onune gecebilirdim. 
// Bazen explicit template argument mecburiyet senaryosu olarak kullaniliyor.

#include <iostream>
#include <string>
#include <memory>

template <typename T>
void foo(T t)
{
    std::cout << typeid(T).name() << "\n";
}

int main()
{
    foo(1.2); 
    foo<double>(12.f); 
    foo<double>(234); 
    foo<double>('S'); 
}

//Ekran ciktisi:
// d
// d
// d
// d

/******************************************************************/

// func. geri donus degerine cagiran karar verecek sekilde de kurgu yapabilirim:

#include <iostream>

template <typename R, typename T, typename U>
R sum(T t, U u)
{
    return t + u;
}

int main()
{
    sum<int>(12, 'K');
}


/******************************************************************/

// Baska bir örnek:

#include <iostream>

template <typename R, typename T, typename U>
R sum(T t, U u)
{
    return t + u;
}

int main()
{
    auto x =  sum<int>(12, 'K');
    auto y =  sum<double>(1.2, 23);
}

/******************************************************************/

//Bunu yapmanin baska yollari da var:

#include <iostream>

template <typename T, typename U>
auto sum(T t, U u)
{
    return t + u;
}

int main()
{
    auto x = sum(3.4, 12);
}

// return type double olacak!


/******************************************************************/

#include <iostream>

template <typename T, typename U>
auto sum(T t, U u)
{
    return t + u;
}

int main()
{
    auto x = sum(3u, 12);
}

// burada return type unsigned int olacak.












