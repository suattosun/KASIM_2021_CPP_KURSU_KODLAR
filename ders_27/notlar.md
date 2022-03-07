
# Anlatilacak Konular:
- Exception Handling - Devam
- template konusuna giris yaptik- generic paradigm
- function templates
    - deduction sureci
    - type ve non type parameters
    - template parametresi olan türün bir func. yada class türü olabileceginden bahsettik
- explicit template argumani ve tipik kullanim senaryolarindan bahsettik.
- auto return type
- trailing return type

*****************

# Exception Handling - Devam

- Exception handling 1. bolumun sonuna gelindi.

- function try block:
- constructor disinda kullanmanin bir esprisi yok. 
- Ama dilin kurallari acisindan baska yerlerde de kullanilabilir!

```void func()
try
{
	
}
catch(int) {

}
```

- func. catch blogunda func. parameters hala visible dir.
- func. catch blogunda return deyimi olabilir.


```
#include<iostream>
#include<exception>

int  func(int x)
try
{
	if(x%2 == 0)
        throw;

    return 0;
}
catch(int) {

    return x*x;
}
```

- Önemli: 
- class in default const. parametresi nedeniyle exception throw ederse
function try block bunu yakalayamaz. 

```
class Myclass{
public:
    Myclass(){
        throw 1;
    }    

    Myclass(const Myclass&){
        throw 2;
    }
};

void  func(Myclass)
try
{
	
}
catch(int) {
   
}
```
// yukaridaki tanimsiz davranis!

// function try block'un temel kullanim alani contructor icinde kullanim.

// bu sekilde excption yakalamak mumkun degil. debug da da gorulecek!


Soru: 
Neden const. in member indan gelecek hatalari yakalmaya calisayim?

Cevap: 
Amac hala nesneyi kurmanin mumkun olmasi degil.
ya hatayi loglamak ve rethrow etmek
yada eception u transform etmek
Bunu nasil yapicaz. Cevap function try block!

/****************************************************************/
```
#include<iostream>
#include<exception>

class Member{
public:
    Member(int x){

        if(x%2 == 0)
            throw std::runtime_error("hata hata!");
    }    
};

class Nec{
public:
    Nec() try : mx(20)           
    {
        /* code */
    }
    catch(const std::exception& e)
    {
        std::cout << "exception caught: " << e.what() << '\n';
    }        

private:        
    Member mx;
};

int main()
{
    // eger main icinde de extradan try blogu olusturmazsak
    // exception'u constructor icinde catch etmis olmamiza karsin
    // uygulama yine de terminate edecekti!!!
    // Constructer'in catch'i icinde rethrow etsek de etmesek de ayni exception
    // main icine de geliyor.
    // Bizim constructer icinde hatayi yakalamamizin su sekilde faydalari olabilir:
    // 1- hatayi rethrow etmek
    // 2- hatayi transform etmek(baska bir türe cevirmek)
    // 3- Alinan tüm kaynaklari iade ettikten sonra programi güvenle sonlandirabilirim.
    try
    {
        std::cout << "main basladi! " << '\n';
        Nec nx;
        // asagidaki yaziyi exception olustugundan göremeyecegiz!
        std::cout << "main calismaya devam ediyor! " << '\n';
    }
    catch(const std::exception& e)
    {
        std::cerr << "ayni exception main icinde de yakalandi! " << e.what() << '\n';
    }
    
    std::cout << "exception handling sonrasi main calismaya devam ediyor! " << '\n';
}
```
// try in yerine(syntax) dikkat!

// kural su: 
// eger siz burda rethrow etseniz de etmesininz de exception constructer dan cikip main'e siziyor.

### Önemli:
kitaplarin cogunda bu konuya degilinilmiyor ama bence(Necati E.) cok onemli bir arac!

### Soru:
Excetion constructer icinde yakalanmasina karsin neden buradan main icine rethrow ediliyor?
Cevap:
Eger main bu hatayi bilmeseydi, ilgili nesneyi normal sekilde olustu sanip kullanmaya devam ederdi.
Ilgili nesne ZOMBI Object olurdu.

/****************************************************************/

// Buradaki "what" onemli cunku bazi durularda biz what i override edecegiz!
```
#include<iostream>
#include<exception>

class FormatError : public std::exception{
};

int main()
{
    try
    {
        throw FormatError{};
    }
    catch(const std::exception& e)
    {
        std::cerr << "exception caught " << e.what() << '\n';
    }
}
```
// yukaridaki kod ile hata konusunda detayli bilgi edinemiyoruz.

/****************************************************************/

// Bu sekilde kenid custom hata mesajimi belirtebiliriz.
```
#include<iostream>
#include<exception>

class FormatError : public std::exception{
public:
    const char* what()const override{
        return "formatlama hatasi\n";
    }

};

int main()
{
    try
    {
        throw FormatError{};
    }
    catch(const std::exception& e)
    {
        std::cerr << "exception caught " << e.what() << '\n';
    }
}
```
/****************************************************************/

// bazi durumlarda exception dan kalitimla almak yerine child exception tiplerinden birini kullanmak da isteyebiliriz.
```
#include<iostream>
#include<exception>

using namespace std;

class FormatError : public std::runtime_error{
public:
    FormatError() : std::runtime_error{"custom message: format error"}{}
};

int main()
{
    try
    {
        throw FormatError{};
    }
    catch(const std::exception& e)
    {
        std::cerr << "exception caught in main: \n" << e.what() << '\n';
    }
}
```
// Ekran ciktisi:
// exception caught in main: 
// custom message: format error
/****************************************************************/

// kendi Constructer'imizi da olusturabilirdik.
// bir baka ihtimal inherited const kullanmak:
```
#include<iostream>
#include<exception>

class FormatError : public std::runtime_error{
public:
    using std::runtime_error::runtime_error;
};

int main()
{
    try
    {
        throw FormatError{};
    }
    catch(const std::exception& e)
    {
        std::cerr << "exception caught in main: \n" << e.what() << '\n';
    }
}
```
/****************************************************************/

- %95 genel egilim. Kendi hata siniflarimizi stdlib in hatalarindan birinden turetmek.
- eger allocation ile ilgili sorun varsa ornegin: bad_alloc. 
- String add out of range varsa mesela: out_of_range kullanilabilir...

//olusturacagimiz hata siniflari tabi daha complex de olabilir.

//client code lar bizim exception dan extra bilgiler de edinebilirler.
// Kendi error sinifimiz icine get_file_name gibi get_line_no gibi fonksiyonlar ekleyebiliriz.
// hangi dosyanin hangi satirinda hata oldugu bilgisi bu sekilde gonderebilir.
// eger vakit kalirsa exception handling-2 olacak. ya kendimiz ogrenecegiz ya da ilieri c++ ta ogrenilebilir. 
// orada idiomatic bazi yapilar, custom exception siniflari gorulecek!
// End of Exception handling!

*****************************************************************

# template - Generic Programlamaya Adim

- C deki Pointerlar nasil donumse burada da Generic porgrmalama paradig masi ayni sekilde ogreneni zorlayacak bolum.

- OOP konularina kurs kapsaminda bitti gibi. Design pattern ler vs. zaman kalirsa tekrar bakilacak.

- C++ derleyicisi bizim icin kod yazan bir programdir.

- Derleyiciye kod yazdiran kodu biz yazdiriyoruz. Buna template deniyor.
    
- Sablon manasinda kullanacagiz.
    
- meta code yada code formule tabirlerini kullanabilirdik.
    
- Farkli bir syntax ile bir kod yaziyoruz amaci derleyiciye kod yazdirmak.
    
- Modern C++ ile template aracina bir cok eklemeler yapildi. Syntax cok genisledi.
    
- Ilk C++ kurslari 120 saatti. 20 ser saat artarak devam etti. Suan 180 saat.Dil buyuyor, ozellikle Generic programlama tarafinda surekli dil buyuyor.
    
- Demir kalibi gibi, derleyici yazdigimiz kodlari kalip olarak kullanip, bizim yerimize kod yaziyor.
    
###  Soru:
Neden boyle bir seye ihtiyac var?
+ ###  Cevap:
Algoritmalar cogu zaman turden bagimsiz.
swap func. int, double, long icin ayri ayri yzamak yerine derleyiciye meta code versem derleyici gerektigi anda benim icin ozel bir kod yazsa. bizim icin onlarca binlerce swap func. yazabilir.
- Fonksiyonlari türden bagimsiz hale getirmek amacli.
    Turden bagimsiz programlama(generic), degisik sekillerde yapilabilir.
    
- c de ornegin void * parametreli bir fonksiyon her turden degiskenle cagrilabilir.
    
- c++ daki yapinin bununla hicbir alakasi yok.
    
- 2.generic yapi kalitimla gerceklenen generic yapi. C#, java da tum siniflar Object ten turetilmis. Bir func. parametresi Object yapilirsa o func. her turden degisken alabilir.
- c++ daki yapinin bununla da hicbir alakasi yok!
    
- Bizim yazdigimiz meta code türden bagimsiz ama derleyicinin olusturacagi kod %100 türe bagli.
    
- Template modern c++ oncesi 2 kategoriye ayriliyordu:
- function templates(oyle bir kod ki; derleyici bunu kullanip bizim icin farkli turlerde func. lar olusturacak)
- class templates(derleyici sinif kodu yazacak)

- Bu konu STL ( standart template library). Bizim bu gune kadar gordugumuz ve gorecegimiz surusuyle sinif template ile ilgili. vector, string, veri yapilari ile ilgili siniflar... Once template leri ogrenip, sonrasinda da STL denilen kutuphaneyi ogrenecegiz.
    
- Aslinda STL ile C++ in standard kutuphanesi ayri seyler.
- Gunumuzde cogu programci bu ikisini ayni anlamda kullaniliyor. Teknik larak dogru degil ama hoca da ayni anlamda kullaniyor.
    - STL
    - C++ Standart Library
    
### Soru:
Moden C++ ile ne degisti?
### Cevap:
Mevcut olanlara yeni eklemeler yapilip, kisitmalar genisletildi. Restrictionlar, constrainler gevsetildi. Lamda ifadeleri icin de ayni sekilde. Baslangicta cok kisit vardi, sonra yavas yavas kisitlar gevsetildi. Constexpr functionlar hakeza..
- C++11, 14, 17 yeni araclar ekleniyor.
- Yeni template turleriyle 4 tur var(suanda):
	- function tamplates
	- class templates
	- variable templates(degisken sablonlari)
	- alias templates(es isim sablonlari)


- variadic template ler de eklendi. Template ile iliskili ama yeni tur degil. Simdilik kafamiza takmamiza gerek yok.

- "David Vandevoorde and Nicolai M. Josuttis" 'in C++template kitabi normal bir programlama kitabindan daha kalin. Dolayisila burda temel atilip, STL i ogrenmeye hazir hale gelinecek. Daha fazla uzmanlasmak isteyen bu kitaptan detaylarina girebilir. Kendimiz generic kutuphane olusturmak istersek, o zaman baska konular daha ogrenmemiz gerekecek.
    
- C++ i kendi kendine ogrenmeye calisanlarin en cok zorlandigi konulardan biri template ler.
    
- Konu karmasik. Programci terimleri duzgun ogrenmezse iyice karisiyor.
    
- template parameters , function parameters ile karistirilmamali!
- 3 tür parametre var, 3. ile simdilik kafa karistirmaya gerek yok:
	- type parameters
	- non-type parameters
	- template template parameters
  
### Type Parameter : 
Bizim soyledigimiz isim bir türün yerine geciyor. Compiler gercek kodu yazinca bu parametre yerine bir tür kullanacak(int gibi, myclass gibi, int * gibi...)

### non-type parameters: 
Tür olmayan parametreler. Derleyiciye bu isim yerinde sabit kullanmasi gerektigini soyluyoruz.

- C++ in ilk yillarinda template icinde "class" keyword u kullaniliyordu. Bu class, bizim class lar ile karismamali.
Bu da kötü bir secim! Ilk ogrenenler sanki burda bir class kullanmamiz gerekiyor gibi anlayabiliyor.
- Moden C++ oncesinde class ifadesine alternatif olarak "typenme" ifadesi geldi. Biz hep bunu kullanacagiz!
- "T" ifadesi, derleyiciye bizim burada bir sablon verecegimizi anlatiyor, derleyici burda bunun yerine int gibi bir tür sececek ve bizim yerimize bu kodu yazacak. 

`template <typename T>`

- Burada "T" yerine Saban da yazilabilirdi. Isim onemli degil. Bunlar birer tür olmak üzere demek.
- Birdan fazla parametre varken class yada typename herbirinde yazmak gerekir!
`template <class T, typename U>`

- Hoca typename i kullaniyor. class i hic kullanmiyor. Tavsiye bu sekilde!
- Ilerleyen yerlerde typename'in baska kullanimlari da olacak. oralarda class keyword'ü kullanilamayacak. Sadece bu context te class ve template ayni anlamda kullaniliyor.

### video'nun 70.dk:
- Non-type parameter: Bu isim bir sabit olmak uzere demek.
`template <int x>` 
derleyiciye sen burda int turunden bir sabit kullanacaksin diyoruz.

```
template <int x>
class Myclass {
	
	double a[x];
};
```
+ Derleyici compile time da dizinin size ini ogrenip set edecek.
Asagidaki kodda derleyici tur un double ve size in kac oldugunu ogrenecek:
```
template <typename T, int x>
class Myclass {
	
	T a[x];
};
```


- **C++ 20 ye kadar non-type gercek sayi turlerinden olamiyordu, C++20 ile devrim niteliginde bir degisiklik oldu. Artik literal types ve gercek sayilar da kullanilabiliyor. C++17 de bile bu hata verecek.**
    - Asagidaki T ve U türler demek:
```
template <typename T, typename U>
class Myclass {
	
};
```

### Soru:
Bu turlerin farkli tur olma zorunlulugu var mi? 
+ ### Cevap:
Ayni tür de olabilir. Isimleri farkli, compile time da ikisi icin de int türünü kullanabilir. (T ve U degiskenleri pekala ayni tur de olabilir.)
    
- template argument:
 `template <typename T>` T nin karsiligi olan gercek türe template argument deniliyor.
(Kavramlari duzgun oturtmak lazim!)    
- Template parametresi baska template argument baska.
- Tipki function parameter ile function argument arasindaki fark gibi.
    template <typename T> ifadesinde derleyici bunun compile time da int oldugunu anladiginda buna template argument deniliyor. Türden bagimsiz T parametresine karsilik gelen gercek tür.`template <int size>` burada derleyici size ifadesinin yerine kac gelecegini anladiginda buna template argument diyoruz.
    
- string de bu sekilde. aslinda string bir typename ismi.
    
- asagidaki gibi yazmak zoroldugundan biz tür es ismi olan stringi kullaniyoruz.
- basic_string<char, char_traits<char>, allocator<char>>
## **Cok onemli Soru:** (80.dk))
### Soru: Dedik ki derleyici meta code dan gercek kodu yazmasi icin gercek türü bilmeli. Peki nasil bilecek?
+ 2 ayri mekanizma var:
    - deduction mechanism(cikarim): Compiler a explicit tür ü söylemiyoruz ama derleyici context ten cikarim yapiyor.
    Asagida derleyici anladi ama ben soylemedim.

```
template <typename T>
void func(T x)
{
    //
}

int main()
{
    func(12);
}

// Burada func fonksiyonu uzerine mouse ile geldigimizde 
// IDE yardimci araci da int type deduction'in otomatik yapildigini bize gosterir! 
```
   - 2.olasilik: explicit template argument: ozellikle türü belirtiyorsak.

```
template <typename T>
void func(T x)
{
    //
}

int main()
{
    func(12); // type deduction
    func<double>(12); //explicit template argument
}

```
+ Burada sadece konuya genel bir tanitim, giris yapiliyor, konu sonra detaylandirilacak!

+ 2 tür ayni anda bir template de de kullanilabilir. Bir kismini biz soyledik(implicit), bir kismini kendi cikardi(deduction) gibi.
    
### Compiler'in yazdigi, bizim template'imizi kullanarak olusturdugu kod bizim sablonumuzun specialization i olarak isimlendiriliyor.
## **Template instantiation:** 
+ Templateden(Sablondan) gercek kod uretme sureci.
+ Template instantiation surecin kendisine denir. Sonunda cikan urun **template specialization** dir.
    
+ Client lari ilgilendiren butun template code lar header larin icine yazilmali aksi taktirde compiler bunlari goremez ve code uretimi yapamaz!
    
- Ornegin biz kodumuzda algorithm header i kendi kodumuza include edince(`#include<algorithm>`) derleyici ilgili algorithm icindeki template leri de gorebilir hale geliyor.
    
- Eger tepmlate lerimiz baska modulu ilgilendirmiyor ise sadece implementation ile ilgiliyse cpp icine de konabilir. (kullanacak bir client planlanmiyorsa)
    
- Templates one definition rule u ihlal etmez.
    
- Asagidaki func un her yerinde "T" türünü kullanabilrim.
    
```
template <typename T>
void func(T x)
{
    //
}
```
    
- "T" bir tür olmak üzere func parameter "T".
    
- Compiler in bizim yerimize kod yazmasi icin bilgi edinmesi gerekiyor. Daha once de anlattigimiz gibi bunun 2 yolu var. Ilk inceleyecegimiz :
    
## template argument deduction:
    
### Buradaki kurallar ile auto da uygulanan kurallar bir istisna disinda ayni.auto kurallarina hakimsek buradaki type deduction kurallarina da hakimiz denebilir!

```
template <typename T>
void func(T x)
{
    x.foo();
    ++x;
    x = 56;
}
```
+ yukaridaki func. icin yapilan basit kontroller: Block ac kapa, cumle sonunda ";" var mi? name lookup kontrolu yapiliyor.
```
template <typename T>
void func(T x)
{
    foo();
}
```
- ilk asamada kabaca kontroller yapiliyor denilebilir.
    
+ ### Ikinci asamada: Compiler T türünün ne oldugunu biliyor ise, hemen hata alacagiz. int türünü anladiginda ona gore ayri kontroller yapilacak.
    
- Aslinda 3. asamali kontrol var ama hoca suan icin kasitli sekilde bu asamayi anlatmiyor(gizliyor).
    
- Eger auto yu biliyorsak burada hicbir zorluk yok.
    
- Hatirlayalim, 3 farkli kullanim vardi:
    
````
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
````
+ iki kullanim arasinda nerdeyse hicbir fark yok.
+ auto type deduction inda esitligin solunda tanimladigimiz degisken icin nasil type belirleniyor ise; "func(T  x)" ifadesindeki T'nin type i da ayni sekilde belirleniyor.
auto deductionda esitligin saginda deduction icin kullandigimiz degisken, template function type decutionda func'in parametre degiskeni olmus oluyor!

*********************************************************************************

### Soru:
Buradaki x'in tipi nedir?

```
template<typename T>
void func(T x)
{

}

int main()
{
	const int x = 10;
	func(x); // auto icin deduction dusunuldugunde denk ifade "auto y = x;"
}
```

**Cevap:** 
int x tir. const luk autoda oldugu gibi düser. Imlec func ifadesinin uzerine geldiginde, int oldugunu gorebiliyoruz.

*********************************************************************************

### **Hoca burada bir hileden bahsediyor:**
Eger imleci uzerine getirdigimizde IDE gostermiyor ise(online compiler vs.) bu hile ile türü ogrenebiliyoruz. 

- Asagidaki ornekte olusturdugumuz Typeteller isimli tamamlanmamis class sayesinde derleyici bize tamamlanmamis bir class i kullanmaya calistigimizi ve hangi turden bir parametre bekledigini soyleyecek!

Hata mesaji:" error: 'Typeteller<**int**\> y' has incomplete type"

```
template<typename T>
class Typeteller;

template <typename T>
void func(T  x)
{
    Typeteller<T> y;
}

int main()
{
    func(10); // auto icin deduction dusunuldugunde denk ifade "auto y = 10;"
}
```
******************************************************************************

```
template<typename T>
class Typeteller;

template <typename T>
void func(T  x)
{
    Typeteller<T> y;
}

int main()
{
    int x = 10;
    const int& r = x;
    func(r);// auto icin deduction dusunuldugunde denk ifade "auto y = r;"
}
```
        
- Burada tür int
 
*********************************************************************************
   
```
template<typename T>
class Typeteller;

template <typename T>
void func(T  x)
{
    Typeteller<T> y;
}

int main()
{
    int a[5]{};
    func(a);// auto icin deduction dusunuldugunde denk ifade "auto y = a;"
    //auto y = a; // deducted type is int *
}
```    
- burada int * olacak (**void func<int *>(int *x)**)

*********************************************************************************
    
```
template<typename T>
void func(T x)
{

}

int foo(int x)
{
    return x * x;
}

int main()
{
    func(foo); 
    // Saban yorum:
    // auto icin deduction dusunuldugunde denk ifade "auto y = foo;"
    // auto y = foo; // deducted type is int (*)(int x)
}

```
    
- burada function to pointer conversion var. (int (*)(int x))

*********************************************************************************
```
template<typename T>
void func(T x)
{

}

int main()
{
    func("Saban"); 
    // Saban yorum:
    // auto icin deduction dusunuldugunde denk ifade "auto y = "Saban";"
    // auto y = "Saban"; // deducted type is const char *
}

```

+ T türü const char *

*********************************************************************************
    
## referans deklarotorü olma durumu:
### Bu durumu da "auto &y = x" ifadesindeki referans ile eslestirebiliriz. Ornegin bu durmda const'luk dusmuyordu vs.
    
```
template<typename T>
void func(T & x)
{

}

int main()
{
    int a[5]{};
    func(a); 
    // Saban yorum:
    // auto icin deduction dusunuldugunde denk ifade "auto& y = a"
    // auto& y = a; // deducted type is int (&y)[5]
}

```        
*********************************************************************************

+ ### en cok kafa karistiran yerler bunlar!
    
```
template<typename T>
void func(T & x)
{

}

int main()
{
    func("saban"); //const char [6]  const char (&x)[6]
    // Saban yorum:
    // auto icin deduction dusunuldugunde denk ifade "auto& y = a"
    auto& y = "saban"; // deducted type is void    const char [6]  const char (&x)[6]
}

```    

*********************************************************************************

### Typeteller hilesi sayesinde compile time da degiskenlerin degerini gorebiliyoruz.
    
```
template<typename T>
void func(T &)
{

}

int foo(int x)
{
    return x * x;
}

int main()
{
    func(foo); 
    // bu ornekte IDE de mouse ile func ifadesi uzerine gelince deducted type int (&)(int x) goruyoruz!
    // auto& y = foo; // Saban yorum: ayni ifadenin auto karsiligi. "int (&y)(int x)"
}

```    
*********************************************************************************

+ ### en karmasik senaryo func. parameter olarak "&&" bu sag taraf ref. degil. forwarding reference di! Scott Meyers'a gore "Universal Reference"
    
```
template <typename T>
class typeteller;

template<typename T>
void func(T &&) //forwarding reference veya Universal Reference
{

}
```
###  universal reference i scott meyers uydurmus. forwarding genel kullanim. Ozellikle yeni araclar da dusunuldugunde artik forwarding reference yanlis oluyor. Scott in terimi daha dogru. Biz de universal reference kullanalim.
    
***********************************************************************************************

+ ### Burasi karisik!
    
    - autoda da bahsedilen konular tekrar:
    - **Autoda 3 farkli durum vardi:**
```
int x = 10; //sabit 

int& y = x; //lvalue ref 
int&& z = 10; //rvalue ref
```
- auto ifadesinde derleyici ifadeye bakarak auto yerine gelmesi gereken yere karar veriyordu. Simdi ise;
    `func(10);`
    derleyici bu func(10) ifadesine bakarak T'nin ne oldugunu cikarmaya calisiyor.
    

***********************************************************************************************

```
template <typename T>
class typeteller;

template<typename T>
void func(T &&) //forwarding reference veya Universal Reference
{

}

// universal reference ise 
// T yerine hangi tur kullanilacagi fonksiyon cagrisindaki argumanin deger kategorisine bagli
```
+ eger func arg r value expr. ise T türü türün kendisi.o zaman T is int.


***********************************************************************************************    
```
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
```
### value kategori burada secici unsur.**
    
***********************************************************************************************

- eger func. sol taraf value gonderilir ise bu durumda T lvalue referans olacak!
    
```
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
```    
+ ### C++ ta ref to ref yoktur.Ancak bazi baglamlarda bu durum olusunca ilgili türün ne olacagi reference collapse kurallarina bagli. Bunun ilgili bir tablo var.
        
+ ### Dikkat!: Burasi auto da da karisikti. Bakalim hatirlayabilecek misiniz!


***********************************************************************************************

```
#include

template<typename T>
class Typeteller;

template<typename T>
void func(T &&) //forwarding reference veya Universal Reference
{
Typeteller y;
}
```

// Eger func. parametresi Universal Reference ise:

- T nin ne oldugu func. gonderilen argumanin deger kategorisine bagli.
- Eger func. gonderilen degerde rvalue kullanilirsa, asagidaki ornekteki gibi

`func(12); // T is int, func parameter is int &&`

+ ### Burasi detay degil, cok iyi ogrenilmesi gerekiyor!
bu durumda T yerine kullanilacak tür; tür'ün kendisi yani reference türü degil.
`func(12); // T is int, func parameter is int &&`
arguman(12) bir sag taraf reference idir. Dolayisila arguman in kendi türünü aldik(int).

***********************************************************************************************

- Func a bir lvalue gonderirsem, bu durumda T lvlaue reference olacak.
Ornek:
 ```
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
```
```
IDE ayni sekilde T'nin "int &" türünden olmasi gerektigini söylüyor. Bu durumda template'in imzasi su sekilde sekillenecek:`void func(int& &&param)`
**C++ ta reference to reference yoktur. Template gibi bazi baglamlarda bu tip bir durum olusunca. Address collapsing kurallari devreye girecek:**
T & & Sonuc     = T& (eger sol taraf reference ina sol taraf reference i olusursa )
T & && Sonuc   = T&(eger sol taraf reference ina sag taraf reference i olusursa )
T && & Sonuc   = T&(eger sag taraf reference ina sol taraf reference i olusursa )
T && && Sonuc = T&&(eger sag taraf reference ina sag taraf reference i olusursa )
+ ### Ancak sag taraf reference ina sag taraf reference i olusmasi durumunda sag taraf sonucu cikiyor.Logical OR ifadesi gibi! 
```
+ ### Olusan sonuc:

- Bir func par. universal reference(forwarding reference ise) , bu durumda cikarim nasil yapiliyormus? Derleyici func. gonderilen argumana bakiyor. Arguman in deger category si rvalue, T bir referans türü degil. Bu durumda func. parametre degiskeni sag taraf reference i olacak.
- Func. gonderilen arg. lvalue expr. , T sol taraf ref.
    Cunku ornegimizde param "&&" tanimlanmisti. Logical OR ifadesinde 2 ihtimal kalmis oluyor.
    & ve && --> sonuc sol taraf
    veya
    && ve && --> sonuc sag taraf

Yalniz func. nin parametresi ile T türünü karistirmamak lazim!
Eger asagidaki func. sag taraf degeri ile cagirirsam calisir. Sol taraf degeri ile cagirirsam lvalue reference tipindeki bir degiskene ilk deger vermedigimden hata alirim:

***********************************************************************************************

```
#include

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
```
+ ### Hata mesaji: "error: 'x' declared as reference but not initialized"

***********************************************************************************************

- type deduction, using yada typedef dolayisila reference to reference durumlari olustugunda OR ifadesinde oldugu gibi sadece && ve && (sag taraf ref to sag taraf ref) durumunda &&(sag taraf ref) sonucu cikacak, bunun disinda lvalue ref(sol taraf reference i sonucu cikacak.)
    
+ ### veya operatoru gibi. bir tane sol taraf ref. sonucu sol taraf ref yapiyor.
+ ### sag taraf icin ikisinin de sag olmasi gerekiyor.

+ ### bu kisim detay degil cok iyi ogrenilmeli!!!

- Reference collapsing kurallarini anlatmak icin soyle bir hile yapiliyor:

```
int main()
{
    using  mytype = int&;
    int ival{};

    mytype& x = ival;
}

```
OR:
```
int main()
{
    using  mytype = int&;
    int ival{};

    mytype& x; //error message: "'x' declared as reference but not initialized"
}
```

+ Yukaridaki ornekte mytype dedigimiz degisken int gibi bir tür ama "int&" türünde. Dolayisi ile bu ifadenin acilimi aslinda su sekilde:
mytype & x --> int& & x(sol taraf referansina sol taraf referansi durumu)
bu da collapsing kurallarinin uygulanmasini gerektiriyor. Sonuc:

```
using mytype = int&;
mytype & x;
```
**& ve & --> sonuc x sol taraf reference'i olacak**
ve syntax hatasi olusacak!

Or:
```
using mytype = int&&;
int ival{};

mytype& x = ival; // lvalue ref. e deger atadigimdan hata yok.
```

+ ### Yorumlamasi:
**&& ve & --> sonuc x sol taraf reference'i olacak**

kodu degistirelim,
OR:
```
using mytype = int&&;
int ival{};

mytype&& x = 10;
```
+ ### && ve && --> sonuc x SAG taraf reference'i olacak

Tekrar etmek gerekirse:
- a- template argument deduction sirasinda
- b- using yada typedef tanimlari yapildiginda reference collapsing kurallari devreye giriyor ve cozumleme yapiliyor.
Ozet: Sadece sag ref to sag ref = Sag taraf ref
else
sol taraf ref olacak!

*****************************************************************************



### Soru: T'nin ve function in parametre türleri nedir?
```
#include

template<typename T>
void func(T &&);

int main()
{
    int ival = 5;
    func(ival);
}
```

- T --> int &
- function parameter türü --> int &

### Soru:
auto&& x = ival; // buradaki x'in türü nedir?

x rvalue ref degil!
x Universal Reference. Cikarim nasil yapiliyor?
auto yerine auto ref gelecek. Cikarim?
sag taraf ref e & sol taraf ref geldiginden cikarim SOL TARAF ref. olacak.

- reference a referans kurallari asagidaki gibidir. sadece sag ref e sag ref durumunda sag taraf ref olusuyor. onun disinda hep sol taraf ref
    
```
Reference Collapsing Table
T&      &        T&
T&      &&       T&
T&&      &       T&
T&&     &&       T&&
```    
- asagidaki sag taraf degil!

*****************************************************************************
    
```
template<typename T>
void func(T &&) //forwarding reference veya Universal Reference
{

}

int main()
{
    auto&& x = 10;
}
```    
- auto yerine gelecek tür int

*****************************************************************************
```
template<typename T>
void func(T &&) //forwarding reference veya Universal Reference
{

}

int main()
{
    func(10);
    auto&& x = 10;
}
```    
    
- x universal ref.
```    
auto&& x = ival;
```    
- aslinda auto deduction ile template argument deduction arasinda bir fark yoktur.

*****************************************************************************    

- Bunun tek istisnasi:
 ```    
auto x = {1, 2, ,3, 4, 5};//autonun bu kullaniminda auto karsiligi yapilan cikarim=initializer list sinifi olacak ki bu da onemli bir konu basligimiz. //std:initializer_list<int> x
```    
+ GUI de mouseoverda gosteriyor.
    
+ ### asagdaki syntax hatasi:
    
```#include

template<typename T>
void func(T x);

int main()
{
// auto gibi olsa bu sekilde kullanim mümkün olmaliydi ama böyle degil!
// Syntax error!
func({1, 2, ,3, 4, 5});
}
```
+ ### template de burada type deduction yapamiyor. - programci ilk basta bunu C deki macro gibi dusunuyor. 

*****************************************************************************

### Soru:
```
#include

template<typename T>
void func(T x);

int main()
{
int ival{};
func(&ival); //Buradaki "&" reference degil, esitligin sag tarafinda kullandigimiz adres manasinda
}
```
+ degisken türü nedir?
+ Cevap: int*

*****************************************************************************

### Soru:
```
#include

template<typename T>
void func(T *x);

int main()
{
int ival{};
func(&ival);
}
```
+ ### Cevap:
Yine T türü int olacak. Sanki arada fark yok gibi ama var.

+ Ornegin ikinci ornekte int tipindeki degiskeni ilkinde oldugu gibi int * olarak degerlendirip ilk deger olarak nullptr atamak istersem compiler hata verecekti.
```
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
```
+ Cikti:"error: cannot convert 'std::nullptr_t' to 'int' in initialization"

*****************************************************************************

+ ### Ör:
```
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
```

Yorumlanmasi: Bu durumda derleyicinin bizim icin uretecegi func fonksiyonun parametresi int** türünden olacak ama "T" parametresinin türü "int"
olacak!!!
- Mouse ile func üzerine geldigimizde görecegimiz ifade: "void func<int>(int **)"

*****************************************************************************

### Soru:
Eger func in imzasindaki "**" ifadesini "*" olarak degistirirsem ne olur?
```
template<typename T>
void func(T *x)
{

}
```
+ Yorumlanmasi:
Bu durumda derleyicinin bizim icin uretecegi func fonksiyonu'nun parametresi int** türünden olacak ama "T" parametresinin türü "int *" olacak!!!

*****************************************************************************

### Soru:
Eger func in imzasindaki "T *x" ifadesini "T x" olarak degistirirsem ne olur?
```
template<typename T>
void func(T x)
{

}
```
+ Yorumlanmasi: 
Bu durumda derleyicinin bizim icin uretecegi func fonksiyonu'nun parametresi int** türünden olacak ama "T" parametresinin türü "int **" olacak!!!

*****************************************************************************

###  Soru:
 ```

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
```
+ Cevap:
T'nin türü: int [5]
foo func. imzasi:
(int (&)[5]);

*****************************************************************************

+ ### Soru:
```
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
```
+ Cevap: T=int, size = 5; func. imzasi: void foo<int, 5>(int (&)[5]); yani:
```
template<typename T, int size>
void func(T (&)[size]); //int (&) [5]
```
*****************************************************************************

### Soru: T ve U nedir?
```
#include

template <typename T, typename U>
void foo(T(*)(U));

int func(double);

int main()
{
foo(func);
}
```
### Cevap:
T:int, U:double dir.

Not: Burada anlatilmak istenen bu islemin sadece basit bir yer degistirme islemi olmadigi. Arkada calisan ciddi bir karar mekanizmasi var. C deki makrolar sadece metinsel bir yer degistirme(substitution).

*****************************************************************************

## substitution:

*****************************************************************************

//**substitution:**

- parametre nedir?
```
void foo(int(*)(double))
{
    
}
``` 
- function pointer!

bu da farkli bir yazimi:
```
template<typename T, typename U>
void foo(T(*)(U));

int func(double);

int main()
{
    foo(func);
}
```
- IDE'nin gosterdigi deger:
	- `void foo<int, double>(int (*)(double))`


- Burada anlatilmak istenen bu basit bir yer degistirme degil. Bu complex bir islem.C deki macrolar ile hicbir alakasi yok. Oradaki metinsel bir substitution .Burada ciddi bir cikarim mekanizmasi var.

```
template<typename T>
T * foo(T *);

// int * foo(int *);

int main()
{
    foo<int>(10);
}
```

- buradaki surec'e substitution diyoruz. Bunun neden bu kadar önemli oldugu ileride anlasilacak!
### substitution:
Derleyici bizim gönderdigimiz template parameteresini(T) deduction ile anladiktan sonra, T parametresine göre tanimladigimiz fonksiyonun imzasini cikarir. Bu örnek icin konusacak olursak:
T=int,
substitution sonrasi olusan fonksiyonun imzasi ise su sekilde olur:
int * foo(int *);
*****************************************************************************

### Soru:
Acaba template argument deduction her zaman basarili olmak zorunda mi?
- Gunun onemli sorularindan biri.
- Hayir! Syntax hatasi alabiliriz. Birden fazla nedeni var.
	- func. cagrisindan hareketle compiler template parameters in karsiligi kullanilacak template argumanlarinin cikarimini yapamaz. Yeterli bilgi yok. Syntax hatasi verir.
	- Burada donus degeri cikarimi yapilamaz:
    
```
template<typename T>
T foo();

// int * foo(int *);

int main()
{
    int x = foo();
}
```
    
- Compiler hata mesaji: "bağımsız değişken listesiyle eşleşen işlev şablonu "foo" örneği yok"
    
- could not deduce template argument for T
	- ambiguity (cift anlamlilik hata türü)    
    - burada celiski yok
```      
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
```

**********************

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


**********************


- template in butun parametreleri template parametresini bagli olmasi gerekmiyor.

*****************

**Interview & Tricks Question!!!**

```
// Soru:
// Buraya kadar ögrendiklerimize göre asagidaki ifadede Syntax error var mi, yok mu?

#include<iostream>

template<typename T>
T func(T x, T &&);

int main()
{
    // func<int>(10, 20);
}

// Cevap:
// T nin degeri ilk parametre düsünüldügünde int dir
// ikinci parametre icin de forwarding reference int alabileceginden syntax hatasi yok!
```

*****************

```
// Soru:
// Buraya kadar ögrendiklerimize göre asagidaki ifadede Syntax error var mi, yok mu?

#include<iostream>

template<typename T>
T func(T x, T &&);

int main()
{
    int ival{10};
    func<int>(ival, ival);
}

// Cevap:
// T nin degeri ilk parametre düsünüldügünde int dir!!! 
// ikinci parametre icin de forwarding reference(&&) düsünüldügünde almasi gereken deger lvalue reference yani int& tir.
// Nasil oldu, anlamadim sorusuna cevap? 
// eger argumanlari tek tek cagirsaydik nasil bir type deduction olur diye soruyoruz.
// sadece ilk arguman olsaydi tür cikarimi int olurdu.
// sadece 2. arguman olsaydi tür cikarimi int& olurdu.
// Dolayisiyla compiler bunlardan birini secemeyecek!
// yani deduction sirasinda ambiguity olacagindan syntax error verecek.
// error: cannot bind rvalue reference of type 'int&&' to lvalue of type 'int'
```

*****************

- Neden scott meyers in Universal Reference tabiri daha populer.
- Cunku bu tarz bir func.'a sol ve sag taraf degeri gonderilebilir.
- Asagidaki func. her tur degiskenle cagrilabiliyor.
```
template<typename T>
void func(T &&);
```    
### Scott meyers buna Universal Reference demesinin sebeb bu: const, lvalue, rvalue hersey kabul. Const yada non-const Universal Reference.

*******

- sag taraf ref. leri daha once mumkun olmayan 2 seyi saglamak uzere dile eklenmisti
	- move semantics
	- perfect forwarding(ileride islenecek)

- func. larin cagrilma durumuna gore ayni template ten cok fazla sayida func. lar uretilebilir. STL de gorecegimiz gibi.

- buradaki parameter terimlerine dikkat , farkli
```
template <typename T> //template type parameter
void func(T x) // x call parameter
{

}
```
- ayni olmak zorunda degiller!
```
template <typename T> //template type parameter
void func(T (&x)[10]) // x call parameter
{
    
}
```

*************
### Ornek:
```
template <typename F> 
void func(F f) 
{
    f();
}
```
- burada function pointer olabilir. Function cagri operatorunun Overloadu'nun devlesmesinin template lerle karsimiza cikmasi.

```
#include<iostream>

template <typename F> 
void func(F f)  // int (*)(int)
{
    f(12);
}

int foo(int x)
{
    std::cout << "foo cagrildi\n";
    return x*x*5;
}

int main(){
    func(foo);
}
```
- derleyicinin yazacagi kod:
```
int func(int (*f)(int))  // int (*)(int)
{
    return f(12);
}
```
+ ## tek ihtimal bu degil. Ikinci ihtimal:
```
#include <iostream>

template <typename F> 
int func(F f)  // int (*)(int)
{
    return f(12);
}

class Myclass{
public:
    int operator()(int x) const
    {
        std::cout << "Myclass operator()(int)\n";
        return x + 5;
    }   
};

int main(){
    auto x =  func(Myclass{});
}
```
- Template e Myclass tipinde parametre gectik, template icinde "f()" ifadesini goren template bunun Myclass classinin overload edilmis"()- ac kapa parantez operatoru" oldugunu anladi ve bu yordami cagirdi!!!
### - Bu kullanim STL de en cok karsimiza gelen kullanimlardan biri!

- "()" operatorunu overload eden siniflara "functer" deniliyor.

****************
- Template function in return type i 2 türlu olabilir:
    -auto return type
    -trailing return type

## trailing return type:
```
tmplate <typename T>
auto func(T x) -> decltype(exp);
```
- func geri donus degerie auto yaziliyor. "->" ile devam ediyor.
- auto da Compiler return type a bakip kendi karar verecek.

```
tmplate <typename T>
auto func(T x)
{
    return x + .5;
}
```
****************
### Ornek:
```
template <typename T>
T sum(T x, T y)
{
    return x + y;
}

int main()
{
    auto x = sum(1.2, 3.4);
    std::cout << "x=" << x << "\n";
}
```
- Asagida yine hata olmaz
```
#include <iostream>

template <typename T>
T sum(T x, T y)
{
    return x + y;
}

int main()
{
    using namespace std;

    string s1="saban";
    string s2 = "kocal";
    auto x = sum(s1, s2);
    std::cout << "x=" << x << "\n";
}
```
********
- veri kaybi olacak!
```
#include <iostream>

template <typename T, typename U>
T sum(T t, U u)
{
    return t + u;
}

int main()
{
    auto x = sum(12, 3.4);
    std::cout << "x=" << x << "\n";
}
```
- parametrelerin yerini degisince yine sorun:
```
#include <iostream>

template <typename T, typename U>
U sum(T t, U u)
{
    return t + u;
}

int main()
{
    auto x = sum(1.32, 5);
    std::cout << "x=" << x << "\n";
}
```
************
```
// explicit template argument(derleyiciye acik acik soyleme)
// yeni bir typename daha ekleniyor.

#include <iostream>

template <typename R, typename T, typename U>
R sum(T t, U u)
{
    return t + u;
}

int main()
{
    auto x = sum<double>(12, 4.5);
    std::cout << "x=" << x << "\n";
}

//ilkini ben soyledim, kalan ikisini deduction. T ve U comp. belirledi.
```

```
#include <iostream>

template <typename T, typename U, typename W>
void f(T t, U u, W w);

int main()
{
    f(1, 2.3, 5L);
}

// Compiler türleri deduction ile tespit ediyor.
```
*********
```
// asagidaki ornekte derleyiciye data türlerini biz soyluyoruz.

#include <iostream>

template <typename T, typename U, typename W>
void f(T t, U u, W w);

int main()
{
    //f<int, int, int>(1, 2.3, 5L);
    // kac parametreyi explicit belirtmek istiyorsam onlari belirtiyorum, kalani compiler a ait.
    f<int>(1, 2.3, 5L); 
}
```

*****************

### Soru: 
Neden explicit argument kullanilir?
- Derleyicinin cikarim yapma sansi yok.
- Ör: make_unique ve make_shared gibi functionlar. Cunku burda geri donus türünde kullaniliyor. Burada cikarim yapma sansi yok.
- Diger bir ihtimal:
    - Asagidaki kodda derleyici her biri icin ayri fonksiyon yazmak zorunda!

```

#include <iostream>
#include <string>
#include <memory>

template <typename T>
T foo(T t)
{
    //
    return t * t;
}

int main()
{
    foo(1.2); 
    foo(12.f); 
    foo(234); 
    foo('S'); 
}
```
*****************************

// Her bir arguman icin derleyici yeni func. uretiyor

```
#include <iostream>
#include <string>
#include <memory>

template <typename T>
void foo(T t)
{
    std::cout << typeid(T).name() << "\n";
}

int main()
{
    foo(1.2); 
    foo(12.f); 
    foo(234); 
    foo('S'); 
}

//Ekran ciktisi:
// d
// f
// i
// c

```
******************************

```
// Istersem her degisken türü icin ayri func. üretmenin onune gecebilirdim. 
// Bazen explicit template argument mecburiyet senaryosu olarak kullaniliyor.

#include <iostream>
#include <string>
#include <memory>

template <typename T>
void foo(T t)
{
    std::cout << typeid(T).name() << "\n";
}

int main()
{
    foo(1.2); 
    foo<double>(12.f); 
    foo<double>(234); 
    foo<double>('S'); 
}

//Ekran ciktisi:
// d
// d
// d
// d
```

*****************************

-  func. geri donus degerine cagiran karar verecek sekilde de kurgu yapabilirim:
```

#include <iostream>

template <typename R, typename T, typename U>
R sum(T t, U u)
{
    return t + u;
}

int main()
{
    sum<int>(12, 'K');
}
```

*****************************

- Baska bir örnek:
```
#include <iostream>

template <typename R, typename T, typename U>
R sum(T t, U u)
{
    return t + u;
}

int main()
{
    auto x =  sum<int>(12, 'K');
    auto y =  sum<double>(1.2, 23);
}
```
*****************************

- Bunu yapmanin baska yollari da var:

```
#include <iostream>

template <typename T, typename U>
auto sum(T t, U u)
{
    return t + u;
}

int main()
{
    auto x = sum(3.4, 12);
}

// return type double olacak!

```

*****************************
```
#include <iostream>

template <typename T, typename U>
auto sum(T t, U u)
{
    return t + u;
}

int main()
{
    auto x = sum(3u, 12);
}

// burada return type unsigned int olacak.

```

#  trailing return types 

### trailing return type : C++11 ile dile eklendi.
### auto return type bu anda yoktu. C++14 standartlariyla dile eklendi.

*****************************************************************************
### - Asagidaki kullanim hata verir!!!
```

#include <iostream>

template <typename T, typename U>
decltype(t*u) sum(T t, U u)
{
    return t * t;
}

int main()
{
    
}
```
*****************************

- Bunu asmak icin oktan sonra gecis degeri yazilinca syntax hatasi olmuyor!!!
- Trailing return type: Genel manada fonksiyonlar icin
```
#include <iostream>

template <typename T, typename U>
auto sum(T t, U u) -> decltype(t*u)
{
    return t * t;
}

int main()
{
    
}
```

## Ders ozeti:
- Exception handling konusu tamamalandi
- template konusuna giris yaptik- generic paradigm
- function templates
    - deduction sureci
    - type ve non type parameters
    - template parametresi olan türün bir func. yada class türü olabileceginden bahsettik
- auto return type, trailing return type
- explicit template argumani ve tipik kullanim senaryolarindan bahsettik.