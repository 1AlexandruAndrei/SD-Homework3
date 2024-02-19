#include <iostream>
#include <fstream>
#include <vector>
using namespace std;
ifstream f("paranteze.in");
ofstream g("paranteze.out");
int main()
{
    long long i,n,l=0;
    string ch;
    vector<int>v;

    f>>n>>ch;
    for(i=0; i<n; i++)
    {

        if(ch[i]=='(' || ch[i]=='[' || ch[i]=='{')
            v.push_back(i);
        else if(( ( (ch[i]==')' && ch[v.back()]=='(') || (ch[i]==']' && ch[v.back()]=='[') || (ch[i]=='}' && ch[v.back()]=='{') ) && v.size()>0))
        {
            v.pop_back();
            if(i-v.back()>l)
                l=i-v.back();///l curent max
        }
        else
            v.push_back(i);

    }
    g<<l;

    return 0;
}
