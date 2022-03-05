/*
* Bir fonksiyon eğer başlık dosyasına konacak ise inline olması gerekir.
* Bu sayede ODR (One Definition Rule) çiğnenmemiş olur.
* Diğer türlü eğer linker hatası ile karşılaşılır.
*/

//func.h
#pragma once
inline void func()
{
}

//other.cpp
#include "func.h"
void foo()
{
    func();
}

//main.cpp
#include "func.h"
int main()
{
    func();
}
