/****************	Functions  ****************/

/*
Soru: Neden member func. olmasina ragmen 
	  C# ve javadan farkli olarak global func. tanimlamaya da devam ediyoruz?

Cevap: Dilin diger araclari dusunuldugunde bazen global func. kullanmak daha ideal oluyor.
*/


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

/****************************************************************/

//Referans semantigi ile pointer karmasasindan cikip problem domain'ine odaklaniyoruz.
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

/****************************************************************/
//Ayni ornegin member function ile gerceklenmesi.
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

/****************************************************************/
/*
 Onemli: C++ ta siniflarin non-static member funcionlari'nin aslinda biz gormesek de 
 "Myclass *(pointer)" tipinden gizli bir parametresi vardir.
 Her üye func. aslinda +1 parametresi var diyebiliriz. 
 Bu gizli parametre bizden sinif türünden bir nesne ister.
*/

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


/****************************************************************/
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

 // bunun yerine yazgimiz func. i Myclass etki alani icin yazmis olsaydik bu sefer Myclass'in private member larina da erismis olacaktik.
 
 Myclass gm;
 
 void Myclass::func(int x)
 {
 	gm.mx = 120; // erisim problemi yok.
 }
 
 
 /****************************************************************/
 
 // Ayni isimdeki(mx) degiskenine 3 farkli kapsamda erisim:
 #include "myclass.h"
 
 int mx = 45;
 
 void Myclass::func(int x){
	int mx = 5;
	
	mx = ::mx + Myclass::mx;
 }
 
 /****************************************************************/
 
 #include "myclass.h"
 
 void Myclass::func(int x){
	Myclass::mx
	// this->mx	
 }
 
 /****************************************************************/
 // Not: Siniflarin uye fonksiyonlari da func. overloading kurallarina dahildir.
 // Not: Member fonksiyonlar icin Function redeclaration yoktur.
 
/******************		Soru: Yorumlayiniz?		******************/ 
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

/*
Cevap: Burada access kontrolu 3. asamada yapilan islemdir. 
Once function overload resolution yordami yurutulur. 
int parametreli private func. exact match oldugundan secilir. 
Sonrasinda yine bu func. private oldugundan acess kontrolune takilir ve syntax error olur.
Not: Gonderilen arguman double olsa sorun olmayacakti!
*/

/******************		Soru	******************/ 
// Soru: Asagidaki kodu yorum satirindan cikardigimda gecerli midir, nasil calisir?
 
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

/*
Cevap: 
- foo ismi aranacak. Uye func. icinde isim arama nasil yapilir? 
  Once blokta, sonra class scope ta. 
  Isim class icinde non-static olan foo(double) olarak bulundu.    
- foo(12) --> class a cagri yapinca aslinda ilk parametreye Myclass in adresi gizli parametre olarak gececek.    

  is gorusmelerinde en onemli elenme nedenlerinden:
- Burada aday su sekil yorum yapar: int ile cagri yapildigindan global foo(int) secilir der 
  ve bu da en basic kavramlardan name lookup kavramini bilmedigini gosterir. 
  Cunku burada function overloading oldugunu dusunmustur. 
  Halbuki burada function overloading de yoktur. Cunku bunlar ayni scope ta degil. 
  Biri class in scope unda ki: once buraya bakilir. yoksa global scope a gecilir.
  2 farkli scope arasinda func. overloading olmaz.
    
- Eger gercekten global func. cagirmak isteseydik:
  o zaman ::foo(12) seklinde cagirabilirdik ve de sorun olmazdi.  
*/

/******************		Soru: Yorumlayiniz?		******************/ 
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

/*
Cevap: 
- Recursive sekilde kendisini cagirir.
- Eger su sekilde cagirilmis olsa global func. cagirilacakti:
  ::func(12);
*/

/******************		Soru: Syntax hatasi var mi?		******************/  
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

/*
Cevap: 
- double parametreli member func. cagrilir. 
- Eger int parametre ile cagirsak recursive olurdu.
*/

/**********		Soru: Buradaki hatanin nedeni nedir?		***********/  
class Myclass {
private:
public:
	void func(double);	
};

int main()
{
	Myclass::func(1.23);
}

/*
Cevap: 
- Myclass::func non-static function called illegally. Nesne tanimlanmamis.
- Aslinda cpp komitesine buna benzer bir kullanim onerilmis fakat reddedilmis:
  Myclass m;
  Myclass::func(m, 1.23);
*/
