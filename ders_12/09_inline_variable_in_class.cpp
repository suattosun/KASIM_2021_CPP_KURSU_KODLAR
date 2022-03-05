/*
* inline variable hem gloabal değişkenler için hem de sınıfın statik
* veri elemanları için geçerli
*/

//neco.h
#pragma once

class Nec{
    static inline int x = 5;
}

//main.cpp
#include "neco.h"
#include <iostream>

int main()
{
    std::cout<<Nec::x<<"\n";
}
