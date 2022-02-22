/*
* Client kodun static veri elemanlarına erişiminde
* erişilecek elemanın ::, . ve -> operatörünün sağ operandı olması halinde erişim sağlanabilir.
* Tabii ki accsess kontrolünden de geçmesi gerekiyor
*/

#include <iostream>

class Nec {
public:
    static int x;
};
int Nec::x;

int main()
{
    Nec::x = 10; //çözünürlük opt. ile erişilebilir.
    auto val = Nec::x; 

    //İlginç bir şekilde sınıf nesnesi üzerinden de (. veya -> oprattörü ile) erişilebiliyor
    //Fakat bu şekilde kullanım kodu okuaynda yanlış bir algı yaratabileceğinden tavsiye edilmiyor.
    Nec n1, n2, n3;
    
    //tümü aynı x'e işaret ediyor. Sonuc hepsinde 10 yazar
    std::cout << n1.x << "\n"; 
    std::cout << n2.x << "\n";
    std::cout << n3.x << "\n";
}
