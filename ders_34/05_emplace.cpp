/**********************     emplace      ********************/   

/*
- Moden C++ ile gelen belki de en onemli nimetlerden biri
- emplace oncesinde copya cikartiliyordu
- modern C++ ile tasima seklinde de yapilabiliyor
- perfect forwarding ile ctor a gecilecek parametreleri geciyoruz, const luk vs bozulmadan, uyenin bunu tutmasini sagliyoruz.
- push_back i cagiracagimizi dusunelim
- sag rataf ref. ile perfect forwarding eklenmesi sayesinde artik copy islemi olmadan da bu eleman ekleme yapilabilmeye baslandi.
*/

// #include <nutility.h> Necati hoca bu header'i ekledikten sonra bu satir acilabilir!
#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <string>
// #include "date.h" bu header da buyuk ihtimalle https://github.com/HowardHinnant/date buradan alinmali, emin degilim!

using namespace std;

// SABAN NOT: Hoca, orneklerde nutility.h daki print func. kullaniyor. 
// nutility.h olmadan da ornegi calistirabilmek icin ben de bir print func template yazdim!
// Bu kisim hocanin kodlarinda yoktu; hatalar, eksiklikler bana ait!
template <typename T>
void print(std::vector<T> vec)
{
    for(auto item : vec){
        std::cout << item << "\t"; 
    }
    std::cout << "\n";
};

int main()
{
    vector<Date> dvec;
    rfill(dvec, 5, Date::random);
    print(dvec);

    /* 
        - soyle bir sey istense?
        - belirli bir tarihi ekleyin
        - modern C++ oncesi
        - Degeri: 5 Mayis 1987 olan bir Date ekleyin!
        - Moden C++ oncedinde burada copyalama yapiliyordu.
    */
   dvec.push_back(Date{5, 5, 1987});

    // boyle degil de parametreleri gecsek ve date nesnesi direk yerinde olusturulsa            
    // emplace_back bunu yapiyor
    dvec.emplace_back(Date{5, 5, 1987});
}


/*************************************************************************/

/*
- perfect forarding de gonderdigimiz argumanlar baska bir func. cagri sirasinda arguman olarak kullaniliyordu.
- gonderdigim cost ise, const gitmeli, lvalue ise lvalue, rvalue ise rvalue seklinde gondermeli
- yani const luk ve value categorisi bozulmayacak
- benim dogrudan cagirmamla senin cagirman arasinda hicbir fark olmayacak
*/

#include <set>
// #include "date.h" bu header da buyuk ihtimalle https://github.com/HowardHinnant/date buradan alinmali, emin degilim!

using namespace std;

template <typename ...Ts>
void func(Ts &&...args)
{
    foo(std::forward<Ts>(args)...);
};

// perfect forwarding buydu!
// yazilan kodlarda en buyuk hatalardan biri emplace yerine programcinin push_back cagirmasi!!!

/*
    myvec.push_back(Myclass{}); // Burada hem default ctor hem de copy ctor cagriliyor
    myvec.emplace_back(Myclass{}); // Burada sadece copy ctor cagriliyor
    - programcilarin %90 i tarafindan yanlis anlasiliyor!!!
*/

/*********************************************************************************/
// default ctor un cagrildigini gosterelim

#include <iostream>
#include <vector>

class Myclass{
    public:
    Myclass(){
        std::cout << "default ctor \n";
    }

    Myclass(const Myclass & ){
        std::cout << "copy ctor \n";
    }
};

int main()
{
    using namespace std;

    vector<Myclass> myvec;
    myvec.reserve(20);

    Myclass m; //1. m olustugu icin default ctor cagrildi

    myvec.push_back(m); //2. vectore eklerken copy ctor cagrildi.
}

/*
    Ekran ciktisi:
    default ctor 
    copy ctor
*/


/*********************************************************************************/
// default ctor un cagrildigini gosterelim

#include <iostream>
#include <vector>

class Myclass{
    public:
    Myclass(){
        std::cout << "default ctor \n";
    }

    Myclass(const Myclass & ){
        std::cout << "copy ctor \n";
    }
};

int main()
{
    using namespace std;

    vector<Myclass> myvec;
    myvec.reserve(20);

    myvec.push_back(Myclass{}); // Bu kullanimda da ayni sekilde once default ctor, sonrasinda copy ctor cagrildi!
}

/*
    Ekran ciktisi:
    default ctor 
    copy ctor
*/

/*********************************************************************************/
// default ctor un cagrildigini gosterelim

#include <iostream>
#include <vector>

class Myclass{
    public:
    Myclass(){
        std::cout << "default ctor \n";
    }

    Myclass(const Myclass & ){
        std::cout << "copy ctor \n";
    }

    //Ornegimizin bu varyasyonudne move ctor'u da ekledik!
    Myclass(Myclass &&){
        std::cout << "move ctor \n";
    }
};

int main()
{
    using namespace std;

    vector<Myclass> myvec;
    myvec.reserve(20);

    //Ornegimizin bu varyasyonudne move ctor'u da ekledik!
    myvec.push_back(Myclass{}); //once default ctor, sonra move ctor cagrildi!
}

/*
    Ekran ciktisi:
    default ctor 
    move ctor !!! move ctor tanimlaninca artik copty ctor yerine move ctor cagriliyor!
*/

/*********************************************************************************/
// sadece default ctor un cagrildigini gosterelim!!!

#include <iostream>
#include <vector>

class Myclass{
    public:
    Myclass(){
        std::cout << "default ctor \n";
    }

    Myclass(const Myclass & ){
        std::cout << "copy ctor \n";
    }

    Myclass(Myclass &&){
        std::cout << "move ctor \n";
    }
};

int main()
{
    using namespace std;

    vector<Myclass> myvec;
    myvec.reserve(20);

    myvec.emplace_back(); // Bu kullanimda sadece default ctor cagrildi!
}

/*
    Ekran ciktisi:
    default ctor
*/

/*********************************************************************************/
/****** Necati hoca burayi bir kere de kayittan dinleyin dedi. Ben daha once boyle dedigini duymamistim !!! ******/ 
/****** yanlis anlayan kitle icinde olmayin!!! ******/

#include <iostream>
#include <vector>

class Myclass{
    public:
    Myclass(){
        std::cout << "default ctor \n";
    }

    Myclass(int, int, int){
        std::cout << "Myclass(int, int, int)\n";
    }

    Myclass(const Myclass & ){
        std::cout << "copy ctor \n";
    }

    Myclass(Myclass &&){
        std::cout << "move ctor \n";
    }
};

int main()
{
    using namespace std;

    vector<Myclass> myvec;
    myvec.reserve(20);

    myvec.emplace_back(Myclass{1, 4, 7}); 
}

/*
   Myclass(int, int, int)
   move ctor
*/

/*********************************************************************************/
/****** bu sefer Myclass ismini belirtmeden sadece parametreleri geciyoruz!!! ******/

#include <iostream>
#include <vector>

class Myclass{
    public:
    Myclass(){
        std::cout << "default ctor \n";
    }

    Myclass(int, int, int){
        std::cout << "Myclass(int, int, int)\n";
    }

    Myclass(const Myclass & ){
        std::cout << "copy ctor \n";
    }

    Myclass(Myclass &&){
        std::cout << "move ctor \n";
    }
};

int main()
{
    using namespace std;

    vector<Myclass> myvec;
    myvec.reserve(20);

    //bu sefer Myclass ismini belirtmeden sadece parametreleri geciyoruz!!!
    myvec.emplace_back(1, 4, 7);  
    //Boylece Myclass default ctor'u cagrilmamis oldu!!!
}

/*
   Ekran ciktisi:
   Myclass(int, int, int)
*/


// - burada bu fonksiyonun cagri maliyeti odenmemis oluyor. Bunun yuzlerce defa yapildigi dusunuldugunde cok ciddi bir perfromance kazanci var.

/*********************************************************************************/
// - her insert isleminin bir de emplace karsiligi var

#include <iostream>
#include <vector>

using namespace std;

int main()
{

    vector<Date> dvec{Date{1, 4, 1987}};
    dvec.emplace(dvec.begin(), 5, 5, 1995);

    // - her insert isleminin bir de emplace karsiligi var
    dvec.emplace_back(1, 4, 7);  
}

