/**********************     assign  ********************/   

// container a atama yapmak icin assign fonksyonu kullanilabilir.
// Soru: Esittir(=) operatoru yeterli degil mi?
// Cevap: Cogunlukla operator overloading ile cozulemiyecek durumlarda assign func. ini kullanmayi tercih ediyoruz.
// bir vectore baska bir vectoru ancak turleri ayni ise yapabiliriz
// ama assign ile farkli turleri de birbirine atayabiliriz
// temel varlik nedeni operator overloading ile dogrudan yapilamayacak islemler   

#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <string>


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
    vector<string> svec = {"ali", "nur", "deniz", "ferhan"};
    set<string> myset = {"albert", "hans", "olga", "richard"};
    
    print(svec);
    // svec = myset; //GECERSIZ. Farkli turdeki containerlari birbirine direk atama yapamiyoruz!
    svec.assign(myset.begin(), myset.end());
    print(svec); //bu asamada yeni degerler ile yazdirma islemi yapiliyor!
}

// assign func. unun return valuesu yok
// assign func. u parametre olarak init list de alabilir ama bunun zaten = operatoru ile de yapabiliyorduk. Bir avantaj saglamiyor.