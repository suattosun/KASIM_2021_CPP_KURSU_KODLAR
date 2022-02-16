/****************	Functions  ****************/

/*
- Exception handling 1. bolumun sonuna gelindi.

function try block:
constructor disinda kullanmanin bir esprisi yok. 
Ama dilin kurallari acisindan baska yerlerde de kullanilabilir!
*/

void func()
try
{
	
}
catch(int) {

}

/*
- func. catch blogunda func. parameters hala visible dir.
- func. catch blogunda return deyimi olabilir.
*/

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

/*
Önemli: 
class in default const. parametresi nedeniyle exception throw ederse
function try block bunu yakalayamaz. 
*/

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

// yukaridaki tanimsiz davranis!

// function try block'un temel kullanim alani contructor icinde kullanim.

// bu sekilde excption yakalamak mumkun degil. debug da da gorulecek!

/*
Soru: 
Neden const. in member indan gelecek hatalari yakalmaya calisayim?

Cevap: 
Amac hala nesneyi kurmanin mumkun olmasi degil.
ya hatayi loglamak ve rethrow etmek
yada eception u transform etmek
Bunu nasil yapicaz. Cevap function try block!
*/

/****************************************************************/

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

// try in yerine(syntax) dikkat!

// kural su: 
// eger siz burda rethrow etseniz de etmesininz de exception constructer dan cikip main'e siziyor.

/*
Önemli:
kitaplarin cogunda bu konuya degilinilmiyor ama bence(Necati E.) cok onemli bir arac!

Soru:
Excetion constructer icinde yakalanmasina karsin neden buradan main icine rethrow ediliyor?
Cevap:
Eger main bu hatayi bilmeseydi, ilgili nesneyi normal sekilde olustu sanip kullanmaya devam ederdi.
Ilgili nesne ZOMBI Object olurdu.
*/

/****************************************************************/

// Buradaki "what" onemli cunku bazi durularda biz what i override edecegiz!

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

// yukaridaki kod ile hata konusunda detayli bilgi edinemiyoruz.

/****************************************************************/

// Bu sekilde kenid custom hata mesajimi belirtebiliriz.

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

/****************************************************************/

// bazi durumlarda exception dan kalitimla almak yerine child exception tiplerinden birini kullanmak da isteyebiliriz.

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

// Ekran ciktisi:
// exception caught in main: 
// custom message: format error
/****************************************************************/

// kendi Constructer'imizi da olusturabilirdik.
// bir baka ihtimal inherited const kullanmak:

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
/****************************************************************/

/*
%95 genel egilim. Kendi hata siniflarimizi stdlib in hatalarindan birinden turetmek.
eger allocation ile ilgili sorun varsa ornegin: bad_alloc. 
String add out of range varsa mesela: out_of_range kullanilabilir...
*/

//olusturacagimiz hata siniflari tabi daha complex de olabilir.

//client code lar bizim exception dan extra bilgiler de edinebilirler.
// Kendi error sinifimiz icine get_file_name gibi get_line_no gibi fonksiyonlar ekleyebiliriz.
// hangi dosyanin hangi satirinda hata oldugu bilgisi bu sekilde gonderebilir.
// eger vakit kalirsa exception handling-2 olacak. ya kendimiz ogrenecegiz ya da ilieri c++ ta ogrenilebilir. 
// orada idiomatic bazi yapilar, custom exception siniflari gorulecek!
// End of Exception handling!