#include <iostream>
#include <fstream>
#include <set>
using namespace std;
ifstream f("heapuri.in");
ofstream g("heapuri.out");
int main()
{
    int n,i,op,x,k=1,v[200001]={};
    multiset<int>s;
    f>>n;
    for(i=0; i<n; i++)
    {
        f>>op;
        if(op==1)
        {
            f>>v[k];
            s.insert(v[k]);
            k++;

        }
        else if(op==2)
        {
            f>>x;
            s.erase(v[x]);
        }
        else
            g<<*(s.begin())<<endl;

    }

    f.close();
    g.close();
    return 0;
}
