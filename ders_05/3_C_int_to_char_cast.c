/* C'de bazan tür dönüşümü işlemini derleyicinin verdiği uyarıları yok etmek (derleyicinin sesini kesmek) için de 
* bilinçli olarak yapabiliriz. Aşağıdaki örnekte int türünden char türüne dönüşüm söz konusudur.
*/
#include <stdio.h>

int main(void)
{
	char str[40];
	int c;
	int idx=0;
	
	while((c = getchar()) != '\n'){
		str[idx++] = (char)c; //zaten otomatik dönüşüm söz konusu. Fakat bunu bilerek yaptığımızı derleyiciye söylüyoruz.
	}
}