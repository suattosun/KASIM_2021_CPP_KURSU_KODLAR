/*
* İkinci kullanım tipi ise operandın doğrudan bir isim formu olmayıp, isim olmayan bir 
* ifade formunda olmasıdır. Bu durumda ise farklı bir kural setine tabidir ve çıkarım, operandı olan ifadenin 
* değer kategorisine bağlıdır.
*
* operand PR value --> elde edilen tür operandın türünün kendisi olur.
* operand L value  --> elde edilen tür sol taraf referansı olur.
* operand X value  --> elde edilen tür sağ taraf referansı olur.
*/

int main()
{
    int x = 10;
    double dval = .5;

    //PR value cat için örnek
    decltype(x + 5) ival; //x + 5 ifadesinin değer kategorisi PR olduğundan ival'in türü ifadenin kendi türü yani int olacaktır.
    decltype(x + dval) y; //yine y'nin türü double olacaktır.

    //L value cat için örnek
    int *ptr;
    decltype(*ptr) z = x; //operand L value cat ve int türünden olduğundan çıkarım int& olur.

    //Başka bir örnek
    int m = 5;
    int n = 6;
    decltype(m) k = n; //k'nın türü int olarak çıkarıldı
    decltype((m)) l = n; //l'nin türü int& olarak çıkarıldı

    //X value cat için örnek
    int&& foo();
    decltype(foo()) rref = 100; //çıkarılan tür int&&
}
