/*
* inline fonksiyonlaraa sınıflarda hatırlayalım ve örnek verelim.
*/

//class.h
#pragma once

class Neco {
public:
    void func();
}

inline void Neco::func()
{
    //func inline tanımlandığı için ODR ihlali yok.
    //veya sadece bildirimde de inline kullanılabilirdi.
}

//VEYA:

class Neco {
public:
    void func()
    {
        //implicitly inline
    }
}
