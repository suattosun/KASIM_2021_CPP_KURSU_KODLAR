/*
* decltype tür çıkarımına güzel bir örnek
*/
#include <iostream>

int main()
{
   int a = 10;
   int y = 45;

   decltype(++a) x = y; //declype için operand unevaluated context'dir. İşlem kodu üretilmez, a artmaz.
   //Fakat ön ek ++ operatörü ile oluşturulan ifadeler C'de R value expr, C++'da L value expr'dır. 
   //O halde x'in türü int& olacak ve y değişkenine işaret edecektir.
   x *= 10;

   std::cout << "y = " << y << "\n"; //450 yazar
   std::cout << "a = " << a << "\n"; //10 yazar
}