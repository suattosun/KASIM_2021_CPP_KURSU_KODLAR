/*-------------------------------------------------------------------------------
nullptr bir sabittir ve türü nullptr_t türüdür. C++ ile kod yazarken NULL macrosu yerine
daima nullptr anahtar sözcüğü kullanılır. Macroların C++'ta istenmemesi NULL macrosunun
yerine nullptr kullanımı söz konusudur.
user defined types:
1-)structures
2-)unions
3-)enums
aşağıdaki örnekte C dili için konuşucak olursak struct anahtar sözcüğü bu türü
betimleyen bir anahtar sözcük değildir. Bu sebepte bu yapıyı struct anahtar sözcüğü
olmadan kullanmaya çalışmak syntax hatasına neden olur! Ancak
C++'ta C'de typedef bildirimi kullanılmış user defined türleri gibi kullanılabilir.
Yani struct tag enum tag ve union tag aslında türü betimleyen bir isimdir.
Bu sebeple bu türler doğrudan kullanılabilir.
-------------------------------------------------------------------------------*/
struct Data{
    int x,y,z;
}
int main(){
    struct Data mydata;
    Data mydata;//C'de syntax hatası C++'ta geçerli
}
/*-------------------------------------------------------------------------------
C'de enum türlerinin underlying type(baz türü)'ı int iken C++'ta böyle değildir.
C++ dili için enum sabitlerine verdiğimiz değerlere bağlı olarak derleyici
bu sabitlerin türlerine kendi karar vermektedir.
Aşağıdaki örnek C dilinin kurallarına göre geçerlidir.
-------------------------------------------------------------------------------*/

enum Color{Red,Blue,Black};

int main(){
    enum Color mycolor=Red;

    mycolor=76;
    mycolor=1;
    int ival;
    ival=Red;
}

/*-------------------------------------------------------------------------------
Aşağıdaki örnekte kodun tamamı C dili kuralları için geçerlidir ancak C++ dili
için 1 ve 2 nolu durumlar geçersizdir.
-------------------------------------------------------------------------------*/
enum Color{Red,Blue,Black};
enum Pos{Off,On,Hold};


int main(){
    enum Color mycolor=Red;

    mycolor=76;//1
    mycolor=1;//2
    int ival;//3
    ival=Red;//4
}

/*-------------------------------------------------------------------------------
Scoped enum(enum class)
kolon karakteri kullanılarak programcı enumların
underlying type(baz tür)'ını kendi kararlaştırabilir.
-------------------------------------------------------------------------------*/

enum Color:unsigned {Blue,Red,Black};


int main() {

    Color mycolor=4;//error

}
/*-------------------------------------------------------------------------------

-------------------------------------------------------------------------------*/
enum Color{Red,Blue,Black};
enum Pos{Off,On,Hold};


int main(){
    Color c=Off;//error
}

/*-------------------------------------------------------------------------------
Aşağıdaki örnek C ve C++'ta syntax hatasıdır çünkü aynı isimde birden fazla enum
elemanı bulunamaz.
-------------------------------------------------------------------------------*/
enum Color{Red,Black,Blue};
enum TrafficLights{Red,Yellow,Green};

int main(){



}
/*-------------------------------------------------------------------------------
Yukarıdaki sorunun çözümü aşağıdaki gibidir.
enum classlar için o elemanın hangi enum türüne ait olduğunu belirtmek bu durumda zorunludur.
-------------------------------------------------------------------------------*/
enum class Color{Red,Black,Blue};
enum class TrafficLights{Red,Yellow,Green};

int main(){

  Color cx=Blue;//error
  Color cy=Color::Blue;//okay
}
//--------------------------------------------------------------------------------
#include <stdio.h>

int main(){
    char str[4]="mert";

    puts(str);//ub

}


/*-------------------------------------------------------------------------------
C++ dilinde 3 farklı init tipi vardır:
1-)Copy initialization
    int a = 10;
2-)Direct initialization
    int a(10);
3-)Uniform/direct list initialization
    int a{10};
neden uniform init:
1-)tek biçimli
2-)veri kaybı.....sentaks hatası
3-)most vexing parse()
-------------------------------------------------------------------------------*/

int main(){

    double d=3.4;
    int ival{d};//error
}
//-------------------------------------------------------------------------------
class A{

};
class B{
public:
    B(A);

};
int main(){

    B bx(A());//Parentheses were disambiguated as a function declaration
}
//-------------------------------------------------------------------------------
int main(){
    int y;//default init
    int x=10;//copy init
}
//-------------------------------------------------------------------------------
int main(){
    const int x;//error
}
//-------------------------------------------------------------------------------
int main(){
    int x{};//0
    int y;//çöp değer
}
//-------------------------------------------------------------------------------
#include <iostream>

int main(){
    int x{};
    std::cout<<"x=" << x << "\n";
}
//-------------------------------------------------------------------------------

int x;

int main(){

}
//-------------------------------------------------------------------------------
int main(){
    int x{};
    std::cout<<"x="<<x<<"\n";
}
//-----------------------------------------------------------------------------
int main(){
    auto a=10;
}
//-----------------------------------------------------------------------------
double foo();

int main(){
    auto a=foo();
}
/*-------------------------------------------------------------------------------
AAA(Almost Always auto)
Neden auto kullanmalıyız?
1-)auto ile bildirilen değişkenler init. edilmek zorundadır.
-------------------------------------------------------------------------------*/
int main(){
    auto x;//error
}
/*-------------------------------------------------------------------------------
2-)auto kullanımı kod değişikliğinde avantaj sağlar.Örneğin aşağıdaki örnekte
fonksiyonun geri dönüş değeri değiştiği takdirde temel türlerden biri ile bildirim
yapılsaydı veri kaybı oluşabilirdi.
-------------------------------------------------------------------------------*/
double foo();

int main(){
    auto a=foo();
}
/*-------------------------------------------------------------------------------
Fonksiyonların varsayılan argüman alması(default argument)
Bu mekanizmanın programın çalışma zamanına ek bir maliyeti yoktur. Bu tamammen
compile time a yönelik bir mekanizmadır.
-------------------------------------------------------------------------------*/

void func(int,int,int=0);

int main(){

    func(1,2,3);
    func(1,2);//func(1,2,0);
}
//-------------------------------------------------------------------------------
void func(int,int=10,int);//syntax hatası

int main(){

    func(1,2,3);
    func(1,2);//func(1,2,0);
}
//-------------------------------------------------------------------------------
void func(int,int=10,int);//syntax hatası

int main(){

    func(1,2,3);
    func(1,2);//func(1,2,0);
}
/*-------------------------------------------------------------------------------
Yukarıdaki problemin çözümü ya sadece 3.argümanın default argüman almasıyla
ya da hem 2. hem de 3. argümanın default argüman almasıyla çözülebilir.
Eğer argümanların 3 ü de default argüman alırsa bu gene geçerlidir.
-------------------------------------------------------------------------------*/

void func(int,int=10,int=23);//syntax hatası değil
void foo(int,int,int=23);//syntax hatası değil
void bar(int=98,int=10,int=23);//syntax hatası değil

/*-------------------------------------------------------------------------------
Önemli Not 1: Varsayılan argümanlar ister fonksiyon bildirimde ister fonksiyon tanımında
yapılabilir ancak her ikisinde yapılırsa syntax hatası oluşur.
Önemli Not 2:Varsayılan argümanlar her zaman sondaki argüman veya argümanlara yapılabilir.
-------------------------------------------------------------------------------*/
#include <iostream>

void func(int=10,int=20,int=33);

int main(){

    func(1,2,3);
    func(1,2);//func(1,2,33);
    func(1);//func(10,20,33);
    func();//func(10,20,33);

}
void func(int x,int y,int z){

    std::cout<<"x=" << x << "\n";
    std::cout<<"y=" << y << "\n";
    std::cout<<"z=" << z << "\n";
    std::cout<<"-----------------\n";
}
/*-------------------------------------------------------------------------------
aşağıdaki örnekte foo fonksiyonun bildirimi syntax hatasıdır çünkü burda maximal
munch rule(en uzun atom kuralı) söz konusudur. derleyici bunu çarpı eşittir olarak görür.
-------------------------------------------------------------------------------*/

void func(int,int*p=nullptr);
void foo(int,int *=nullptr);//error
/*-------------------------------------------------------------------------------
Yukarıdaki problemin çözümü aşağıdaki gibidir.
-------------------------------------------------------------------------------*/

void foo(int,int* =nullptr);
//---------------------------------------------------------------------------------

double get_cyl_area(double radius,double height);

int main(){
    get_cyl_area();

}
//---------------------------------------------------------------------------------

int func(int x=10,int y=20);

void foo(int = func());

int main(){

    foo();//foo(func(10,20));

}
/*-------------------------------------------------------------------------------
Aşağıdaki örnek C için geçersiz iken C++ için geçerlidir. Kısacası C'de
fonksiyon tanımları için parametre değişkenlerine isim vermek zorunludur.
-------------------------------------------------------------------------------*/

int foo(int){

//code

}
/*-------------------------------------------------------------------------------
Aşağıdaki örnekte ekran çıktısı 10 11 12 olucaktır.
-------------------------------------------------------------------------------*/
#include <iostream>

int x=10;

int foo(int a= x++){

 std::cout<<"a="<<a<<"\n";

}
int main(){
    foo();//foo(x++);
    foo();//foo(x++);
    foo();

}
/*-------------------------------------------------------------------------------
function redeclaration ile fonksiyona varsayılan argüman verilebilir.
-------------------------------------------------------------------------------*/

int foo(int,int,int);

int foo(int,int,int = 0);

int foo(int,int = 0,int);//bu durumda syntax hatası yok

int main(){

 foo(12);//foo(12,0,0);

}
/*-------------------------------------------------------------------------------
Aşağıdaki örnekte istenen foo fonksiyonunun ikinci argümanına varsayılan argüman geçmektir.
-------------------------------------------------------------------------------*/

void foo(int x,int y,int z);

void call_foo(int x,int z,int y=10){

    foo(x,y,z);
}
int main(){

    call_foo(1,2);

}
//--------------------------------------------------------------------------------

int foo( , ,T*p); //out parametre

int foo( , ,const T*p);//in parametre
/*-------------------------------------------------------------------------------
Bir in parametre örneği bu örnekte timer değişkeni localtime fonksiyonunu çağırdığında
onu hesaplamalarında kullanmaktadır.
-------------------------------------------------------------------------------*/
#include <time.h>

int main(){

    time_t timer;
    time(&timer);
    localtime(&timer);

}
//-------------------------------------------------------------------------------

void func(int, int*p=nullptr);//varsayılan argüman nullptr olabilir.

int main(){
    int x;

    func(1,&x);
}

/*-------------------------------------------------------------------------------

-------------------------------------------------------------------------------*/
#include <ctime>
#include <iostream>

void print_date(int day=-1,int month=-1,int year=-1);

void print_date(int day,int month,int year){
    if(year == -1){
        std::time_t timer;
        std::time(&timer);
        auto p=std::localtime(&timer);
        year= p->tm_year + 1990;
        if(month == -1){
            month = p->tm_mon + 1;
            if(day == -1){
             day= p->tm_mday;

            }
        }

    }
    std::cout << day <<"-"<<month<<"-"<<year<<'\n';
}

int main(){

    print_date(4,5,1987);
    print_date(4,5);//4,5,-1 -> 4 5 2021
    print_date(4);//4,-1,-1 -> 4 11 2021
    print_date();//-1,-1,-1 -> 7 11 2021

}
//------------------------------------------------------------------------------
namespace nec{
    int a=10;

}
int main(){
    nec::a=20;

}
//------------------------------------------------------------------------------
int x=10;

int main(){
    int x=20;//yerel x
    ::x+=x;//global x i yerel x kadar arttır.

}
//-------------------------------------------------------------------------------
#include <iostream>


int main(){

    std::cout.put('A');
}
//--------------------------------------------------------------------------------
int main(){

    int x=10;
    int& r=x;//r x e bir referans
    ++r;//++x
}
/*--------------------------------------------------------
Aşağıdaki kod ile yukarıdaki arasında assembly düzeyinde 
bir farklılık yoktur.
-------------------------------------------------------*/

int main(){

    int x=10;
    int*ptr=&x;//r x e bir referans
    ++(*ptr);//++x
}

