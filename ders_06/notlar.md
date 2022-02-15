## decltype

/*
mantik olarak "auto" keywordüne benziyor fakat kullanimi daha karisik.

decltype'in operandi olan ifade T türünden olsun

decltype(a + b)

decltype ile elde edilen tür operand olan ifadenin "value category" 

T

pr value =====>		T
l  value =====>		T&
xvalue	 =====>		T&&

(baglam)

unevaluated context 
"sizeof" ifadesinde de oldugu gibi burada da decltpe i belirleyen ifade(expr.) isletilmez!

sizeof(x++)
sizeof(*ptr)
sizeof(a[10])

decltype(++x) // x'in degeri degismez!
*/

****************************************************************
### Dynamic Cast
+ C de karsiligili yok. Kalitim konusuna girince görecegiz.

****************************************************************

## extern "C"  

+ C de func. overloading yok C++ ta var. Bundan dolayi;

    + Ornegin bir func(1, 3, 5); fonksiyonumuz olsun 

	    + C de compiler foksyonu soyle tarif edebilir "@func"
	    + C++ ta bunun icin belki su sekilde bir dekore gerekecek. "_func@i@i@i"
	  C ve C++ arasindaki bu uyumsuzluk(Object module yazilan external referans olan ismin dekore edilmesindeki farklilik) 
	  C++ icinde C de derlenmis bir fonksyon cagrildiginda derleyici eger onun C de yazilmis oldugunu bilmez ise 
	  C++ tipi dekore edince hata alacaktir.

	    + Durumu test etmek icin ".c" uzantili bir dosya olusturursak.

```
#include "necati.h"
#include <iostream>

int main()
{
	int x = foo(12, 45);
	
	std::cout << "x = " << x << "\n";
}
```

  + Yukaridaki kodda compile hatasi yok. link hatasi var(unresolved)
  
  + Bu eklenti C++ compiler a bu foknksiyonu C tarzinda dekore etmesi gerektigini soyler.
    extern "C" int foo(int, int); 
    
+ 2 farkli sekilde extern "C" tanimlamasi yapilabilir:
    1-)
		extern "C" int f1(int, int);
		extern "C" int f2(int, int);
		extern "C" int f3(int, int);
		extern "C" int f4(int, int);
		extern "C" int f5(int, int);
    2-) Öyle bir yazim tarzina ihtiyacim var ki; hem C de hem C++ ta ayni dosyayi kullandigimda iki tarafta da hata almayayim.
    Bunun icin on tanimli
```		
		#ifndef __cplusplus
		extern "C" {
		#endif
		int f1(int, int);
		int f2(int, int);
		int f3(int, int);
		int f4(int, int);
		int f5(int, int);
		#ifndef __cplusplus
		}
		#endif#
```

## Sınıflara giriş `(Introduction to Classes)`
+ C++ 'in en cok ovundugu taraf; data abstraction tarafinda kullaniciya cok daha fazla imkan veriyor.
Ornegin 2 matrix'i toplamak istedigimizde C++ bize bu imkani veriyor ama siniflari kullanmamiz gerekiyor.

+ C deki char * a karsilik, C++ ta string class'inin olmasi...
+ Temel yapi tasi sinif oldugu icin C++ taki class larin cok iyi ogrenilmesi gerekiyor.
+ Class'larin C deki en yakin karsiligi struct'lardi fakat C++ icindeki struct lar da C den farkli olarak artik Class lara cok yakin bir manada kullaniliyor.

```
class Myclass{
// Normalde class; ne ile ilgili ise class ismini ona gore secmek gerekiyor.
};
```

Ornek class Coder...
Buadaki amacimiz konuyu anlatmak oldugundan en basit class isimlendirmelerini kullanacagiz.

// Cdeki asagidaki gibi ici bos tanimlama yapsak hata olurdu. C++ ta bu tarz kullanim legal.
struct Nec{
};

+ Kursumuz sirasinda dersler anlatilirken struct lar da class olarak isimlendirilerek anlatilacak, terminolojiye alismak lazim.
+ C de structlari sadece tür ismiyle kullanmak icin typedef tanimlamasi yapmak gerekirdi. C++ ta ise enumlarda da oldugu gibi direk isimleriyle kullanabiliyoruz.
+ Class lar 3 farkli turden uyeler icerebiliyor:
    + data members(veri elemanlari)
    + member functions(üye elemanlari)
    + type members(nested types) (tür elemanlari)

```
//global function
// yada free function
// yada standalone function seklinde isimlendirilebiliyor.
void f(int);

class  Nec{
    //Data members, C deki struct'larin elemanlari gibi.
    int mx, my; //data members. 
    void foo(int); // sinifin üye fonksyonlari
    
    class Nested{
        // Simdilik burasiyla isimiz yok!
    }
}
```

+ C++ ta C den farkli olarak 2 farkli func. var:
    
    + C de olan C++ ta olan normal fonksiyonlar.
    + Bildirimi sinifin icinde yapilan fonksyonlar(member function)
+ Ilk anlamamiz gereken nokta scope(kapsam). Scope nedir?
    
    + Neyin scope'u olur? Ismin scope'u olur. Bir ismi scope'u icinde kullanirsaniz derleyici o ismi arar, scope'u icinde bulur.
    + scope / name lookup cok iliskili, yakin terimler. Name lookup(isim arama): Derleyici kodu cevirebilmek icin o ismin neyin ismini anlamasi gerekiyor. Bunun cevabi name lookup ile belirleniyor. C deki isim arama kurallarina gore C++ ta cok daha karmasik kurallar var.
    + C++ isim arama tahmin ettiginizden cok daha onemli olacak.

```
Or:
int x();

int main()
{
    x(); // hata yok!
}

Or:
int x();

int main()
{
    Isim arama kurallarina göre bu degisken x olarak bulunur.
    int x = 10;
    
    // sonrasinda x degiskeninin aslinda function olmadigi anlasilir ve syntax hatasi alinir.
    x(); // 
}
```

### C++ ta isim arama 2 sekilde sonuclanabilir:
+ Aranan isim bulunamaz. Syntax error olur.
+ Birden fazla isim bulunur ancak dilin kurallari bu bildirimlerden hangisinin secilecegi konusunda belirleyici degildir. Bu nedenle Syntax error olur. Buna ambiguity//ambigious denir. Boyle bir hata C de yoktu.

### Isim aramanin altin kurallari:

+ isim arama (dil tarafindan belirlenen) bir siraya gore yapilir. Once lokal scope icinde arama, daha sonra global isim alaninda aramaya devam etme gibi... Burada detay anlatilmayacak.
+ Isim arama aranan ismin bulunmasiyla biter ve bir daha baslamaz ve context kontrolu baslar(C yada C++ ogrenenlerin en cok yanlis modelledikleri konulardan biri)
Onceki ornegimizde isim aramasi lokal degisken olan x ismini bulur. Sonra context controlu yapar ve x in fonksyon olmadigi icin syntax hatasi ile bitmesine neden olur.


## Scope & Name lookup iliskisi

+ Ayni kavramin iki farkli gozle gorulmesi:
    + Scope Programci gozuyle, biz bu ismi nerelerde kullanabiliriz.
    + Name lookup Derleyici gozuyle, bu isim bir yerde kullanilmis, bu ismi bulmam gerekiyor.

**C deki scope kategorieri:**

+ file scope
+ block scope
+ function prototype scope
+ function scope

**C++ deki scope kategorieri:**

+ namespace scope(C de yoktu)
+ class scope(C de yoktu)
+ block scope
+ function prototype scope
+ function scope

### Class scope taki kodlarin bulunmasi icin su kosullarin saglanmasi gerekiyor:
+ Isim nitelenmis(qualified name) olarak kullanilacak. Asagidaki operatorlerden biri ile birlikte kullanilmasi gerekiyor:
+ "."
+ "->"
+ "::(scope resolution operator)" C'de yoktu.

```
int main()
{
    Nec mynec;
    Nec *mynec;
    mynec.mx; // Buradaki "." operatoru
}
```

+ "::" cozunurluk operatoru belki C++ en cok kullanilan operatorü.
+ Iki farkli sekilde kullanilabiliyor:
    + **::x** derleyiciye sadece global isim alaninda ara demis oluyoruz.

```
int x = 34;
int main()
{
    int x = 12; // name hiding(tavsiye edilmeyen bir kullanim!)
    x++;// local x
    ::x++; // global olan x e atifta bulunmus olduk.
}
```

+ Eger "::" bir class veya namespace ile birlikte kullanilirsa. Solundaki operand'in icindeki bir class'a, degiskene vs. erismeye calisiyor anlamina gelir.

```
class Myclass{
public:
	int x;
}

int main()
{
		Myclass::x = 5; // Error! Illegal reference to non-static member 'Myclass::x'
}
```

## Name lookup & Access control

**Cok önemli! Mulakatlarda sorulacak sorularin bir cogu bu konu ile ilgili:**
- name lookup(ilgili ismi ara ve bul)
- context controlu(code legal mi degil mi?)
- access control (erisim kontrolu). C de olmayan bir arac! Ilgili kodu kimin kullanma hakki var, kimin yok. (private, public, protected...)

```
class Myclass {
	int x;
}

int main()
{
	Myclass m;
	m.x = 12; // Buradaki "." operatoru
}

//Compiler x'e erisemezsin seklinde hata veriyor.
```
```
// C de bu sekilde bir acces controlu yok. C++ ile kiyaslayacak olursak her sey public.
struct Data{
    int x, y;
}
```

Siniflarin elemanlari derleyicinin yapacagi erisim kontrolu acisindan 3 ayri statüde olabilir:
+ public elemanlari (public reference): Herkese acik
+ private elemanlari: Sinifin ic yapisinda kullanilacak olan, disariya acik olmayan, clientlarin bilmesi gerekmeyen veya istenmeyen üyeler.
+ protected elemanlar: Kalitim konusuyla ilgili oldugundan daha sonra detaya girilecek. Ozetle kalitim ile olusturulan siniflar base class'in protected bolumune erisebilir ama private bolumune erisemez. Bunun disinda private ile fark yok.

+ eger sadece class ifadesi yazilirsa

```
//C++ ta diger bir cok dildekinin aksine her member in basina ayrica public, private yazmiyoruz.	
class Myclass {
    private int x;
    public int y;
}
```

```
//C++ ta
//class ile birlikte özellikle public denmez ise default Private dir!!!
class Myclass {
    public:
    // sinifin public bölümü
    private:
    // sinifin private bölümü
}
```
+ ### Class yerine struct tanimlamasi yapsaydik default erisim alani public'tir. 


Örnek kullanim:

```
class Data{
private:
    int x;
protected:
    int c;
public:
    void f3();
}
```

+ Asagidaki örnekte, sinifin bir private member'ina "." operatorü ile erismeye calistigimda 3. basamakta(access control) hata olusuyor.

```
class Myclass {
	int x;
}

int main()
{
	Myclass m;
	m.x = 12; // Buradaki "." operatoru
}
```
+ Compiler x'e erisemezsin seklinde hata veriyor.

+ Kendi basina ögrenenlerin en fazla yanlis ogrendikleri konulardan biri.

+ Assembly anlaminda member func. diye bir sey yok. Kod yazmayi kolaylastirmak icin, semantic acidan fayda saglamak, daha iyi algi yaratmak icin eklenen bir arac.
+ Java, C# gibi dillerde zaten global func. diye bir sey yok. C++ ta ise yogun olarak global func. kullaniyoruz. Cogu zaman üye func. ile global func. isbirligi halinde calisiyor.
+ Ör: Javadan, C# tan farkli olarak eger bir header dosyasi icin konusuyorsak; sadece public kismindakiler degil ayni zamanda global kisimda olanlar da bu interface'in bir parcasi.

```
/////bilge.h

class Data{
public:
    void f1();
    void f2();
    void f3();
}

void foo(Data x);
```


### Soru: Neden member func. olmasina ragmen C# ve javadan farkli olarak global func. tanimlamaya da devam ediyoruz?

Cevap: Dilin diger araclari dusunuldugunde bazen global func. kullanmak daha ideal oluyor.

```
class Myclass {
	int mx, my;
	double dval;
};

void foo(struct Data* pdest);

int main()
{
	struct Data mydata;
	foo(&mydata);
}
```
****************************************************************

+ ### Referans semantigi ile pointer karmasasindan cikip problem domain'ine odaklaniyoruz.

```
//struct class
struct Fighter{
	int mx, my;
	double dval;
}

void attack_enemy(Fighter *, Fighter *)
void kill_enemy(Fighter *, Fighter *)

int main()
{
	Fighter my_fighter, enemy_fighter;
	// Bu ornekte kimin kime saldiracagi belli degil!
	attack_enemy(&my_fighter,&enemy_fighter);
	kill_enemy(&my_fighter,&enemy_fighter);
}
```
****************************************************************

+ Ayni ornegin member function ile gerceklenmesi.
+ kimin saldiracagi asagida bariz belli
```
struct Fighter{
	int mx, my;
	double dval;
}

void attack_enemy(Fighter *, Fighter *)
void kill_enemy(Fighter *, Fighter *)

int main()
{
	Fighter my_fighter, enemy_fighter;
	my_fighter.attack(enemy_fighter);
}
```

****************************************************************

## Onemli: 
+ C++ ta siniflarin non-static member funcionlari'nin aslinda biz gormesek de 
 "Myclass *(pointer)" tipinden gizli bir parametresi vardir.
 Her üye func. aslinda +1 parametresi var diyebiliriz. 
+ Bu gizli parametre bizden sinif türünden bir nesne ister.
+ C olasydi class in addresini kendim gondermem ve func. nun global olmasi gerekirdi. Burada bu islemi C++ bizim yerimize yapiyor.

```
class Myclass {
public:
	void func(int);
	void foo(int, int);
private:
	int mx, my;
};

int main()
{
	Myclass m;
	
	m.func(10);
	// yukaridaki func. cagrisi aslinda arka planda bu sekilde cagri yapilmis gibi degerlendirilecek.
	//func(&m, 10); 
}
```
+ Burada C den farkli olarak "." operatorunun sagindaki isimler sadece ilgili siniflarin icinde, ilgili class scope ta aranacak.
    
+ Global func. access kontrolune tabi.


****************************************************************
```
class Myclass{
public:
    void func(int);
    void foo(int, int);	
private:
    int mx, my
 };
 
 void foo(Myclass& r)
 {
 	// bu kodu derledigimde hata alacaktim cunku global func. lar siniflarin private memberlarina erisemezler!
    r.mx = 10;
 }
```

+ bunun yerine yazgimiz func. i Myclass etki alani icin yazmis olsaydik bu sefer Myclass'in private member larina da erismis olacaktik.
 
```
 Myclass gm;
 
 void Myclass::func(int x)
 {
 	gm.mx = 120; // erisim problemi yok.
 }
```
 
 + Siradisi senaryolar disinda sinif tanimini header dosyasina ekliyoruz, bu class lari kullanmak isteyenler(client) bu header i include etmesi gerekecek.
 
## Dikkat! 
Sinifin üye fonksyonu icinde bir ismi nitelemeden kullanirsak
isim sirasiyla:
1. once kullanildigi blogun basindan ismin kullanildigi yere kadar
2. orada bulamazsa class scope'ta(class kapsama alaninda)
3. classta da bulamaz ise namespace(global isim alani) icinde arar.

 ****************************************************************
 
 + Ayni isimdeki(mx) degiskenine 3 farkli kapsamda erisim:
 ```
#include "myclass.h"
 
 int mx = 45;
 
 void Myclass::func(int x){
	int mx = 5;
	
	mx = ::mx + Myclass::mx;
 }
```
 
****************************************************************
 
 ```
#include "myclass.h"
 
 void Myclass::func(int x){
	Myclass::mx
	// this->mx	
 }
```
 
****************************************************************
+ Not: Siniflarin uye fonksiyonlari da func. overloading kurallarina dahildir.
+ Not: Member fonksiyonlar icin Function redeclaration yoktur.
 
### Soru: Yorumlayiniz?

```
class Myclass {
private:
	void func(int);
public:
	void func(double);
};

int main()
{
	Myclass m;
	
	//m.func(12);
}
```

### Cevap: 
Burada access kontrolu 3. asamada yapilan islemdir. 
Once function overload resolution yordami yurutulur. 
int parametreli private func. exact match oldugundan secilir. 
Sonrasinda yine bu func. private oldugundan acess kontrolune takilir ve syntax error olur.
Not: Gonderilen arguman double olsa sorun olmayacakti!

### Soru: 
Asagidaki kodu yorum satirindan cikardigimda gecerli midir, nasil calisir?
 
```
class Myclass {
private:
public:
	void func(double);
	void foo(double);
};

void foo(int)
{
	
}

Myclass::func(double d)	
{
	//foo(12);
}
```

### Cevap: 
+ foo ismi aranacak. Uye func. icinde isim arama nasil yapilir? 
  Once blokta, sonra class scope ta. 
  Isim class icinde non-static olan foo(double) olarak bulundu.    
+ foo(12) --> class a cagri yapinca aslinda ilk parametreye Myclass in adresi gizli parametre olarak gececek.    

## Dikkat! 
Is gorusmelerinde en onemli elenme nedenlerinden:
+ Burada aday su sekil yorum yapar: int ile cagri yapildigindan global foo(int) secilir der ve bu da en basic kavramlardan name lookup kavramini bilmedigini gosterir. 
+ Cunku burada function overloading oldugunu dusunmustur. 
+ Halbuki burada function overloading de yoktur. Cunku bunlar ayni scope ta degil. 
  Biri class in scope unda ki: once buraya bakilir. yoksa global scope a gecilir.
+  2 farkli scope arasinda func. overloading olmaz.
    
+ Eger gercekten global func. cagirmak isteseydik:
  o zaman ::foo(12) seklinde cagirabilirdik ve de sorun olmazdi.  

********************************************************************

### Soru: Yorumlayiniz?
```
class Myclass {
private:
public:
	void func(double);	
};

void func(int x)
{
	
}

Myclass::func(double x)	
{
	func(12);
}
```

### Cevap: 
+ Recursive sekilde kendisini cagirir.
+ Eger su sekilde cagirilmis olsa global func. cagirilacakti:
  ::func(12);

********************************************************************

+ namespace scopetaki ile class scope taki func birbirini overload etmez.

********************************************************************

### Soru: Syntax hatasi var mi?
```
class Myclass {
private:
public:
	void func(double);	
	void func(int);	
};

Myclass::func(int x)	
{
	//func(1.23);
}
```

### Cevap: 
+ double parametreli member func. cagrilir. 
+ Eger int parametre ile cagirsak recursive olurdu.

********************************************************************

+ ### ozellikle c#, java dan gelen arkadaslar func. tanimini class icinde yapiyor. ordan gelen aliskanlik. Bu sekilde tanimlamalar c++ ta da var ama bunlar inline function lar. C# taki gibi bir kullanim burada uygun degil. Daha sonra detayli anlatilacak.

********************************************************************

### Soru: Buradaki hatanin nedeni nedir?
```
class Myclass {
private:
public:
	void func(double);	
};

int main()
{
	Myclass::func(1.23);
}
```
### Cevap: 
+ Myclass::func non-static function called illegally. Nesne tanimlanmamis.
+ Aslinda cpp komitesine buna benzer bir kullanim onerilmis fakat reddedilmis:
  Myclass m;
  Myclass::func(m, 1.23);

********************************************************************


#	this ve "*this"  

+ this is a keyword. Baska dillerde self var, kavramlar yakin.
+ this anahtar sozcugu yalnizca sinifin non-static uye fonksyonlarinda kullanilir. 
+ Global bir func. icinde bu keyword un kullanimi direk syntax error.
+ This anahtar sozcugu, fonk. hangi nesne icin cagrilmissa fonksyonun pointer gizli parametre degiskeninin degeri(adresi) anlamina geliyor.
+ Eger adresini degil de nesnenin kendisine erismek isteseydik o zaman da "*this" seklinde kullanmam gerekirdi.
+ this ifadesi PR value expression.

```
mx = x 
this->mx-> = x; 
(*this).mx = x;
Myclass::mx=x;
//hepsi ayni manaya geliyor.
```

## Soru: this pointer i neden var?
Cevap: Global bir fonksiyona icinde bulundugumuz fonksiyon hangi nesne icin cagrilmis 
bu bilgiyi gondermenin baska bir yolu yok!

```
class Myclass {
private:
public:
		void func(int);
};

void f(Myclass*);
void g(Myclass &);

void Myclass::func(int x)
{
	f(this);
}

int main()
{
	Myclass m;
	m.func(12);
}
```

****************************************************************
// Bunun boyle oldugunu ispatlayan bir uygulama:

```
#include <iostream>

class Myclass {
private:
public:
		void func(int);
};

void f(Myclass* p)
{
	std::cout << "f cagrildi p = " << p << "\n";
}

void g(Myclass& r)
{
	std::cout << "g cagrildi &r = " << &r << "\n";
}

void Myclass::func(int x)
{
	std::cout << "Myclass::func(int) this = " << this << "\n";
	f(this);
	g(*this);
}

int main()
{
	Myclass m;
	
	std::cout << "&m = " << &m << "\n";
	
	m.func(12);
}
```
### Ekran ciktisi:
+ &m = 0x7ffd4413a837
+ Myclass::func(int) this = 0x7ffd4413a837
+ f cagrildi p = 0x7ffd4413a837
+ g cagrildi &r = 0x7ffd4413a837

****************************************************************

## this'in 2.kullanim alani:
###	java, c# ta da kullanilan bu yapiya fluent API deniliyor. 
###	C++ ta daha cok **chaining** deniliyor.

```
	x.foo().func().f(); // eger return value Myclass&(this) olursa olur.

	x.foo().func().f();

	x.foo();
	x.func();
	x.f();
```

+ Chain yapisinin belirli faydalari var ama suan o konuya girilmeyecek.
+ Geri donus degeri referans tipinde olmali.
+ Cunku donus degeri olarak lvalue degiskene ihtiyac var.

****************************************************************
```
#include <iostream>

class Myclass {
private:
public:
	Myclass& foo();
	Myclass& func();
	Myclass& bar();
};

Myclass& Myclass::foo()
{
	std::cout << "Myclass::foo() \n";
	
	return *this;
}

Myclass& Myclass::func()
{
	std::cout << "Myclass::func() \n";
	
	return *this;
}

Myclass& Myclass::bar()
{
	std::cout << "Myclass::bar() \n";
	
	return *this;
}

int main()
{
	Myclass m;
	
	m.bar().foo().func();
}
```



### Ekran ciktisi:
+ Myclass::bar() 
+ Myclass::foo() 
+ Myclass::func() 

+ ### func. larin geri donus degeri referans degil de Myclass* olsaydi: nokta operatoru yerine pointer dan dolayi "->" operatoru kullanmamiz gerekecekti.

***************************************************************

+ ### func. larin geri donus degeri referans degil de Myclass* olsaydi: nokta operatoru yerine pointer dan dolayi "->" operatoru kullanmamiz gerekecekti.
+ Ekran ciktisi tamamen ayni!

```
#include <iostream>

class Myclass {
private:
public:
	Myclass* foo();
	Myclass* func();
	Myclass* bar();
};

Myclass* Myclass::foo()
{
	std::cout << "Myclass::foo() \n";
	
	return this;
}

Myclass* Myclass::func()
{
	std::cout << "Myclass::func() \n";
	
	return this;
}

Myclass* Myclass::bar()
{
	std::cout << "Myclass::bar() \n";
	
	return this;
}

int main()
{
	Myclass m;
	
	m.bar()->foo()->func();
}
```


****************************************************************
+ ### This'i kullandigimda adeta assembly kodda olan, fonksyoun gizli parametresi olan ama burada gorunmeyen pointer i kullanmis oluyorum.

****************************************************************

## Soru: Bu kod legal mi?

```
class Myclass {
private:
public:
	void func();
};

void Myclass::func()
{
	Myclass m;
	//this = &m; // Koddaki comment acilirsa ne olur?
}
```

### Cevap:
this, lvalue olmasi gerekirken pr value oldugundan hata aliyoruz. Not: This pointer'ini atama operatorunun sol operandi yapamazsiniz!

+ peki onceki soruda 
+ *this = m: olsa ne olurdu?
+ Gecerli olurdu. Cunku *this bir lvalue degiskenidir.

****************************************************************

### Populer hata:
+ Global func. ile sinifin uye func. hicbir zaman bir overload olusturmaz.

****************************************************************
+ Chaining yapisina ornek olarak, bu yapiyi surekli cout fonksiyon cagrilamizda kullaniyoruz. 
+ cout surekli kendini donuyor.

```
#include <iostream>

int main()
{
	int x = 5;
	double d = 8.9;
	
	std::cout << "x = " << x << " d= " << d << "\n"; // operator overloading
	
	std::cout.operator<<(x).operator<<(d);
}
```


