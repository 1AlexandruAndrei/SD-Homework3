#include <iostream>
#include <fstream>
#include <vector>
using namespace std;
ifstream f("hashuri.in");
ofstream g("hashuri.out");
int main()
{
    int mod=104729;
    vector<vector<int>> v;
    v.resize(mod);
    int i,n,op,x,j,ok;
    f>>n;
    for(i=0; i<n; i++)
    {
        f>>op>>x;
        int id=x%mod;
        if(op==1)
        {
            ok=0;
            for(j=0; j<v[id].size(); j++)
                if(x==v[id][j])
                {
                    ok=1;
                    break;
                }
            if(ok==0)
                v[id].push_back(x);
        }
        else if(op==2)
        {
            for(j=0; j<v[id].size(); j++)
                if(x==v[id][j])
                {
                    v[id].erase(v[id].begin()+j);
                    break;
                }
        }
        else
        {
            ok=0;
            for(j=0; j<v[id].size(); j++)
                if(v[id][j]==x)
                {
                    ok=1;
                    break;
                }
            if (ok!=0)
                g<<"1"<<endl;
            else
                g<<"0"<<endl;

        }
    }
    f.close();
    g.close();
    return 0;
}
