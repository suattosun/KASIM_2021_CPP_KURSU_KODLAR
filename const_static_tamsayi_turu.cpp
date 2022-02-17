/*
* static veri elamanları için c++'da eskiden beridir gelen bir özellik var
* Eğer bir static veri elemanı const ve tamsayı türlerinden ise 
* ilk değer verme sınıf içerisinde yapılabiliyor.
*/

class Nec {
public: 
    const static int x = 5; //geçerli
    const static double y = .2; //syntax error çünkü tamsayı türü değil
};

#include <iostream>

int main()
{
    std::cout << Nec::x << "\n";
}
