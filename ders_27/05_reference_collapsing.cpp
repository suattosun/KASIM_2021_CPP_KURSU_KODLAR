/********************************	reference collapsing  ********************************/
// !!! Dersin cok detayli özeti icin notlar.md dosyasina bakmanizi tavsiye ederim !!! 

// en karmasik senaryo func. parameter olarak "&&" bu sag taraf ref. degil. forwarding reference! Scott Meyers'a gore "Universal Reference"
    
template <typename T>
class typeteller;

template<typename T>
void func(T &&) //forwarding reference veya Universal Reference
{

}

//  universal reference i scott meyers uydurmus. forwarding genel kullanim. 
//Ozellikle yeni araclar da dusunuldugunde artik forwarding reference yanlis oluyor. 
// Scott in terimi daha dogru. Biz de universal reference kullanalim.
    
/*************************************************************************************/

/*
 Burasi karisik!
    
    - autoda da bahsedilen konular tekrar:
    - **Autoda 3 farkli durum vardi:**

int x = 10; //sabit 

int& y = x; //lvalue ref 
int&& z = 10; //rvalue ref

- auto ifadesinde derleyici ifadeye bakarak auto yerine gelmesi gereken yere karar veriyordu. Simdi ise;
    `func(10);`
    derleyici bu func(10) ifadesine bakarak T'nin ne oldugunu cikarmaya calisiyor.
*/    

/*******************************************************************************************/


template <typename T>
class typeteller;

template<typename T>
void func(T &&) //forwarding reference veya Universal Reference
{

}

// universal reference ise 
// T yerine hangi tur kullanilacagi fonksiyon cagrisindaki argumanin deger kategorisine bagli

// eger func arg r value expr. ise T türü türün kendisi.o zaman T is int.

/*******************************************************************************************/

template <typename T>
class typeteller;

template<typename T>
void func(T &&) //forwarding reference veya Universal Reference
{

}

// universal reference ise 
// T yerine hangi tur kullanilacagi fonksiyon cagrisindaki argumanin deger kategorisine bagli

int main()
{
    func(12); //T is int    param is int && 
    // Saban yorum:
    // auto&& y = 12; //ayni ifadenin auto karsiligi. "int &&y"
}

// value kategori burada secici unsur.
    
/******************************************************************************************/

// eger func. sol taraf value gonderilir ise bu durumda T lvalue referans olacak!

template <typename T>
class typeteller;

template<typename T>
void func(T &&) //forwarding reference veya Universal Reference
{

}

// universal reference ise 
// T yerine hangi tur kullanilacagi fonksiyon cagrisindaki argumanin deger kategorisine bagli

int main()
{
    int x = 10;
    func(x); //T is int &     
    // Saban yorum:
     auto&& y = x; //ayni ifadenin auto karsiligi. "int &y"
}

// C++ ta ref to ref yoktur.Ancak bazi baglamlarda bu durum olusunca ilgili türün ne olacagi reference collapse kurallarina bagli. Bunun ilgili bir tablo var.
        
// Dikkat!: Burasi auto da da karisikti. Bakalim hatirlayabilecek misiniz!

/******************************************************************************************/

#include

template<typename T>
class Typeteller;

template<typename T>
void func(T &&) //forwarding reference veya Universal Reference
{
    Typeteller y;
}

/*
// Eger func. parametresi Universal Reference ise:

- T nin ne oldugu func. gonderilen argumanin deger kategorisine bagli.
- Eger func. gonderilen degerde rvalue kullanilirsa, asagidaki ornekteki gibi

`func(12); // T is int, func parameter is int &&`

+ ### Burasi detay degil, cok iyi ogrenilmesi gerekiyor!
bu durumda T yerine kullanilacak tür; tür'ün kendisi yani reference türü degil.
`func(12); // T is int, func parameter is int &&`
arguman(12) bir sag taraf reference idir. Dolayisila arguman in kendi türünü aldik(int).
*/

/***********************************************************************************************/

//Func a bir lvalue gonderirsem, bu durumda T lvlaue reference olacak.
// Ornek:

#include

class Typeteller;

template<typename T>
void func(T &&param)
{
    Typeteller t;
}

//Universal Reference ise hangi tür kullanilacagi
//fonksiyon cagrisindaki deger kategorisinden elde edilecek!

int main()
{
    int x = 10;
    func(x);
}

/*
IDE ayni sekilde T'nin "int &" türünden olmasi gerektigini söylüyor. Bu durumda template'in imzasi su sekilde sekillenecek:`void func(int& &&param)`
**C++ ta reference to reference yoktur. Template gibi bazi baglamlarda bu tip bir durum olusunca. Address collapsing kurallari devreye girecek:**
T & & Sonuc     = T& (eger sol taraf reference ina sol taraf reference i olusursa )
T & && Sonuc   = T&(eger sol taraf reference ina sag taraf reference i olusursa )
T && & Sonuc   = T&(eger sag taraf reference ina sol taraf reference i olusursa )
T && && Sonuc = T&&(eger sag taraf reference ina sag taraf reference i olusursa )
+ ### Ancak sag taraf reference ina sag taraf reference i olusmasi durumunda sag taraf sonucu cikiyor.Logical OR ifadesi gibi! 

+ ### Olusan sonuc:

- Bir func par. universal reference(forwarding reference ise) , bu durumda cikarim nasil yapiliyormus? Derleyici func. gonderilen argumana bakiyor. Arguman in deger category si rvalue, T bir referans türü degil. Bu durumda func. parametre degiskeni sag taraf reference i olacak.
- Func. gonderilen arg. lvalue expr. , T sol taraf ref.
    Cunku ornegimizde param "&&" tanimlanmisti. Logical OR ifadesinde 2 ihtimal kalmis oluyor.
    & ve && --> sonuc sol taraf
    veya
    && ve && --> sonuc sag taraf

Yalniz func. nin parametresi ile T türünü karistirmamak lazim!
Eger asagidaki func. sag taraf degeri ile cagirirsam calisir. Sol taraf degeri ile cagirirsam lvalue reference tipindeki bir degiskene ilk deger vermedigimden hata alirim:
*/

***********************************************************************************************

class Typeteller;

template<typename T>
void func(T &&param)
{
    T x;
}

//Universal Reference ise hangi tür kullanilacagi
//fonksiyon cagrisindaki deger kategorisinden elde edilecek!

int main()
{
    int a = 5;
    func(a);
}

// Hata mesaji: "error: 'x' declared as reference but not initialized"

/***********************************************************************************************/

/*
    - type deduction, using yada typedef dolayisila reference to reference durumlari olustugunda OR ifadesinde oldugu gibi sadece && ve && (sag taraf ref to sag taraf ref) durumunda &&(sag taraf ref) sonucu cikacak, bunun disinda lvalue ref(sol taraf reference i sonucu cikacak.)  

    +  veya operatoru gibi. bir tane sol taraf ref. sonucu sol taraf ref yapiyor.
    +  sag taraf icin ikisinin de sag olmasi gerekiyor.

    +  bu kisim detay degil cok iyi ogrenilmeli!!!
*/