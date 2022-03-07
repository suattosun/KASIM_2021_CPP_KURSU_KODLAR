// !!! Dersin cok detayli özeti icin notlar.md dosyasina bakmanizi tavsiye ederim !!! 

// Soru: T ve U nedir?
/* 
    Soru:
    Acaba template argument deduction her zaman basarili olmak zorunda mi?
    - Gunun onemli sorularindan biri.
    - Hayir! Syntax hatasi alabiliriz. Birden fazla nedeni var.
        - func. cagrisindan hareketle compiler template parameters in karsiligi kullanilacak template argumanlarinin cikarimini yapamaz. Yeterli bilgi yok. Syntax hatasi verir.
        - Burada donus degeri cikarimi yapilamaz:
 */    

template<typename T>
T foo();

// int * foo(int *);

int main()
{
    int x = foo();
}

/*         
    - Compiler hata mesaji: "bağımsız değişken listesiyle eşleşen işlev şablonu "foo" örneği yok"
        
    - could not deduce template argument for T
        - ambiguity (cift anlamlilik hata türü)    
        - burada celiski yok
 */      

/******************************************************************/
// Bu örnekte ayni T degiskeni icin int ve double arasinda secim yapilamadigindan compiler hata verecek.
// hata mesaji: "deduced conflicting types for parameter 'T' ('int' and 'double')"

#include<iostream>

template<typename T>
T func(T x, T y){
    std::cout << "function is called!\n" ; 
}

int main()
{
    func(10, 2.0);
}


/******************************************************************/
// func<int>(10, 2.0);
// burada int kullanacagimizi özellikle söyledigimizden artik error yok.
// narrowing conversion olacak seklinde, sadece warning var!

#include<iostream>

template<typename T>
T func(T x, T y){
    std::cout << "function is called!\n" ; 
}

int main()
{
    func<int>(10, 2.0);
}
