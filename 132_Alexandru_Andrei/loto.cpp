#include <iostream>
#include <fstream>
#include <vector>
#include <unordered_map>
#include <queue>
using namespace std;
ifstream f("loto.in");
ofstream g("loto.out");
int main()
{
    int n,s,a,b,c,i;
    f>>n>>s;
    int v[101];
    unordered_map<int, vector<int>> m;
    priority_queue<int, vector<int>, greater<int>> h;
    for (a=0; a<n; a++)
        f>>v[a];

    for(a=0; a<n; a++)
        for(b=0; b<n; b++)
            for(c=0; c<n; c++)
            {
                if (m.find(v[a]+v[b]+v[c])==m.end())
                {
                    m[v[a]+v[b]+v[c]].push_back(v[a]);
                    m[v[a]+v[b]+v[c]].push_back(v[b]);
                    m[v[a]+v[b]+v[c]].push_back(v[c]);
                }
            }

    int ok=0;
    for (a=0; a<n && ok==0; a++)
        for (b=0; b<n && ok==0; b++)
            for (c=0; c<n && ok==0; c++)
            {
                if (m.find(s-(v[a]+v[b]+v[c]))!=m.end())
                {
                    ok=1;
                    for (i=0; i<m.find(s-(v[a]+v[b]+v[c]))->second.size(); i++)
                        h.push(m.find(s-(v[a]+v[b]+v[c]))->second[i]);

                    h.push(v[a]);
                    h.push(v[b]);
                    h.push(v[c]);
                }
            }
    if(h.size()==0)
        g<<-1;
    else
    {
        while (h.size()>0)
        {
            int top_element=h.top();
            h.pop();
            g<<top_element<<" ";
        }

    }


    f.close();
    g.close();
    return 0;
}
