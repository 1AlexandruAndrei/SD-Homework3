#include <iostream>
#include <fstream>
#include <map>
using namespace std;
ifstream f("pariuri.in");
ofstream g("pariuri.out");
int main()
{
    int n,i,bani,timp,m,j;
    map<int,int>v;
    f>>n;
    for(i=0;i<n;i++)
    {
        f>>m;
        for(j=0;j<m;j++)
        {
            f>>timp>>bani;
            v[timp]=v[timp]+bani;
        }
    }
    g<<v.size()<<endl;
    for(auto it : v)
        g<<it.first<<" "<<it.second<<" ";

    f.close();
    g.close();

    return 0;
}
