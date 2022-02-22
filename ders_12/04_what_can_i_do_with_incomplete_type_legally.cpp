/*
* Incoplete type'lar ile legal olarak neler yapabiliriz?
*/

class Nec; //incomplete bir sınıf (forward decl)

//Aşağıdaki gibi fonksiyon bildirimleri yapabiliriz
Nec f1(Nec*);
Nec& f2(Nec&);
Nec f3(Nec);
Nec& f4(Nec*);

//extern olarak bildirim yapabiliriz. Çünkü derleyici nx'e başka bir modülde zaten yer ayrıldığını düşünür.
extern Nec nx; 

//typedef bildirimi yapabiliriz.
typedef Nec* NecPtr;
typedef Nec& NecRef;

//veya tür eş ismi belirtiminde using kullanılarak da yapılabilir.
using NecP = Nec*;

int main()
{
    Nec* p; //pointer tanımlayabilriz
    Nec* ptr = nullptr; //ayrıca null verebiliriz
   
    f1(p);//geri dönüş değeri Nec olduğu için geçersiz bir kod
    f4(p);//geçerli çünkü geri dönüş değeri Nec& türünden
}
