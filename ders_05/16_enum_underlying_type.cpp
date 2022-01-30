/*
* Modern c++ ile gelen özelliklerden biri de klasik enum ve kapsamlandırılmış enum türlerinin baz türünü
* (underlying type) belirleyebiliyor olmamız. C'de belirleme imkanımız yoktu default olarak int idi.
*/

#include <iostream>

enum Color : char {red, blue, green};

int main()
{
    std::cout<<"size : "<<sizeof(enum Color)<<"\n"; //sonuc sizeof(char) olacaktır.

    //Başka bir güzelliğide incomplete type bildirimlerinde size önceden belli olacağı için geçerli olması
    enum Nec : int; //forward declaration
    std::cout<<"size : "<<sizeof(enum Nec)<<"\n"; //sonuc sizeof(int) olacaktır.
}