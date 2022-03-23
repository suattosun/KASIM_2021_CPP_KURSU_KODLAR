/*
    - Cok sik hata yapilan bir soru, mulakat sorusu, odev sorusu?      
    - bu vectorde soyle bir desiklik yap. Eger bir ismin uzunlugu 5 ise ondan bir tane daha hemen arkasina ekle.
    - eger 6 ise bu elemani sil!
    
    - !!! muhtemelen yazdigimiz code dogru calismiyacak, sonra nedenini inceliyecegiz!!!
*/


// insert sonrasinda return value eklenen ilk elemani gosteren iteratordur
// erase sonrasinda return value silinen elemandan sonra gelen elemanin adresi

#include <iostream>
#include <vector>
#include <algorithm>
#include <exception>
#include "nutility.h"

using namespace std;

int main(){
    
    std::vector<std::string> svec = {"diana", "malik", "hilal", "nazif", "sadiye", "abdi", "suheyla", "petek", "metin", "zahide", "necmettin", "orkun", "murat", "nevsin", "sidre", "kurthan", "turhan", "helin", "gul", "belgin"};
//    std::vector<std::string> svec = {"burhan", "helin", "ceyda", "hakki", "burhan", "mehmet", "irmak", "mucahit", "ayla", "kelami", "hilal", "engin", "beste", "diana", "nuri", "sarp", "lale", "esen", "umut", "melek"};
    //rfill(svec, 20, rname);
    print(svec);
    
    // isin puf noktasi: eleman ekleme ve silme sonrasinda donus degerlerini kullanmak!!!
    auto beg_iter = svec.begin();
    while(beg_iter!=svec.end()){
        if(beg_iter->length() == 5){
            beg_iter = svec.erase(beg_iter);
            // erase sonrasinda return value silinen elemandan sonra gelen elemanin adresi
            // bundan dolayi iteratoru artirmiyoruz
        }
        else if(beg_iter->length() == 6){
            //SABAN YORUM: mevzuyu daha iyi anlayabilmek icin her ekleme sonrasi size ve distance degerlerini de kontrol edebiliriz
            std::cout << "\n" << "iligli string=" << *beg_iter << " ekleme oncesi size=" << svec.size() << " iterator_index=" << distance(svec.begin(), beg_iter) <<  "\n";        
            print(svec);
            std::cout << "\n";
            
            std::cout << "\n" << "hemen ekleme oncesi iterator_index=" << distance(svec.begin(), beg_iter) <<  "\n";        
            beg_iter = svec.insert(beg_iter, *beg_iter);
            std::cout << "\n" << "hemen ekleme sonrasi iterator_index=" << distance(svec.begin(), beg_iter) <<  "\n";        
            
            // insert sonrasinda return value eklenen ilk elemani gosteren iteratordur
            // bundan dolayi iteratoru 2 artiriyoruz ki; sonraki elemandan devam edelim!
            beg_iter+=2; //advance(beg_iter, 2) ayni isi yapardi!

            //SABAN YORUM: mevzuyu daha iyi anlayabilmek icin her ekleme sonrasi size ve distance degerlerini de kontrol edebiliriz
            std::cout << "\nsize=" << svec.size() << " iterator_index=" << distance(svec.begin(), beg_iter) <<  "\n";        
            print(svec);
            std::cout << "\n";
        }
        else{
            beg_iter++;
        }
    }

    std::cout << "\nislem sonucu:\n";
    print(svec);

}

/*
Ekran ciktisi:
diana malik hilal nazif sadiye abdi suheyla petek metin zahide necmettin orkun murat nevsin sidre kurthan turhan helin gul belgin 
islem sonucu:
sadiye sadiye abdi suheyla zahide zahide necmettin nevsin nevsin kurthan turhan turhan gul belgin belgin
*/
