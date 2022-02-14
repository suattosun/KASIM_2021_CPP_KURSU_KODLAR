/* C'de const nesne adresi türünden const olmayan nesne adresi türüne yapılan dönüşümler de (const cast) söz konusudur.
* Fakat böyle bir şey yapmamız kodun her zaman legal olacağı anlamaına gelmez.
*/
#include <stdio.h>

int main(void)
{
	const int x = 10;
	
    	int* p1 = &x; //C'de uyarı, c++'da syntax hatası.
	
    	int* p2 = (int*)&x; //Fakat şimdi derleyicinin uyarısı kesildi. Ama yine de riskli bir kod.
	*p2 = 56; //değiştirme girişimi undefined behaviour
}
