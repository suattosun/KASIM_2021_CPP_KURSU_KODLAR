/****************	decltype  ****************/

// decltype konusu aslen 5.Ders'in son 75 dk sindan itibaren anlatilmaya baslanmis.
// 5.Ders'e ait kisimda decltype ile ilgili bir kisim goremedim!

/*
mantik olarak "auto" keywordüne benziyor fakat kullanimi daha karisik.

decltype'in operandi olan ifade T türünden olsun

decltype(a + b)

decltype ile elde edilen tür operand olan ifadenin "value category" 

T

pr value =====>		T
l  value =====>		T&
xvalue	 =====>		T&&

(baglam)

unevaluated context 
"sizeof" ifadesinde de oldugu gibi burada da decltpe i belirleyen ifade(expr.) isletilmez!

sizeof(x++)
sizeof(*ptr)
sizeof(a[10])

decltype(++x) // x'in degeri degismez!
*/