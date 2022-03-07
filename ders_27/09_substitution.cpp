/********************************	substitution  ********************************/

// !!! Dersin cok detayli özeti icin notlar.md dosyasina bakmanizi tavsiye ederim !!! 

// Soru: T ve U nedir?

#include

template <typename T, typename U>
void foo(T(*)(U));

int func(double);

int main()
{
foo(func);
}

/* 
    Cevap:
    T:int, U:double dir.

    Not: Burada anlatilmak istenen bu islemin sadece basit bir yer degistirme islemi olmadigi. Arkada calisan ciddi bir karar mekanizmasi var. C deki makrolar sadece metinsel bir yer degistirme(substitution).
 */
/*****************************************************************************/

//substitution:

//Soru: parametre nedir?

void foo(int(*)(double))
{
    
}
 
// function pointer!

// bu da farkli bir yazimi:

template<typename T, typename U>
void foo(T(*)(U));

int func(double);

int main()
{
    foo(func);
}

/* 
    - IDE'nin gosterdigi deger:
	- void foo<int, double>(int (*)(double))

    - Burada anlatilmak istenen bu basit bir yer degistirme degil. Bu complex bir islem.C deki macrolar ile hicbir alakasi yok. Oradaki metinsel bir substitution .Burada ciddi bir cikarim mekanizmasi var.
 */

template<typename T>
T * foo(T *);

// int * foo(int *);

int main()
{
    foo<int>(10);
}

/* 
    - buradaki surec'e substitution diyoruz. Bunun neden bu kadar önemli oldugu ileride anlasilacak!
    ### substitution:
    Derleyici bizim gönderdigimiz template parameteresini(T) deduction ile anladiktan sonra, T parametresine göre tanimladigimiz fonksiyonun imzasini cikarir. Bu örnek icin konusacak olursak:
    T=int,
    substitution sonrasi olusan fonksiyonun imzasi ise su sekilde olur:
    int * foo(int *);
 */