#include <fstream>
#include <iostream>
#include <deque>
using namespace std;

ifstream f ("branza.in");
ofstream g ("branza.out");
long long v[100001];
int main()
{

    long long n,s,t,cost=0,x,i;
    deque <int> deq;
    f>>n>>s>>t;
    for(i=1;i<=n;i++)
    {
        f>>v[i]>>x;
        while(deq.size()>0 && v[i]<v[deq.back()] + s*(i-deq.back()))
            deq.pop_back();
        deq.push_back(i);
        while(deq.size()>0 && i-deq.front()>t)
            deq.pop_front();///nu mai e buna
        cost=cost+x*(v[deq.front()]+s*(i-deq.front()));///ce e bun

    }

    g<<cost;
    return 0;
}
