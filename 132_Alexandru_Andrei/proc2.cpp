#include <iostream>
#include <fstream>
#include <queue>
using namespace std;
ifstream f("proc2.in");
ofstream g("proc2.out");
int main()
{
    int i,n,m,j,s,d;
    priority_queue<int, vector<int>, greater<>> v;
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> heap;
    f>>n>>m;
    for(j=1;j<=n;j++)
        v.push(j);
    for(i=0;i<m;i++)
    {
        f>>s>>d;
        int timp=s+d;

        while(!heap.empty() && heap.top().first<=s)
        {
            v.push(heap.top().second);
            heap.pop();
        }
        heap.push({timp, v.top()});
        g<<v.top()<<endl;
        v.pop();
    }
    f.close();
    g.close();
    return 0;
}
