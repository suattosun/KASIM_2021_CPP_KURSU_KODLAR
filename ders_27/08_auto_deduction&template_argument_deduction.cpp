// !!! Dersin cok detayli özeti icin notlar.md dosyasina bakmanizi tavsiye ederim !!! 

template<typename T>
void func(T &&) //forwarding reference veya Universal Reference
{

}

int main()
{
    auto&& x = 10;
}

// Cevap: auto yerine gelecek tür int

/*****************************************************************************/

template<typename T>
void func(T &&) //forwarding reference veya Universal Reference
{

}

int main()
{
    func(10);
    auto&& x = 10;
}

/* 
    - x universal ref.
    auto&& x = ival;
    - aslinda auto deduction ile template argument deduction arasinda bir fark yoktur.
 */
/*****************************************************************************/    
/* 
    - Bunun tek istisnasi:
    
    auto x = {1, 2, ,3, 4, 5};//autonun bu kullaniminda auto karsiligi yapilan cikarim=initializer list sinifi olacak ki bu da onemli bir konu basligimiz. //std:initializer_list<int> x

    + GUI de mouseoverda gosteriyor.
        
    + asagdaki syntax hatasi:
 */    
#include

template<typename T>
void func(T x);

int main()
{
// auto gibi olsa bu sekilde kullanim mümkün olmaliydi ama böyle degil!
// Syntax error!
func({1, 2, ,3, 4, 5});
}

// template de burada type deduction yapamiyor. - programci ilk basta bunu C deki macro gibi dusunuyor. 

/*****************************************************************************/

### Soru:

#include

template<typename T>
void func(T x);

int main()
{
int ival{};
func(&ival); //Buradaki "&" reference degil, esitligin sag tarafinda kullandigimiz adres manasinda
}

/* 
    + degisken türü nedir?
    + Cevap: int*
 */
/*****************************************************************************/

### Soru:

#include

template<typename T>
void func(T *x);

int main()
{
int ival{};
func(&ival);
}

/* 
    Cevap:
    - Yine T türü int olacak. Sanki arada fark yok gibi ama var.
    - Ornegin ikinci ornekte int tipindeki degiskeni ilkinde oldugu gibi int * olarak degerlendirip ilk deger olarak nullptr atamak istersem compiler hata verecekti.
 */
#include

template<typename T>
void func(T *x)
{
T y = nullptr;
}

int main()
{
int ival{};
func(&ival);
}

// Cikti:"error: cannot convert 'std::nullptr_t' to 'int' in initialization"

/*****************************************************************************/

// Ör:

#include

template<typename T>
void func(T **x)
{

}

int main()
{
int x = 10;
int* p = &x;
int** ptr = &p;

func(ptr);
}

/* 
    Yorumlanmasi: Bu durumda derleyicinin bizim icin uretecegi func fonksiyonun parametresi int** türünden olacak ama "T" parametresinin türü "int"
    olacak!!!
    - Mouse ile func üzerine geldigimizde görecegimiz ifade: "void func<int>(int **)"
 */
/*****************************************************************************/
/* 
    Soru:
    Eger func in imzasindaki "**" ifadesini "*" olarak degistirirsem ne olur?
 */
template<typename T>
void func(T *x)
{

}

/* 
    + Yorumlanmasi:
    Bu durumda derleyicinin bizim icin uretecegi func fonksiyonu'nun parametresi int** türünden olacak ama "T" parametresinin türü "int *" olacak!!!
 */
/*****************************************************************************/
/* 
    Soru:
    Eger func in imzasindaki "T *x" ifadesini "T x" olarak degistirirsem ne olur?
 */

template<typename T>
void func(T x)
{

}

/* 
    Yorumlanmasi: 
    Bu durumda derleyicinin bizim icin uretecegi func fonksiyonu'nun parametresi int** türünden olacak ama "T" parametresinin türü "int **" olacak!!!
 */
/*****************************************************************************/

// Soru: 

#include<iostream>

template<typename T, int size>
void func(T (&) [size]);

template<typename T>
void foo(T &);

int main()
{
    int a[5]{};
    foo(a);

    std::cout << "executed \\n";
}

/* 
    Cevap:
    T'nin türü: int [5]
    foo func. imzasi:
    (int (&)[5]);
 */
/*****************************************************************************/

// Soru:

#include

template<typename T, int size>
void func(T (&)[size]);

template<typename T>
void foo(T &);

int main()
{
int a[5]{};
func(a);

std::cout << "executed \\n";
}

/* 
    Cevap: T=int, size = 5; func. imzasi: void foo<int, 5>(int (&)[5]); yani:

    template<typename T, int size>
    void func(T (&)[size]); //int (&) [5]
 */
/*****************************************************************************/

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
