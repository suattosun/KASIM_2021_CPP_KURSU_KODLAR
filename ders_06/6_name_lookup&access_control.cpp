/****************	Name lookup & Access control  ****************/

/*
Cok önemli! Mulakatlarda sorulacak sorularin bir cogu bu konu ile ilgili:**
1- Name lookup(ilgili ismi ara ve bul)
2- Context controlu(code legal mi degil mi?)
3- Access control (erisim kontrolu). C de olmayan bir arac! 
   Ilgili kodu kimin kullanma hakki var, kimin yok. (private, public, protected...)
*/

class Myclass {
	int x;
}

int main()
{
	Myclass m;
	m.x = 12; // Buradaki "." operatoru
}

//Compiler x'e erisemezsin seklinde hata veriyor.
