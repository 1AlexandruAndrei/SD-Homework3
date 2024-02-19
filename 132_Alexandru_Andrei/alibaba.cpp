#include <iostream>
#include <fstream>
#include <stack>
#include <string>
using namespace std;
ifstream f("alibaba.in");
ofstream g("alibaba.out");
int main()
{
    int nrc,nrd,i,c;
    string nr;

    f>>nrc>>nrd>>nr;

    stack<int> cif;
    for(i=0; i<nrc; i++)
    {

        c=nr[i]-'0';

        while(cif.size()>0 && cif.top()<c && nrd>0)
        {
            cif.pop();
            nrd--;

        }
        cif.push(c);
    }
    while(nrd>0 && cif.size()>0)
    {
        cif.pop();
        nrd--;
    }


    string maxi(cif.size(), ' ');
    int j=cif.size()-1;
    while(cif.size()>0)
    {
        maxi[j]=cif.top()+'0';
        j--;
        cif.pop();
    }
    g<<maxi;
    f.close();
    g.close();
    return 0;
}
