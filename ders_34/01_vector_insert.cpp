/*
- butun insert func. ozelligi insert pozisyonunu almasi. Diger parametreler neyin insert edilecegi
- sonraki parametre init list olabilir, bir range olabilir...
- tek oge ekleyebilirim
- toplu ekleme yapabilirim --> 5, kerim...
- range ekleyebilirim
*/

#include <algorithm>
#include <vector>

using namespace std;

int main()
{
    vector<string> svec;
    rfill(svec, 5 rname);

    print(svec);
    svec.insert(svec.begin(), {"ali", "can", "nur"});
    print(svec);
}