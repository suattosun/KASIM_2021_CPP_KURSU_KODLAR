/****************	Public - Private -Protected  ****************/

/*
Siniflarin elemanlari derleyicinin yapacagi erisim kontrolu acisindan 3 ayri statüde olabilir:
- public elemanlari (public reference): Herkese acik
- private elemanlari: Sinifin ic yapisinda kullanilacak olan, 
  disariya acik olmayan, clientlarin bilmesi gerekmeyen veya istenmeyen üyeler.
- protected elemanlar: Kalitim konusuyla ilgili oldugundan daha sonra detaya girilecek. 
  Ozetle kalitim ile olusturulan siniflar base class'in protected bolumune erisebilir 
  ama private bolumune erisemezler. 
  Bunun disinda private ile protected arasinda bir fark yok.
*/

//C++ ta class ile birlikte özellikle public denmez ise default "private" dir!!!
class Myclass {
	public:
	// sinifin public bölümü
	private:
	// sinifin private bölümü
}

/****************************************************************/


class Myclass {
	int mx, my;
}

int main()
{
	Data mydata;
	
	// mydata.mx //comment acilirsa...
	//Sinifin bir private member'ina "." operatorü ile erismeye calistigimda 
	//3. basamakta(access control) hata olusuyor.
}
