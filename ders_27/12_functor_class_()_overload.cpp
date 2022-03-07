/********************************	functor  ********************************/
// !!! Dersin cok detayli özeti icin notlar.md dosyasina bakmanizi tavsiye ederim !!! 

//Ornek:

template <typename F> 
void func(F f) 
{
    f();
}

// burada function pointer olabilir. Function cagri operatorunun Overloadu'nun devlesmesinin template lerle karsimiza cikmasi.

/****************************************************************/
#include<iostream>

template <typename F> 
void func(F f)  // int (*)(int)
{
    f(12);
}

int foo(int x)
{
    std::cout << "foo cagrildi\n";
    return x*x*5;
}

int main(){
    func(foo);
}

// derleyicinin yazacagi kod:

int func(int (*f)(int))  // int (*)(int)
{
    return f(12);
}

/****************************************************************/
// tek ihtimal bu degil. Ikinci ihtimal:

#include <iostream>

template <typename F> 
int func(F f)  // int (*)(int)
{
    return f(12);
}

class Myclass{
public:
    int operator()(int x) const
    {
        std::cout << "Myclass operator()(int)\n";
        return x + 5;
    }   
};

int main(){
    auto x =  func(Myclass{});
}

/* 
    - Template e Myclass tipinde parametre gectik, template icinde "f()" ifadesini goren template bunun Myclass classinin overload edilmis"()- ac kapa parantez operatoru" oldugunu anladi ve bu yordami cagirdi!!!
    ### - Bu kullanim STL de en cok karsimiza gelen kullanimlardan biri!

    - "()" operatorunu overload eden siniflara "functor" deniliyor.
 */