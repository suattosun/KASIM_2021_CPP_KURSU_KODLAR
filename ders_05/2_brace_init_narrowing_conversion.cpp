/* 
*Brace initialization'ın dile eklenmesindeki güzelliklerden bir tanesi de değişken init işleminde
*veri kaybı olacak bir durumu engellemesidir. Narrowing (daralan) conversion durumlarını engellemek için güzel bir init yöntemi
*/

#include <iostream>

int main()
{
	double dval = 4.51; 
	int x1 = dval; //veri kaybı var
	int x2(dval); //veri kaybı var
	int x3{dval}; //veri kaybına izin yok. Syntax error.
}