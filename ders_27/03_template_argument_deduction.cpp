/********************************	template argument deduction  ********************************/

// !!! Dersin cok detayli özeti icin notlar.md dosyasina bakmanizi tavsiye ederim !!! 

/* 
    - Eger auto yu biliyorsak burada hicbir zorluk yok.    
    - Hatirlayalim, 3 farkli kullanim vardi:
 */    

#include<algorithm>

template <typename T>
void func(T  x)
{

}

int main()
{
    func(10);
    
    auto x = 10;
    auto &y = x;
    auto &&z = 10;
}

/* 
    + iki kullanim arasinda nerdeyse hicbir fark yok.
    + auto type deduction inda esitligin solunda tanimladigimiz degisken icin nasil type belirleniyor ise; "func(T  x)" ifadesindeki T'nin type i da ayni sekilde belirleniyor.
    auto deductionda esitligin saginda deduction icin kullandigimiz degisken, template function type decutionda func'in parametre degiskeni olmus oluyor!
 */