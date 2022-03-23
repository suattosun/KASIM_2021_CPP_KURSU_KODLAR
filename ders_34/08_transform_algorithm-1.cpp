/**********************    transform algorithm   *********************/

/*
    Dersinden bu kismindan sonra onemli bazi algoritmalara deginecegiz

    // ufunc: unary func. tek parametreli fonksyonun implementasyonu yaklasik olarak asagidaki sekilde
    template <typename InIter, typename OutIter, typename UFunc>
    OutIter transform(InIter beg, InIter end, OutIter destbeg, UFunc f)
    {
        while (beg!=end)
        {
            *destbeg++ = f(*beg++);
        }
        
        return destbeg;
    }
*/


/***************************************************/

// ikinci overload da karsilikli olarak iki range var, bunlar üzerinde bir transform uygulanip 3. bir range yaziliyor
// ikinci range de yeterince eleman yoksa runtime hatasi olur.
// bir ornek, maalesef lambda ifadelerini kullanacak. Bugun onu da ogrenecegiz.

#include <iostream>
#include <vector>
#include <list>
#include <algorithm>
#include "nutility.h"

using namespace std;

int square(int x)
{
    return x*x;
}

int main()
{
    vector<int> ivec{1,4,7,9,12,15,20};
    list<int> ilist(ivec.size());

    transform(ivec.begin(), ivec.end(), ilist.begin(), square);
    print(ilist);
}

/*
    Ekran ciktisi:
    1 16 49 81 144 225 400 
*/