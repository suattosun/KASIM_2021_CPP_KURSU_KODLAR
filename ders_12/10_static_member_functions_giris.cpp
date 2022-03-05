/*
* Sınıfın static üye fonksiyonları
* 1. this pointerine sahip değiller
* 2. bir instance için çağrılmayacaklar
* 3. class scope içindeler
* 4. sınıfın üyeleri oldukaları için sınıfın private bölümün erişebilirler
* 5. intsance için değil sınıf için bir iş yapıyorlar
* 6. erişim kontrolüne sahipler
*/

//myclass.h
class Myclass {
public:
    static int foo(); //static member func bildirimi
    int func(); //non-static member func bildirimi

    //Veya imlicitly inline olarak tanımlayabiliriz.
    static int bar()
    {
        mx = 10; //mx non-static olduğundan static bir fonksiyon bu şekilde erişemez.
        
        Myclass m;
        m.mx = 20; //bu şekilde erişim mümkündür. mx private olsa dahi static member func 
        //erişebiliyor ilginç bir biçimde nesne üzerinden :)

        return 10;
    }
private:
    int mx, my;
};

//myclass.cpp
int Myclass::foo() //static keyword burada kullanmıyoruz.
{
    return 1;
}

int main()
{

}

/*
Ek bilgi:
static keyword fonksion tanımında kullanılmadığından fonksiyonun cpp dosyasındaki
koda bakarak statik mi değili mi anlaması güç olabilir. Bu yüzden bazan programcılar şöyle bir teknik kullanıyor:

#define STATIC
#define PUBLIC
#define PRIVATE

PUBLIC STATIC int Myclass::foo()
{
    return 1;
}

Bu durumda önişlemci #define edilmiş yerleri sileceği için 
koda bir etkisi olmayacaktır.
*/



