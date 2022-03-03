# Online C++ Kursu Ders İçerikleri

## Ders_01
+ C++'in tarihcesi
+ C++ dili ve programlama paradigmaları
+ C++ dili standartları
+ C++98 – 03
+ C++11
+ C++14
+ C++17
+ C++20
+ eski C++ ve **modern C++**
+ **Boost** kütüphanesi ile ilgili kisa bilgilendirme
+ C dili ile C++ icindeki C dili arasindaki farklar

**************************

## Ders_02
+ C dili ile C++ icindeki C dili arasindaki farklar - Devam
+ enum class in C++
+ C++ taki ilk deger verme`(initialization)` türleri
+ anahtar sözcügü`(auto keyword)`
+ default argument`(Fonksiyonların varsayılan argüman alması)`
+ fonksiyonlarin yeniden tanimlanmasi`(function redeclaration)`
+ forwarding function
+ isim alanlari `(namespace)`
+ referans semantigi `(reference semantics)`
+ deger kategorileri`(value categories)`

**************************

## Ders_03
### Referans Semantiği (Reference Semantics)
+ sol taraf referansları `(L value references)`
+ sağ taraf referansları `(R value references)`
+ referanslar ve const semantiği `(references & const semantics)`
+ referanslar ile göstericilerin `(pointer)` karşılaştırılması
+ parametresi referans olan işlevler
+ referans döndüren işlevler
+ Auto Type Deduction

**************************
## Ders_04
+ ### Auto Type Deduction - Devam
+ ### Sabit İfadeleri _(Constant Expressions)_
    + const anahtar sözcüğü ve const semantiği
    + const nesneler
    + constexpr anahtar sözcüğü
    + **constexpr işlevler `(constexpr functions)`**
    + consteval işlevler - C++20 `(consteval functions - C++20)`
+ ### İşlev Yüklemesi`(Function Overloading)`
    + genel kurallar
    + yüklenmiş işlev çözümlenmesi `(function overload resolution)`
    + const yüklemesi `(const overloading)`
    + işlev yüklemesinde dikkat edilmesi gereken durumlar
+ ### C++ a neden `nullptr` eklendi?


**************************

## Ders_05
+ ### İşlev Yüklemesi`(Function Overloading)` - Devam
+ ### Tür Dönüştürme Operatörleri _(Type-cast Operators)_
    + static_cast<> operatörü
    + const_cast<> operatörü
    + reinterpret_cast<> operatörü
    + dynamic_cast<> operatörü `(kalıtım başlığı altında)`
+ enum türleri `(enum classes & scope)`
+ ### decltype `(declared type of name)`

**************************

## Ders_06
+ ### decltype `(declared type of name)` - devam
+ ### extern "C" bildirimi `(extern C declarations)`
+ ### **Sınıflara giriş `(Introduction to Classes)`**
    + sınıf kapsamı `(class scope)`
    + sınıflar ve isim arama `(name lookup)`
    + erişim kontrolü `(access control)` ve veri gizleme `(data hiding)`
        + public öğeler `(public members)`
        + private öğeler `(private members)`
        + protected öğeler `(protected members)`
  + **this göstericisi ve \*this**

**************************

## Ders_07
### Sınıflara giriş `(Introduction to Classes)` - Devam
+ ### this göstericisi ve \*this - devam
+ ### sınıfların öğeleri `(class members)`
    + sınıfların veri öğeleri `(data members)`
        + non-static veri öğeleri
        + mutable veri öğeleri
        + static veri öğeleri
    + sınıfların üye işlevleri
        + non-static üye işlevler
        + const üye işlevler
        + static üye işlevler

**************************

## Ders_10
+ ### Özel üye fonksiyonları(special member function) derleyici tarafında tablo şeklinde yorumlanması
+ ### Conversion constructor
+ ### Explicit conversion constructor
+ ### Geçici sınıf nesneleri (Temporary Object)
+ ### Kopyalamanın elimine edilmesi (Copy Elision) - giriş

**************************

## Ders_17
### Namespace
+ ### Nested Namespace
+ inline Namespace
+ unnamed Namespace
+ namespace alias
### Nested Types
### Composition (Containment)

**************************

## Ders_27
### Exception Handling - Devam
### Templates
+ ### template konusuna giris - generic paradigm
+ ###  function templates
    + deduction sureci
    + type ve non type parameters
    + Fonk. veya class parametresi olarak template parametresi kullanimi
+ ###  explicit template argumani ve tipik kullanim senaryolari
+ ###  auto return type
+ ###  trailing return type

**************************

## Ders_29
### `(templates)` - Devam
+ ### explicit specialization / full specialization 
+ ### partial specialization
+ ### meta-function
	+ ### deger hesaplamaya yönelik meta-function
	+ ### tür hesaplamaya yönelik meta-function
+ ### alias template
+ ### variable templates

**************************

## Ders_30
### `(templates)` - Devam
+ ### perfect forwarding
+ ### Variadic templates
	+ ### template parameter pack
	+ ### function parameter pack
	+ ### pack expansion
	+ ### variadic parametreleri kullanma teknikleri
		+ #### compile-time recursive pack expansion
		+ #### compile-time recursive pack expansioninitializer list
		+ #### C++17 fold expression(Advanced C++ kursu kapsaminda)
		+ #### C++17 compile-time if(kisa tanitim yapildi)

