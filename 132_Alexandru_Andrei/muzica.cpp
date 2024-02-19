#include <iostream>
#include <fstream>
#include <unordered_set>
using namespace std;
ifstream f("muzica.in");
ofstream g("muzica.out");
int main()
{
    long a,b,c,d,e,m,n,x,i,k=0;
    unordered_set<long>v(1000000);
    f>>n>>m;
    f>>a>>b>>c>>d>>e;
    for(i=0;i<n;i++)
    {
        f>>x;
        v.insert(x);

    }
    for(i=0;i<m;i++)
    {
        if(v.find(a)!=v.end())
        {
            k++;
            v.erase(a);
        }
        x=(c*b+d*a)%e;
        a=b;
        b=x;
    }
    g<<k;
    f.close();
    g.close();
    return 0;
}
