/********************************	Templates  ********************************/

// !!! Dersin cok detayli özeti icin notlar.md dosyasina bakmanizi tavsiye ederim !!! 

/*
Genel Bilgi: 
+ kursun 3. bölümüne gecmis oluyoruz.
+ C dilinde Pointer öncesindeki konular ile Pointer sonrasinin kiyaslamasi nasilsa 
  burada da Templates öncesi ve sonrasi ayni sekilde. Konular cok zorlasiyor. Bazi 
  konulari 10 kere tekrar etmek gerekecek.
*/

// Cok onemli Soru:** (80.dk))
/*
Soru: Dedik ki derleyici meta code dan gercek kodu yazmasi icin gercek türü bilmeli. Peki nasil bilecek?
+ 2 ayri mekanizma var:
    - deduction mechanism(cikarim): Compiler a explicit tür ü söylemiyoruz ama derleyici context ten cikarim yapiyor.
    Asagida derleyici anladi ama ben soylemedim.

*/
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

/**********************************************************/

//   - 2.olasilik: explicit template argument: ozellikle türü belirtiyorsak.

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

// Burada sadece konuya genel bir tanitim, giris yapiliyor, konu sonra detaylandirilacak!
