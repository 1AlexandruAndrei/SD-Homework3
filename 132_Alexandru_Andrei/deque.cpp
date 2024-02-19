#include <iostream>
#include <fstream>
using namespace std;
ifstream f("deque.in");
ofstream g("deque.out");

int main()
{
    long long n,k,i,s=0;
    f>>n>>k;
    int *v=new int[n+1];
    int *d=new int[n+1];
    for(i=1;i<=n;i++)
        f>>*(v+i);
    int fr=1, bk=0;
    for(i=1;i<=n;i++)
    {
        while(fr<=bk && *(v+i)<=*(v+*(d+bk)))
            bk--;
        bk++;
        *(d+bk)=i;
        if(*(d+fr)==i-k)
            fr++;
        if(i>=k)
            s+=*(v+*(d+fr));
    }
    g<<s;

    f.close();
    g.close();
    return 0;
}
