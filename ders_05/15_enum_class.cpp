/*
* Modern c++ ile gelen özelliklerden biri enum class (kapsamlandırılmış enum)
* Tanımında class anahtar sözcüğü kullanılsa da bu bir class değildir!
*/

#include <iostream>

enum class Color {red, green, blue}; //artık isimlerin kendi skobu var
enum class Nec {xyz, red, abc}; //red ismi bir kapsam problemi yaratmayacak

int main()
{
    //Color mycolor1 = red; //kapsamdan dolayı syntax error
    Color mycolor2 = Color::red; //geçerli

    //Fakat her zaman kapsam çözünürlük (::) operatörünü kullanmak kod kalabalığına neden olabilir
    //C++ 2020 ile gelen özellik sayesinde tüm enum isimlerinin nitelendirilmeden kullanımını sağlayabiliyoruz.
    using enum Color;
    Color c = red;//artık geçerli

    //yine aynı şekilde:
    using Color::blue;
    Color clr = blue; //sadece blue ismini nitelemeden kullanabiliyoruz.
}