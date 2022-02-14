/*
* decltype ile yapılan tür çıkarımı iki biçimde yapılıyor.
* Birincisi decltype'ın operandı olan ifade doğrudan isim formunda olacak.
* Buna ifadenin . ve -> operatörünün operandı olması da dahil.
* Tür çıkarımında bildirimdeki tür esas alınır.
*/

int x = 10;
const int cx = 20;
int *ptr = &x;
int &r = x;
int arr[] = {1, 2, 3};

int main()
{
    decltype(x) a; //a'nın türü int
    decltype(cx) ca = 10; //ca'nın türü const int (const'luk düşmez). Const olduğundan ilk değer vermek gerekir. 
    decltype(ptr) p; //p'nin türü int*
    decltype(r) ref = x; //ref'in türü int& (referanslık da düşmez)
    decltype(arr) b; //b'nin türü int[3] (array decay olmaz)
}
