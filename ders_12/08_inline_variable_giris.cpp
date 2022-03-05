/*
* C++17 ile gelen yeni bir özellik inline variable tanımlayabilmektir.
* Bu header-only library oluşturmakta son derece önemlidir.
*/

//instance.h
#pragma once

//Bu özellik öncesinde bir global değişkeni header dosyasına
//koymak istersek ODR için bazı hileler yapılıyor idi:
inline int& get_instance()
{
    static int x = 10; //sadece birkez hayata gelecek
    return x;
}

//main.cpp
#include "instance.h"

int main()
{
    get_instanece() = 9; //hayata gelen x'e 9 atanıyor.
}
