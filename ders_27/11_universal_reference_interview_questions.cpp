// !!! Dersin cok detayli özeti icin notlar.md dosyasina bakmanizi tavsiye ederim !!! 

// Soru:
// Buraya kadar ögrendiklerimize göre asagidaki ifadede Syntax error var mi, yok mu?

#include<iostream>

template<typename T>
T func(T x, T &&);

int main()
{
    // func<int>(10, 20);
}

// Cevap:
// T nin degeri ilk parametre düsünüldügünde int dir
// ikinci parametre icin de forwarding reference int alabileceginden syntax hatasi yok!


/********************************************************************/


// Soru:
// Buraya kadar ögrendiklerimize göre asagidaki ifadede Syntax error var mi, yok mu?

#include<iostream>

template<typename T>
T func(T x, T &&);

int main()
{
    int ival{10};
    func<int>(ival, ival);
}

// Cevap:
// T nin degeri ilk parametre düsünüldügünde int dir!!! 
// ikinci parametre icin de forwarding reference(&&) düsünüldügünde almasi gereken deger lvalue reference yani int& tir.
// Nasil oldu, anlamadim sorusuna cevap? 
// eger argumanlari tek tek cagirsaydik nasil bir type deduction olur diye soruyoruz.
// sadece ilk arguman olsaydi tür cikarimi int olurdu.
// sadece 2. arguman olsaydi tür cikarimi int& olurdu.
// Dolayisiyla compiler bunlardan birini secemeyecek!
// yani deduction sirasinda ambiguity olacagindan syntax error verecek.
// error: cannot bind rvalue reference of type 'int&&' to lvalue of type 'int'


/********************************************************************/
/* 
    - Neden scott meyers in Universal Reference tabiri daha populer.
    - Cunku bu tarz bir func.'a sol ve sag taraf degeri gonderilebilir.
    - Asagidaki func. her tur degiskenle cagrilabiliyor.

 */

template<typename T>
void func(T &&);
    
// Scott meyers buna Universal Reference demesinin sebeb bu: const, lvalue, rvalue hersey kabul. Const yada non-const Universal Reference.

/********************************************************************/
/* 
    - sag taraf ref. leri daha once mumkun olmayan 2 seyi saglamak uzere dile eklenmisti
        - move semantics
        - perfect forwarding(ileride islenecek)

    - func. larin cagrilma durumuna gore ayni template ten cok fazla sayida func. lar uretilebilir. STL de gorecegimiz gibi.

    - buradaki parameter terimlerine dikkat , farkli
 */

template <typename T> //template type parameter
void func(T x) // x call parameter
{

}

// ayni olmak zorunda degiller!

template <typename T> //template type parameter
void func(T (&x)[10]) // x call parameter
{
    
}